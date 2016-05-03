/*
  In Mod0, we calculate the free energy for a give set of parameters.
  Results are printed and not saved, this mode is mainly for testing.
*/
void Mod0( ){

  print_fE=1;
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag
  calculateFreeEnergy();
  std::cout<<"Box Size=  "<<NBox<<"  "<<"FreeEnergy=  "<<(totalFreeEnergy-Homogenous_fE)/Volume<<std::endl;
  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
