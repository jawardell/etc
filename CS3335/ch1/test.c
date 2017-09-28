#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
	int i;
	char input[200];
	puts("\nenter a string\n");
	fgets(input, sizeof(input), stdin);
	char* tokens[3];
	char* token = strtok(input, " ");
	do {
		tokens[i] = token;
		puts(tokens[i]);
		token = strtok(NULL, " ");
		i++;
	} while(token != NULL);


}
