load ABcyl25.dat;
load ABAcyl25.dat;
load ABcyl30.dat;
load ABAcyl30.dat;
load ABcyl35.dat;
load ABAcyl35.dat;

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

ABkm25 = 2*ABcyl25(:,6);
ABAkm25 = 2*ABAcyl25(:,6);
ABkm30 = 2*ABcyl30(:,6);
ABAkm30 = 2*ABAcyl30(:,6);
ABkm35 = 2*ABcyl35(:,6);
ABAkm35 = 2*ABAcyl35(:,6);

AB_kg25 = AB_ktot25-2*ABkm25;
ABA_kg25 = ABA_ktot25-2*ABAkm25;
AB_kg30 = AB_ktot30-2*ABkm30;
ABA_kg30 = ABA_ktot30-2*ABAkm30;
AB_kg35 = AB_ktot35-2*ABkm35;
ABA_kg35 = ABA_ktot35-2*ABAkm35;

ABAkgkm30 = ABA_kg30./ABAkm30;
ABAkgkm35 =ABA_kg35./ABAkm35;

ABkgkm30 = AB_kg30./ABkm30;
ABkgkm35 =AB_kg35./ABkm35;


D = plot (fA, ABAkgkm30, 'rs-', fA ,ABAkgkm35, 'r^-' , fA, ABkgkm30, 'ks-', fA,ABkgkm35, 'k^-');
%D = plot (fA, ABAkgkm30, fA ,ABAkgkm35 , fA, ABkgkm30, fA,ABkgkm35);

set(D(1),'linewidth',1.2,'markersize',9);
set(D(2),'linewidth',1.2,'markersize',9);
set(D(3),'linewidth',1.2,'markersize',9);
set(D(4),'linewidth',1.2,'markersize',9);
set(gca,'fontsize',16);

legend(' ABA \chi{\itN} = 30',' ABA \chi{\itN} = 35', '  AB  \chi{\itN} = 30', '  AB  \chi{\itN} = 35','Location','southwest')
legend('boxoff');

xlabel('    \itf_A');
ylabel('        \kappa_G/\kappa_M');

axis([0.27 0.71 -1.5 1])
numberOfXTicks = 5;
set(gca,'Xtick',linspace(fA(1),fA(end)+0.02,numberOfXTicks))

hy = graph2d.constantline(0, 'Color',[.7 .7 .7]);
changedependvar(hy,'y');

% get handle of xlabel
h = get(gca,'xlabel');

% get current position of label
pos = get(h,'position');

% change position to be below x-axis by 8%
ylimits = get(gca,'ylim');
pos(2) = ylimits(1) - 0.08 * (ylimits(2) - ylimits(1));
set(h,'position',pos)






