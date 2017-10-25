#include "printboard.h"

void printboard(int rowlim, int collim) {
	int i, j;

	for(i = 0; i < rowlim; i++) {
		for(j = 0; j < collim; j++) {
			if(j == collim) {
				printf("%s\n", (*(board + i))[j]);
			} else {
				printf("%s", (*(board + i))[j]);
			}
		}
	}

}
