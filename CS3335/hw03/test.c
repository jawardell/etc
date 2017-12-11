#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


void printarray(char[], int);



void printarray(char array[], int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("a[%d] = %c\n", i, array[i]);
	}

}



int main() {

	char a[SIZE], *p;
	p = a;
	int i;

	for(i = 0; i < SIZE; i++) {
		a[i] = (char)i;	
	}

	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(double) = %lu\n", sizeof(double));
	printf("sizeof(long double) = %lu\n", sizeof(long double));

	printf("*(p+3) = %d\n", *(p+3));
	printf("*(char *)((int *)p+3) = %d\n", *(char *)((int *)p+3) );

	printf("*(char *)((double *)p+3) = %d\n", *(char *)((double *)p+3));
	printf("*(char *)((long double *)p+3) = %d\n", *(char *)((long double *)p+3));
	
	printf("\nprint array\n");
	printf("sizeof(a) = %lu\nsizeof(char) = %lu\n", sizeof(a), sizeof(char));
	printarray(a, sizeof(a)/sizeof(char));	

}
