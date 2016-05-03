load 'fA5_ABA.dat';

curv = fA5(:,1);
curv = curv./4.3;

fE = fA5(:,2);
fE_hom = fA5(:,3);

dfE = fE - fE_hom;

dfE = dfE./(pi*4.3^3);

plot(curv,dfE,'r+-');



