//#include "resprint.h"
//#include "arrprint.h"
//#include "talk.h"
//#include "getin.h"
//#include "arrprint.h"
//#include "mean.h"
//#include "sdev.h"
//#include "resprint.h"
#include <stdio.h>
#include <math.h>//might not need
#include <time.h>//might not need
#include <stdlib.h>
#include <unistd.h>//might not need
#include <strings.h>



#define MAX_ITEM 8

int main(int argc, char* argv[]) {
	double list[MAX_SIZE], diffs[MAX_SIZE];
	talk();
	getin(list);
	arrprint(list);
	double mean = mean(list);
	double sdev = sdev(list, mean);
	resprint(list, diffs);
	


	
	
}
