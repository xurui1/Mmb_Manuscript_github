clear all;

load 'cylmid5.dat';
load 'cylmid4.dat';
load 'cylmid6.dat';
load 'cylmid7.dat';
load 'cylmid3.dat';

OP05 = cylmid5(:,1);
OP04 = cylmid4(:,1);
OP03 = cylmid3(:,1);
OP06 = cylmid6(:,1);
OP07 = cylmid7(:,1);

f05 = cylmid5(:,2);
f04 = cylmid4(:,2);
f03 = cylmid3(:,2);
f06 = cylmid6(:,2);
f07 = cylmid7(:,2);


km05 = cylmid5(:,4);
km05_const = cylmid5(1,4);
km04 = cylmid4(:,4);
km04_const = cylmid4(1,4);
km03 = cylmid3(:,4);
km03_const = cylmid3(1,4);
km06 = cylmid6(:,4);
km06_const = cylmid6(1,4);
km07 = cylmid7(:,4);
km07_const = cylmid7(1,4);


plot3(OP03,f03,km03/km03_const,'rs-',OP04,f04,km04/km04_const,...
    'k+-',OP05,f05,km05/km05_const,'g+-',OP06,f06,km06/km06_const,'b+-');
%plot(OP03,km03/km03_const,'r+-');

xlabel('\fontsize{14} Order Parameters \Omega');
ylabel('\fontsize{14} K_M / K_M^{AB}');

legend('\fontsize{14} f_A = 0.3','\fontsize{14} f_A = 0.4',...
    '\fontsize{14} f_A = 0.5','\fontsize{14} f_A = 0.6','location','northeast');
legend('boxoff');
%axis([-1 1 0.98 1.25]);


