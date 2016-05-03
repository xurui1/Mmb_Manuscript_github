/*
  In this header-file, I allocate the memory used in the program.
*/
void allocateMemory(int index){

  if(index==1){
    // Allocationg memory
    w=create_3d_double_array(ChainType,NBox,NBox,"w");
    phiAve=create_1d_double_array(3,"phiAve");
    p_ave=create_1d_double_array(ChainType,"p_ave");
    phi=create_3d_double_array(ChainType,NBox,NBox,"phi"); 
    eta=create_2d_double_array(NBox,NBox,"eta");
    pin=create_2d_double_array(NBox,NBox,"pin");
    Ns=create_1d_int_array(ChainType,"Ns");
    drz=create_1d_double_array(2,"drz");
    del_phi=create_2d_double_array(NBox,NBox,"del_phi");
    del_w=create_3d_double_array(ChainType,NBox,NBox,"del_w");
    cal_w=create_3d_double_array(ChainType,NBox,NBox,"cal_w");
    chiMatrix=create_2d_double_array(ChainType,ChainType,"chiMatrix");
    qini=create_2d_double_array(NBox,NBox,"qini");
    qmid=create_2d_double_array(NBox,NBox,"qmid");
    Mu=create_1d_double_array(NBox,"Mu");
    Ml=create_1d_double_array(NBox,"Ml");
    Mm=create_1d_double_array(NBox,"Mm");
    Rvector=create_1d_double_array(NBox,"Rvector");
    dum_func1=create_2d_double_array(NBox,NBox,"dum_func1");
    dum_func2=create_2d_double_array(NBox,NBox,"dum_func2");
    dum_func3=create_2d_double_array(NBox,NBox,"dum_func3");
    w_ave=create_1d_double_array(ChainType,"w_ave");
    del_w_ave=create_1d_double_array(ChainType,"del_w_ave");
    f=create_1d_double_array(ChainType,"f");
  }else if(index==2){
    // Allocating memory for propagators, after Ns values are defined
    q0=create_3d_double_array(NBox,NBox,Ns[0],"q0");
    q1=create_3d_double_array(NBox,NBox,Ns[1],"q1");
    q2=create_3d_double_array(NBox,NBox,Ns[2],"q2");
    q3=create_3d_double_array(NBox,NBox,Ns[3],"q3");
    q4=create_3d_double_array(NBox,NBox,Ns[4],"q4");
    q5=create_3d_double_array(NBox,NBox,Ns[5],"q5");
    q0dag=create_3d_double_array(NBox,NBox,Ns[0],"q0dag");
    q1dag=create_3d_double_array(NBox,NBox,Ns[1],"q1dag");
    q2dag=create_3d_double_array(NBox,NBox,Ns[2],"q2dag");
    q3dag=create_3d_double_array(NBox,NBox,Ns[3],"q3dag");
    q4dag=create_3d_double_array(NBox,NBox,Ns[4],"q4dag");
    q5dag=create_3d_double_array(NBox,NBox,Ns[5],"q5dag");
  }else if(index==-1){
    //Deallocating memory
    destroy_3d_double_array(w);
    destroy_1d_double_array(phiAve);
    destroy_1d_double_array(p_ave);
    destroy_2d_double_array(eta);
    destroy_2d_double_array(pin);
    destroy_3d_double_array(phi);
    destroy_1d_int_array(Ns);
    destroy_1d_double_array(drz);
    destroy_2d_double_array(chiMatrix);
    destroy_3d_double_array(del_w);
    destroy_3d_double_array(cal_w);
    destroy_2d_double_array(del_phi);
    destroy_3d_double_array(q0);
    destroy_3d_double_array(q1);
    destroy_3d_double_array(q2);
    destroy_3d_double_array(q3);
    destroy_3d_double_array(q4);
    destroy_3d_double_array(q5);
    destroy_3d_double_array(q0dag);
    destroy_3d_double_array(q1dag);
    destroy_3d_double_array(q2dag);
    destroy_3d_double_array(q3dag);
    destroy_3d_double_array(q4dag);
    destroy_3d_double_array(q5dag);
    destroy_2d_double_array(qini);
    destroy_2d_double_array(qmid);
    destroy_1d_double_array(Mu);
    destroy_1d_double_array(Ml);
    destroy_1d_double_array(Mm);
    destroy_1d_double_array(Rvector);
    destroy_2d_double_array(dum_func1);
    destroy_2d_double_array(dum_func2);
    destroy_2d_double_array(dum_func3);
    destroy_1d_double_array(w_ave);
    destroy_1d_double_array(del_w_ave);
    destroy_1d_double_array(f);
    //-------------------------------------
  }else{
    std::cout<<"Please check your input to allocateMemory.hh file."<<std::endl;
    exit(1);
  }
  return;
};
