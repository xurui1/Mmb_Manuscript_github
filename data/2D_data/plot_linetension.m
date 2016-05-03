load 'linetension_AB.dat'
load 'linetension_ABA.dat'

fA = linetension_AB(:,1);
sigma_ABA = linetension_ABA(:,2);
sigma_AB = linetension_AB(:,2);

zero = sigma_AB-sigma_AB;

D = plot(fA, sigma_ABA,'r+-',fA,sigma_AB,'ks-');

legend(' ABA Pore','  AB Pore', 'location', 'east')
legend('boxoff');
xlabel('\it f_A');
ylabel('\fontsize{20} \sigma/\sigma_0');
set(gca,'Ytick',linspace(-0.1,0.3,5))
set(gca,'Xtick',linspace(0.3,0.7,5))


axis([0.28 0.72 -0.15 0.35])
set(gca,'Fontsize',16);

set(D(1),'linewidth',1.5,'markersize',9);
set(D(2),'linewidth',1.5,'markersize',9);
 
A = line([0.28 0.72], [0 0],'Color','k','linestyle',':');
% get handle of xlabel
h = get(gca,'xlabel');

% get current position of label
pos = get(h,'position');

% change position to be below x-axis by 8%
ylimits = get(gca,'ylim');
pos(2) = ylimits(1) - 0.08 * (ylimits(2) - ylimits(1));
set(h,'position',pos)
