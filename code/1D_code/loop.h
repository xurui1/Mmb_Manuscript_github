

/*************This is my function for calulating the looping fraction for triblock************************/
void calcloop(double **qA2,double **qB2LL,double **qB2LR,double **qA3,int *Ns,double **w,double *mu,int imax,double *loop,double dr,double ds){ 
    
    double Q_ABA=0.0;
    
    //reset looping fractions
    loop[0]=0.0;
    loop[1]=0.0;
    
    //imax = Nr/2;
    
    //Generate constrained case
    for (int i=0;i<Nr;i++){
        if (i<imax){
            qB2LL[i][0] = qA2[i][Ns[0]];
            qB2LR[i][0] = 0.0;
        }
        else{
            qB2LL[i][0] = 0.0;
            qB2LR[i][0] = qA2[i][Ns[0]];
        }
    }
    
    solvediffyQ(qB2LL,w[3],ds,2*Ns[1],dr);
    solvediffyQ(qB2LR,w[3],ds,2*Ns[1],dr);
    
    
    //Calculate probability of looping
    for (int i=0;i<=imax;i++){
        double term =((qB2LL[i][2*Ns[1]])*(qA2[i][Ns[0]])*dV(i,dr));
        loop[0]+=term;
    }
    for (int i=imax;i<Nr;i++){
        double term = ((qB2LR[i][2*Ns[1]])*(qA2[i][Ns[0]])*dV(i,dr));
        loop[1]+=term;
    }
    for (int i=0;i<Nr;i++){
        Q_ABA += qA3[i][0]*qA2[i][Ns[0]]*dV(i,dr);
        
    }
    
    loop[0]/=Q_ABA;
    loop[1]/=Q_ABA;
    
}