#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_EMPTY -1

int push(char[], char, int*, int);
char pop(char[], int*);
void printstack(char[]);
void makerands();


int push(char stack[], char item, int *top, int max_size) {
	if(*top == max_size - 1) {
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
	return 0;
}


char pop(char stack[], int *top) {
	return '\0';

}



void printstack(char stack[]) {
	int i;
	puts("\n\t\tprint stack!\n");
	for(i = 0; i < STACK_SIZE; i++) {
		printf("\t\titem%d is: %c\n", i, stack[i]);
	}
}


void makerands() {
	puts("\n\nlet's make some random values, shall we??\n\n");
	for(i = 0; i < STACK_SIZE; i++) {
		printf("\n%d\n", (int)(rand() % 89 + 33));
	}
}


int main() {
	
	char stack[STACK_SIZE];
	int s_top = STACK_EMPTY, *top, i;

	srand(time(NULL));

	for(i = 0; i < STACK_SIZE; i++) {

		char item = (char) rand() % 89 + 33;
		printf("\n\tpushing item: %c\n", item);
		printf("\n\t\texit value:%d\n\n", push(stack, item, &s_top, STACK_SIZE));
		

	}

	printstack(stack);
	makerands();

}
