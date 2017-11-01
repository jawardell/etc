#include "resprint.h"

void resprint(double list[8], double diffs[8], double mean, double sdev) {
	int i;
	printf("\nThe mean is %f.\n", mean);
	printf("The standard deviation is %f\n\n", sdev);
	puts("Table of diff between data items and mean\n");
	puts("------------------------------------------");
	printf("%20s%20s%20s\n", "Index", "Item", "Diff");
	for(i = 0; i < 8; i++) {
		printf("%20d%20f%20f\n", i, *(list + i), *(diffs + i));
	}

}
