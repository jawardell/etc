#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <strings.h>

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
	
	char line[max-min];
	for(i = 0; i < (sizeof(line)/sizeof(char)) ; i++) {
		line[i] = ' ';
	}
	t = 0;
	//plug in t
	//make array[f(t)] = *
	//make loop that goes to length of char array
	//have counter for t that only increments when at the end of char array
	//this is how you know what t is and make array[f(t)] = *
	
	for(i = 0; i < (sizeof(line)/sizeof(char)); i++) {
		printf("t = %d", i);
		
		if(i == (sizeof(line)/sizeof(char)-1)) {
			printf("\n");
			t++;
			continue;
		}
		if(f(t) == i) {
			printf("*");
		}
		if(f(t) != i) {
			printf(" ");
		}





	
	

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
