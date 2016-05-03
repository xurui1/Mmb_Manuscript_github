reset

#set term postscript enhanced color
#set output "~/Desktop/fE.ps"

path1= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/SHARCNET/fA_Line_Tension.dat"

plot path1 using 1:2 w lp


pause(-1)
