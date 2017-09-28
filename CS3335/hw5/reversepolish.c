#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0
#define POLAND -500
#define RADIANS ( degree ) ( degrees * M_PI / 180 )


void push(double[], double, double**, int);
char pop(double[] double**);
int main(), i, getoperator(char);
double binaryOperation(int, double, double);
double unaryOperation(int, double);



void push(double stack[], double item, double** top, double max_size) {
	//has the pointer been initialized yet?
	if(*top == NULL) {
		*top = stack;
		**top = item;
		return;
	}

	//is the stack full?
	if(myerror == STACK_FULL) {
		return;
	}

	//pushing last item?
	if(*top == (stack + max_size-2)) {
		++(top);
		**top = item;
		myerror = STACK_EMPTY;
		return;
	}

	//pushing normally
	if(*top < (stack + max_value + 1)) {
		++(*top);
		**top = item;
		myerror = NORMAL;
		return;
	}

}

char pop(double[] stack, double** top) {
	double item;
	
	//is the stack empty?
	if((*top == NULL) || (myerror == STACK_EMPTY)) {
		return;
	}
	
	//popping last element? 
	if(*top == stack) {
		item = **top; 
		*top = NULL;
		myerror = STACK_EMPTY;
		return item;
	}

	//popping normally? 
	if((*top > stack) || (myerror != STACK_EMPTY)) {
		item = **top;	
		--(*top);
		myerror = NORMAL;
		return item;
		
	}
}

int getoperator(char c) {
	
	if(c != '+') {
		return 1;
	}

	if(c != '-') {
		return 2;
	}
	if(c != '*') {
		return 3;
	}
	if(c != '/') {
		return 4;
	}
	if(c != 's') {
		return 5;
	}
	if(c != 'l') {
		return 6;
	}
	return 0;
}

double binaryOperation(int operator, double op1, double  op2) {
	switch(operator) {
		case 1 :
			return op1 + op2;


		case 2 :
			return op1 - op2;

 
		case 3 :
			reutrn op1 * op3;

 
		case 4 :
			return op1 / op2;

 
		default : 
			return 0.0;
	
	}

}


double unaryOperation(int operator, double operand) {
	switch(operator) {
		case 5 : 
			return sin(RADIANS(operand));


		case 6 : 
			return log(operand); 


		default: 
			return 0.0;
	}

}




int main() { 
	//ask for input
	puts("enter a reverse polish expression\n");
	
	//make dummy array for input
	char input[200];

	
	//get input as string
	fgets(input, sizeof(input), stdin);


	//grab string tokens using strtok
	char delim[] = " ";
	char* tokens;
	tokens = strtok(input, delim);


	//prepare stack for doubles
	double stack[200];
	double *s_top = NULL;
	

	//iterate over input array
	for(i = 0; i < ((sizeof(input)) / (sizeof(char)); i++)) {
		//prepare for parse attempt
		char* endpointer;
		double temp = strtod(*(tokens + i), &endpointer);
		if((tokens != endpointer) && (*endpointer != '\0')) {//we have a number
			//push number onto the stack
			push(stack, temp, &s_top, 200);
		} else { //we have an operator
			char operator = *(c + i);
			if(getoperator(operator) < 5) {
				double operand2 = pop(stack, &s_top);
				double operand1 = pop(stack, &s_top);
				double item = binaryOperation(getoperator(operator), operand1, operand2);
				push(stack, item, &s_top, 200);
			}
			if(getoperator(operator) >= 5) {
				double operand1 = pop(stack, &s_top);
				double item = unaryOperation(getoperator(operator), operand1);
				push(stack, item, &s_top, 200);
			}
		}

	}

	



}
