#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0
#define POLAND -500
#define RADIANS ( degree ) ( degrees * M_PI / 180 )


void push(char[], char, char**, int);
char pop(char[] char**);
int main(), i, getoperator(char);
double binaryOperation(int, double, double);
double unaryOperation(int, double);



void push(char stack[], char item, char** top, int max_size) {
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

char pop(char[] stack, char** top) {
	char item;
	
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
	char stack[], *s_top = NULL, input[], delim[], *c = NULL;



	puts("\n\tenter a reverse polish expression: \n");
	do {
		//use stringtok to get tokens from input
		fgets("%c", input);
		c = strtok(input, delim);
		
		//keep going until one item is left on the stack
		do {
			char* end;
			double number  = strtod(*(c+i), &end);
			//push in all NUMBERS!
			if((c != end) && (*end == '\0')) { // is a number
				push(stack, *(c+i), &s_top, ((sizeof(c))/(sizeof(char))));
				
			} else if((*(c+i) == end) && (*end != '\0')) { // isn't a number
				if(getoperator(c+i) < 5) {
				}
				if(getoperator(c+i) >= 5) {
					
				}
			}
			i++;

		} while(!POLAND);


	
		
	} while(input != EOF);


}
