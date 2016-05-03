/*
  In this function,  we are calculating the omega fields.
*/
void calculateOmega( ){

  delta_W=0.0;
  for(int i=0;i<NBox;i++){
    for(int j=0;j<NBox;j++){
      
      for(int ii=0;ii<ChainType;ii++){
	cal_w[ii][i][j]=0.0;
	for(int jj=0;jj<ChainType;jj++){
	  cal_w[ii][i][j]+=chiMatrix[ii][jj]*phi[jj][i][j];
	}
	// Add the pinning condition 
	if(ii==0){cal_w[ii][i][j]+=eta[i][j]-pin[i][j];}
	if(ii==1){cal_w[ii][i][j]+=eta[i][j]+pin[i][j];}
	if(ii==2){cal_w[ii][i][j]+=eta[i][j]-pin[i][j];}
	if(ii==3){cal_w[ii][i][j]+=eta[i][j]-pin[i][j];}
	if(ii==4){cal_w[ii][i][j]+=eta[i][j]+pin[i][j];}
	if(ii==5){cal_w[ii][i][j]+=eta[i][j]-pin[i][j];}

	del_w[ii][i][j]=cal_w[ii][i][j]-w[ii][i][j];
	delta_W+=abs(del_w[ii][i][j]);
	// Updating omega fileds
	w[ii][i][j]+=epsilon_w*del_w[ii][i][j]-epsilon_phi*del_phi[i][j];
      }
    }
  }
  delta_W/=(NBox*NBox);
  return;
 
};

