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


					//perform computation 
					//put on stack
					//	....as string???? 
					//	....converting decimals to strings? ?? ?? 
					//			lossy conversion!!! 
				}
				if(getoperator(c+i) >= 5) {
					//perform computation
					//put on stack 
					//   . ..  .. as string
					//   	.. convert decimal to string>> 
					//   	D:
					//
					//
					//
					//
					//   	might just need to make two stacks
					//   		one for operators
					//   		one for operands
					//   		keep popping numbers into operands stack
					//   		keep popping until operator is encountered
					//
					//
					//
					//
					//   		char stack from input 
					//   		double stack of calculations
					//   			and numbers
					//   		read input in from console 
					//   		put into a char string,
					//   			this is iterable.. 
					//   			don't forget '\0'
					//   			keep looking at chars
					//   			grab chars and put them onto 
					//   				numbers stack.. 
					//   			keep putting them on.. 
					//
					//
					//   		wait!! 
					//   			now we see an operator!! 
					//
					//
					//
					//   		grab the numbers on the numbers stack 
					//   		 	get all two of them!! 
					//   		 		is it a unary or 
					//   		 			binary 
					//   		 		operator?? 
					//   		 	perform the calcluation.. 
					//   		 push the result of the calculation back onto the 
					//   		 	stack.. 
					//
					//   		keep doing this until we reach the end of the
					//   			iterable list of chars.. 
					//   		when we are at the end of char list, 
					//   			we should have only one value left im the
					//   			stack of numerical calculation values. .. s
					//   		we can return this value. 
					//
					//   		this is the result of the polish expression. 
					//   		\
					//
					//
					//
					//
					//
					//
					//
					//
					//
					//
					//   		so > 
					//
					//
					//   		read in input
					//
					//   		use fgets to grab whole line 
					//
					//
					//   		use strtok to place into an array / pointer location
					//
					//
					//   		iterate over input array / iterable pointer 
					//
					//
					//
					//
					//   		THE HEART : our stack of doubles
					//
					//   			layer one: stack pointer constant
					//   			layer two: element in stack
					//
					//   		
					//   		push numbers onto numbers stack
					//
					//
					//   		when an operator is seen, 
					//   		pop either two or one of the elements in the stack
					//
					//
					//   		perform the operation 
					//
					//
					//   		place calculation back onto stack 
					//
					//
					//
					//   		when the iterable char list/ array is at the end 
					//
					//
					//   		and 
					//
					//
					//   		the numbers stack has one element left 
					//
					//
					//
					//
					//   		we have the answer
					//
					//
					//
					//
					//
					//
					//
					//
					//
					//   		~~~~~~~~~~ 
					//
					//
					//   		iterataing through characters
					//   		parsing all numbers into doubles 
					//   		and pushing them onto stack 
					//
					//
					//   		use functions to identify correct operator actions
					//		execute those operations and return a douible value
					//
					//
					//		push that single double value on the stack
					//
					//
					//		the next number on the stack will use the 
					//			previously calculated value .. 
					//
					//
					//
					//
					//
					//
					//
					//			this should work. 
					//
					//
					//			hopefully i can implement it. .. 
					//
					//   		
					//
			
				}
			}
			i++;

		} while(!POLAND);


	
		
	} while(input != EOF);


}
