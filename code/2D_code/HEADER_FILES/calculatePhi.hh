/*
  This function will calculate all the phi values using a Trapozoildal integration
*/
void calculatePhi(){
  
  for(int chain=0;chain<ChainType;chain++){
      for(int i=0;i<NBox;i++){
          for(int j=0;j<NBox;j++){
              phi[chain][i][j]=0.0;
              for(int s=0;s<Ns[chain];s++){
	  
	  if(s==0 || s==(Ns[chain]-1)){
	    if(chain==0){phi[chain][i][j]+=0.5*q0[i][j][s]*q0dag[i][j][(Ns[chain]-1)-s]*ds;}	    
	    if(chain==1){phi[chain][i][j]+=0.5*q1[i][j][s]*q1dag[i][j][(Ns[chain]-1)-s]*ds;}
	    if(chain==2){phi[chain][i][j]+=0.5*q2[i][j][s]*q2dag[i][j][(Ns[chain]-1)-s]*ds;}
	    if(chain==3){phi[chain][i][j]+=0.5*q3[i][j][s]*q3dag[i][j][(Ns[chain]-1)-s]*ds;}
	    if(chain==4){phi[chain][i][j]+=0.5*q4[i][j][s]*q4dag[i][j][(Ns[chain]-1)-s]*ds;}
	    if(chain==5){phi[chain][i][j]+=0.5*q5[i][j][s]*q5dag[i][j][(Ns[chain]-1)-s]*ds;}
	  }else{
	    if(chain==0){phi[chain][i][j]+=q0[i][j][s]*q0dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==1){phi[chain][i][j]+=q1[i][j][s]*q1dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==2){phi[chain][i][j]+=q2[i][j][s]*q2dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==3){phi[chain][i][j]+=q3[i][j][s]*q3dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==4){phi[chain][i][j]+=q4[i][j][s]*q4dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==5){phi[chain][i][j]+=q5[i][j][s]*q5dag[i][j][Ns[chain]-s]*ds;}
	  }
	}
	// Adding the constant infront, depending on the type of ensemble
	if(Canonical==1){
	  if(chain==0){phi[chain][i][j]*=phiAve[0]/(kappa_triblock*Q_ABC);}
	  if(chain==1){phi[chain][i][j]*=phiAve[0]/(kappa_triblock*Q_ABC);}
	  if(chain==2){phi[chain][i][j]*=phiAve[0]/(kappa_triblock*Q_ABC);}
	  if(chain==3){phi[chain][i][j]*=phiAve[1]/(kappa_diblock*Q_DE);}
	  if(chain==4){phi[chain][i][j]*=phiAve[1]/(kappa_diblock*Q_DE);}
	  if(chain==5){phi[chain][i][j]*=phiAve[2]/(kappa_homopolymer*Q_F);}
	}else if(GrandCanonical==1){
	  if(chain==0){phi[chain][i][j]*=(act_t/kappa_triblock);}
	  if(chain==1){phi[chain][i][j]*=(act_t/kappa_triblock);}
	  if(chain==2){phi[chain][i][j]*=(act_t/kappa_triblock);}
	  if(chain==3){phi[chain][i][j]*=(act_d/kappa_diblock);}
	  if(chain==4){phi[chain][i][j]*=(act_d/kappa_diblock);}
	  if(chain==5){phi[chain][i][j]*=(act_h/kappa_homopolymer);}
	}else{
	  std::cout<<"Something is wrong in calculatePhi function!"<<std::endl;
	  exit(1);
	}
	
      }
    }
  }

  return;
  
};
