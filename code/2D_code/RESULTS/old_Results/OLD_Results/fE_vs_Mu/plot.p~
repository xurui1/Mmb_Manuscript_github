reset

#path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/"
path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/"

set autoscale
unset key

f(x)=0.0414

set pointsize 2

#set xr [0.0 : 20.0]
#set yr [0.0 : 40.0]

a=4.3
b=4.3**3 * 3.14 * 2.0


plot path."fE_vs_R_zero.dat" using 2:((($3/$5)-$4)*($6)) w lp lc 1 pt 6,\
 path."fE_vs_R_4p4.dat" using 2:((($3/$5)-$4)*($6)) w lp lc 3 pt 4,\
path."fE_vs_R.dat" using 2:((($3/$5)-$4)*($6)) w lp lc 4 pt 2



pause(-1)


#plot path."Bi_Por_Ten.dat" using ($2/a):(($7-$3)/(b)) w lp lc 1 pt 6
#path."Bi_Por_NoTen.dat" using ($2/a):(($7-$3)/(b)) w lp lc 3 pt 4
