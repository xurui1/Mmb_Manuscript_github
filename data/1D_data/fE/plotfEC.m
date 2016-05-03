clear all;

load 'fEC_AB_cylinder.dat';
load 'fEC_ABA_cylinder.dat';
load 'fEC_AB_sphere.dat';
load 'fEC_ABA_sphere.dat';

Curvature = fEC_AB_cylinder(:,1);

%hold on;
ABA_sph = sqrt(2*pi)*fEC_ABA_sphere(:,2);
AB_sph = sqrt(2*pi)*fEC_AB_sphere(:,2);
ABA_cyl = sqrt(2*pi)*fEC_ABA_cylinder(:,2);
AB_cyl  = sqrt(2*pi)*fEC_AB_cylinder(:,2);

ABsph_fit = polyfit(Curvature, AB_sph,2);
ABx2 = 0:0.001:0.68;
ABy2 = polyval(ABsph_fit,ABx2);

ABAsph_fit = polyfit(Curvature, ABA_sph,2);
ABAx2 = 0:0.001:0.68;
ABAy2 = polyval(ABAsph_fit,ABAx2);

ABcyl_fit = polyfit(Curvature, AB_cyl,2);
ABx3 = 0:0.001:0.68;
ABy3 = polyval(ABcyl_fit,ABx3);

ABAcyl_fit = polyfit(Curvature, ABA_cyl,2);
ABAx3 = 0:0.001:0.68;
ABAy3 = polyval(ABAcyl_fit,ABAx3);

%activate to use polynomial fitting
%A = plot (ABx2,ABy2,'k', ABAx2, ABAy2,'r',ABx3,ABy3,'k', ABAx3, ABAy3,'r', Curvature,ABA_sph,'r+',Curvature, ABA_cyl,'rs',Curvature,AB_sph,'k+',Curvature,AB_cyl,'ks');
A = plot( Curvature, ABA_sph ,'rs-' , Curvature , ABA_cyl,'r+-',Curvature,AB_sph,'ks-',Curvature,AB_cyl ,'k+-');
set(A(1),'linewidth',1.2,'markersize',8);
set(A(2),'linewidth',1.2,'markersize',8);
set(A(3),'linewidth',1.2,'markersize',8);
set(A(4),'linewidth',1.2,'markersize',8);

ylabel('F/\gamma_{int}');
xlabel('Curvature (C = d/r)');
axis([-0.02 0.67 -0.002 0.031])
set(gca, 'YTick', [0 0.01 0.02 0.03])
legend(' ABA Sphere',' ABA Cylinder','  AB Sphere','  AB Cylinder','location','Northwest');
legend('boxoff');
set(gca,'fontsize',16)

% get handle of xlabel
h = get(gca,'xlabel');

% get current position of label
pos = get(h,'position');

% change position to be below x-axis by 8%
ylimits = get(gca,'ylim');
pos(2) = ylimits(1) - 0.08 * (ylimits(2) - ylimits(1));
set(h,'position',pos)



%hold off;

