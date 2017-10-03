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
<<<<<<< HEAD
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
	

=======
>>>>>>> 0bc2fd1b89f987633eb26bd85f2267e45f45945f
	
	//pop normally
	double temp = **top;
	--(*top);
	myerror = NORMAL;
	return temp;
}
