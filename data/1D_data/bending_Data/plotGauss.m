load ABsph25.dat;
load ABAsph25.dat;
load ABsph30.dat;
load ABAsph30.dat;
load ABsph35.dat;
load ABAsph35.dat;



fA = ABsph25(:,1);
AB_ktot25 = ABsph25(:,6);
ABA_ktot25 = ABAsph25(:,6);
AB_ktot30 = ABsph30(:,6);
ABA_ktot30 = ABAsph30(:,6);
AB_ktot35 = ABsph35(:,6);
ABA_ktot35 = ABAsph35(:,6);



AB_kg25 = AB_ktot25-2*ABkm25;
ABA_kg25 = ABA_ktot25-2*ABAkm25;
AB_kg30 = AB_ktot30-2*ABkm30;
ABA_kg30 = ABA_ktot30-2*ABAkm30;
AB_kg35 = AB_ktot35-2*ABkm35;
ABA_kg35 = ABA_ktot35-2*ABAkm35;

ABA_kg25_P = sqrt(6)*ABA_kg25*100/(sqrt(25)*4.3*4.3)*100;
AB_kg25_P = sqrt(6)*AB_kg25*100/(sqrt(25)*4.3*4.3)*100;
AB_kg30_P = sqrt(6)*AB_kg30*100/(sqrt(30)*4.3*4.3)*100;
ABA_kg30_P = sqrt(6)*ABA_kg30*100/(sqrt(30)*4.3*4.3)*100;
AB_kg35_P = sqrt(6)*AB_kg35*100/(sqrt(35)*4.3*4.3)*100;
ABA_kg35_P = sqrt(6)*ABA_kg35*100/(sqrt(35)*4.3*4.3)*100;

zero = ABA_kg25-ABA_kg25;


%A = plot (fA, ABA_kg, 'r*-', fA, ABA_kg30, 'r*-', fA, ABA_kg20, 'r+-');
%B = plot (fA,AB_kg, 'k*-',fA,AB_kg30, 'k*-',fA,AB_kg20, 'k+-' );
%C = plot (fA, ABA_kg25, 'r*-', fA, ABA_kg30, 'r+-', fA,AB_kg25, 'k*-',fA,AB_kg30,'k+-');
D = plot (fA, ABA_kg25_P, 'ro-', fA, ABA_kg30_P, 'rs-', fA, ABA_kg35_P, 'r^-', fA,AB_kg25_P, 'ko-',fA,AB_kg30_P,'ks-',fA,AB_kg35_P,'k^-');
set(D(1),'linewidth',1.2,'markersize',9);
set(D(2),'linewidth',1.2,'markersize',9);
set(D(3),'linewidth',1.2,'markersize',9);
set(D(4),'linewidth',1.2,'markersize',9);
set(D(5),'linewidth',1.2,'markersize',9);
set(D(6),'linewidth',1.2,'markersize',9);

legend(' ABA \chi{\itN} = 25', ' ABA \chi{\itN} = 30', ' ABA \chi{\itN} = 35','  AB  \chi{\itN} = 25', '  AB  \chi{\itN} = 30', '  AB  \chi{\itN} = 35','Location','southwest')
legend('boxoff');
numberOfXTicks = 5;
set(gca,'Xtick',linspace(fA(1),fA(end)+0.02,numberOfXTicks))
set(gca,'fontsize',16);
axis([0.27 0.71 -9 5])

%# horizontal zero line
hy = graph2d.constantline(0, 'Color',[.7 .7 .7]);
changedependvar(hy,'y');

xlabel('     \itf_A'), ylabel(' 10^2  \kappa_G / (\gamma_{int}d^2)')

% get handle of xlabel
h = get(gca,'xlabel');

% get current position of label
pos = get(h,'position');

% change position to be below x-axis by 8%
ylimits = get(gca,'ylim');
pos(2) = ylimits(1) - 0.08 * (ylimits(2) - ylimits(1));
set(h,'position',pos)

