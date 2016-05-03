/*
  In Mod2, we calculate the Free energy as a function of chemical potential.
  The result is saved in RESULTS/Mod2_Results.dat
  You can plot the results by running the Mod1_Result.p script in Gnuplot platform
*/
void Mod2( ){

  std::cout<<"Starting Mod2 function"<<std::endl;
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  
  double mu, mu_Lim=8.9;
  
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag

  std::ofstream outputFile1("./RESULTS/Mod2_Results.dat");
  outputFile1<<"#"<<"mu"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
  std::cout<<"mu"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
 
  do{
    
    if(AB_Hom==1){mu=mu_d;}
    if(ABA_Hom==1){mu=mu_t;}
    
    
    calculateFreeEnergy();
    
    std::cout<<mu<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
    outputFile1<<mu<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
    
    
    if(AB_Hom==1){mu_d+=0.05;}
    if(ABA_Hom==1){mu_t+=0.05;}
    
  
  }while(mu<mu_Lim);
  std::cout<<"+++++++++++++++++++++++++++"<<std::endl;

  outputFile1.close();
  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
