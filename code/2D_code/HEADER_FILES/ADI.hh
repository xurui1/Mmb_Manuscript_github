/*
  This header-file contains the algorithm that preforms the Alternating Direction Implicit method.
  For more information on this file, please look at the included pdf file (theory.pdf)
  and for more general idea of what the algorithm does, visit:
  (https://en.wikipedia.org/wiki/Alternating_direction_implicit_method)
*/
double alpha(int i){
  double val;
  val=((ds)/(4.0*drz[0]*(((double)i)*drz[0]+R)))-((ds)/(2.0*drz[0]*drz[0]));
  return val;
}
double beta(int i,int j, int chain){
  double val;
  val=1.0+((ds*w[chain][i][j])/(4.0))+((ds)/(drz[0]*drz[0]));
  return val;
}
double gamma(int i){
  double val;
  val=-((ds)/(4.0*drz[0]*(((double)i)*drz[0]+R)))-((ds)/(2.0*drz[0]*drz[0]));
  return val;
}
double theta(int i){
  double val;
  val=(ds)/(2.0*drz[1]*drz[1]);
  return val;
}
double sigma(int i,int j, int chain){
  double val;
  val=1.0-((ds)/(drz[1]*drz[1]))-((ds*w[chain][i][j])/(4.0));
  return val;
}
//________________________________________________________________________
//________________________________________________________________________
double thetaHat(int i){
  double val;
  val=-(ds)/(2.0*drz[1]*drz[1]);
  return val;
}
double sigmaHat(int i,int j, int chain){
  double val;
  val=1.0+((ds)/(drz[1]*drz[1]))+((ds*w[chain][i][j])/(4.0));
  return val;
}
double alphaHat(int i){
  double val;
  val=((ds)/(2.0*drz[0]*drz[0]))-((ds)/(4.0*drz[0]*(((double)i)*drz[0]+R)));
  return val;
}
double betaHat(int i,int j, int chain){
  double val;
  val=1.0-((ds)/(drz[0]*drz[0]))-((ds*w[chain][i][j])/(4.0));
  return val;
}
double gammaHat(int i){
  double val;
  val=((ds)/(4.0*drz[0]*(((double)i)*drz[0]+R)))+((ds)/(2.0*drz[0]*drz[0]));
  return val;
}
//________________________________________________________________________
//________________________________________________________________________
// Upper Diagonal __________________________________________________________________________________________
void Make_Upper(char step, int index, int chain){
  int i;
  if(step=='h'){// half step
    Mu[0]=(gamma(0)+alpha(0));
    Mu[NBox-1]=0.0;
    for(i=1;i<(NBox-1);i++){
      Mu[i]=gamma(i);
    }
  }else{// full step
    Mu[0]=(2.0*thetaHat(0));
    Mu[NBox-1]=0.0;
    for(i=1;i<(NBox-1);i++){
      Mu[i]=thetaHat(i);
    }
  }
  return;
}
// Lower Diagonal __________________________________________________________________________________________
void Make_Lower(char step, int index, int chain){
  int i;
  if(step=='h'){// half step (the index assignment here looks a little weird, it is right, look at the theory derivation)
    Ml[NBox-1]=(gamma(NBox-1)+alpha(NBox-1));
    Ml[0]=0.0;
    for(i=1;i<(NBox-1);i++){
      Ml[i]=alpha(i);
    }
  }else{// full step
    Ml[NBox-1]=(2.0*thetaHat(0));
    Ml[0]=0.0;
    for(i=1;i<(NBox-1);i++){
      Ml[i]=thetaHat(i);
    }
  }
  return;
}
// Middle Diagonal __________________________________________________________________________________________
void Make_Middle(char step, int index, int chain){
  int i;
  if(step=='h'){
    for(i=0;i<NBox;i++){
      Mm[i]=beta(i,index,chain); 
    }
  }else{
    for(i=0;i<NBox;i++){
      Mm[i]=sigmaHat(index,i,chain);
    }
  }
  return;
}
// Right Vector _______________________________________________________________________________________________
void Make_Right_Vector(char step, int index, int chain){
  int i;
  if(step=='h'){ // half step
    if(index==0){
      for(i=0;i<NBox;i++){
	Rvector[i]=sigma(i,index,chain)*qini[i][index]+2.0*theta(index)*qini[i][index+1];	
      }
    }else if(index==(NBox-1)){
      for(i=0;i<NBox;i++){
	Rvector[i]=2.0*theta(index)*qini[i][index-1]+sigma(i,index,chain)*qini[i][index];
      }
    }else{
      for(i=0;i<NBox;i++){
	Rvector[i]=theta(index)*qini[i][index-1]+sigma(i,index,chain)*qini[i][index]+theta(index)*qini[i][index+1];
      }
    }
  }else{ // full step
    if(index==0){
      for(i=0;i<NBox;i++){
	Rvector[i]=betaHat(index,i,chain)*qini[index][i]+(alphaHat(index)+gammaHat(index))*qini[index+1][i];
      }
    }else if(index==(NBox-1)){
      for(i=0;i<NBox;i++){
	Rvector[i]=betaHat(index,i,chain)*qini[index][i]+(alphaHat(index)+gammaHat(index))*qini[index-1][i];
      }
    }else{
      for(i=0;i<NBox;i++){
	Rvector[i]=alphaHat(index)*qini[index-1][i]+betaHat(index,i,chain)*qini[index][i]+gammaHat(index)*qini[index+1][i];
      }
    }
  }

  return;
}
// Setting vectors _______________________________________________________________________________________________
void Make_q(char step, int index, int s, int chain, int direction){

  int counter,i,j;
  
  if(step=='h'){ // half step
    for(counter=0;counter<NBox;counter++){
      qmid[counter][index]=Rvector[counter];
    }
  }else if(step=='i'){// make qini from qmid
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	qini[i][j]=qmid[i][j];
      }
    }
  }else if(step=='f'){// full step
    if(direction==1){
      if(chain==0){
	for(counter=0;counter<NBox;counter++){
	  q0[index][counter][s]=Rvector[counter];
	}
      }else if(chain==1){
	for(counter=0;counter<NBox;counter++){
	  q1[index][counter][s]=Rvector[counter];
	}
      }else if(chain==2){
	for(counter=0;counter<NBox;counter++){
	  q2[index][counter][s]=Rvector[counter];
	}
      }else if(chain==3){
	for(counter=0;counter<NBox;counter++){
	  q3[index][counter][s]=Rvector[counter];
	}
      }else if(chain==4){
	for(counter=0;counter<NBox;counter++){
	  q4[index][counter][s]=Rvector[counter];
	}
      }else if(chain==5){
	for(counter=0;counter<NBox;counter++){
	  q5[index][counter][s]=Rvector[counter];
	}
      }
    }else if(direction==-1){
      if(chain==0){
	for(counter=0;counter<NBox;counter++){
	  q0dag[index][counter][s]=Rvector[counter];
	}
      }else if(chain==1){
	for(counter=0;counter<NBox;counter++){
	  q1dag[index][counter][s]=Rvector[counter];
	}
      }else if(chain==2){
	for(counter=0;counter<NBox;counter++){
	  q2dag[index][counter][s]=Rvector[counter];
	}
      }else if(chain==3){
	for(counter=0;counter<NBox;counter++){
	  q3dag[index][counter][s]=Rvector[counter];
	}
      }else if(chain==4){
	for(counter=0;counter<NBox;counter++){
	  q4dag[index][counter][s]=Rvector[counter];
	}
      }else if(chain==5){
	for(counter=0;counter<NBox;counter++){
	  q5dag[index][counter][s]=Rvector[counter];
	}
      }
    }
  }else if(step=='j'){// make qini from q[s]
    if(direction==1){
      if(chain==0){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q0[i][j][s];
	  }
	}
      }else if(chain==1){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q1[i][j][s];
	  }
	}
      }else if(chain==2){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q2[i][j][s];
	  }
	}
      }else if(chain==3){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q3[i][j][s];
	  }
	}
      }else if(chain==4){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q4[i][j][s];
	  }
	}
      }else if(chain==5){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q5[i][j][s];
	  }
	}
      }
    }else if(direction==-1){
      if(chain==0){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q0dag[i][j][s];
	  }
	}
      }else if(chain==1){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q1dag[i][j][s];
	  }
	}
      }else if(chain==2){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q2dag[i][j][s];
	  }
	}
      }else if(chain==3){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q3dag[i][j][s];
	  }
	}
      }else if(chain==4){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q4dag[i][j][s];
	  }
	}
      }else if(chain==5){
	for(i=0;i<NBox;i++){
	  for(j=0;j<NBox;j++){
	    qini[i][j]=q5dag[i][j][s];
	  }
	}
      }
    }  
  }else{
    std::cout<<"Something is wrong in Make_q functions!"<<std::endl;
  }
  
  return;
} 

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// This part goes over the actual ADI algorithm.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ADI(int chain, int direction){

  int s, i, j;

  for(s=1;s<Ns[chain];s++){ //s=0 is the initial condition
 
    for(j=0;j<NBox;j++){
      Make_Upper('h',j,chain);
      Make_Middle('h',j,chain);
      Make_Lower('h',j,chain);
      Make_Right_Vector('h',j,chain);
      TDI(Ml,Mm,Mu,Rvector,NBox);
      Make_q('h',j,s,chain,direction);
    }

    Make_q('i',0,s,chain,direction);
    
    for(i=0;i<NBox;i++){
      Make_Upper('f',i,chain);
      Make_Middle('f',i,chain);
      Make_Lower('f',i,chain);
      Make_Right_Vector('f',i,chain);
      TDI(Ml,Mm,Mu,Rvector,NBox);
      Make_q('f',i,s,chain,direction);
    }

    Make_q('j',0,s,chain,direction);

  }
  
  return;
};
