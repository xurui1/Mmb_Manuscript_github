reset

#path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_Mu/"
path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/fE_vs_Mu/"


unset key

set pointsize 2

#set xr [0.0 : 20.0]
#set yr [0.0 : 40.0]

f(x)=0.0

plot f(x) w l lc -1,\
path."Mod2_Results_diblock_R.dat" using 1:(($2-$3)/$4) w lp lc 1 pt 6,\
path."Mod2_Results_diblock.dat" using 1:(($2-$3)/$4) w lp lc 3 pt 8


pause(-1)
