load 'ABAcyl.dat'
load 'ABAsph.dat'
load 'ABAplane.dat'
load 'ABcyl.dat'
load 'ABsph.dat'
load 'ABplane.dat'

radius = ABAcyl(:,1);
phiA_ABAcyl = ABAcyl(:,2)+ ABAcyl(:,4)+ ABAcyl(:,6);
phiB_ABAcyl = ABAcyl(:,3)+ ABAcyl(:,5);
phiC_ABAcyl = ABAcyl(:,7);

phiA_ABAsph = ABAsph(:,2)+ ABAsph(:,4)+ ABAsph(:,6);
phiB_ABAsph = ABAsph(:,3)+ ABAsph(:,5);
phiC_ABAsph = ABAsph(:,7);

phiA_ABAplane = ABAplane(:,2)+ ABAplane(:,4)+ ABAplane(:,6);
phiB_ABAplane = ABAplane(:,3)+ ABAplane(:,5);
phiC_ABAplane = ABAplane(:,7);

phiA_ABcyl = ABcyl(:,2)+ ABcyl(:,4)+ ABcyl(:,6);
phiB_ABcyl = ABcyl(:,3)+ ABcyl(:,5);
phiC_ABcyl = ABcyl(:,7);

phiA_ABsph = ABsph(:,2)+ ABsph(:,4)+ ABsph(:,6);
phiB_ABsph = ABsph(:,3)+ ABsph(:,5);
phiC_ABsph = ABsph(:,7);

phiA_ABplane = ABAplane(:,2)+ ABAplane(:,4)+ ABAplane(:,6);
phiB_ABplane = ABAplane(:,3)+ ABAplane(:,5);
phiC_ABplane = ABAplane(:,7);

%A = plot (radius, phiA_ABAcyl, radius, phiB_ABAcyl, radius, phiC_ABAcyl);
%B = plot (radius, phiA_ABAsph, radius, phiB_ABAsph, radius, phiC_ABAsph);
%C = plot (radius, phiA_ABAplane, radius, phiB_ABAplane, radius, phiC_ABAplane);
D = plot (radius, phiA_ABAplane, radius, phiB_ABAplane, radius, phiC_ABAplane, ...
    radius, phiA_ABAsph, ':', radius, phiB_ABAsph, ':', radius, phiC_ABAsph,':', ...
    radius, phiA_ABAcyl,'--', radius, phiB_ABAcyl,'--', radius, phiC_ABAcyl,'--');

%E = plot (radius, phiA_ABcyl, radius, phiB_ABcyl, radius, phiC_ABcyl);
%F = plot (radius, phiA_ABsph, radius, phiB_ABsph, radius, phiC_ABsph);
%G = plot (radius, phiA_ABplane, radius, phiB_ABplane, radius, phiC_ABplane);
%H = plot (radius, phiA_ABplane, radius, phiB_ABplane, radius, phiC_ABplane, ...
 %   radius, phiA_ABsph,':', radius, phiB_ABsph,':', radius, phiC_ABsph, ':',...
 %   radius, phiA_ABcyl,'--', radius, phiB_ABcyl, '--', radius, phiC_ABcyl,'--');
%J = plot (radius, phiA_ABplane, radius, phiB_ABplane, radius, phiC_ABplane);

set(D(1),'linewidth',1.2, 'color', 'g');
set(D(2),'linewidth',1.2, 'color', 'k');
set(D(3),'linewidth',1.2, 'color', 'b');
set(D(4),'linewidth',1.2, 'color', 'g');
set(D(5),'linewidth',1.2, 'color', 'k');
set(D(6),'linewidth',1.2, 'color', 'b');
set(D(7),'linewidth',1.2, 'color', 'g');
set(D(8),'linewidth',1.2, 'color', 'k');
set(D(9),'linewidth',1.2, 'color', 'b');

%set(H(1),'linewidth',1.2, 'color', 'r');
%set(H(2),'linewidth',1.2, 'color', 'k');
%set(H(3),'linewidth',1.2, 'color', 'b');
%set(H(4),'linewidth',1.2, 'color', 'r');
%set(H(5),'linewidth',1.2, 'color', 'k');
%set(H(6),'linewidth',1.2, 'color', 'b');
%set(H(7),'linewidth',1.2, 'color', 'r');
%set(H(8),'linewidth',1.2, 'color', 'k');
%set(H(9),'linewidth',1.2, 'color', 'b');

%set(J(1),'linewidth',1.5, 'color', 'r');
%set(J(2),'linewidth',1.5, 'color', 'b');
%set(J(3),'linewidth',1.5, 'color', 'k');
    
%legend(' \phi_A Cylinder', ' \phi_B Cylinder', ' \phi_H Cylinder', ...
    %' \phi_A Sphere', ' \phi_B Sphere', ' \phi_H Sphere', ...
    %' \phi_A Plane', ' \phi_B Plane', ' \phi_H Plane','Location','east')
legend(' \phi_A', ' \phi_B', ' \phi_H','Location','east');
legend('boxoff');

xlabel('  Radius (R/R_g)'), ylabel(' \fontsize{28} \phi')
set(gca,'fontsize',16)


axis([0 12 0 1.1])



