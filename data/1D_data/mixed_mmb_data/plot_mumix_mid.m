clear all;

load 'cylmid5.dat';
load 'cylmid4.dat';
load 'cylmid6.dat';
load 'cylmid7.dat';
load 'cylmid3.dat';
load 'cylmid55.dat';
load 'cylmid45.dat';
load 'cylmid65.dat';
load 'cylmid35.dat';


OP05 = cylmid5(:,1);
f5 = cylmid5(:,2);
OP04 = cylmid4(:,1);
f4 = cylmid4(:,2);
OP03 = cylmid3(:,1);
f3 = cylmid3(:,2);
OP06 = cylmid6(:,1);
f6 = cylmid6(:,2);
OP055 = cylmid55(:,1);
f55 = cylmid55(:,2);
OP045 = cylmid45(:,1);
f45 = cylmid45(:,2);
OP035 = cylmid35(:,1);
f35 = cylmid35(:,2);
OP065 = cylmid65(:,1);
f65 = cylmid65(:,2);
OP07 = cylmid7(:,1);
f7 = cylmid7(:,2);



km05 = cylmid5(:,5);
km05_const = cylmid5(1,5);
km04 = cylmid4(:,5);
km04_const = cylmid4(1,5);
km03 = cylmid3(:,5);
km03_const = cylmid3(1,5);
km06 = cylmid6(:,5);
km06_const = cylmid6(1,5);
km055 = cylmid55(:,5);
km055_const = cylmid55(1,5);
km045 = cylmid45(:,5);
km045_const = cylmid45(1,5);
km035 = cylmid35(:,5);
km035_const = cylmid35(1,5);
km065 = cylmid65(:,5);
km065_const = cylmid65(1,5);
km07 = cylmid7(:,5);
km07_const = cylmid7(1,5);

km_matrix = [km03/km03_const km035/km035_const km04/km04_const km045/km045_const ...
    km05/km05_const km055/km055_const km06/km06_const km065/km065_const km07/km07_const]
OP_matrix = [OP03 OP035 OP04 OP045 OP05 OP055 OP06 OP065 OP07]

fA = ones(size(OP_matrix));
fA(:,1) = 0.3;
fA(:,2) = 0.35;
fA(:,3) = 0.4;
fA(:,4) = 0.45;
fA(:,5) = 0.5;
fA(:,6) = 0.55;
fA(:,7) = 0.6;
fA(:,8) = 0.65;
fA(:,9) = 0.7;

tri = delaunay(OP_matrix,fA);
plot(fA,OP_matrix,'.')
h = trisurf(tri, OP_matrix, fA, km_matrix);


axis([-1 1 0.3 0.7 1 1.25]);
xlabel('\fontsize{14} Order Parameters \Omega');
ylabel('\fontsize{14} Hydrophilic Fraction F_{A}');
zlabel('\fontsize{14} K_M / K_M^{AB}');
lighting phong
shading interp
colorbar East

