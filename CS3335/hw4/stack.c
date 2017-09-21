#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0

int myerror = NORMAL;
void push(double[], double, double**, int);
double pop(double[], double**);

void push(double stack[], double item, double** top, int max_size) {
	//check to see if full
	if(*top == max_size) {
		return;
	}
	//are we at end of stack
	if(*top == max_size-1) {
		(int**)top;
		stack[**top] = item;	
		(double**)top;
		return;
	}
	//insert in normal place
	if(**top < max_size) {
		(int**)top;
		stack[**top] = item;	
		**top++;
		(double**)top;
		return;
		
	}
}

double pop(double stack[], double** top) {
	if(**top == -1) {
		return STACK_EMPTY;
	}

	(int**)top;
	double temp = stack[**top];
	**top--;
	(double**)top;
	return temp;
}

int main() {
	double s[STACK_SIZE];
	double* s_top = STACK_EMPTY;
	srand(time(NULL));
	
	//push until full
	while(*s_top != STACK_SIZE-1) {
		double item = (double)(rand()/126.0*33.0);
		printf("pushing item %f\n", item);
		push(s, item, &s_top, STACK_SIZE);
		
	}
	//pop until empty
	int i = 0;
	while(*s_top != STACK_EMPTY) {
		i = *s_top;
		printf("POP! item %d is: %f\n", pop(s, &s_top));
	}






}
