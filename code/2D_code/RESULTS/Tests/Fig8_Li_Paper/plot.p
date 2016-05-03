reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"



path= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/Tests/Fig8_Li_Paper/" #Landua

set ylabel '{/Symbol s}'  font ",32" offset 0,0
set xlabel 'f_A'  font ",32" offset -1.5,-0.1

set xr [0.3 : 0.7]
set yr [-0.1 : 0.35]

unset key
set pointsize 2.0
set lmargin 9
set bmargin 4

f(x)=0.0

plot f(x) lc 0,\
path."LineTension_vs_fA.dat" using 1:2 w lp lc -1 pt 6 lw 3

