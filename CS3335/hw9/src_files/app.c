#include "cl.h"
//#include "function.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct soldier_type {
	char* name;
	soldier_type* next;
} soldier;


void* insert(void* cursor, void* name) {
	soldier s;
	if((s = malloc(sizeof(soldier))) == NULL) {
		puts("no more room on heap");
		puts("exiting now. . .");
		return 1;
	}

	//make room on heap for the name
	//then put it on the heap
	//then make the pointer in struct point to it
	s -> strdup(name);


	//if list empty, there is no cursor
	//make s point to itself
	//then return s as the new cursor
	if (cursor -> next == NULL) {
		s -> next = s;	
		return s;
	}

	//otherwise, insert directly after the cursor
	//and return s as the new cursor
	cursor -> next = s;
	return s;	

}

void* release(void* cursor) {
	if(cursor == NULL) {
		return NULL;
	}
	soldier* temp = cursor -> next;
	soldier* good = temp -> next;
	free(temp -> name);
	free(temp);
	cursor -> next = good;
	return cursor;
}

void* advance(void* cursor) {
	soldier* temp = cursor -> next;
	cursor -> next = temp -> next;
	return cursor;
}

void print(void* cursor) {
	soldier* temp = cursor -> next;
	fprintf(stdout, "\n%s\n", temp.name);
}


int main() {

	soldier* cursor;


	char name[100];
	while(fgets(name, sizeof(name), stdin) != NULL) {
		insert(cursor, name);
	}

	//kill every seventh one
	int i = 1;

	while((cursor -> next) != NULL) {
		if(i % 7 == 0) {
			fprintf(stdout, "\n%s died\n", c.name);
		}
		advance(cursor);
		i++;	
	}
	fprintf(stdout, "\n%s survived\n", cursor.name);

}
