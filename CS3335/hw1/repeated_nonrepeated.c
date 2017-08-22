#include <stdio.h>
#include <stdlib.h>
//doesn't work

int main(){
	// Change the elements in the following array
	// to test your program
	int digits[]={26, 25, 0 , 26, 30, 13, 25, 30, 13, 0};
	int i;
	
	if(sizeof(digits) == 0) {
		puts("first rep: n/a\nfirst non-rep: n/a\n");
		puts("last rep: n/a\nlast non-rep: n/a\n");
		exit(1);	
	}

	printf("In the array of ");	
	for (i=0; i<sizeof(digits)/sizeof(int); i++)
		printf("%d ", digits[i]);
	printf("\n");	

	// Your code here...


	
	//value holders!
	int firstrep = -1;
	int firstnonrep = -1;
	int lastrep = -1;
	int lastnonrep = -1;

	

	int tallies[99]; //make tally board for every digit 1-99 
	for(i = 0; i < 99; i++) //initialize all tallies to 0
		tallies[i] = 0;
	

	puts("\n[1/5]tallies array initialized to 0 [we made it past that part] size of digits : ");
	printf("%lu\n", sizeof(digits));

	for(i = 0; i < sizeof(digits)/sizeof(int); i++) { //1. look at values and make tallies
	//how many occurences are there?? let's see..
		tallies[digits[i]] = tallies[digits[i]] +  1;	
	}

	puts("\n[2/5]we made it past the tally making\n");

	for(i = 0; i < sizeof(digits)/sizeof(int); i++) { //2. NOW, look thru digits FORWARD
		int foundrep = 0;//finding first repeated
		int foundnonrep = 0;//finding first non-repeated
		
		puts("\n[3/5]inside of foward looking loop...\n");
	
		if(foundrep && foundnonrep) {
			break;
		}
		if(!foundrep && tallies[digits[i]] > 1) {
			firstrep = digits[i];
			foundrep = 1;
		}
		if(!foundnonrep && tallies[digits[i]] == 1) {
			firstnonrep = digits[i];
			foundnonrep = 1;
		}
		
	}
	
	
	for(i = (int)(sizeof(digits)/sizeof(int))-1; i >= 0; i--) { // 3. look thru digits backward..

		int foundrep = 0;
		int foundnonrep = 0;

		puts("\n[4/5]inside of backward looking loop...\n");
		
		if(foundrep && foundnonrep) {
			break;
		}

		if(!foundrep && tallies[digits[i]] > 1) {
			lastrep = digits[i];
			foundrep = 1;
		}

		if(!foundnonrep && tallies[digits[i]] == 1) {
			lastnonrep = digits[i];
			foundnonrep = 1;
		}

	}

	puts("\n[5/5]made it to the end.. \n");
	printf("last rep:%d\nlast non-rep:%d\nfirst rep:%d\nfirst  non-rep:%d\n\n", firstrep, firstnonrep, lastrep, lastnonrep);
	for(i = 0; i < sizeof(digits)/sizeof(int); i++) {
		printf(" %d ", digits[i]);
	}
	puts("\n");
	return 0;
}


/*
I learned from this exercise how dumb c is. It doesn't even know how many elements are in an array. 
It can , however, see how many bytes are in an array or how many bytes are in one element of an array.. 

to see how many elements are in an array in c, please do the following:: 

sizeof(array)   -- this tells you how many bytes are in the array
sizeof(int)     -- this tells you how many bytes are in an int (or what ever data type, this differs per machine b/c c is machine dependent)
sizeof(array)/sizeof(int)   --   if an int takes up this much space and there is this much data in the array, it makes sense
	that this equation would tell you how many elements are in the array... 


:D



*/
