#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0
#define STACK_SIZE 10

double pop(double[], double, double**, int);
void push(double[], double**);
int main(), myerror;

double pop(double stack[], double item, double** top, int size) {
	//pop last item
	if(*top == stack) {
		double temp = **top;
		*top = NULL; 
		myerror = STACK_EMPTY;
		return temp;
	}

	//stack is empty
	if(myerror == STACK_EMPTY) {
		return 0.0;
	}

	//pop normally
	double temp = **top;
	--(*top);
	myerror = NORMAL;
	return temp;
}

void push(double stack, double item, double** top, int size) {
	//init top pointer 
	if(*top == NULL) {
		*top = stack;
		**top = item;
		myerror = NORMAL;
		return;
	}
	
	//pushing last item
	if(*top == (size-1)) {
		++(*top);
		**top = item;
		myerror = STACK_FULL;
		return;
	}

	//stack is full
	if(myerror == STACK_FULL) {
		return;
	}

	//push normally
	++(*top);
	**top = item;
	myerror = NORMAL;
}




int main() {

	char* input[200];
	puts("enter a reverse polish expression\n");
	fgets(input, 200, stdin);
	cha

}

