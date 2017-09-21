#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL  0

double myerror = -1;
void push(double[], double, double**, int);
double pop(double[], double**);

void push(double stack[], double item, double** top, int max_size) {
	if(**top == max_size-1) {
		return;
	}
	if((**top < max_size) && (**top != max_size)) {
		stack[(int)(**top) + 1] = item;
		**top = **top + 1;
		return;
	}
}

double pop(double stack[], double** top) {
	if(**top == -1) {
		**top = STACK_EMPTY; 
		return STACK_EMPTY;
	}
	double temp = stack[(int)**top];
	**top = **top--;
	return temp;
}

int main() {
	puts("we are here!!");
	double s[STACK_SIZE];
	double* s_top = &myerror;
	puts("we are here 2!");

	puts("we are here 3");
	srand(time(NULL));
	puts("made it here 1\n");
	//push until full
	double j;
	while(*s_top != STACK_SIZE-1) {
		j = *s_top;
		double item = (double)(rand()/126.0*33.0);
		printf("pushing item %f into pos %d\n", item, (int)(j+1));
		push(s, item, &s_top, STACK_SIZE);
		
	}	
	puts("made it here 2\n");	
	//pop until empty
	double i = 0;
	while(*s_top != STACK_EMPTY) {
		i = *s_top;
		printf("POP! item %d is: %f\n", (int)i, pop(s, &s_top));
	}

	
	puts("made it here 3\n");
}
