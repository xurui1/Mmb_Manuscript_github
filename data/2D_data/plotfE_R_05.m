clear all;
hold off;

%load fA5 data

load './ABA_fAtest/results/fA5.dat';

curv = fA5(:,1);
curv = curv./4.3;

fE = fA5(:,2);
fE_hom = fA5(:,3);
dfE = fE - fE_hom;
dfE = dfE./(pi*4.3^3);

load './AB_fAtest/results/fA5.dat';

curv2 = fA5(:,1);
curv2 = curv2./4.3;

fE2 = fA5(:,2);
fE_hom2 = fA5(:,3);
dfE2 = fE2 - fE_hom2;
dfE2 = dfE2./(pi*4.3^3);


P1 = polyfit(curv,dfE,1);
fit = [P1(2), P1(1)*25+P1(2)];

P2 = polyfit(curv2,dfE2,1);
fit2 = [P2(2), P2(1)*25+P2(2)];


curvfit1=[0;25];
curvfit2=[0;25];


%load fA4 data

load './ABA_fAtest/results/fA4.dat';

curvf4 = fA4(:,1);
curvf4 = curvf4./4.3;

fEf4 = fA4(:,2);
fE_homf4 = fA4(:,3);
dfEf4 = fEf4 - fE_homf4;
dfEf4 = dfEf4./(pi*4.3^3);

load './AB_fAtest/results/fA4.dat';

curv2f4 = fA4(:,1);
curv2f4 = curv2f4./4.3;

fE2f4 = fA4(:,2);
fE_hom2f4 = fA4(:,3);
dfE2f4 = fE2f4 - fE_hom2f4;
dfE2f4 = dfE2f4./(pi*4.3^3);


P1f4 = polyfit(curvf4,dfEf4,1);
fitf4 = [P1f4(2), P1f4(1)*25+P1f4(2)];

P2f4 = polyfit(curv2,dfE2f4,1);
fit2f4 = [P2f4(2), P2f4(1)*25+P2f4(2)];


curvfit1f4=[0;25];
curvfit2f4=[0;25];

%load fA 6 data

load './ABA_fAtest/results/fA6.dat';

curvf6 = fA6(:,1);
curvf6 = curvf6./4.3;

fEf6 = fA6(:,2);
fE_homf6 = fA6(:,3);
dfEf6 = fEf6 - fE_homf6;
dfEf6 = dfEf6./(pi*4.3^3);

load './AB_fAtest/results/fA6.dat';

curv2f6 = fA6(:,1);
curv2f6 = curv2f6./4.3;

fE2f6 = fA6(:,2);
fE_hom2f6 = fA6(:,3);
dfE2f6 = fE2f6 - fE_hom2f6;
dfE2f6 = dfE2f6./(pi*4.3^3);


P1f6 = polyfit(curvf6,dfEf6,1);
fitf6 = [P1f6(2), P1f6(1)*25+P1f6(2)];

P2f6 = polyfit(curv2,dfE2f6,1);
fit2f6 = [P2f6(2), P2f6(1)*25+P2f6(2)];


curvfit1f6=[0;25];
curvfit2f6=[0;25];

%load fA 3 data

load './ABA_fAtest/results/fA3.dat';

curvf3 = fA3(:,1);
curvf3 = curvf3./4.3;

fEf3 = fA3(:,2);
fE_homf3 = fA3(:,3);
dfEf3 = fEf3 - fE_homf3;
dfEf3 = dfEf3./(pi*4.3^3);

load './AB_fAtest/results/fA3.dat';

curv2f3 = fA3(:,1);
curv2f3 = curv2f3./4.3;

fE2f3 = fA3(:,2);
fE_hom2f3 = fA3(:,3);
dfE2f3 = fE2f3 - fE_hom2f3;
dfE2f3 = dfE2f3./(pi*4.3^3);


P1f3 = polyfit(curvf3,dfEf3,1);
fitf3 = [P1f3(2), P1f3(1)*25+P1f3(2)];

P2f3 = polyfit(curv2f3,dfE2f3,1);
fit2f3 = [P2f3(2), P2f3(1)*25+P2f3(2)];


curvfit1f3=[0;25];
curvfit2f3=[0;25];

%load fA 7 data

load './ABA_fAtest/results/fA7.dat';

curvf7 = fA7(:,1);
curvf7 = curvf7./4.3;

fEf7 = fA7(:,2);
fE_homf7 = fA7(:,3);
dfEf7 = fEf7 - fE_homf7;
dfEf7 = dfEf7./(pi*4.3^3);

load './AB_fAtest/results/fA7.dat';

curv2f7 = fA7(:,1);
curv2f7 = curv2f7./4.3;

fE2f7 = fA7(:,2);
fE_hom2f7 = fA7(:,3);
dfE2f7 = fE2f7 - fE_hom2f7;
dfE2f7 = dfE2f7./(pi*4.3^3);


P1f7 = polyfit(curvf7,dfEf7,1);
fitf7 = [P1f7(2), P1f7(1)*25+P1f7(2)];

P2f7 = polyfit(curv2f7,dfE2f7,1);
fit2f7 = [P2f7(2), P2f7(1)*25+P2f7(2)];


curvfit1f7=[0;25];
curvfit2f7=[0;25];

    
    
A = plot(curv,dfE,'r+',curv2,dfE2,'k+',curvfit1,fit,'r',curvfit2,fit2,'k');
%plot(curv,dfE,'r+',curv2,dfE2,'k+');

set(A(3),'linewidth',1.5);
set(A(4),'linewidth',1.5);
%set(A(7),'linewidth',1.5);
%set(A(8),'linewidth',1.5);
%%set(A(11),'linewidth',1.5);
%set(A(12),'linewidth',1.5);
%set(A(15),'linewidth',1.5);
%set(A(16),'linewidth',1.5);
%set(A(19),'linewidth',1.5);
%set(A(20),'linewidth',1.5);

xlabel('\fontsize{14} Radius (R/R_g)');
ylabel('\fontsize{14} F^P');




