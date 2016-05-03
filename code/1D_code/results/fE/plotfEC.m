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
AB_cyl = sqrt(2*pi)*fEC_AB_cylinder(:,2);

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


A = plot (ABx2,ABy2,'k', ABAx2, ABAy2,'r',ABx3,ABy3,'k', ABAx3, ABAy3,'r', Curvature,ABA_sph,'r+',Curvature, ABA_cyl,'rs',Curvature,AB_sph,'k+',Curvature,AB_cyl,'ks');
ylabel('F/\gamma_{int}');
xlabel('Curvature (C = d/r)');
axis([0 0.65 -0.001 0.03])
%set(gca, 'YTick', [0 0.01 0.02 0.03])
legend('AB','ABA','location','Northwest');
legend('boxoff');
set(gca,'fontsize',18)


%hold off;

