runstate: algo.o timer.o
	g++ algo.o timer.o -o runstate

statemain.o: algo.cpp timer.h
	g++ -c -std=c++11 algo.cpp  -o algo.o

state.o:  timer.cpp timer.h
	g++ -c timer.cpp timer.h  -o timer.o timer.h

clean:
	rm *.o runstate

