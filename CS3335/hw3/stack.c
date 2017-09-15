#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_EMPTY -1


int push(char[], char, int*, int), i;
char pop(char[], int*);
void printstack(char[]);
void makerands();


int push(char stack[], char item, int *top, int max_size) {
	if(*top == max_size - 1) {
		printf("\tnothing happend -- the stack is full!");
		return 0;
	}
	if((*top < max_size) && (*top != max_size - 1)) {
		stack[*top + 1] = item;
		*top = *top+1;
		return 1;
	}
	if((*top < max_size) && (*top == max_size - 1)) {
		stack[*top] = item;
		return 1;
	}
	return -1;
}


char pop(char stack[], int *top) {
	if(*top != -1) {
		char temp = stack[*top];
		*top = *top - 1;
		return temp;
	}
	return '\0';
}



void printstack(char stack[]) {
	puts("\n\t\t~~~~print stack!~~~~\n");
	for(i = 0; i < STACK_SIZE; i++) {
		printf("\t\titem %d is: %c\n", i, stack[i]);
	}//note, the stack only officially includes elements stack[0] - stack[*top]
}


void makerands() {
	puts("\n\n\nlet's make some random values, shall we??\n");
	for(i = 0; i < STACK_SIZE; i++) {
		printf("\n%d", (int)(rand() % 89 + 33));
	}
	puts("\n\n");
}



int main() {	
	char stack[STACK_SIZE];
	int s_top = STACK_EMPTY, *top;
	srand(time(NULL));
	puts("push**************\n\n");
	for(i = 0; i < STACK_SIZE+2; i++) {//try 2 times to push when full...
		char item = (char) rand() % 89 + 33;
		printf("\n\tpushing item: %c", item);
		printf("\n\t\texit value:%d\n", push(stack, item, &s_top, STACK_SIZE));
	}	
	printstack(stack);
	puts("\n\npop**************\n\n");
	top = &s_top;	
	while(s_top != -1) {
		i = *top;
		printf("POP! item %d is: %c\n", i, pop(stack, top));
	}
	printstack(stack);
}
