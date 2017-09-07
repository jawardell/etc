#include <stdio.h>

int main(){
	int a[4]={-1, 2, 0, 79}, b[]={20, 1}; //a is an immutable address to a[0]
	
//	a[1] = 23;//but the elements are mutable...
	
	*(a+3) = 100;
	int i;
	for (i=0; i<sizeof(a)/sizeof(*a); i++)  // size of a is how many bits in array total
						// the size of the data type which a points to
		printf("a[%d] = %d ", i, a[i]);

	printf("\n");

	int *c =a;//....and we can catch the address of the array
		//...and assign it to c
		//..a pointer to the array.. POINTER...
		//AND c`pointer` is mutable but a`pointer` is not

	// This is problematic because sizeof(c) is
	// not the number of bytes in a, rather, it is the 
	// size of a pointer
	printf("sizeof(c)=%ld, sizeof(*c)=%ld\n", sizeof(c), sizeof(*c));
//	for (i=0; i<sizeof(c)/sizeof(*c); i++) this is moving using the wrong step size
	for (i=0; i<sizeof(a)/sizeof(*a); i++)
		printf("a[%d] = %d ", i, c[i]);

	printf("\n");

	c=b;            // c is a regular pointer which is mutable ... we can do this.
	*(c+1) =100 ;
	for (i=0; i<sizeof(b)/sizeof(*b); i++)
		printf("b[%d] = %d \n", i, *(c+i));
	return 0;
}
