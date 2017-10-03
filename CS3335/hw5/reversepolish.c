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
int  i, getoperator(char*), alarm, myerror_c, myerror_d; 
double unaryOperation(int, double);
double binaryOperation(int, double, double);



void push(double stack[], double item, double** top, int max_size) {
	//report stack size
	if(*top == stack) {
		puts("poland!");
		alarm = POLAND;
	}

	//has top been initialized yet?
	if(*top == NULL) {
		*top = stack;
		printf("pushing item %f\n", item);
		**top = item;
		++(*top);
		return;
	}

	//is the stack full?
	if(myerror_d == STACK_FULL) {
		return;
	}
	
	//pushing last item?
	if(*top == (stack + (max_size - 2))) {
		++(*top);
		printf("pushing item %f\n", item);
		**top = item;
		myerror_d = STACK_FULL;
		return;
	}

	//pushing normally
	if(*top < (stack + (max_size - 1))) {
		++(*top);
		printf("pushing item %f\n", item);
		**top = item;
		myerror_d = NORMAL;
		return;
	}


}

double pop(double stack[], double** top) {
	//report stack size
	if(*top == stack) {
		puts("poland!!");
		alarm = POLAND;
	}

	//is the stack empty? 
	if(myerror_d == STACK_EMPTY) {
		puts("stack empty");
		return 0.0;
	}

	//popping last item? 
	if(*top == stack) {
		double item = **top;
		printf("pop: %f\n", item);
		*top = NULL;
		myerror_d = STACK_EMPTY;
		return item;
	}

	//popping normally
	double item = **top;
	printf("pop: %f\n", item);
	--(*top);
	myerror_d = NORMAL;
	return item;
}

int getoperator(char* c) {
	switch(*c) {
		case '+' : 
			return 1;
		case '-' : 
			return 2;
		case '*' : 
			return 3;
		case '/' : 
			return 4;
		case 's' : 
			return 5;
		case 'l' : 
			return 6;
		default: 
			return 0;
	}


}


double unaryOperation(int operator, double operand) {
	switch(operator) {
		case 5 : 
			return (sin(RADIANS(operand)));
		case 6 : 
			return (log(operand));
		default : 
			return 0.0;

	}
}

double binaryOperation(int operator, double op1, double op2) {
	switch(operator) {
		case 1 : 
			return (op1 + op2);
		case 2 :
			return (op1 - op2);
		case 3 : 
			return (op1 * op2);
		case4 : 
			return (op1 / op2);
		default : 
			return 0.0;
	}
}

int main() {
	double solution = 0;
	char input[200];
	myerror_d = 0;

	puts("\n\tenter a reverse polish expression\n");
	fgets(input, sizeof(input), stdin);	


	puts("\nenter number of operands in expression -->  ");	
	int d_num;
	scanf("%d", &d_num);


	puts("\nenter number of operators in expression -->  ");
	int c_num; 
	scanf("%d", &c_num);

	double stack_d[d_num], *d_top = NULL;
	



	char* token = strtok(input, " ");
	do {
		token = strtok(NULL, " ");
		char* endpointer;
		
		//try to parse token
		
		strtod(token, &endpointer);
		//printf("*endpointer is %c\n", *endpointer);
		if((*endpointer == '\0') &&  (endpointer == token)) { //we have a number
			double item = strtod(token, &endpointer);
			push(stack_d, item, &d_top, d_num);
			
		} else { //we have an operator
			if(getoperator(token) < 5) {
				double op1 = pop(stack_d, &d_top);
				double op2 = pop(stack_d, &d_top);
				double eval = binaryOperation(getoperator(token), op1, op2);
				push(stack_d, eval, &d_top, d_num);
			}
			if(getoperator(token) >= 5) {
				double op1 = pop(stack_d, &d_top);
				double eval = unaryOperation(getoperator(token), op1);
				push(stack_d, eval, &d_top, d_num);
				
			}
			
		}

		//check stack size
		if(alarm == POLAND) {
			solution = pop(stack_d, &d_top);
			break;
		}

	} while(token != NULL);
	

	
	printf("\n\tThe evaluated reverse polish expression is: %f\n", solution);
	puts("\n\tHave a nice day!");
	

	
}
