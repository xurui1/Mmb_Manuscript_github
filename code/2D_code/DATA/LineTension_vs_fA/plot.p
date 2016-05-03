reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/DATA/LineTension_vs_fA/" #Mac

set ylabel '{/Symbol s}'  font ",32" offset 0,0
set xlabel 'f_A'  font ",32" offset 0,-1

set xr [0.3 : 0.7]
set yr [-0.10 : 0.31]

set key t r spacing 2 font ",22"
set pointsize 2.0
set lmargin 9
set bmargin 4

f(x) = 0.0

plot f(x) notitle " " w l lc -1,\
path."LineTension_vs_fA.dat" using 1:4 title "AB Pore" w lp lc -1 lt 1 pt 6 lw 4,\
path."LineTension_vs_fA.dat" using 1:5 title "ABA Pore" w lp lc 1 lt 2 pt 8 lw 4

