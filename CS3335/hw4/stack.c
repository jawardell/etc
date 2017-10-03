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
<<<<<<< HEAD
	//initialize top
	if(*top == NULL) {
		puts("init stack top\n");
		*top == stack;
		**top = item;
		++(*top);
		myerror = NORMAL;
=======
	//init top
	if(*top == NULL) {
		*top = stack;
		**top = item;
		printf("\npushed item %f first on stack\n", item);
		++(*top);
		myerror = NORMAL; 
>>>>>>> 0bc2fd1b89f987633eb26bd85f2267e45f45945f
		return;
	}

	//stack is full
	if(myerror == STACK_FULL) {
<<<<<<< HEAD
		puts("the stack is full...\n");
=======
		printf("\nstack is full\n");
>>>>>>> 0bc2fd1b89f987633eb26bd85f2267e45f45945f
		return;
	}

	//pushing last item
<<<<<<< HEAD
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
=======
	if((*top == stack + (max_size - 2)) && (myerror == NORMAL)) {
		++(*top);
		**top = item;
		printf("\npushed item %f last on stack\n", item);
		myerror = STACK_FULL;
		return;
	}

	//push normally
	++(*top);
	**top = item;
	printf("\npushed item %f normally\n", item);
	myerror = NORMAL;
>>>>>>> 0bc2fd1b89f987633eb26bd85f2267e45f45945f
}


double pop(double stack[], double** top) {
<<<<<<< HEAD
	//the stack is empty
	if(myerror = STACK_EMPTY) {
		puts("stack empty, returning null...\n");
		return NULL;
	}
	
	
=======
	//stack is empty
	if(myerror == STACK_EMPTY) {
		printf("\nstack is empty, nothing to pop\n");
	}

	//pop last item
	if(*top == stack) {
		double temp = **top;
		--(*top);
		myerror = STACK_EMPTY;
		return;
	}

	//pop normally
	double temp = **top;
	--(*top);
	printf("\npopping item %f normally\n", temp);
	return temp;
>>>>>>> 0bc2fd1b89f987633eb26bd85f2267e45f45945f
}


int main() {
<<<<<<< HEAD
=======
	double stack[STACK_SIZE];
	double* s_top = NULL;
	srand(time(NULL));


	while(myerror != STACK_FULL) {
		double item = (double)(rand()/126.0*33.0);
		push(stack, item, &s_top, STACK_SIZE);	
	}

	while(myerror != STACK_EMPTY) {
		pop(stack, &s_top);
	}
>>>>>>> 0bc2fd1b89f987633eb26bd85f2267e45f45945f


}
