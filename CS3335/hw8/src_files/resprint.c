#include "resprint.h"

#include <stdio.h>
void resprint(double list[8], double diffs[8], double mean, double sdev) {
	int i;
	for(i = 0; i < 8; i++) {
		*(diffs + i) = *(list + i) - mean;
	}
	printf("\nThe mean is %f.\n", mean);
	printf("The standard deviation is %f\n\n", sdev);
	puts("Table of diff between data items and mean\n");
	puts("------------------------------------------");
	printf("%-20s%-20s%-20s\n", "Index", "Item", "Diff");
	for(i = 0; i < 8; i++) {
		if(*(diffs + i) < 0) {

			printf("%-20d%-20.3f%-19.3f\n", i, *(list + i), *(diffs + i));
		} else {
			printf("%-20d%-20.3f%-20.3f\n", i, *(list + i), *(diffs + i));
		}
	}

}
