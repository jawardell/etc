#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0
#define POLAND -500
#define RADIANS( degrees ) ( degrees * M_PI / 180 )

void pushD(double[], double, double**, int);
void pushC(char* [], char* , char***, int);
double popD(double[], double**);
char popC(char* [], char***);
int  i, getoperator(char), alarm, myerror_c, myerror_d; 
double unaryOperation(int, double);
double binaryOperation(int, double, double);



void pushD(double stack[], double item, double** top, int max_size) {
	//report stack size
	if(*top == stack) {
		alarm = POLAND;
	}

	//has top been initialized yet?
	if(*top == NULL) {
		*top = stack;
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
		**top = item;
		myerror_d = STACK_FULL;
		return;
	}

	//pushing normally
	if(*top < (stack + (max_size - 1))) {
		++(*top);
		**top = item;
		myerror_d = NORMAL;
		return;
	}


}

void pushC(char* stack[], char* item, char*** top, int max_size) {
	//has top been initialized yet?
	if(*top == NULL) {
		*top = stack;
		**top = item;
		++(*top);
		return;
	}

	//is the stack full?
	if(myerror_c == STACK_FULL) {
		return;
	}
	
	//pushing last item?
	if(*top == (stack + (max_size - 2))) {
		++(*top);
		**top = item;
		myerror_c = STACK_FULL;
		return;
	}

	//pushing normally
	if(*top < (stack + (max_size - 1))) {
		++(*top);
		**top = item;
		myerror_c = NORMAL;
		return;
	}

}

double popD(double stack[], double** top) {
	//report stack size
	if(*top == stack) {
		alarm = POLAND;
	}

	//is the stack empty? 
	if(myerror_d = STACK_EMPTY) {
		return 0.0;
	}

	//popping last item? 
	if(*top == stack) {
		double item = **top;
		*top = NULL;
		myerror_d = STACK_EMPTY;
		return item;
	}

	//popping normally
	double item = **top;
	--(*top);
	myerror_d = NORMAL;
	return item;
}

char* popC(char* stack[], char*** top) {
	//is the stack empty? 
	if(myerror_c = STACK_EMPTY) {
		return 0.0;
	}

	//popping last item? 
	if(*top == stack) {
		char* item = **top;
		*top = NULL;
		myerror_c = STACK_EMPTY;
		return item;
	}

	//popping normally
	char* item = **top;
	--(*top);
	myerror_c = NORMAL;
	return item;
}

int getoperator(char* c) {
	switch(c) {
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

	puts("\n\tenter a reverse polish expression\n");
	fgets(input, sizeof(input), stdin);	


	puts("\nenter number of operands in expression -->  ");	
	int d_num;
	scanf("%d", &d_num);


	puts("\nenter number of operators in expression -->  ");
	int c_num; 
	scanf("%d", &c_num);

	double stack_d[d_num], **d_top = NULL;
	char* stack_c[c_num + d_num], **c_top = NULL;



	char* token = strtok(input, " ");
	do {
		pushC(stack_c, token, &c_top, (c_num+d_num));
		token = strtok(NULL, " ");

	} while(token != NULL);

	while(myerror_c != STACK_EMPTY) {
		char* current = popC(stack_c, &c_top);
		char* endpointer;	
		double temp = strtd(current, &endpointer);//try to parse
		

		if((current != endpointer) && (endpointer != '\0')) { //we have a number
			pushD(stack_d, temp, &d_top, d_num);
		} else { //we have an operator
			char* operator = current;
			
			if(getoperator(operator) < 5) {
				double operand2 = popD(stack_d, &d_top);
				double operand1 = popD(stack_d, &d_top);
				double eval = binaryOperation(getoperator(operator), operand1, operand2);
				pushD(stack_d, eval, &d_top, d_num);
			}
			if(getoperator(operator) >= 5) {
				double operand = popD(stack_d, &d_top);
				double eval = unaryOperation(getoperator(operator), operand);
				pushD(stack_d, eval,  &d_top, d_num);
			}

		}

		if(alarm == POLAND) {
			solution = popD(stack_d, &d_top);
			break;
		}
	}
	
	printf("\n\tThe evaluated reverse polish expression is: %f\n", solution);
	puts("\n\tHave a nice day!");
	

	
}
