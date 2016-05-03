reset

path = "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/WORK/PLOTS/"

set autoscale
set key r c


f(x)=0.0

plot   path."f_0p5.dat" using 1:2 title "A" w lp,\
f(x)

pause(-1)

