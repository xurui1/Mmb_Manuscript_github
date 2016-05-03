load ABcyl25.dat;
load ABAcyl25.dat;

load ABcyl30.dat;
load ABAcyl30.dat;
load ABcyl35.dat;
load ABAcyl35.dat;

fA = ABcyl25(:,1);
ABkm25 = ABcyl25(:,6);
ABAkm25 = ABAcyl25(:,6);
ABkm30 = ABcyl30(:,6);
ABAkm30 = ABAcyl30(:,6);
ABkm35 = ABcyl35(:,6);
ABAkm35 = ABAcyl35(:,6);

M1 = mean(ABAkm35)
M2 = mean(ABkm35)
diff = (M1-M2)/M2

ABAkm25 = 2*ABAkm25;
ABkm25 = 2*ABkm25;
ABkm30 = 2*ABkm30;
ABAkm30 = 2*ABAkm30;
ABkm35 = 2*ABkm35;
ABAkm35 = 2*ABAkm35;

ABAkm25_P = sqrt(2*pi)*ABAkm25*100/(sqrt(25)*4.3*4.3)*100;
ABkm25_P =sqrt(2*pi)* ABkm25*100/(sqrt(25)*4.3*4.3)*100;
ABkm30_P = sqrt(2*pi)*ABkm30*100/(sqrt(30)*4.3*4.3)*100;
ABAkm30_P = sqrt(2*pi)*ABAkm30*100/(sqrt(30)*4.3*4.3)*100;
ABkm35_P =sqrt(2*pi)*ABkm35*100/(sqrt(35)*4.3*4.3)*100;
ABAkm35_P =sqrt(2*pi)*ABAkm35*100/(sqrt(35)*4.3*4.3)*100;


%A = plot (fA,ABkm25, 'k*-',fA, ABAkm25, 'r*-',fA, ABkm30, 'k-',fA, ABAkm30, 'r-',fA, ABkm20, 'k+-',fA, ABAkm20, 'r+-');
%B = plot ( fA, ABkm30, 'k*-',fA, ABAkm30, 'r*-', fA, ABkm25, 'k+-',fA, ABAkm25, 'r+-', fA, ABkm35, 'k-',fA, ABAkm35, 'r-'  );
%C = plot ( fA, ABkm30, 'k*-',fA, ABAkm30, 'r*-', fA, ABkm35, 'k+-',fA, ABAkm35, 'r+-'  );
D = plot ( fA, ABAkm30_P, 'rs-', fA, ABAkm35_P, 'r^-' , fA, ABkm30_P, 'ks-', fA, ABkm35_P, 'k^-');
%D = plot ( fA, ABAkm30_P, 'y', fA, ABAkm35_P, 'r' , fA, ABkm30_P, 'b', fA, ABkm35_P, 'g');

set(D(1),'linewidth',1.2,'markersize',9);
set(D(2),'linewidth',1.2,'markersize',9);
set(D(3),'linewidth',1.2,'markersize',9);
set(D(4),'linewidth',1.2,'markersize',9);


legend('ABA \chi{\itN} = 30','ABA \chi{\itN} = 35', ' AB  \chi{\itN} = 30', ' AB  \chi{\itN} = 35','Location','south')
legend('boxoff');
numberOfXTicks = 5;
set(gca,'Xtick',linspace(fA(1),fA(end)+0.02,numberOfXTicks))

axis([0.27 0.71 3.5 7.5])

% get handle of xlabel
h = get(gca,'xlabel');

% get current position of label
pos = get(h,'position');

% change position to be below x-axis by 8%
ylimits = get(gca,'ylim');
pos(2) = ylimits(1) - 0.08 * (ylimits(2) - ylimits(1));
set(h,'position',pos)




xlabel('\fontsize{16}      \it{f_A}'), ylabel(' \fontsize{16} 10^2  \kappa_M / (\gamma_{int}d^2)')
%title('Mean Bending Moduli')
