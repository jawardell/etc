//Joanne Wardell
//CS3335
//Thursday, August 24, 2017
//Design:
	//program uses hashtable 0-99 to mark occurrences
	//iterates forward through input array to find first rep/non-rep
	//iterates backward through input array to find last rep/non-rep
	//returns speacial values
	//NOTE: if value is not found, values remain -1.
//Runtime Commplexity - O(n) Oh-of n


#include <stdio.h>
#include <stdlib.h>


int main(){
	// Change the elements in the following array
	// to test your program
	
	//int digits[]={26, 25, 10 , 26, 30, 13, 25, 30, 13, 0};
	//int digits[]={25, 25, 25};	
//	int digits[]={26, 25, 0 , 26, 30, 13, 25, 30, 13, 0};
//	int digits[] = {25};
	int digits[] = {1, 2, 3, 4, 5, 6, 7};
	//int digits[] = {1, 2, 2, 3,4, 5, 4,8};
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


	
	//value holders
	int firstrep = -1;
	int firstnonrep = -1;
	int lastrep = -1;
	int lastnonrep = -1;


	if(sizeof(digits)/sizeof(int) == 1) {
		firstrep = digits[0];
		firstnonrep = digits[0];
		lastrep = digits[0];
		lastnonrep =  digits[0];	
		printf("last rep:%d\nlast non-rep:%d\nfirst rep:%d\nfirst  non-rep:%d\n\n", lastrep, lastnonrep, firstrep, firstnonrep);
		return 0;
	}
	int allsame = 1;
	int value = digits[0];
	for(i = 0; i < sizeof(digits)/sizeof(int); i++) {
		if(value != digits[i]) {
			allsame = 0;		
		}
	}


	if(allsame) {
		firstrep = digits[0];	
		firstnonrep = digits[0];	
		lastrep = digits[0];	
		lastnonrep = digits[0];
		printf("last rep:%d\nlast non-rep:%d\nfirst rep:%d\nfirst  non-rep:%d\n\n", lastrep, lastnonrep, firstrep, firstnonrep);
		
		return (0);	
	}	


	int tallies[100] = {}; //make tally board for every digit 1-99
	




	for(i = 0; i < sizeof(digits)/sizeof(int); i++) {
		tallies[digits[i]]++;	
	}


	for(i = 0; i < sizeof(digits)/sizeof(int); i++) {
		int foundrep = 0;
		int foundnonrep = 0;
		

	
		if(foundrep && foundnonrep) {
			break;
		}
		if(!foundrep  && (tallies[digits[i]] > 1)) {
			firstrep = digits[i];
			foundrep = 1;
		}
		if(!foundnonrep && (tallies[digits[i]] == 1)) {
			firstnonrep = digits[i];
			foundnonrep = 1;
		}
		
	}
	
	
	for(i = sizeof(digits)/sizeof(int)-1; i >= 0; i--) {

		int foundrep = 0;
		int foundnonrep = 0;


		
		if(foundrep && foundnonrep) {
			break;
		}

		if(!foundrep && (tallies[digits[i]] > 1)) {
			lastrep = digits[i];
			foundrep = 1;
		}

		if(!foundnonrep  && (tallies[digits[i]] == 1)) {
			lastnonrep = digits[i];
			foundnonrep = 1;
		}

	}


	printf("last rep:%d\nlast non-rep:%d\nfirst rep:%d\nfirst  non-rep:%d\n\n", firstrep, firstnonrep, lastrep, lastnonrep);
//	for(i = 0; i < sizeof(digits)/sizeof(int); i++) {
//		printf(" %d ", digits[i]);
//	}
	puts("\n");
	return 0;
}
