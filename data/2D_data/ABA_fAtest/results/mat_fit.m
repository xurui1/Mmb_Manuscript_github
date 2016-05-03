clear all;

load 'fA3.dat'

fA3_R = fA3(:,1);
fA3_R = (1.0/4.3)*fA3_R;
fA3_fE = fA3(:,2);
fA3_fE_hom = fA3(:,3);
fA3_dfE = fA3_fE - fA3_fE_hom;
fA3_dfE = (1.0/(pi*4.3*4.3*4.3))*fA3_dfE;

fA3_fit = nlinfit(fA3_R,fA3_dfE,'poly1',1);

plot(fA3_fit,fA3_R,fA3_dfE);
%plot(fA3_R,fA3_dfE);