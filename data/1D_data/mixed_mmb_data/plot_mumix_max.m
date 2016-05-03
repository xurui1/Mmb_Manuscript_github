clear all;

load 'cylmax5.dat';
load 'cylmax4.dat';
load 'cylmax6.dat';
load 'cylmax7.dat';
load 'cylmax3.dat';
load 'cylmax55.dat';
load 'cylmax45.dat';
load 'cylmax65.dat';
load 'cylmax35.dat';


OP05 = cylmax5(:,1);
f5 = cylmax5(:,2);
OP04 = cylmax4(:,1);
f4 = cylmax4(:,2);
OP03 = cylmax3(:,1);
f3 = cylmax3(:,2);
OP06 = cylmax6(:,1);
f6 = cylmax6(:,2);
OP055 = cylmax55(:,1);
f55 = cylmax55(:,2);
OP045 = cylmax45(:,1);
f45 = cylmax45(:,2);
OP035 = cylmax35(:,1);
f35 = cylmax35(:,2);
OP065 = cylmax65(:,1);
f65 = cylmax65(:,2);
OP07 = cylmax7(:,1);
f7 = cylmax7(:,2);



km05 = cylmax5(:,4);
km05_const = cylmax5(1,4);
km04 = cylmax4(:,4);
km04_const = cylmax4(1,4);
km03 = cylmax3(:,4);
km03_const = cylmax3(1,4);
km06 = cylmax6(:,4);
km06_const = cylmax6(1,4);
km055 = cylmax55(:,4);
km055_const = cylmax55(1,4);
km045 = cylmax45(:,4);
km045_const = cylmax45(1,4);
km035 = cylmax35(:,4);
km035_const = cylmax35(1,4);
km065 = cylmax65(:,4);
km065_const = cylmax65(1,4);
km07 = cylmax7(:,4);
km07_const = cylmax7(1,4);

km_matrix = [km03/km03_const km035/km035_const km04/km04_const km045/km045_const ...
    km05/km05_const km055/km055_const km06/km06_const km065/km065_const km07/km07_const];
OP_matrix = [OP03 OP035 OP04 OP045 OP05 OP055 OP06 OP065 OP07];

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

%surf(km_matrix,OP_matrix);

%mesh(km_matrix,OP_matrix);
%set(gca,'XTick',[] ); %This are going to be the only values affected.
%set(gca,'YTickLabel',[0.3 0.4 0.5 0.6 0.7] ); %This is what it's going to appear in those places.
%set(gca,'YTickLabel',[1 0.5 0 -0.5 -1] ); %This is what it's going to appear in those places.
set(gca,'Ytick',linspace(fA(1,1),fA(1,end),5))

axis([-1 1 0.3 0.7 1 1.25]);
view([0,90])
xlabel(' Order Parameter  \Omega');
ylabel('   {\itf_A}');
%c = colorbar;
%yyaxis right
%zlabel('\fontsize{14} \kappa_M / \kappa_M^{AB}');
%set(gca,'CameraPosition',[54 15 7687])
set(gca,'Fontsize',16);
lighting phong
shading interp
colorbar EastOutside

