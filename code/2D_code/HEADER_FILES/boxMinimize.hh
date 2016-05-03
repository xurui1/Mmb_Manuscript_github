/*
  This header-file contains the algorithm that minimizes the free 
  energy of the system by looking at small changes in the box size.
*/
void boxMinimize( ){

  int i, exit_code;
  double dz[3], boxfE[3];

  exit_code=0;
  do{

    dz[0]=drz[1]+deltaBox;
    dz[1]=drz[1];
    dz[2]=drz[1]-deltaBox;
    for(i=0;i<3;i++){
      drz[1]=dz[i];
      calculateFreeEnergy();
      boxfE[i]=totalFreeEnergy;
      std::cout<<drz[1]*NBox<<" "<<boxfE[i]<<std::endl;
      std::cout<<"__"<<std::endl;
    }
    if((boxfE[0]<boxfE[1]) && (boxfE[0]<boxfE[2])){
      drz[1]=dz[0];
    }else if((boxfE[1]<boxfE[0]) && (boxfE[1]<boxfE[2])){
      drz[1]=dz[1];
      exit_code=1;
    }else if((boxfE[2]<boxfE[0]) && (boxfE[2]<boxfE[1])){
      drz[1]=dz[2];
    }else{
      exit_code=1;
    }

  }while(exit_code==0);
   
  return;

};
