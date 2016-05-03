reset

#set term postscript enhanced color
#set output "~/Desktop/fE.ps"

path1= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/SHARCNET/fA_Mu_c.dat"


set fit logfile '/dev/null'

unset key
set pointsize 2

set xr [0.2 : 0.8]
#set yr [0.0 : 100.0]

#set ylabel 'F^D/R'  font ",32"
#set xlabel 'R'  font ",32"


#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
f1(x) = a1*x + b1
fit [0.2 : 0.8] f1(x) path1 using  1:2 via a1, b1
#++++++++++++++++++++++++++++++++++++

g(x)=0.0

plot f1(x) w l lt 1 lc -1 lw 3,\
path1 using 1:2 w p lc 1 pt 7,\
g(x)

pause(-1)
