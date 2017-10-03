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
		printf("\npushing item %f first onto stack\n", item);
		myerror = NORMAL;
		return;
	}

	//stack is full
	if(myerror == STACK_FULL) {
		printf("\nnothing pushed, stack is full\n");
		return;
	}

	//pushing last item
	if((*top == stack + (max_size - 2)) && (myerror == NORMAL)) {
		++(*top);
		**top = item;
		printf("\nitem %f pushed onto stack, last item\n", item);
		myerror = STACK_FULL;
		return;
	}

	//pushing normally
	++(*top);
	**top = item;
	printf("\nitem %f pushed onto stack normally\n", item);
	myerror = NORMAL;
}


double pop(double stack[], double** top) {
	//stack is empty
	if((*top == NULL) || (myerror == STACK_EMPTY)) {
		printf("\nnothing to pop, stack empty\n");
		return 0.0;
	}

	//pop last item
	if(*top == stack) {
		double temp = **top;
		--(*top);
		myerror = STACK_EMPTY;
		printf("\npopping %f last item on stack\n", temp);
		return temp;
	}

	//pop normally
	double temp = **top;
	--(*top);
	printf("\npopping item %f normally\n", temp);
	return temp;

}




int main() {
	double stack[STACK_SIZE];
	double* s_top = NULL;
	
	while(myerror != STACK_FULL) {
		double item = (double)(rand()/126.0*33.0);
		push(stack, item, &s_top, STACK_SIZE);
	}

	while(myerror != STACK_EMPTY) {
		pop(stack, &s_top);
	}


}
