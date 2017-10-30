//#include "getin.h"
//#include "calc.h"
#include <stdio.h>
#include <math.h>//might not need
#include <time.h>//might not need
#include <stdlib.h>
#include <unistd.h>//might not need
#include <strings.h>



#define MAX_ITEM 8

int main(int argc, char* argv[]) {
	puts("\nHello human! Enter a list of numbers.\n");
	puts("\nI will make some calcuations for you.\n");
	puts("\nPlease only enter 0 to 8 numbers. Thank you!\n");

	int nums[MAX_ITEM], i = 0;
	
	char* str;
	str = scanf("%s", &str);
	while(str != "\n") {
		if() {
		}
		int temp = atoi(str); 
		scanf("%d", &temp);
		nums[i] = temp;
		printf("\nnums[%d] = %d\n",i,  nums[i]);
		i++;
	}
}
