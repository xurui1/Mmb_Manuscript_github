reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"



path= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/Tests/Fig3_Review_Paper/" #Landua

set ylabel 'F^D/R'  font ",32" offset 0,0
set xlabel 'R'  font ",32" offset 0,0

set xr [0.0 : 20.0]
set yr [0 : 16]
unset key
set pointsize 2.0
set lmargin 9
set bmargin 4


#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
f1(x) = a1*x + b1 
fit [0.0 : 30.0] f1(x) path."Mod1_Results.dat" using 1:(2*(($2-$3)/$4)*$5/$1) via a1, b1
#++++++++++++++++++++++++++++++++++++

plot f1(x) lc -1 lt 1 lw 2,\
 path."Mod1_Results.dat" using 1:(2*(($2-$3)/$4)*$5/$1) w lp lc -1 pt 6



pause(-1) #*******************************************************************************************************************

reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"


path= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/Tests/Fig3_Review_Paper/" #Landua


set ylabel 'F^D'  font ",32" offset 0,0
set xlabel 'R'  font ",32" offset 0,0

set xr [0.0 : 20.0]
set yr [0.0 : 300.0]
unset key
set pointsize 3.0
set lmargin 9.5
set bmargin 4


#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
c1 = 0.0

f1(x) = a1*x**2 + b1*x +c1
fit [0.0 : 30.0] f1(x) path."Mod1_Results.dat" using 1:(2*(($2-$3)/$4)*$5) via a1, b1, c1
#++++++++++++++++++++++++++++++++++++

plot f1(x) lc -1 lt 1 lw 4,\
 path."Mod1_Results.dat" using 1:(2*(($2-$3)/$4)*$5) w lp lc -1 pt 6
