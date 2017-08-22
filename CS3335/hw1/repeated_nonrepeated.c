#include <stdio.h>

int main(){
	// Change the elements in the following array
	// to test your program
	int digits[]={2,0,38,2,3,1,3};
	int i;
	
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
	
	for(i = 0; i < sizeof(digits); i++) { //1. look at values and make tallies
	//how many occurences are there?? let's see..
		tallies[digits[i]]++;	
	}

	for(i = 0; i < sizeof(digits); i++) { //2. NOW, look thru digits FORWARD
		int foundrep = 0;//finding first repeated
		int foundnonrep = 0;//finding first non-repeated
	
	
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
	

	for(i = sizeof(digits)-1; i >= 0; i--) { // 3. look thru digits forward

		int foundrep = 0;
		int foundnonrep = 0;
		
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


	printf("first rep:%d\nfirst non-rep:%d\nlast rep:%d\n last non-rep:%d", firstrep, firstnonrep, lastrep, lastnonrep);

	return 0;
}
