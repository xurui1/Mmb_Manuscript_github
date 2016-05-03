reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/DATA/LineTension_vs_xAB/" #Mac

set ylabel '{/Symbol s}'  font ",32" offset 0,0
set xlabel '{/Symbol c}_{AB}'  font ",32" offset 0,-1

set xr [28 : 42]
set yr [0.08 : 0.16]

set key b r spacing 2 font ",22"
set pointsize 2.0
set lmargin 9
set bmargin 4


plot path."LineTension_vs_xAB.dat" using 1:2 title "AB Pore" w lp lc -1 lt 1 pt 6 lw 4,\
path."LineTension_vs_xAB.dat" using 1:3 title "ABA Pore" w lp lc 1 lt 2 pt 8 lw 4

