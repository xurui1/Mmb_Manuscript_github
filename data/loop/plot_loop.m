clear all;

load 'loopr3.dat';
load 'loopr4.dat';
load 'loopr5.dat';
load 'loopr6.dat';
load 'loopr7.dat';

curv = loopr3(:,1);
I_30 = loopr3(:,2);
O_30 = loopr3(:,3);

I_40 = loopr4(:,2);
O_40 = loopr4(:,3);

I_50 = loopr5(:,2);
O_50 = loopr5(:,3);

I_60 = loopr6(:,2);
O_60 = loopr6(:,3);

I_70 = loopr7(:,2);
O_70 = loopr7(:,3);
hold on;
I3 = plot (curv,I_30,'r--','linewidth',1.2);
O3 = plot (curv,O_30,'r','linewidth',1.2);
I4 = plot (curv,I_40,'b--','linewidth',1.2);
O4 = plot (curv,O_40,'b','linewidth',1.2);
I5 = plot (curv,I_50,'k--','linewidth',1.2);
O5 = plot (curv,O_50,'k','linewidth',1.2);
I6 = plot (curv,I_60,'g--','linewidth',1.2);
O6 = plot (curv,O_60,'g','linewidth',1.2);
I7 = plot (curv,I_70,'c--','linewidth',1.2);
O7 = plot (curv,O_70,'c','linewidth',1.2);
hold off;

legend([O3,O4,O5,O6,O7],' {\itf_A} = 0.3',' {\itf_A} = 0.4', ' {\itf_A} = 0.5', ' {\itf_A} = 0.6',' {\itf_A} = 0.7','Location','east')
legend('boxoff');
box on;

ylabel(' Looping fraction (\nu_L)');
xlabel(' Curvature (C = d/r)');

axis([0.0 0.65 0 0.6])

set(gca,'Fontsize',16);


% get handle of xlabel
h = get(gca,'xlabel');

% get current position of label
pos = get(h,'position');

% change position to be below x-axis by 8%
ylimits = get(gca,'ylim');
pos(2) = ylimits(1) - 0.08 * (ylimits(2) - ylimits(1));
set(h,'position',pos)

