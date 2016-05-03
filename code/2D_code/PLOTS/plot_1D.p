reset

path= "/Users/ruixu/Documents/Thesis/SCFT_2D/2D_Master/2D_Master/2D_Master/PHI/"
#path= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/PHI/" #Landua
#path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/PHI/" # Elmspace


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

#path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/PHI/"   # Mac
path= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/PHI/"  #Landua
#path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/PHI/" #Elmspace


set autoscale
set key r c


plot   path."phi_z.dat" using 1:2 title "A" w lp,\
path."phi_z.dat" using 1:3 title "B" w lp,\
path."phi_z.dat" using 1:4 title "C" w lp,\
path."phi_z.dat" using 1:5 title "D" w lp,\
path."phi_z.dat" using 1:6 title "E" w lp,\
path."phi_z.dat" using 1:7 title "F" w lp
