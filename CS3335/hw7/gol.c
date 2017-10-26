#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
#include <time.h>

int main(int argc, char* argv[]) {
	int collim;
	int rowlim; 
	int percent;
	if(argc == 3) { puts("\nmade it here\n");
		percent = atoi(argv[0]); puts("\nmade it here\n");
		rowlim = atoi(argv[1]); puts("\nmade it here\n");
		collim = atoi(argv[2]);
	} else if(argc == 2) {
		rowlim = atoi(argv[0]);
		collim = atoi(argv[1]);
	}
	int num_orgs = ((percent * .01) * (collim * rowlim));
	int num_blank = (collim * rowlim) - num_orgs;

	int i, j;

	char board[rowlim][collim];
	
	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			board[i][j] = '*';
		}
	}
	
	srand(time(NULL));

	for(i = num_orgs; i <= 0; i--) {
		int randx = rand() % rowlim;
		int randy = rand() % collim;
		board[randx][randy] = 'x';
	}


	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			if(j == (rowlim - 1)) {
				printf("%c\n", board[i][j]);
			} else {
				printf("%c", board[i][j]);
			}
		}
	}


}
