void mod_dmu(double *f,double *mu,double **chiMatrix,double **w,double **phi,double *eta,int *Ns,double ds,double *chi,double dr,int nmu,double *A, double *B, double *C, int nradii, double *mu_vec){
    
    cout<<"Running mod_dmu"<<endl;
    f[0] = 0.5;
    f[1] = 0.5;
    Ns[0] = 50;
    Ns[1] = 50;
    Ns[2] = 100;
    mu[1] = -8.0;
    
    double *r_0vector=create_1d_double_array(nradii+1, "r_0vector");
    double *Rad=create_1d_double_array(nradii, "Rad");                  //Radius for fitting
    double *Rad2=create_1d_double_array(nradii, "Rad");                  //Radius for fitting
    double *Curv1=create_1d_double_array(nradii, "Curvsq2");            //Curv sq. for fitting
    double *Curv2=create_1d_double_array(nradii, "Curvsq2");            //Curv sq. for fitting
    double *dFE = create_1d_double_array(nradii,"dfE");
    double *OP = create_1d_double_array(2*nmu+1,"OP");
    
    double *a1=create_1d_double_array(nmu+1, "a1");            //bending moduli constant term
    double *a2=create_1d_double_array(nmu+1, "a2");            //bending moduli quadratic term
    double *a3=create_1d_double_array(nmu+1, "a3");            //bending moduli quartic term
    double *a4=create_1d_double_array(nmu+1, "a1");            //bending moduli constant term
    double *a5=create_1d_double_array(nmu+1, "a2");            //bending moduli quadratic term
    double *a6=create_1d_double_array(nmu+1, "a3");            //bending moduli quartic term
    
    
    double volume;
    double fE_hom;
    
    for (int mu_iter=0;mu_iter<=nmu;mu_iter++){
        
        cout<<"diblock mu: "<<mu[0]<<" triblock mu: "<<mu[1]<<" homopolymer mu: "<<mu[2]<<endl;
        
        //Set parameters
        fE_hom=homogfE(mu,chiMatrix,f);                 //calculate homog. fE
        double pin=2*Nr/5;

        omega(w);                                       //Initiate omega field
        secant(w,phi,eta,Ns,ds, chi, dr, chiMatrix, mu,f,pin);
        
        //Set radius vector
        set_radius(r_0vector,nradii,f[0]);
        
        r_0=r_0vector[0];                                        //reset radius
        double avgradius=0.0;                                  //reset avgradius
        double avgmiddle=0.0;
        


        for (int radius=0;radius<nradii;radius++){
            volume=vol(dr);
            
            //calculate free energy minus homogeneneous free energy
            dFE[radius]=FreeEnergy(w,phi,eta,Ns,ds,chi,dr,chiMatrix,mu,volume,f,pin,0);
            
            int imax=mmbcentre(phi);                       //membrane center (max phib)
            int ihalf=mmb_half(phi,imax,pin);              //membrane middle (1/2 phib = phiA)
            
            avgradius+=(double)imax*dr;                    //avg membrane center
            avgmiddle+=(double)ihalf*dr;
            
            Rad[radius]=r_0;                               //set radius vectors
            Rad2[radius]=r_0;                               //set radius vectors

            
            //output concentration profile
            outputphi(phi,dr);
            
            //set new radius
            r_0=r_0vector[radius+1];
            
        }
        //output average radius
        avgradius/= (double)nradii;
        avgmiddle/= (double)nradii;
        
        //average OP
        OP[mu_iter] = calcOP(phi,dr,volume);                    //calculate order parameter

        
        //build curvature and curvature squared vectors
        for (int radius=0;radius<nradii;radius++){
            
            Rad[radius]+=avgmiddle;
            Rad2[radius]+=avgradius;

            Curv1[radius] =pow((4.3/Rad[radius]),2.0);

            Curv2[radius] =pow((4.3/Rad2[radius]),2.0);
        }
        
      
        curvefit(Curv1,dFE,nradii,mu_iter+1,a1,a2,a3);
        curvefit(Curv2,dFE,nradii,mu_iter+1,a4,a5,a6);

        
        //update mu triblock and diblock
        if (mu[1] < -2.0){
            mu[1]+= 0.25*abs(mu[1]);
        }
        else if (mu[1]<(-1e-10) && mu[1] >=-2.0 ){
            mu[1]+= 4.0/((double)nmu-10.0);
        }
        else {
            if (abs(mu[0])<=2.0){
                mu[1]=0.0;
                mu[0]-= 4.0/((double)nmu-10.0);
            }
            else{
                mu[1]=0.0;
                mu[0]-= 0.25*abs(mu[0]);
            }
        }
        
        
            
        
    }
  
    ofstream outFile1;
    ofstream outFile2;

    string filename1;
    string filename2;
    if (Coord==2){
        filename1="./results/mix/cylmid"+DoubleToStr(10.0*f[0])+".dat";
        filename2="./results/mix/cylmax"+DoubleToStr(10.0*f[0])+".dat";

    }
    else if (Coord==3){
        filename1="./results/mix/sphmid"+DoubleToStr(10.0*f[0])+".dat";
        filename2="./results/mix/sphmax"+DoubleToStr(10.0*f[0])+".dat";

    }
    outFile1.open(filename1.c_str());
    outFile2.open(filename2.c_str());

    
    for (int mu_iter=0;mu_iter<nmu;mu_iter++){
        outFile1<<OP[mu_iter]<<" "<<f[0]<<"  "<<a1[mu_iter]<<"    "<<a2[mu_iter]<<"  "<<a3[mu_iter]<<endl;
        outFile2<<OP[mu_iter]<<" "<<f[0]<<"  "<<a4[mu_iter]<<"    "<<a5[mu_iter]<<"  "<<a6[mu_iter]<<endl;

    }
    
    
}