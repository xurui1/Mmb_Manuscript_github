/*
  In this function we will be calculating the free energy using the ADI technique.
*/
void calculateFreeEnergy( ){

  int i,j,ii,jj,iter;

  Volume=0.0;
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      dum_func1[i][j]=1.0;
    }
  }
  Volume=2.0*Pi*integrationTrapezoidal(dum_func1,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');

  // Full area from center to right edge of box
  if(Pore==1){Area=Pi*(R+(drz[0]*NBox/2.0))*(R+(drz[0]*NBox/2.0));}
  if(Disk==1){Area=Pi*(R+(drz[0]*NBox/2.0))*(R+(drz[0]*NBox/2.0));}
  if(Bilayer==1){Area=Pi*(R+(drz[0]*NBox))*(R+(drz[0]*NBox));}
  

  // Setting the const chemical potential
  act_h=exp(kappa_homopolymer*(mu_h-mu_ref));
  act_t=exp(kappa_triblock*(mu_t-mu_ref));
  act_d=exp(kappa_diblock*(mu_d-mu_ref));
  
  // Homogenous free energy (not per volume)
  Homogenous_fE=calculatedHomogenousEnergy()*Volume;

  setToZero();
  iter=0;
  do{
    
    iter_global=iter;
    
    // Solving diffusion equations________________
    if(AB_Hom==1){
      solveDiffusionEquation(1);
      solveDiffusionEquation(2);
    }else if(ABA_Hom==1){
      solveDiffusionEquation(0);
      solveDiffusionEquation(2);
    }else if(AB_ABA_Hom==1){
      solveDiffusionEquation(0);
      solveDiffusionEquation(1);
      solveDiffusionEquation(2);
    }else{
      std::cout<<"You have choose the right blend!"<<std::endl;
      exit(1);
    }  
    // Calculate SCFT Equations___________________
    calculatePhi();
    calculateEta();
    calculateOmega(); 
    // Calculate Free Energy______________________

    if(Canonical==1){
      Entropy_fE=((phiAve[0]/kappa_triblock)*log(Q_ABC))+((phiAve[1]/kappa_diblock)*log(Q_DE))+((phiAve[2]/kappa_homopolymer)*log(Q_F));
    }else if(GrandCanonical==1){
      Entropy_fE=(act_t*Q_ABC/kappa_triblock)+(act_d*Q_DE/kappa_diblock)+(act_h*Q_F/kappa_homopolymer);
    }

    Omega_fE=0.0;
    Interaction_fE=0.0;

    for(i=0;i<NBox;i++){
        for(j=0;j<NBox;j++){
            dum_func1[i][j]=0.0;
            dum_func2[i][j]=0.0;
            for(ii=0;ii<ChainType;ii++){
                for(jj=0;jj<ChainType;jj++){
                    dum_func1[i][j]+=phi[ii][i][j]*chiMatrix[ii][jj]*phi[jj][i][j];
                }
                dum_func2[i][j]+=w[ii][i][j]*phi[ii][i][j];
            }
        }
    }
      
    // Calculating the components of the free energy
    Interaction_fE=integrationTrapezoidal(dum_func1,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c')/2.0;// 2 is for double counting
    Omega_fE=integrationTrapezoidal(dum_func2,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
        
    Omega_fE*=(2.0*Pi);
    Interaction_fE*=(2.0*Pi);
    
    totalFreeEnergy=Interaction_fE-Omega_fE-Entropy_fE;
    
    // Setting some parameters for the output.
    phi_diblock=0.0;
    phi_triblock=0.0;
    phi_hom=0.0;
    phi_diblock+=integrationTrapezoidal(phi[3],0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
    phi_diblock+=integrationTrapezoidal(phi[4],0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
    phi_diblock*=(2.0*Pi/Volume);
    phi_hom=integrationTrapezoidal(phi[5],0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
    phi_hom*=(2.0*Pi/Volume);
    phi_triblock=1.0-phi_diblock-phi_hom;

    if(print_fE==1 && iter%10==0){
      std::cout<<"Iteration= "<<iter<<"Delta FreeEnergy= "<<(totalFreeEnergy-Homogenous_fE)/Volume<<"   Convergence Condition= "<<delta_W<<"    Stops when less than= "<<precision<<std::endl;
    }
    
    if((iter%100)==0){
      saveData();
    }

    iter++;
    
  }while((delta_W>precision)||(iter<200));

  
};
