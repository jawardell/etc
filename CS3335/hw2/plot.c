#include <stdio.h>
#include <limits.h>
#include <math.h>

int f(int);

int main(void){
	int i, t, funval;
	
    // Make sure to change low and high when testing your program
	int low=-3, high=11;
	for (t=low; t<=high;t++){
		printf("f(%2d)=%3d\n",t,f(t));
   	 }

	// Your code here...
	

	int min = INT_MAX;
	int max = INT_MIN;
	
	for(i = low; i <= high; i++) {
		if(f(i) < min) {
			min = f(i);
		}
		if(f(i) > max) {
			max = f(i);
		}
	}
	printf("min = %d\nmax = %d\n", min, max);
	//do the x axis here, incriment by five to high
	int count = low;
	printf("%d\n", (max-min)/5);
	printf("\t");
	for(i = 0; i <= (max-min)/5; i++) {
		printf("%d\t", count);
		count += 5;
	}
	puts("\n");
	count = low;
	printf("\t");
	for(i = 0; i <= (max-min)/5; i++) {
		printf("|\t");
	}
	puts("\n");
	for(i = low; i <= high; i++) {
		printf("t = %d\n", i);
	}


	return 0;
}


int f(int t){
    // example 1
	return (t*t-4*t+5);
    
    // example 2
    // return (-t*t+4*t-1);
    
    // example 3
    // return (sin(t)*10);
    
    // example 4
	// if (t>0)
	//	return t*2;
	// else
	//	return t*8;
}
