#include "retone.h"
#include "retzero.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
#include <time.h>
int k;
int main(int argc, char* argv[]) {
	puts("\n\thello! thank you for using game of life\n");
	puts("\n\tplease use ctrl c  to quit.\n");
	puts("\n\tyour game will begin shortly\n");
	puts("\n\tthank you!\n");

	usleep(7000000);

	int collim;
	int rowlim; 
	double percent;

	//grab those args!
	if(argc == 4) { //percent specified
		percent = (double)atoi(argv[1]);
		rowlim = atoi(argv[2]);
		collim = atoi(argv[3]);

	} else if(argc == 3) {//percent set to default
		rowlim = atoi(argv[1]);
		collim = atoi(argv[2]);
		percent = 10;

	} else {//useage not satisfied
		puts("\noops, you did not enter commands correctly...\n");
		puts("\nusage: ./gameoflife percent_organisms rows columns\n");
		puts("\nor usage: ./gameoflife rows columns\tpercent defaults to 10 percent life\n");
		return 1;
	}

	//initialize a few variables here, make percentage calculations
	double num_orgs = ((percent * .01) * (collim * rowlim));
	double num_blank = (collim * rowlim) - num_orgs;
	int i, j;
	char board[rowlim][collim];


	//initialize the board to spaces
	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			board[i][j] = ' ';
		}
	}


	//use time as a random seed
	srand(time(NULL));


	//randomly place x's on board 
	//while observing the percentage of life requested
	for(i = (int)num_orgs; i >= 0; i--) {
		int randx = rand() % rowlim;
		int randy = rand() % collim;
		if (board[randx][randy] == 'x') {
			//x has already been placed here
			//so trick the for loop and continue on
			i++;
			continue;
		} else {
			board[randx][randy] = 'x';
		}

	}



	//do first board print
	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			if(j == (rowlim - 1)) {
				printf("%c\n", board[i][j]);
			} else {
				printf("%c", board[i][j]);
			}
		}
	}



	//make array to hold values of neighbors of each grid space
	double hoodcount[rowlim][collim];
	for(i = 0; i < rowlim; i++) {   //initialize that array to zeros
		for(j=  0; j < collim; j++) {
			hoodcount[i][j] = 0;
		}
	}	
	int hood[8]; //make linear array to hold number of neighbors count
	for(i = 0; i < 8; i++) {//initialize that array to zeros
		hood[i] = 0;
	}
	//for each grid space, observe all eight of its neighbor positions
	//check each position to see if there is an x there
	//if so, mark that position in the hood linear array
	//also do corner and edge wrapping on the board

	//get ready to loooop!
	while(!feof(stdin)) { //keep doing this until we reiceve EOF signal from stdin
		for(i = 0; i < rowlim; i++) {
			for(j = 0; j < collim; j++) {

				int fulfilled = 0;
				//if its a corner, do special corner wrapping
				//cor0  -- upper left corner
				if((i == 0) && (j == 0)) {
					hood[0] = (board[rowlim-1][collim-1] == 'x') ? retone() : retzero();
					hood[1] = (board[rowlim-1][0] == 'x') ? retone() : retzero();
					hood[2] = (board[rowlim - 1][1] == 'x') ? retone() : retzero();
					hood[3] = (board[i][collim - 1] == 'x') ? retone() : retzero();
					hood[4] = (board[i][j + 1] == 'x') ? retone() : retzero();
					hood[5] = (board[i + 1][collim - 1] == 'x') ? retone() : retzero();
					hood[6] = (board[i + 1][j] == 'x') ? retone() : retzero();
					hood[7] = (board[i + 1][j + 1] == 'x') ? retone() : retzero();
					fulfilled = 1;
				}
				//cor1 -- upper right corner
				if((i == 0) && (j == (collim - 1))) {
					hood[0] = (board[rowlim -1][j - 1] == 'x') ? retone() : retzero();
					hood[1] = (board[rowlim - 1][j] == 'x') ? retone() : retzero();
					hood[2] = (board[rowlim - 1][0] == 'x') ? retone() : retzero();
					hood[3] = (board[i][j - 1] == 'x') ? retone() : retzero();
					hood[4] = (board[0][0] == 'x') ? retone() : retzero();
					hood[5] = (board[i + 1][j - 1] == 'x') ? retone() : retzero();
					hood[6] = (board[i + 1][j] == 'x') ? retone() : retzero();
					hood[7] = (board[i + 1][0] == 'x') ? retone() : retzero();
					fulfilled = 1;
				}
				//cor 2 -- lower left corner
				if((i == (rowlim - 1)) && (j == 0)) {
					hood[0] = (board[i - 1][collim - 1] == 'x') ? retone() : retzero();
					hood[1] = (board[i - 1][j] == 'x') ? retone() : retzero();
					hood[2] = (board[i - 1][j + 1] == 'x') ? retone() : retzero();
					hood[3] = (board[i][collim - 1] == 'x') ? retone() : retzero();
					hood[4] = (board[i][j + 1] == 'x') ? retone() : retzero();
					hood[5] = (board[0][collim - 1] == 'x') ? retone() : retzero();
					hood[6] = (board[0][0] == 'x') ? retone() : retzero();
					hood[7] = (board[0][j + 1] == 'x') ? retone() : retzero();
					fulfilled = 1;
				}
				//cor3 -- lower right corner
				if((i == (rowlim - 1)) && (j == (collim - 1))) { 
					hood [0] = (board[i - 1][j - 1] == 'x') ? retone() : retzero();
					hood [1] = (board[i + 1][j] == 'x') ? retone() : retzero();
					hood [2] = (board[i - 1][0] == 'x') ? retone() : retzero();
					hood [3] = (board[i][j - 1] == 'x') ? retone() : retzero();
					hood [4] = (board[i][0] == 'x') ? retone() : retzero();
					hood [5] = (board[0][j - 1] == 'x') ? retone() : retzero();
					hood [6] = (board[0][j] == 'x') ? retone() : retzero();
					hood [7] = (board[0][0] == 'x') ? retone() : retzero();
					fulfilled = 1;
				}
				//if it just needs normal wrapping adjustments
				//column wrapping on left side
				if((j == 0) && (fulfilled == 0)) {
					hood[0] = (board[i - 1][rowlim - 1] == 'x') ? retone() : retzero();
					hood[3] = (board[i][rowlim - 1] == 'x') ? retone() : retzero();
					hood[5] = (board[i + 1][rowlim - 1]) ? retone() : retzero();
					fulfilled = 1;
				}
				//column wrapping on right side
				if((j == collim - 1) && (fulfilled == 0)) { 
					hood[2] = (board[i - 1][0] == 'x') ? retone() : retzero();
					hood[4] = (board[i][0] == 'x') ? retone() : retzero();
					hood[7] = (board[i + 1][0] == 'x') ? retone() : retzero();
					fulfilled = 1;
				}
				//row wrapping at bottom
				if((i == rowlim - 1) && (fulfilled == 0)) {
					hood[5] = (board[0][j - 1] == 'x') ? retone() : retzero();
					hood[6] = (board[0][j] == 'x') ? retone() : retzero();
					hood[7] = (board[0][j + 1] == 'x') ? retone() : retzero();
					fulfilled = 1;
				}
				//row wrapping at top
				if((i == 0) && (fulfilled == 0)) {
					hood[0] = (board[rowlim - 1][j - 1] == 'x') ? retone() : retzero();
					hood[1] = (board[rowlim - 1][j] == 'x') ? retone() : retzero();
					hood[2] = (board[rowlim - 1][j + 1] == 'x') ? retone() : retzero();
					fulfilled = 1;
				}
				//if no wrapping is needed, check neighbor positions normally
				if(fulfilled == 0) {
					hood[0] = (board[i - 1][j - 1] == 'x') ? retone() : retzero();
					hood[1] = (board[i - 1][j] == 'x') ? retone() : retzero();
					hood[2] = (board[i - 1][j + 1] == 'x') ? retone() : retzero();
					hood[3] = (board[i][j - 1] == 'x') ? retone() : retzero();
					hood[4] = (board[i][j + 1] == 'x') ? retone() : retzero();
					hood[5] = (board[i + 1][j - 1] == 'x') ? retone() : retzero();
					hood[6] = (board[i + 1][j] == 'x') ? retone() : retzero();
					hood[7] = (board[i + 1][j + 1] == 'x') ? retone() : retzero();

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




		/*

		   for(i = 0; i < rowlim; i++) {
		   for(j = 0; j < collim; j++) {
		   if(j == (collim - 1)) {
		   printf("%2d\n", (int)hoodcount[i][j]);
		   } else {
		   printf("%2d ",(int)hoodcount[i][j]);
		   }
		   }
		   }

		 */

		//look at hoodcount array to redraw board
		for(i = 0; i < rowlim; i ++) {
			for(j = 0; j < collim; j++) {
				//reproduction
				if(hoodcount[i][j] == 3) {
					board[i][j] = 'x';
					continue;
				}
				//overcrowding
				if(hoodcount[i][j] > 3) {
					board[i][j] = ' ';
					continue;
				}
				//survival
				if(hoodcount[i][j] == 2) {
					continue;
				}
				//lonliness
				if(hoodcount[i][j] < 2) {
					board[i][j] = ' ';
					continue;
				}
			}

		}

		//clear the command prompt
		system("clear");


		k = rowlim+1;
		//print board
		for(i = 0; i < rowlim; i++) {
			k--;
			for(j = 0; j < collim; j++) {
				if(j == (collim - 1)) {
					printf("%3c\t%d\n", board[i][j], k);
				} else {
					printf("%3c", board[i][j]);
				}
			}
		}

		for(i =1 ; i <= collim; i++) {
			printf("%3d", i);
		}




		//flush the standard output stream
		fflush(stdout);


		//tell the thread to sleep
		usleep(500000);

	} //throw it all into a while loop with EOF sentinel value . . . 
}
