/*
  This header-file contains the algorithm that does the following:
  1-	Calculates the Lagrange Multiplier that ensures the incompressibility of the system.
  2-	Applies the pinning condition for the pore and disk geometry.

*/
void calculateEta( ){

  int     i,j,chain;
  double     dum1,dum2;
  double  phiTotal;
  double pin_delphi;

  // This part contains the code for the incompresibility condition
  phiTotal=0.0;
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      phiTotal=0.0;
      del_phi[i][j]=0.0;
      for(chain=0;chain<ChainType;chain++){
	phiTotal+=phi[chain][i][j];
      }
      del_phi[i][j]=1.0-phiTotal;
      eta[i][j]-=del_phi[i][j];
      
    }
  }
  
  // This part takes care of the pinning condition
  if(Pore==1 || Disk==1){
    R_tip=drz[0]*I_pin;
    pin_cond=1.0;
  }else if (Bilayer==1 || LamPar==1 || LamPer==1){
    pin_cond=0.0;
  }
  
  pin_delphi=(phi[0][I_pin][J_pin]+phi[2][I_pin][J_pin]+phi[3][I_pin][J_pin]+phi[5][I_pin][J_pin]-phi[1][I_pin][J_pin]-phi[4][I_pin][J_pin]);
  pin[I_pin][J_pin]-=pin_cond*pin_delphi;
  
  return;
  
};
