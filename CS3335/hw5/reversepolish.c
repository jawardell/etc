#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0


void push(double[], double, double**, int);
double pop(double[], double**);
int myerror;



void push(double stack[], double item, double** top, int max_size) {
	//init top
	if(*top == NULL) {
		*top = stack;
		**top = item;
		++(*top);
		myerror = NORMAL;
		return;
	}

	//stack is full
	if(myerror == STACK_FULL) {
		return;
	}

	//pushing last item
	if((*top == stack + (max_size - 2)) && (myerror == NORMAL)) {
		++(*top);
		**top = item;
		myerror = STACK_FULL;
		return;
	}

	//pushing normally
	++(*top);
	**top = item;
	myerror = NORMAL;
}

double pop(double stack[], double item) {
	//popping last item
	if(*top == stack) {
		double temp = **top;
		--(*top);
		myerror = STACK_EMPTY;
		return temp;
	}
	
	//pop normally
	double temp = **top;
	--(*top);
	myerror = NORMAL;
	return temp;
}
