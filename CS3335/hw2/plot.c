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
