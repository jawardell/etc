#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int rows, cols, i, j;
	puts("\nenter rows\n");
	scanf("%d", &rows);
	printf("\nrows is %d\n", rows);
	puts("\nenter cols\n");
	scanf("%d", &cols);
	printf("\ncols is %d\n", cols);


	char array[rows][cols];
	for(i = 0; i < rows; i++) {
		for(j = 0; j < cols; j++) {
			array[i][j] = '*';
		}
	}

	int rowlength;

	for(i = 0; i < rows; i++) {
		for(j = 0; j < cols; j++) {	
			if(j == cols-1) {
				printf("%c\n", array[i][j]);
			} else {
				printf("%c", array[i][j]);
			}
		}
	}

	int choice;

	do {
		puts("\n\n");
		printf("\nyour choice was %d .. \n", choice);
		puts("\n\n");
		int x, y;
		puts("\n\twhere would you like to place an x?\n");
		puts("\nenter x-coord\n");
		scanf("%d", &x);
		printf("\nx is %d\n", x);
		puts("\n\tenter y-coord\n");
		scanf("%d", &y);
		printf("\ny is %d\n", y);
		printf("\nthe coordinates are (%d, %d)\n", x, y);

		array[x][y] = 'x';

		for(i = 0; i < rows; i++) {
			for(j = 0; j < cols; j++) {
				if(j == cols-1) {
					printf("%c\n", array[i][j]);
				} else {
					printf("%c", array[i][j]);
				}
			}
		}

		puts("\n\n");
		puts("\nwould you like to place an x?  [1 yes  |  0 no]\n");
		scanf("%d", &choice);

	} while(choice);
}
