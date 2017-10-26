game: game.o printboard.o
	gcc game.o printboard.o -o game
game.o: game.c printboard.h
	gcc -g -c game.c -o game.o
printboard.o: printboard.c printboard.h
	gcc -g -c printboard.c -o printboard.o

