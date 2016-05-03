reset

set fit logfile '/dev/null'

ABA_path1= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R/ABA/ABA_mu_4p6.dat"
ABA_path2= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R/ABA/ABA_mu_4p7.dat"
ABA_path3= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R/ABA/ABA_mu_4p8.dat"

set term postscript enhanced color
set output "~/Desktop/fE.ps"

set xlabel 'R'  font ",32" offset 0,-1
set ylabel 'F^D/R'  font ",32"

set key at 10.0,1.25 font ",24" spacing 2.5
set pointsize 2
set xr [0.0 : 30.0]
#set yr [0.0 : 40.0]


# ABA Triblock
ABA_g1(x)=(0.0424661)*x + (-0.0325798)
ABA_g2(x)=(0.0114229)*x + (0.0874332)
ABA_g3(x)=(-0.0197615)*x + (0.208679)


plot ABA_g1(x) w l notitle lc -1 lt 1 lw 3,\
ABA_g2(x) w l notitle lc -1 lt 1 lw 3,\
ABA_g3(x) w l notitle lc -1 lt 1 lw 3,\
ABA_path1 using 1:((($2-$3)/($4))*$5/$1) w p title "{/Symbol m}=4.6" lc 1 pt 5,\
ABA_path2 using 1:((($2-$3)/($4))*$5/$1) w p title "{/Symbol m}=4.7" lc 3 pt 7,\
ABA_path3 using 1:((($2-$3)/($4))*$5/$1) w p title "{/Symbol m}=4.8" lc 2 pt 9


pause(-1)


reset

set fit logfile '/dev/null'

AB_path1= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R/AB/AB_mu_4p45.dat"
AB_path2= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R/AB/AB_mu_4p5.dat"
AB_path3= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_R/AB/AB_mu_4p55.dat"

set term postscript enhanced color
set output "~/Desktop/fE.ps"

set xlabel 'R'  font ",32" offset 0,-1
set ylabel 'F^D/R'  font ",32"

set key at 10.0,-0.1 font ",24" spacing 2.5
set pointsize 2
set xr [0.0 : 30.0]
#set yr [0.0 : 40.0]

# AB Diblock
AB_g1(x)=(0.0118126)*x + (0.0727751)
AB_g2(x)=(-0.00382464)*x + (0.133215)
AB_g3(x)=(-0.0194872)*x + (0.193737)

plot AB_g1(x) w l notitle lt 1 lc -1 lw 3,\
AB_g2(x) w l notitle lt 1 lc -1 lw 3,\
AB_g3(x) w l notitle lt 1 lc -1 lw 3,\
AB_path1 using 1:((($2-$3)/($4))*$5/$1) w p title "{/Symbol m}=4.45" lc 1 pt 5,\
AB_path2 using 1:((($2-$3)/($4))*$5/$1) w p title "{/Symbol m}=4.50" lc 3 pt 7,\
AB_path3 using 1:((($2-$3)/($4))*$5/$1) w p title "{/Symbol m}=4.55" lc 2 pt 9

pause(-1)



