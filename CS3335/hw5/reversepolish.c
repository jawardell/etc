#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0
#define STACK_SIZE 10

void push(double[], double, double**, int);
double pop(double[], double**);
int myerror;

void push(double stack[], double item, double** top, int max_size) {
	//init top
	if(*top == NULL) {
		*top = stack; 
		**top = item;
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

	//push normally
	++(*top);
	**top = item;
	myerror = NORMAL;
}

double pop(double stack[], double** top) {
	//stack is empty
	if(myerror == STACK_EMPTY) {
		return 0.0;
	}

	//popping last item
	if(*top == stack) {
		double temp = **top;
		--(*top);
		myerror = STACK_EMPTY;
		return temp;
	}

	//popping normally
	double temp = **top;
	--(*top);
	myerror = NORMAL;
	return temp;
}

int main() {
	double stack[200];
	double* s_top = NULL;
	printf("\nenter a reverse polish expression:");
	char input[200];//input is a pointer constant
	fgets(input, sizeof(input), stdin);
	char* ptr2token = strtok(input, " ");//this points to the first char in a string
	while(ptr2token != NULL) {
		//try to use strtod here
		//does strtok return a pointer constant?
		char* endpointer;
		double number;
			number = strtod(ptr2token, &endpointer);
		if((endpointer == ptr2token) && (*endpointer == '\0')) {//we have a number

			printf("\nthe number is %f\n", number);
		} else {//we don't have a number
			printf("the non number is: %s", endpointer);
		}
		
		ptr2token = strtok(input, NULL);
	}
	puts("");
	
}
