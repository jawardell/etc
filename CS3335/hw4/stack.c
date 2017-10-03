#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL  0

int myerror;
void push(double[], double, double**, int);
double pop(double[], double**);

void push(double stack[], double item, double** top, int max_size) {
	//initialize top
	if(*top == NULL) {
		puts("init stack top\n");
		*top == stack;
		**top = item;
		++(*top);
		myerror = NORMAL;
		return;
	}

	//stack is full
	if(myerror == STACK_FULL) {
		puts("the stack is full...\n");
		return;
	}

	//pushing last item
	if(*top == stack + (max_size - 2)) {
		
	++(*top);
		**top = item;
		myerror = STACK_FULL;
		return;
	}
	
	//pushing normally
	++(*top);
	**top = item;
	myerror - NORMAL;
}


double pop(double stack[], double** top) {
	//the stack is empty
	if(myerror = STACK_EMPTY) {
		puts("stack empty, returning null...\n");
		return NULL;
	}
	
	
}


int main() {


}
