reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"

path1 = "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/line_tension_vs_fA/AB_sigma_vs_fA.dat"

set key at 0.4,-0.15 font ",24" spacing 2.5
set pointsize 2

set xlabel 'f_A'  font ",32" offset 0,-1
set ylabel '{/Symbol s}'  font ",32"

set xr [0.3 : 0.7]
set yr [-0.3 : 0.2]

#set ylabel 'F^D/R'  font ",22"
#set xlabel 'R'  font ",22"


plot path1 using 1:2 w lp title "AB" lc 1 pt 6 lt -1 lw 2,\
 path1 using 1:3 w lp title "ABA" lc 3 pt 8 lt -1 lw 2

