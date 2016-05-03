/*
  This function preforms the Trapezoidal integration. 
  For more general information, visit: (https://en.wikipedia.org/wiki/Trapezoidal_rule)
*/
double integrationTrapezoidal (double **func, int imin, int imax, int jmin, int jmax, double di, double dj, char geom) {

  int i, j;
  double funcSum;
  double radius;

  radius=R; // This is the radius of the pore or disk

  funcSum=0.0;
  
  // Cylindrical geometry
  if(geom=='c'){

    i=imin;
    j=jmin;
    funcSum+=func[i][j]*di*dj*(i*di+radius);
    i=imin;
    j=jmax;
    funcSum+=func[i][j]*di*dj*(i*di+radius);
    i=imax;
    j=jmin;
    funcSum+=func[i][j]*di*dj*(i*di+radius);
    i=imax;
    j=jmax;
    funcSum+=func[i][j]*di*dj*(i*di+radius);

    for(i=(imin+1);i<(imax);i++){
      j=jmin;
      funcSum+=2.0*func[i][j]*di*dj*(i*di+radius);
      j=jmax;
      funcSum+=2.0*func[i][j]*di*dj*(i*di+radius);
    }

    for(j=(jmin+1);j<(jmax);j++){
      i=imin;
      funcSum+=2.0*func[i][j]*di*dj*(i*di+radius);
      i=imax;
      funcSum+=2.0*func[i][j]*di*dj*(i*di+radius);
    }

    for(i=(imin+1);i<(imax);i++){
      for(j=(jmin+1);j<(jmax);j++){
	funcSum+=4.0*func[i][j]*di*dj*(i*di+radius);
      }
    }
    funcSum/=4.0;
  }else{
    std::cout<<"There is a problem in integrationTrapezoidal function!"<<std::endl;
    exit(1);
  }

  return funcSum;
  
}
