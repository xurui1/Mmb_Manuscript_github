load ABsph25.dat;
load ABAsph25.dat;
load ABsph30.dat;
load ABAsph30.dat;

fA = ABsph25(:,1);
AB4thSph25 = ABsph25(:,7);
ABA4thSph25 = ABAsph25(:,7);
AB4thSph30 = ABsph30(:,7);
ABA4thSph30 = ABAsph30(:,7);

A = plot (fA,AB4thSph25, 'k*-',fA, ABA4thSph25, 'r*-',fA,AB4thSph30, 'k+-',fA, ABA4thSph30, 'r+-'  );


xlabel('f_A'), ylabel('B_C')
title('4^{th} order Spherical bending moduli')