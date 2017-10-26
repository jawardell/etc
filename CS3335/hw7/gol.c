#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
#include <time.h>
int k;
int main(int argc, char* argv[]) {
	int collim;
	int rowlim; 
	double percent;
	if(argc == 4) { puts("\nmade it here\n");
		percent = (double)atoi(argv[1]); printf("\npercent is %f\n", percent); 
		rowlim = atoi(argv[2]); printf("\nrowlim is %f\n", rowlim);
		collim = atoi(argv[3]); printf("\ncollim is %f\n", collim);
	} else if(argc == 3) {
		rowlim = atoi(argv[1]);
		collim = atoi(argv[2]);
		percent = 10;
	} else {
		puts("\noops, you did not enter commands correctly...\n");
		puts("\nusage: ./gameoflife percent_organisms rows columns\n");
		puts("\nor usage: ./gameoflife rows columns\tpercent defaults to 10 percent life\n");
		return 1;
	}
	double num_orgs = ((percent * .01) * (collim * rowlim));
	double num_blank = (collim * rowlim) - num_orgs;

	printf("\nnumber of orgs %f\n", num_orgs);

	int i, j;

	char board[rowlim][collim];

	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			board[i][j] = '*';
		}
	}

	srand(time(NULL));

	for(i = (int)num_orgs; i >= 0; i--) {
		int randx = rand() % rowlim;
		printf("\nrandx is %d\n", randx);
		int randy = rand() % collim;
		printf("\nrandy is %d\n", randy);
		if (board[randx][randy] == 'x') {
			i++;
			continue;
		} else {
			board[randx][randy] = 'x';
		}

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


	double hoodcount[rowlim][collim];
	for(i = 0; i < rowlim; i++) {
		for(j=  0; j < collim; j++) {
			hoodcount[i][j] = 0;
		}
	}	


	int hood[7];
	for(i = 0; i < 8; i++) {
		hood[i] = 0;
	}

	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			if(board[i][j] == 'x') {
				int fulfilled = 0;
				//if its a corner, do special corner wrapping
				//cor0  -- upper left corner
				if((i == 0) && (j == 0)) {
					hood[0] = (board[rowlim-1][collim-1] == 'x') ? 1 : 0;
					hood[1] = (board[rowlim-1][0] == 'x') ? 1 : 0;
					hood[2] = (board[rowlim - 1][1] == 'x') ? 1 : 0;
					hood[3] = (board[i][collim - 1] == 'x') ? 1 : 0;
					hood[4] = (board[i][j + 1] == 'x') ? 1 : 0;
					hood[5] = (board[i + 1][collim - 1] == 'x') ? 1 : 0;
					hood[6] = (board[i + 1][j] == 'x') ? 1 : 0;
					hood[7] = (board[i + 1][j + 1] == 'x') ? 1 : 0;
					fulfilled = 1;
				}
				//cor1 -- upper right corner
				if((i == 0) && (j == (collim - 1))) {
					hood[0] = (board[rowlim -1][j - 1] == 'x') ? 1 : 0;
					hood[1] = (board[rowlim - 1][j] == 'x') ? 1 : 0;
					hood[2] = (board[rowlim - 1][0] == 'x') ? 1 : 0;
					hood[3] = (board[i][j - 1] == 'x') ? 1 : 0;
					hood[4] = (board[0][0] == 'x') ? 1 : 0;
					hood[5] = (board[i + 1][j - 1] == 'x') ? 1 : 0;
					hood[6] = (board[i + 1][j] == 'x') ? 1 : 0;
					hood[7] = (board[i + 1][0] == 'x') ? 1 : 0;
					fulfilled = 1;
				}
				//cor 2 -- lower left corner
				if((i == (rowlim - 1)) && (j == 0)) {
					hood[0] = (board[i - 1][collim - 1] == 'x') ? 1 : 0;
					hood[1] = (board[i - 1][j] == 'x') ? 1 : 0;
					hood[2] = (board[i - 1][j + 1] == 'x') ? 1 : 0;
					hood[3] = (board[i][collim - 1] == 'x') ? 1 : 0;
					hood[4] = (board[i][j + 1] == 'x') ? 1 : 0;
					hood[5] = (board[0][collim - 1] == 'x') ? 1 : 0;
					hood[6] = (board[0][0] == 'x') ? 1 : 0;
					hood[7] = (board[0][col + 1] == 'x') ? 1 : 0;
					fulfilled = 1;
				}
				//cor3 -- lower right corner
				if((i == (rowlim - 1)) && (j == (collim - 1))) {
					hood [0] = (board[i - 1][j - 1] == 'x') ? 1 : 0;
					hood [1] = (board[i + 1][j] == 'x') ? 1 : 0;
					hood [2] = (board[i - 1][0] == 'x') ? 1 : 0;
					hood [3] = (board[i][j - 1] == 'x') ? 1 : 0;
					hood [4] = (board[i][0] == 'x') ? 1 : 0;
					hood [5] = (board[0][j - 1] == 'x') ? 1 : 0;
					hood [6] = (board[0][j] == 'x') ? 1 : 0;
					hood [7] = (board[0][0] == 'x') ? 1 : 0;
					fulfilled = 1;
				}
				//if it just needs normal wrapping adjustments
				//column wrapping on left side
				if((j == 0) && (fulfilled == 0)) {
					hood[0] = (board[i - 1][rowlim - 1] == 'x') ? 1 : 0;
					hood[3] = (board[i][rowlim - 1] == 'x') ? 1 : 0;
					hood[5] = (board[i + 1][rowlim - 1]) ? 1 : 0;
					fulfilled = 1;
				}
				//column wrapping on right side
				if((j == collim - 1) && (fulfilled == 0)) {
					hood[2] = (board[i - 1][0] == 'x') ? 1 : 0;
					hood[4] = (board[i][0] == 'x') ? 1 : 0;
					hood[7] = (board[i + 1][0] == 'x') ? 1 : 0;
					fulfilled = 1;
				}
				//row wrapping at bottom
				if((i == rowlim - 1) && (fulfilled == 0)) {
					hood[5] = (board[0][j - 1] == 'x') ? 1 : 0;
					hood[6] = (board[0][j] == 'x') ? 1 : 0;
					hood[7] = (board[0][j + 1] == 'x') ? 1 : 0;
					fulfilled = 1;
				}
				//row wrapping at top
				if((i == 0) && (fulfilled == 0)) {
					hood[0] = (board[rowlim - 1][j - 1] == 'x') ? 1 : 0;
					hood[1] = (board[rowlim - 1][j] == 'x') ? 1 : 0;
					hood[2] = (board[rowlim - 1][j + 1] == 'x') ? 1 : 0;
					fulfilled = 1;
				}
				//if no wrapping is needed, check neighbor positions normally
				if(fulfilled == 0) {
					hood[0] = (board[i - 1][j - 1] == 'x') ? 1 : 0;
					hood[1] = (board[i - 1][j] == 'x') ? 1 : 0;
					hood[2] = (board[i - 1][j + 1] == 'x') ? 1 : 0;
					hood[3] = (board[i][j - 1] == 'x') ? 1 : 0;
					hood[4] = (board[i][j + 1] == 'x') ? 1 : 0;
					hood[5] = (board[i + 1][j - 1] == 'x') ? 1 : 0;
					hood[6] = (board[i + 1][j] == 'x') ? 1 : 0;
					hood[7] = (board[i + 1][j + 1] == 'x') ? 1 : 0;
				}	
			}

			int count = 0;
			//sum up neigbors array
			for(k = 0; k < 8; k++) {
				if(hood[k] == 1) {
					count++;
				}
			}

			//place neighbors count in hoodcount array
			hoodcount[i][j] = count;
		}
	}

	puts("\nprinting hoodcount array. . . .\n");
	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			if(j == (collim - 1)) {
				printf("%2c\n", board[i][j]);
			} else {
				printf("%2c ", board[i][j]);
			}
		}
	}
	

	//look at hoodcount array to redraw board
	for(i = 0; i < rowlim; i ++) {
		for(j = 0; j < collim; j++) {
			//overcrowding
			if(hoodcount[i][j] > 3) {
				board[i][j] = ' ';
			}
			//reproduction
			if(hoodcount[i][j] == 3) {
				board[i][j] = 'x';
			}
			//survival
			if((hoodcount[i][j] == 2) && (board[i][j] == 'x')) {
				continue;
			}
		}

	}

	//flush the console output
}
