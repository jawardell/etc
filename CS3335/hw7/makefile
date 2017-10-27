gol: gol.o retone.o retzero.o
	gcc gol.o retone.o retzero.o -o gol
gol.o: gol.c retone.h retzero.h
	gcc -g -c gol.c -o gol.o
retone.o: retone.c retone.h
	gcc -g -c retone.c -o retone.o
retzero.o: retzero.c retzero.h
	gcc -g -c retzero.c -o retzero.o
