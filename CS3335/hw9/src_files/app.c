#include "cl.h"
//#include "function.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct soldier_type {
	char* name;
	struct soldier_type* next;
} soldier;


void* insert(void* cursor, void* name) {
	soldier* s;
	soldier* curse = (soldier*)cursor;
	char* name1 = (char*)name;
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
	if (curse -> next == NULL) {
		s -> next = s;	
		return s;
	}

	//otherwise, insert directly after the cursor
	//and return s as the new cursor
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
	soldier* temp = curse -> next;
	curse -> next = temp -> next;
	return curse;
}

void print(void* cursor) {
	soldier* curse = (soldier*)cursor;
	soldier* temp = curse -> next;
	fprintf(stdout, "\n%s\n", temp -> name);
}


int main() {

	soldier* cursor;


	char name[100];
	while(fgets(name, sizeof(name), stdin) != NULL) {
		insert(&cursor, &name);
	}

	//kill every seventh one
	int i = 1;

	while((cursor -> next) != NULL) {
		soldier* c = cursor -> next;
		if(i % 7 == 0) {
			fprintf(stdout, "\n%s died\n", c -> name);
		}
		advance(&cursor);
		i++;	
	}
	fprintf(stdout, "\n%s survived\n", cursor -> name);

}
