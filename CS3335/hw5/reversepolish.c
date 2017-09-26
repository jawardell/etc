#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0
#define POLAND -500



void push(char[], char, char**, int);
char pop(char[] char**);
int main(), i;



void push(char stack[], char item, char** top, int max_size) {
	//has the pointer been initialized yet?
	if(*top == NULL) {
		*top = stack;
		**top = item;
		return;
	}

	//is the stack full?
	if(myerror == STACK_FULL) {
		return;
	}

	//pushing last item?
	if(*top == (stack + max_size-2)) {
		++(top);
		**top = item;
		myerror = STACK_EMPTY;
		return;
	}

	//pushing normally
	if(*top < (stack + max_value + 1)) {
		++(*top);
		**top = item;
		myerror = NORMAL;
		return;
	}

}

char pop(char[] stack, char** top) {
	char item;
	
	//is the stack empty?
	if((*top == NULL) || (myerror == STACK_EMPTY)) {
		return;
	}
	
	//popping last element? 
	if(*top == stack) {
		item = **top; 
		*top = NULL;
		myerror = STACK_EMPTY;
		return item;
	}

	//popping normally? 
	if((*top > stack) || (myerror != STACK_EMPTY)) {
		item = **top;	
		--(*top);
		myerror = NORMAL;
		return item;
		
	}
}






int main() {
	char stack[], *s_top = NULL, input[], delim[], *c = NULL;



	puts("\n\tenter a reverse polish expression: \n");
	do {
		//use stringtok to get tokens from input
		fgets("%c", input);
		c = strtok(input, delim);
		
		//keep going until one item is left on the stack
		do {
			char* end;
			char item = strtod(*(c+i), &end);
			//push in all NUMBERS!
			if((*(c+i) != end) && (*end == '\0')) { // is a number
				push(stack, , item, delim, ((sizeof(c))/(sizeof(char))));
			}
			i++;

		} while(!POLAND);


	
		
	} while(input != EOF);


}
