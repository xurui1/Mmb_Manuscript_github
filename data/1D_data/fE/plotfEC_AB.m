clear all;

load 'fEC_AB_cylinder.dat';
load 'fEC_AB_sphere.dat';

Curvature = fEC_AB_cylinder(:,1);

%hold on;
AB_sph = sqrt(2*pi)*fEC_AB_sphere(:,2);
AB_cyl = sqrt(2*pi)*fEC_AB_cylinder(:,2);

sph_fit = polyfit(Curvature, AB_sph,2);
x2 = 0:0.01:0.68
y2 = polyval(sph_fit,x2);

cyl_fit = polyfit(Curvature, AB_cyl,2);
x3 = 0:0.01:0.68
y3 = polyval(cyl_fit,x3);

plot (x2,y2,x3,y3,Curvature,AB_sph,'k+',Curvature,AB_cyl,'ks');
ylabel('F/\gamma_{int}');
xlabel('Curvature (C = d/r)');
axis([0 0.65 -0.001 0.03])
%set(gca, 'YTick', [0 0.01 0.02 0.03])
legend('AB Sphere','AB Cylinder','location','Northwest');
legend('boxoff');
set(gca,'fontsize',18)


%hold off;
