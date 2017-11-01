#include <math.h>
#include "arrprint.h"
#include <stdio.h>
void arrprint(double list[8]) {
	int i;
	for(i = 0; i < 8; i++) {
		printf("%f\n", *(list + i));
	}

}
