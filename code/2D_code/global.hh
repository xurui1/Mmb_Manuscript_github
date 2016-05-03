#include <stdio.h>
#include <iostream>
#include <fstream>
#include <complex>
#include <stdlib.h> 
#include <math.h>      

using namespace std;

// Defined parameters
#define Pi 3.14159
#define NBox 64
#define ChainType 6
#define deltaBox 0.1/NBox

// Hydrophobic/phillic interaction
double mol_int=30.0;         // xN -> hydrophilic/hydrophobic interaction
double N_lipid = 100;        // NAB
double N_hydrophilic  = (0.5)*N_lipid;  // NA

// Choosing the type of ensemble
int Canonical = 0;
int GrandCanonical = 1;

// Type of Polymer Blend
int AB_Hom = 0;
int ABA_Hom = 1;
int AB_ABA_Hom = 0;

// Structure of system
int Bilayer = 0;
int Pore = 0;
int Disk = 0;
int LamPar = 0;
int LamPer = 0;

int Mod_global;

// Set to 1 to print during calculation
int print_fE = 1;

// Pinning condition
double pin_cond;
int iter_global;
int I_pin=int(NBox/2);
int J_pin=0;
  
// Simple mixing parameters 
double epsilon_w=0.01;
double epsilon_phi=0.01;

// Relative chain lengths
double kappa_homopolymer;
double kappa_diblock;
double kappa_triblock;

// Single chain partition functions
double Q_ABC, Q_DE, Q_F;

// Component of free energy
double totalFreeEnergy, Interaction_fE, Omega_fE, Entropy_fE, Homogenous_fE;

// Chemical potential
double mu_t, mu_d, mu_h;
double act_h, act_t, act_d, mu_ref;

// Chain polymerization
double NABC_triblock, NDE_diblock, NF_homopolymer;

// Distance from center of cylinder
double R, R_tip=0.0;

// Volume of the system
double Volume, Area;

// Control parameters
double delta_W, delta_Phi;
double precision=1.0e-3;

// Parameters
double LR, LZ;
double ***w, ***phi, *phiAve, *p_ave, *w_ave;
double  ***cal_w, ***del_w, **del_phi, *del_w_ave;
double **eta, **pin, **chiMatrix;
double ds, *drz;
double *f;
double phi_diblock, phi_triblock, phi_hom;
int *Ns;

// Propagators
double ***q0, ***q0dag;
double ***q1, ***q1dag;
double ***q2, ***q2dag;
double ***q3, ***q3dag;
double ***q4, ***q4dag;
double ***q5, ***q5dag;
double **qini, **qmid;

// ADI Parameters
double *Mu, *Mm, *Ml;
double *Rvector; 

// Dummy functions used for integration
double **dum_func1,**dum_func2,**dum_func3;

