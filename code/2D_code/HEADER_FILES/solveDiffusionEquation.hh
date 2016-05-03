/*
  In this header-file, we solve the diffusion equations for the AB, ABA and H chains using the ADI method.
*/
void solveDiffusionEquation(int species){

  int i,j,s;

  if(species==0){ // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ABC Triblock copolymer
    // Solving forward________________________________
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=1.0;
	q0[i][j][0]=1.0;
      }
    }
    ADI(0,1); 
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=q0[i][j][Ns[0]-1];
	q1[i][j][0]=q0[i][j][Ns[0]-1];
      }
    }
    ADI(1,1);
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=q1[i][j][Ns[1]-1];
	q2[i][j][0]=q1[i][j][Ns[1]-1];
      }
    }
    ADI(2,1);
    // Solving backward________________________________
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=1.0;
	q2dag[i][j][0]=1.0;
      }
    }
    ADI(2,-1); 
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=q2dag[i][j][Ns[2]-1];
	q1dag[i][j][0]=q2dag[i][j][Ns[2]-1];
      }
    }
    ADI(1,-1);
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=q1dag[i][j][Ns[1]-1];
	q0dag[i][j][0]=q1dag[i][j][Ns[1]-1];
      }
    }
    ADI(0,-1);
    // Calculating partition function
    Q_ABC=0.0;
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	dum_func1[i][j]=q0dag[i][j][Ns[0]-1];
      }
    }
    Q_ABC=integrationTrapezoidal(dum_func1,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
    Q_ABC*=(2.0*Pi);
  }else if(species==1){// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ DE Diblock copolymer
    // Solving forward________________________________
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=1.0;
	q3[i][j][0]=1.0;
      }
    }
    ADI(3,1); 
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=q3[i][j][Ns[3]-1];
	q4[i][j][0]=q3[i][j][Ns[3]-1];
      }
    }
    ADI(4,1);
    // Solving backward________________________________
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=1.0;
	q4dag[i][j][0]=1.0;
      }
    }
    ADI(4,-1); 
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=q4dag[i][j][Ns[4]-1];
	q3dag[i][j][0]=q4dag[i][j][Ns[4]-1];
      }
    }
    ADI(3,-1);
    // Calculating partition function
    Q_DE=0.0;
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	dum_func2[i][j]=q3dag[i][j][Ns[3]-1];
      }
    }
    Q_DE=integrationTrapezoidal(dum_func2,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
    Q_DE*=(2.0*Pi);    
  }else if(species==2){// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ F Homopolymer
    // Solving forward________________________________
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=1.0;
	q5[i][j][0]=1.0;
      }
    }
    ADI(5,1); 
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	for(s=0;s<Ns[5];s++){
	  q5dag[i][j][s]=q5[i][j][s];
	}
      }
    }
    // Calculating partition function
    Q_F=0.0;
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	dum_func3[i][j]=q5dag[i][j][Ns[5]-1];
      }
    }
    Q_F=integrationTrapezoidal(dum_func3,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
    Q_F*=(2.0*Pi);
  }else{// Error check
    std::cout<<"Something went wrong in solveDiffusionEquation function!"<<std::endl;
    exit(1);
  }
    
  return;
  
};

// In this function, we will set to zero all q qdag and set to 1 all Q
void setToZero( ){
  int i, j, s;
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      for(s=0;s<Ns[0];s++){
	q0[i][j][s]=0.0;
      }
      for(s=0;s<Ns[1];s++){
	q1[i][j][s]=0.0;
      }
      for(s=0;s<Ns[2];s++){
	q2[i][j][s]=0.0;
      }
      for(s=0;s<Ns[3];s++){
	q3[i][j][s]=0.0;
      }
      for(s=0;s<Ns[4];s++){
	q4[i][j][s]=0.0;
      }
      for(s=0;s<Ns[5];s++){
	q5[i][j][s]=0.0;
      }
      for(s=0;s<Ns[0];s++){
	q0dag[i][j][s]=0.0;
      }
      for(s=0;s<Ns[1];s++){
	q1dag[i][j][s]=0.0;
      }
      for(s=0;s<Ns[2];s++){
	q2dag[i][j][s]=0.0;
      }
      for(s=0;s<Ns[3];s++){
	q3dag[i][j][s]=0.0;
      }
      for(s=0;s<Ns[4];s++){
	q4dag[i][j][s]=0.0;
      }
      for(s=0;s<Ns[5];s++){
	q5dag[i][j][s]=0.0;
      }
    }
  }
  Q_ABC=1.0;
  Q_DE=1.0;
  Q_F=1.0;
  return;
};
