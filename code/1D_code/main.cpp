
#include "global.h"
#include "parameters.h"
#include "filename.h"
#include "omega.h"
#include "TDMA.h"
#include "solvediffeq.h"
#include "vol.h"
#include "phi.h"
#include "Q_partition.h"
#include "polymers.h"
#include "loop.h"
#include "conc.h"
#include "Incomp.h"
#include "output.h"
#include "fE.h"
#include "homogfE.h"
#include "secant.h"
#include "radius.h"
#include "calcexcess.h"
#include "FreeEnergy.h"
#include "curvefitting.h"
#include "mod_width.h"
#include "mod_radius.h"
#include "mod_phi.h"
#include "mod_phif50.h"
#include "mod_FEC.h"
#include "mod_dmu.h"
#include "mod_homog_mu.h"
#include "mod_main.h"


int main( ){
    
    double **w=create_2d_double_array(ChainType,Nr,"w");          //Auxiliary potential fields
    double *eta=create_1d_double_array(Nr,"eta");                //Incompressibility field;
    double **phi=create_2d_double_array(ChainType,Nr,"phi");      //Concentration fields
    double *chi=create_1d_double_array(ChainType,"chi");            //Interaction parameters
    double *f=create_1d_double_array(ChainType,"f");                //Chain fractions
    double *mu=create_1d_double_array(3, "mu");                     //Chemical potentials
    int *Ns=create_1d_integer_array(ChainType, "Ns");            //Chain lengths
    double **chiMatrix=create_2d_double_array(ChainType,ChainType,"chiMatrix");
    int nradii=50,nfa=41,nmu = 40;                                       //number of radius & fa measurements
    double *mu_vec=create_1d_double_array(nfa,"mu_vec");
    double *dFE=create_1d_double_array(nradii, "dFE");                  //Bending free energy
    double *A=create_1d_double_array(1,"A");                        //fitting constants for mmb radius
    double *B=create_1d_double_array(1,"B");
    double *C=create_1d_double_array(1,"C");
    double *D=create_1d_double_array(1,"D");
    double *E=create_1d_double_array(1,"E");
    double *F=create_1d_double_array(1,"F");
    double ds,dr;
    
    
    //Initial time for random number generator
    long iseed;
    time_t t;
    iseed=time(&t);
    srand48(iseed);
    
    //Set parameters & interaction matrix
    parameters(chi,f,&ds,Ns,&dr,mu);
    Xmatrix(chiMatrix,chi);
    
    //mod_width(f,mu,chiMatrix,w,phi,eta,Ns,ds,chi,dr,nfa);
    
    //calculate radius of membrane center
    //mod_radius(f,mu,chiMatrix,w,phi,eta,Ns,ds,chi,dr,A,B,C,D,E,F,nfa,mu_vec);
    
    
    //calculate concentration profiles
    //mod_phi(f,mu,chiMatrix,w,phi,eta,Ns,ds,chi,dr,nfa,A,B,C,nradii,dFE,mu_vec);
    //mod_phif50(f,mu,chiMatrix,w,phi,eta,Ns,ds,chi,dr);
    mod_FEC(f,mu,chiMatrix,w,phi,eta,Ns,ds,chi,dr,nradii);
    
    //calculate bending moduli for blends of ABA and AB
    //mod_dmu(f,mu,chiMatrix,w,phi,eta,Ns,ds,chi,dr,nmu,A,B,C,nradii,mu_vec);
    //parameters(chi,f,&ds,Ns,&dr,mu);
    
    //calculate mu_C for homogeneous membranes for various f_A
    //mod_homog_mu(f,mu,chiMatrix,w,phi,eta,Ns,ds,chi,dr,nfa);
    
    
    ofstream outputrad;
    outputrad.open("./results/radius_fit.dat");
    outputrad<<A[0]<<" "<<B[0]<<" "<<C[0]<<endl;
    outputrad<<D[0]<<" "<<E[0]<<" "<<F[0]<<endl;

    outputrad.close();
    
    //reset parameters
    //parameters(chi,f,&ds,Ns,&dr,mu);

    //main function for finding bending moduli
    //mod_main(f,mu,chiMatrix,w,phi,eta,Ns,ds,chi,dr,nfa,A,B,C,D,E,F,nradii,dFE,mu_vec);
   

    
    //Destroy memory allocations------------
    destroy_2d_double_array(w);
    destroy_1d_double_array(eta);
    destroy_2d_double_array(phi);
    destroy_1d_double_array(chi);
    destroy_1d_integer_array(Ns);
    destroy_1d_double_array(f);
    destroy_2d_double_array(chiMatrix);
    //-------------------------------------
    
    return 0;
}
