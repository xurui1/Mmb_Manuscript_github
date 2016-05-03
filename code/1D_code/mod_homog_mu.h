//Here I calculate the chemical potentials for homogeneous membranes to use in Ash's 2D code
void mod_homog_mu(double *f,double *mu,double **chiMatrix,double **w,double **phi,double *eta,int *Ns,double ds,double *chi,double dr, int nfa){
    
    
    ofstream outputmu;
    if (poly==0){
        outputmu.open("./results/homog_mu_ABA.dat");
    }
    else if (poly==1){
        outputmu.open("./results/homog_mu_AB.dat");
    }
    
    int dds = Ns[2]*0.4/((double)nfa-1.0);
    cout<<"dds: "<<dds<<endl;
    omega(w);
    
    for (int i=0;i<nfa;i++){
        updateparameters(f,Ns,i*dds);
        
        cout<<"fA: "<<f[0]<<"poly: "<<poly<<endl;
        
        //calculate homogeneous mu for f_A
        secant(w,phi,eta,Ns,ds,chi,dr,chiMatrix,mu,f,2*Nr/5);
        outputmu<<f[0]<<"   "<<mu[2]<<endl;
            
    }
    
    outputmu.close();
    
    
}