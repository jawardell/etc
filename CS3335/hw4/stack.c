#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0

int myerror;
void push(double[], double, double**, int);
double pop(double[], double**);

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

	//pushing normally
	++(*top);
	**top = item;
	myerror = NORMAL;
}


double pop(double stack[], double** top) {
	//stack is empty
	if((*top == NULL) || (myerror == STACK_EMPTY)) {
		return NULL;
	}

	//pop last item
	if(*top == stack) {
		double temp = **top;
		--(*top);
		myerror = STACK_EMPTY;
		return temp;
	}

	//pop normally
	double temp = **top;
	--(*top);
	return temp;

}




int main() {
	double stack[STACK_SIZE];
	double* s_top = NULL;
	
	while(myerror != STACK_FULL) {
		double item = (double)(rand()/126.0*33.0);
		printf("\npushing item %f on to stack..\n", item);
		push(stack, item, &s_top, STACK_SIZE);
	}

	while(myerror != STACK_EMPTY) {
		printf("\npopping item %f from stack..\n", pop(stack, &s_top));
	}


}
