/*
  In this file we analyze the command line input arguments. 
  - The arguments read in are in order:
  - 1-> B=Bilayer P=Pore D=Disk
  - 2-> Mod number, which determines what type of calculatin is being done
  - 3-> Chemical Potential
*/
void inputArguments(int numb_of_args, char* arg_input[]){

  double chem_readin;

  if(strcmp( arg_input[1], "B") == 0){
    Bilayer=1;
  }else if(strcmp( arg_input[1], "P") == 0){
    Pore=1;
  }else if(strcmp( arg_input[1], "D") == 0){
    Disk=1;
  }else if(strcmp( arg_input[1], "LPar") == 0){
    LamPar=1;
  }else if(strcmp( arg_input[1], "LPer") == 0){
    LamPer=1;
  }else{
    std::cout<<"The phase you have chosen does not exists! check: inputArguments.hh"<<std::endl;
    exit(1);
  }
 

  chem_readin=atof(arg_input[3]);
    cout<<"chem_readin: "<<chem_readin<<endl;
  if(!(chem_readin==0.0)){
    if(AB_Hom==1){
      mu_t=-200.0;
      mu_h=chem_readin;
      mu_d=0.0;
      mu_ref=mu_d;
    }else if(ABA_Hom==1){
      mu_t=0.0;
      mu_h=chem_readin;
      mu_d=-200.0;
      mu_ref=mu_t;
    }else if(AB_ABA_Hom==1){
      mu_t=chem_readin;
      mu_h=0.0;
      mu_d=chem_readin;
      mu_ref=mu_t;
    }else{
      std::cout<<"The ensemble you have chosen is not correct. check: inputArguments.hh"<<std::endl;
      exit(1);
    }
  }else{
    std::cout<<"The chemical potential input is not correct. check: inputArguments.hh"<<std::endl;
    exit(1);
  }

};
