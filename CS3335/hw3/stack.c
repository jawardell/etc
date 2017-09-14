#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_EMPTY -1







void push(char [], // input/ouput - the stack
	  char,	   // input - data being pushed onto the stack
	  int *,   // input/output - pointer to the ***index*** of the top of stack
	  int);    // constant - maximum size of stack

char		   // output - data being popped out from the stack
     pop(char [],  // input/output - the stack
	 int *);   // input/output - pointer to the ***index*** of the top of stack

void push(char stack[],
	  char item,
	  int* top,
	  int max_size){




/*

stack[]    -- this is the rectangle holding our boxes of chars

item       -- this is the character that we are pushing on to the stack

*top       -- this is a pointer 
		it has an address
		it has a value
			the address ~ where top is 
			the value ~ non-sense memory address 
		use the value of top to get to the current top of the stack


		&top   -- where top is
		*top   -- use the value of top 
				as a memory address
		top    -- the value stored in top
				the memory address of
				the last item in the stack
		why do we need a pointer for this? 

		who knows. 

max_size     -- this is the maximum number of elements that the stack can hold 
*/




	if(*top == max_size - 1) {
		return;
	}
	if((*top < max_size) && (*top != max_size - 1)) {
		stack[*top + 1] = item;
		*top = *top+1;
		return;

	}
	if((*top < max_size) && (*top == max_size - 1)) {
		stack[*top] = item;
		return;

	}












	// Your code here ...
	// Push item to the top of stack if it's not full. 
	// Update the top pointer s/t it points to the index of the new top element on the stack.
	
	
	

	


}

char pop(char stack[],
	 int *top){

	// Your code here ...
	// Pop out the top item on the stack and return it if the stack is not emtpy.
	// Update the top pointer s/t it points to the index of the new top element on the stack. 
	// 
	// Return STACK_EMPTY if the stack is empty. 	

	return STACK_EMPTY;
}

int main(){
	char s[STACK_SIZE];
	int s_top = STACK_EMPTY; // The ***index*** of the top of the stack

	srand(time(NULL));

	// Your code here ...
	// (Using a loop) Keep pushing chars randomly picked between '!'(33) and '~'(126) to the stack
	// until it is full. You will find the function rand() useful here. In case you are not familiar
    // with it, man it.
	// Print each char before each pushing.

	printf("-----------\n");

	// Your code here ...
	// (Using a loop) Keep popping out chars from the stack until it is empty
	// Print each char after each popping. 

	return 0;
}
