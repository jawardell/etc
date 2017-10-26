#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "printboard.h"

int rowlim, collim, percent, i, j;

int main(int argc, char* argv[]) {	
	if(argc == 2) {
		rowlim = atoi(argv[0]);
		collim = atoi(argv[1]);
		percent = 10;
	} else if(argc == 3) {
		percent = atoi(argv[0]);
		rowlim  = atoi(argv[1]);
		collim = atoi(argv[2]);
	}

	int num_orgs = (percent * (rowlim * collim)) - (rowlim * collim);
	int num_blank = (rowlim * collim) - num_orgs; 	

	char board[rowlim][collim];
	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			board[i][j] = '*';
		}
	}

	srand(time(NULL));//use time as a random seed

	for(i = num_orgs; i >= 0; i--) {
		int randx = rand() % collim;
		int randy = rand() % rowlim;
		board[randx][randy] = 'x';
	}

	printboard(rowlim, collim);

	
	
	

}
