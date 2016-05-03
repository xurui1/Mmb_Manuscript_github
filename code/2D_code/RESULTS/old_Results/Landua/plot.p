reset

path = "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/WORK/main1/PHI/"

set autoscale
set key r c


plot   path."phi_r.dat" using 1:2 title "A" w lp,\
path."phi_r.dat" using 1:3 title "B" w lp,\
path."phi_r.dat" using 1:4 title "C" w lp,\
path."phi_r.dat" using 1:5 title "D" w lp,\
path."phi_r.dat" using 1:6 title "E" w lp,\
path."phi_r.dat" using 1:7 title "F" w lp


pause(-1)


reset

path = "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/WORK/main1/PHI/"

set autoscale
set key r c


plot   path."phi_z.dat" using 1:2 title "A" w lp,\
path."phi_z.dat" using 1:3 title "B" w lp,\
path."phi_z.dat" using 1:4 title "C" w lp,\
path."phi_z.dat" using 1:5 title "D" w lp,\
path."phi_z.dat" using 1:6 title "E" w lp,\
path."phi_z.dat" using 1:7 title "F" w lp
