#include "mean.h"


double mean(double list[8]) {
	double res = 0;
	int i; 
	for(i = 0; i < 8; i++) {
		res += *(list + i);
	}
	return res/8.0;

}
