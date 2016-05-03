reset

#set term postscript enhanced color
#set output "~/Desktop/fE.ps"

path1= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/SHARCNET/data.dat"


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


plot f1(x) w l lt 1 lc -1 lw 3,\
path1 using ($1):((($2-$3)/($4))*$5/$1) w p lc 1 pt 7

pause(-1)
