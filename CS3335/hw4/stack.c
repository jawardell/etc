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
	puts("we are here in push 1\n");
	if(**top == max_size) {
		return;
	}
	//insert in normal place
	puts("we are here in push 2\n");
	if(**top < max_size) {
		stack[(int)**top] = item;	
		**top++;
		return;
	}
	puts("we are here in push 3\n");
}

double pop(double stack[], double** top) {
	if(**top == -1) {
		return STACK_EMPTY;
	}
	double temp = stack[(int)**top];
	**top--;
	return temp;
}

int main() {
	double s[STACK_SIZE];
	double* s_top = NULL;
	*s_top = STACK_EMPTY;
	srand(time(NULL));
	puts("made it here 1\n");
	//push until full
	while(*s_top != STACK_SIZE-1) {
		double item = (double)(rand()/126.0*33.0);
		printf("pushing item %f\n", item);
		push(s, item, &s_top, STACK_SIZE);
		
	}	
	puts("made it here 2\n");	
	//pop until empty
	int i = 0;
	while(*s_top != STACK_EMPTY) {
		i = *s_top;
		printf("POP! item %d is: %f\n", pop(s, &s_top));
	}

	
	puts("made it here 3\n");	




}
