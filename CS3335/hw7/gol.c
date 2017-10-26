#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
#include <time.h>

int main(int argc, char* argv[]) {
	double collim;
	double rowlim; 
	double percent;
	if(argc == 4) { puts("\nmade it here\n");
		percent = (double)atoi(argv[1]); printf("\npercent is %f\n", percent); 
		rowlim = (double)atoi(argv[2]); printf("\nrowlim is %f\n", rowlim);
		collim = (double)atoi(argv[3]); printf("\ncollim is %f\n", collim);
	} else if(argc == 3) {
		rowlim = (double)atoi(argv[1]);
		collim = (double)atoi(argv[2]);
		percent = 10;
	} else {
		puts("\noops, you did not enter commands correctly...\n");
		puts("\nusage: ./gameoflife percent_organisms rows columns\n");
		puts("\nor usage: ./gameoflife rows columns\tpercent defaults to 10 percent life\n");
		return 1;
	}
	double num_orgs = ((percent * .01) * (collim * rowlim));
	double num_blank = (collim * rowlim) - num_orgs;

	printf("\nnumber of orgs %d\n", (int)num_orgs);
	
	int i, j;

	char board[(int)rowlim][(int)collim];
	
	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			board[i][j] = '*';
		}
	}
	
	srand(time(NULL));

	for(i = (int)num_orgs; i >= 0; i--) {
		int randx = rand() % (int)rowlim;
		printf("\nrandx is %d\n", randx);
		int randy = rand() % (int)collim;
		printf("\nrandy is %d\n", randy);
		board[(int)randx][(int)randy] = 'x';
	}

	
	for(i = 0; i < (int)rowlim; i++) {
		for(j = 0; j < (int)collim; j++) {
			if(j == ((int)rowlim - 1)) {
				printf("%c\n", board[i][j]);
			} else {
				printf("%c", board[i][j]);
			}
		}
	}


}
