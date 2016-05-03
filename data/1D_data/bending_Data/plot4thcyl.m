
load ABcyl25.dat;
load ABAcyl25.dat;
load ABcyl30.dat;
load ABAcyl30.dat;

fA = ABcyl25(:,1);
AB4th = ABcyl25(:,7);
ABA4th = ABAcyl25(:,7);
AB4th30 = ABcyl30(:,7);
ABA4th30 = ABAcyl30(:,7);

ABA4th = 2*ABA4th;
AB4th = 2*AB4th;
AB4th30 = 2*AB4th30;
ABA4th30 = 2*ABA4th30;

A = plot (fA,AB4th, 'k*-',fA, ABA4th, 'r*-',fA, AB4th30, 'k-',fA, ABA4th30, 'r-');
%B = plot ( fA, ABkm30, 'k-',fA, ABAkm30, 'r-' );
xlabel('f_A'), ylabel('B_C')
title('4^{th} order bending moduli')
