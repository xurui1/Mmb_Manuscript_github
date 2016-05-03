/*
  This file sets the omega functions manually.
  1=LamPar 2=LamPer 3=Bilayer 4=Pore 5=Disk
*/
void setOmegaManual( ){

  int i, j, chain,ii,jj;
  int phase;
  double numb_period=1.0;

  if(LamPar==1){
    phase=1;
  }else if (LamPer==1){
    phase=2;
  }else if(Bilayer==1){
    phase=3;
  }else if(Pore==1){
    phase=4;
  }else if(Disk==1){
    phase=5;
  }else{
    std::cout<<"No phase was selected!"<<std::endl;
    exit(1);
  }
  
  // Set to zero --------------------------
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      phi[0][i][j]=0.0;
      phi[1][i][j]=0.0;
      phi[2][i][j]=0.0;
      phi[3][i][j]=0.0;
      phi[4][i][j]=0.0;
      phi[5][i][j]=0.0;
    }
  }
  // --------------------------------------


  if(phase==1){ // Lam Parallel (modulation in z direction)
    numb_period=LZ/4.1; // 4.1 is for AB Lam fA=0.5 xAB=20
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[0][i][j]=cos(numb_period*2.0*Pi*j/NBox)+1.0;
	phi[1][i][j]=-cos(numb_period*2.0*Pi*j/NBox)+1.0;
	phi[2][i][j]=cos(numb_period*2.0*Pi*j/NBox)+1.0;
	phi[3][i][j]=cos(numb_period*2.0*Pi*j/NBox)+1.0;
	phi[4][i][j]=-cos(numb_period*2.0*Pi*j/NBox)+1.0;
	phi[5][i][j]=0.0;
      }
    }   
  }else if(phase==2){ // Lam Perpendicular (modulation in r direction)
    numb_period=LR/4.1; // 4.1 is for AB Lam fA=0.5 xAB=20
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[0][i][j]=cos(numb_period*2.0*Pi*i/NBox)+1.0;
	phi[1][i][j]=-cos(numb_period*2.0*Pi*i/NBox)+1.0;
	phi[2][i][j]=cos(numb_period*2.0*Pi*i/NBox)+1.0;
	phi[3][i][j]=cos(numb_period*2.0*Pi*i/NBox)+1.0;
	phi[4][i][j]=-cos(numb_period*2.0*Pi*i/NBox)+1.0;
	phi[5][i][j]=0.0;
      }
    }
  }else if(phase==3){ // Bilayer
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[5][i][j]=1.0;
      }
    }
    if(J_pin==0){
      for(i=0;i<NBox;i++){
	for(j=0;j<2;j++){
	  phi[1][i][j]=11.0;
	  phi[4][i][j]=11.0;
	  phi[5][i][j]=0.0;
	}
      }
    }else{
      for(i=0;i<NBox;i++){
	for(j=(NBox/2 - 1);j<(NBox/2 + 1);j++){
	  phi[1][i][j]=11.0;
	  phi[4][i][j]=11.0;
	  phi[5][i][j]=0.0;
	}
      }
    }
  }else if (phase==4){ // Pore
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[5][i][j]=1.0;
      }
    }
    if(J_pin==0){
      for(i=(NBox/2);i<NBox;i++){
	for(j=0;j<2;j++){
	  phi[1][i][j]=11.0;
	  phi[4][i][j]=11.0;
	  phi[5][i][j]=0.0;
	}
      }
    }else{
      for(i=(NBox/2);i<NBox;i++){
	for(j=(NBox/2 - 1);j<(NBox/2 + 1);j++){
	  phi[1][i][j]=10.0;
	  phi[4][i][j]=10.0;
	  phi[5][i][j]=0.0;
	}
      }
    }
  }else if (phase==5){ // Disk
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[5][i][j]=1.0;
      }
    }
    if(J_pin==0){
      for(i=0;i<(NBox/2);i++){
	for(j=0;j<2;j++){
	  phi[1][i][j]=11.0;
	  phi[4][i][j]=11.0;
	  phi[5][i][j]=0.0;
	}
      }
    }else{
      for(i=0;i<(NBox/2);i++){
	for(j=(NBox/2 - 1);j<(NBox/2 + 1);j++){
	  phi[1][i][j]=1.0;
	  phi[4][i][j]=1.0;
	  phi[5][i][j]=0.0;
	}
      }
    }
  }


  // ( Setting the omega fields ) ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      for(ii=0;ii<ChainType;ii++){
	w[ii][i][j]=0.0;
	for(jj=0;jj<ChainType;jj++){  
	  w[ii][i][j]+=chiMatrix[ii][jj]*phi[jj][i][j];
	}
      }
    }
  }
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  return;

};


















 
