set datafile separator ','  
set xtics font "Times-Roman, 20"  
set ytics font "Times-Roman, 20"  
set key font "Times-Roman, 18"  
set xlabel "Time(s)" font "Times-Roman, 24"  
set ylabel "Sender CWND(max segment size)"  font "Times-Roman, 24"  
set key outside right center  
set terminal postscript eps enhanced color font 'Times-Roman, 20'  
set output "sawtooth_47327.eps"
set yrange [0:60]
set xrange [100:160]
set size 2, 1

set title "10.10.1.2:47327 by Joanne Wardell"  
plot 'tcpprobe_47327_comma.csv' using 1:7 title 'congestion window' with lines, 'tcpprobe_47327_comma.csv' using 1:8 title 'slow start threshold' with lines

#set ylabel "Percent (%)" font "Times-Roman, 24"  
#set yrange [0:110]
#set output "tcpprobe_47327_comma.eps"  
#set title "Buffer size for Policy 3"  
#plot 'tcpprobe_47327_comma.dat' using 1:5 title 'Buffer size' with lines
