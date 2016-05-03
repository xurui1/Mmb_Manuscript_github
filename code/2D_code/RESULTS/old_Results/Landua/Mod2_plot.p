reset

path = "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/WORK/mu_find/RESULTS/Mod2_Results.dat"

unset key

f(x)=0.0


#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
f1(x) = a1*x + b1
fit [4.0 : 5.0] f1(x) path using  1:(($2-$3)/$4) via a1, b1
#++++++++++++++++++++++++++++++++++++

set xr [4.0 : 5.0]

plot path using 1:(($2-$3)/$4) w lp lc 1 pt 6,\
f1(x),\
f(x)



pause(-1)

