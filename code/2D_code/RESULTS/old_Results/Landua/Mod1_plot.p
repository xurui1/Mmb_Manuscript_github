reset

path_1 = "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/WORK/main1/RESULTS/"
path_2 = "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/WORK/main2/RESULTS/"
path_3 = "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/WORK/main3/RESULTS/"
path_4 = "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/WORK/main4/RESULTS/"
path_5 = "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/WORK/main5/RESULTS/"



set xr [0.0 : 30.0]
#set yr [-16 : 16]
unset key

#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
f1(x) = a1*x + b1 
fit [0.0 : 30.0] f1(x) path_2."Mod1_Results.dat" using 1:((($2-$3)/$4)*$5/$1) via a1, b1
#++++++++++++++++++++++++++++++++++++

plot path_1."Mod1_Results.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 1 pt 6,\
  path_2."Mod1_Results.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 2 pt 6,\
  path_3."Mod1_Results.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 3 pt 6,\
  path_4."Mod1_Results.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 4 pt 6,\
  path_5."Mod1_Results.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 5 pt 6,\
  f1(x)


pause(-1)

