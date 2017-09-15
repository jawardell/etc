#include <stdio.h>
#include <stdlib.h>
#define SIZE 100


void printarray(char[]);



void printarray(char array[]) {
	int i;
	for(i = 0; i < (sizeof(array)/sizeof(char)); i++) {
		printf("a[%d] = %c\n", i, array[i]);
	}

}



int main() {

	char a[SIZE], *p;
	p = a;
	int i;

	for(i = 0; i < SIZE; i++) {
		a[i] = i;	
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
	printarray(a);	

}
