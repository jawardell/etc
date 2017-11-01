#include "getin.h"
#include <stdio.h>
int getin(double list[8]) {
	int i;
	for(i = 0; i < 8; i++) {
		double temp;
		scanf("%f", &temp);
		list[i] = temp;
	}

}
