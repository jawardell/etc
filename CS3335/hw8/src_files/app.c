#include "resprint.h"
#include "arrprint.h"
#include "talk.h"
#include "getin.h"
#include "arrprint.h"
#include "mean.h"
#include "sdev.h"
#include "resprint.h"
#include <stdio.h>
#include <math.h>//might not need
#include <time.h>//might not need
#include <stdlib.h>
#include <unistd.h>//might not need
#include <strings.h>



#define MAX_ITEM 8

int main(int argc, char* argv[]) {
	double list[MAX_ITEM], diffs[MAX_ITEM];
	talk();
	getin(list);
	arrprint(list);
	double m = mean(list);
	double s = sdev(list, m);
	resprint(list, diffs, m, s);
	


	
	
}
