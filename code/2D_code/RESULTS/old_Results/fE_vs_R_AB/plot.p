reset

#set term postscript enhanced color
#set output "~/Desktop/fE.ps"

path1= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R_AB/Mod1_Results_1.dat"
path2= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R_AB/Mod1_Results_2.dat"
path3= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R_AB/Mod1_Results_3.dat"
path4= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R_AB/Mod1_Results_4.dat"


set fit logfile '/dev/null'

unset key
set pointsize 2

set xr [0.0 : 30.0]
#set yr [0.0 : 100.0]

#set ylabel 'F^D/R'  font ",32"
#set xlabel 'R'  font ",32"


#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
f1(x) = a1*x + b1
fit [0.0 : 30.0] f1(x) path1 using  ($1):((($2-$3)/($4))*$5/$1) via a1, b1
#++++++++++++++++++++++++++++++++++++

#++++++++++++++++++++++++++++++++++++ f2
a2 = 0.0
b2 = 0.0
f2(x) = a2*x + b2
fit [0.0 : 30.0] f2(x) path2 using  ($1):((($2-$3)/($4))*$5/$1) via a2, b2
#++++++++++++++++++++++++++++++++++++

#++++++++++++++++++++++++++++++++++++ f3
a3 = 0.0
b3 = 0.0
f3(x) = a3*x + b3
fit [0.0 : 30.0] f3(x) path3 using  ($1):((($2-$3)/($4))*$5/$1) via a3, b3
#++++++++++++++++++++++++++++++++++++

#++++++++++++++++++++++++++++++++++++ f4
a4 = 0.0
b4 = 0.0
f4(x) = a4*x + b4
fit [0.0 : 30.0] f4(x) path4 using  ($1):((($2-$3)/($4))*$5/$1) via a4, b4
#++++++++++++++++++++++++++++++++++++

plot f1(x) w l lt 1 lc -1 lw 3,\
f2(x) w l lt 1 lc -1 lw 3,\
f3(x) w l lt 1 lc -1 lw 3,\
f4(x) w l lt 1 lc -1 lw 3,\
path1 using ($1):((($2-$3)/($4))*$5/$1) w p lc 1 pt 7,\
path2 using ($1):((($2-$3)/($4))*$5/$1) w p lc 2 pt 7,\
path3 using ($1):((($2-$3)/($4))*$5/$1) w p lc 3 pt 7,\
path4 using ($1):((($2-$3)/($4))*$5/$1) w p lc 4 pt 7


pause(-1)

reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R_AB/Surf_Ten_vs_Mu.dat"

f(x)=0.0

plot f(x),\
path using 1:2 w lp lc 1 pt 7
