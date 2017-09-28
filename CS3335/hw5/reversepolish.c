#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0
#define POLAND -500
#define RADIANS( degrees ) ( degrees * M_PI / 180 )


void push(double[], double, double**, int);
double pop(double[], double**);
int main(), i, getoperator(char), alarm, myerror;
double binaryOperation(int, double, double);
double unaryOperation(int, double);



void push(double stack[], double item, double** top, int max_size) {
	//stack size report
	if(*top == stack) {
		alarm = POLAND;
	}

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
	if(*top < (stack + max_size + 1)) {
		++(*top);
		**top = item;
		myerror = NORMAL;
		return;
	}

}

double pop(double stack[], double** top) {
	double item;
	
	//stack size report
	if(*top == stack) {
		alarm = POLAND;
	}

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
			return (op1 + op2);


		case 2 :
			return (op1 - op2);

 
		case 3 :
			return (op1 * op2);

 
		case 4 :
			return (op1 / op2);

 
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

	puts("\n\tdebug 1\n");

 
	double solution = 0;


	//ask for input
	puts("enter a reverse polish expression\n");
	
	//make dummy array for input
	char input[200];

	puts("\n\tdebug 2\n");

 
	
	//get input as string
	fgets(input, sizeof(input), stdin);

	puts("\n\tdebug 3\n");
	

	//prepare stack for doubles
	double stack[200];
	double *s_top = NULL;
	

	printf("printf(input) is %s\n", input); 

	//grab string tokens using strtok
	char* token = strtok(input, " ");
	do {	
		printf("current token = %s\n", token);
		token = strtok(NULL, " ");


		//prepare for parsing
		char* endpointer;
		double temp = strtod(token, &endpointer);


		if((token != endpointer) && (*endpointer != '\0')) { //we have a number
			push(stack, temp, &s_top, 200);
			
		} else { //we have an operator
			char operator = token;


			if(getoperator(operator) < 5) {
				double operand2 = pop(stack, &s_top);
				double operand1 = pop(stack, &s_top);
				double item = binaryOperation(getoperator(operator), operand1, operand2);
				push(stack, item, &s_top, 200);
			}
			if(getoperator(operator) >= 5) {
				double operand = pop(stack, &s_top);
				double item = unaryOperation(getoperator(operator), operand);
				push(stack, item, &s_top, 200);
			}
		}
		

		//see if one item is left on stack
		if(alarm = POLAND) {
			solution = pop(stack, &s_top);
			break;
		}

	} while(token != NULL);
	
	
	



	puts("\n\tdebug 11\n");

 

	printf("\n\tThe reverse Polish expression evaluates to: %f\n", solution);
	puts("\n\tHave a nice day!\n\n");
	



}
