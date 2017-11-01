//#include "sdev.h"
#include <math.h>

double sdev(double list[8], double mean) {
	double res = 0;
	int i; 
	for(i = 0; i < 8; i++) {
		res += (*(list + i))*(*(list + i));
	}
	
	res = res/8.0;
	res = res - mean*mean;
	return sqrt(res);

}
