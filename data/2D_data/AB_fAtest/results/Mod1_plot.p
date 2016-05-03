reset

path= "/Users/ruixu/Documents/Thesis/SCFT_2D/AB_fAtest/results/" # Elmspace


set xr [0.0 : 20.0]
#set yr [0 : 2]
unset key

#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
f1(x) = a1*x + b1 
fit [0.0 : 30.0] f1(x) path."fA35.dat" using ($1/4.3):(2.0*($2-$3)/(2.0*3.14*4.3**3)) via a1, b1
#++++++++++++++++++++++++++++++++++++



plot path."fA35.dat" using ($1/4.3):(2.0*($2-$3)/(2.0*3.14*4.3**3)) w lp lc 1 pt 6,\
f1(x)


#pause(-1)

