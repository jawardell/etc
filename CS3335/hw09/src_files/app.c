#include "cl.h"
//#include "function.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int empty = 1;
typedef struct soldier_type {
	char* name;
	struct soldier_type* next;
} soldier;


void* insert(void* cursor, void* name) {

	soldier* curse = (soldier*)cursor;
	char* name1 = (char*)name;

	soldier* s;

	if((s = malloc(sizeof(soldier))) == NULL) {
		puts("no more room on heap");
		puts("exiting now. . .");
		return NULL;
	}


	//make room on heap for the name
	//then put it on the heap
	//then make the pointer in struct point to it
	s -> name =  strdup(name1);



	//if list empty, there is no cursor
	//make s point to itself
	//then return s as the new cursor
	if(empty) {
		s -> next = s;
		return s;
	}
	
	//otherwise, insert directly after the cursor
	//and return s as the new cursor
	s -> next = curse -> next;
	curse -> next = s;
	return s;
}

void* release(void* cursor) {
	soldier* curse = (soldier*)cursor;
	if(curse == NULL) {
		return NULL;
	}
	soldier* temp = curse -> next;
	soldier* good = temp -> next;
	free(temp -> name);
	free(temp);
	curse -> next = good;
	return curse;
}

void* advance(void* cursor) {	
	soldier* curse = (soldier*)cursor;
	soldier* temp = curse;
	curse = curse -> next;
	soldier* current = curse -> next;
	while((current -> next) != temp) {
		current = current -> next;
	}



	return curse -> next;
}

void print(void* cursor) {
	soldier* curse = (soldier*)cursor;
	fprintf(stdout, "\n%s\n", curse -> name);
}


int main() {
	empty = 1;
	soldier* cursor;
	//cursor -> next = NULL;
	double count = 0;
	char input[100];
	while(fgets(input, sizeof(input), stdin) != NULL) {	
		input[strlen(input)-1] = '\0';	
		count = count + 1;
		cursor = insert(&cursor, input);
		fprintf(stdout, "\ninserted soldier %s \nmem address:%p\n", cursor -> name, cursor);
		empty = 0;
	}
	int i = 1;
	puts("printing soldiers");
	for(i = 0; i < count; i++) {
		fprintf(stdout, "\nsoldier %d: %s \n", i, cursor -> name);
		cursor = advance(&cursor);	
	}


	//kill every seventh one

	while((cursor -> next) != NULL) {
		if(i % 7 == 0) {
			fprintf(stdout, "\n%s died\n", cursor -> name);
		}
		cursor = release(&cursor);
		i++;
	}
	fprintf(stdout, "\n%s survived\n", cursor -> name);

}
