/*
  In this function, we will be calculating the homogenous free energy.
  Depending on the type of ensemble chosen, either the canonical or grand canonical.
*/
double calculatedHomogenousEnergy( ){

  double eta_ave;
  double dp, dw;
  double Qt_ave, Qd_ave, Qh_ave; 
  double fE_homo;

  
  if(Canonical==1){ // Calculating the canonical free energy
  
    fE_homo=0.0;
    for(int i=0;i<ChainType;i++){
      for(int j=0;j<ChainType;j++){
	fE_homo+=p_ave[i]*p_ave[j]*chiMatrix[i][j];
      }
    }
    fE_homo/=2.0;

  }else if(GrandCanonical==1){ // Calculating the grand canonical free energy


    p_ave[0]=0.002;
    p_ave[1]=0.002;
    p_ave[2]=0.002;
    p_ave[3]=0.002;
    p_ave[4]=0.002;
    p_ave[5]=1.0-(p_ave[0]+p_ave[1]+p_ave[2]+p_ave[3]+p_ave[4]);
    for(int chain=0;chain<ChainType;chain++){
      del_w_ave[chain]=0.0;
    }
    eta_ave=0.0;
    
    for(int ii=0;ii<ChainType;ii++){
      w_ave[ii]=0.0;
      for(int jj=0;jj<ChainType;jj++){
          w_ave[ii]+=chiMatrix[ii][jj]*p_ave[jj];
      }
      w_ave[ii]+=eta_ave;
    }
    
      for (int iter=0;iter<1e6;iter++){
      
      eta_ave=eta_ave-0.05*(1.0-(p_ave[0]+p_ave[1]+p_ave[2]+p_ave[3]+p_ave[4]+p_ave[5]));

      Qt_ave=exp(-kappa_triblock*(w_ave[0]*f[0]+w_ave[1]*f[1]+w_ave[2]*f[2]));
      Qd_ave=exp(-kappa_diblock*(w_ave[3]*f[3]+w_ave[4]*f[4]));
      Qh_ave=exp(-kappa_homopolymer*w_ave[5]);
      
      p_ave[0]=act_t*Qt_ave*f[0];
      p_ave[1]=act_t*Qt_ave*f[1];
      p_ave[2]=act_t*Qt_ave*f[2];
      p_ave[3]=act_d*Qd_ave*f[3];
      p_ave[4]=act_d*Qd_ave*f[4];
      p_ave[5]=act_h*Qh_ave*f[5];

      for(int ii=0;ii<ChainType;ii++){
          del_w_ave[ii]=0.0;
          for(int jj=0;jj<ChainType;jj++){
                del_w_ave[ii]+=chiMatrix[ii][jj]*p_ave[jj];
          }
          del_w_ave[ii]+=eta_ave;
          del_w_ave[ii]-=w_ave[ii];
      }

      dp=1.0-(p_ave[0]+p_ave[1]+p_ave[2]+p_ave[3]+p_ave[4]+p_ave[5]);
      dw=abs(del_w_ave[0]+del_w_ave[1]+del_w_ave[2]+del_w_ave[3]+del_w_ave[4]+del_w_ave[5])/(double)ChainType;

      for(int ii=0;ii<ChainType;ii++){
          w_ave[ii]+=0.005*del_w_ave[ii];
      }
    }
  
    fE_homo=0.0;
    for(int ii=0;ii<ChainType;ii++){
        for(int jj=0;jj<ChainType;jj++){
            fE_homo+=(p_ave[ii]*chiMatrix[ii][jj]*p_ave[jj])/2.0;
        }
        fE_homo-=p_ave[ii]*w_ave[ii];
    }
      fE_homo-=(act_t*Qt_ave/kappa_triblock);
      fE_homo-=(act_d*Qd_ave/kappa_diblock);
      fE_homo-=(act_h*Qh_ave/kappa_homopolymer);
    
  }
    cout<<"fE_homo: "<<fE_homo<<endl;
  
  return fE_homo;

};

