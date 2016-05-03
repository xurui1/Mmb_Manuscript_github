/**************My function for calculating the concentration profile for an FA = 0.5 membrane***********************************************/

void mod_FEC(double *f,double *mu,double **chiMatrix,double **w,double **phi,double *eta,int *Ns,double ds,double *chi,double dr, int nradii){
    
    cout<<"calculating free energy as a function of curvature for fA = 0.5"<<endl;
    
    double dds = 0.2*Ns[2];
    updateparameters(f,Ns,dds);
    
    double volume;
    double fE_hom;
    double *r_0vector = create_1d_double_array(nradii+1,"r_0vector");
    double *dfE = create_1d_double_array(nradii+1,"dfE");
    
    
    //Initiate omega field
    omega(w);
    
    
    //Find tensionless mmb
    secant(w,phi,eta,Ns,ds,chi,dr,chiMatrix,mu,f,2*Nr/5);  //Find tensionless mmb
    
    
    //calculate homogeneous free energy
    fE_hom=homogfE(mu,chiMatrix,f);
    
    set_radius(r_0vector,nradii,f[0]);
    
    //define pinning location
    int pin = 2*Nr/5;
    
    for (int i=0;i<=nradii;i++){
        //reset radius
        r_0=r_0vector[i];
        cout<<r_0<<endl;
        //calculate volume
        volume=vol(dr);
        
        //calculate free energy minus homogeneneous free energy
        dfE[i]=FreeEnergy(w,phi,eta,Ns,ds,chi,dr,chiMatrix,mu,volume,f,pin,1);
        
        
        ofstream outfile;
        if (poly==0 && Coord==3){
            string filename;
            filename="./results/fE/ABA/ABA_sph_"+IntToStr(i)+".dat";
            outfile.open(filename.c_str());
        }
        
        else if (poly==0 && Coord==2){
            string filename;
            filename="./results/fE/ABA/ABA_cyl_"+IntToStr(i)+".dat";
            outfile.open(filename.c_str());
        }
        else if (poly==1 && Coord==3){
            string filename;
            filename="./results/fE/AB/AB_sph_"+IntToStr(i)+".dat";
            outfile.open(filename.c_str());
        }
        
        else if (poly==1 && Coord==2){
            string filename;
            filename="./results/fE/AB/AB_cyl_"+IntToStr(i)+".dat";
            outfile.open(filename.c_str());
        }
        
        for (int j=0;j<Nr;j++){
            outfile<<r_0+j*dr<<" "<<phi[0][j]<<" "<<phi[1][j]<<" "<<phi[2][j]<<" "<<phi[3][j]<<" "<<phi[4][j]<<" "<<phi[5][j]<<endl;
        }
    }
    
    
    //output concentration profile
    
    ofstream outfile2;
    if (poly==0 && Coord==3){
        outfile2.open("./results/fE/fEC_ABA_sphere.dat");
    }
    if (poly==0 && Coord==2){
        outfile2.open("./results/fE/fEC_ABA_cylinder.dat");
    }
    if (poly==1 && Coord==3){
        outfile2.open("./results/fE/fEC_AB_sphere.dat");
    }
    if (poly==1 && Coord==2){
        outfile2.open("./results/fE/fEC_AB_cylinder.dat");
    }
    for (int i=0;i<=nradii;i++){
        outfile2<<4.3/(r_0vector[i]+6.0)<<" "<<dfE[i]<<endl;
    }
    
    
    
    
    
}