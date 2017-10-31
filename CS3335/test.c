#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int array[5][5], i, j;
void printnow(int(*)[5], int, int);

int main() {


	srand(time(NULL));


	for(i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			int temp = rand() % 10 + 1;	
			array[i][j] = temp;
			if(j == 4) {
				printf("%3d\n", array[i][j]);
			} else {
				printf("%3d ", array[i][j]);
			}
		}
	}

	i = 0;
	j = 0;
	puts("\nabout to print using pointer expressions\n");
	

	printnow(array, 5, 5);




}

void printnow(int(*array)[5], int row,  int col) { 
	int i = 0, j = 0;
	while(i < row) { 
		if(j == col-1) { 
			printf("%3d\n", (*(array + i))[j]);
			i++;
			j = 0;
			continue;
		}
		printf("%3d ", (*(array + i))[j]);	
		j++;
	}
}
