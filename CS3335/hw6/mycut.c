#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char* arguments;
char *bstring, *cstring, *dstring, *fstring, *nstring, *sstring;
int b = 0, c = 0, d = 0, f = 0, n = 0, s = 0, i;
char* file_name;

int main(int argc, char* argv[]) {
	printf("\nargc is %d\n", argc);
	for(i = 1; i < argc; i++) {
		printf("\niteration %d argv[%d] is : %s\n", i, i, argv[i]);
		if(strstr(argv[i], "b")) {
			puts("we are here for b");
			b = 1;
			bstring = argv[i];
			printf("\nbstring is %s\n", bstring);
		}
		if(strstr(argv[i], "c")) {
			puts("we are here for c");
			c = 1;
			cstring = argv[i];
			printf("\ncstring is %s\n", cstring);
		}
		if(strstr(argv[i], "d")) {
			puts("we are here for d");
			d = 1;
			dstring = argv[i];
			printf("\ndstring is %s\n", dstring);
		}
		if(strstr(argv[i], "f")) {
			puts("we are here for f");
			f = 1;
			fstring = argv[i];
			printf("\nfstring is %s\n", fstring);
		}
		if(strstr(argv[i], "n")) {
			puts("we are here for n");
			n = 1;
			nstring = argv[i];
			printf("\nnstring is %s\n", nstring);
		}
		if(strstr(argv[i], "s")) {
			puts("we are here for s");
			s = 1;
			sstring = argv[i];
			printf("\nsstring is %s\n", sstring);
		}

	}
	if(b) {	
		puts("\nconcatenating bstring and arguments\n");
		arguments = bstring;
		printf("\narguments is %s\n", arguments);
	}
	if(c) {
		puts("\nconcatenating cstring and arguments\n");
		if(arguments == NULL) {
			puts("\ninit arguments\n");
			arguments = cstring;
			printf("\narguments is %s\n", arguments);
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, cstring);
			arguments = temp;
			printf("\narguments is %s\n", arguments);
		}
	}
	if(d) {
		puts("\nconcatenating dstring and arguments\n");
		if(arguments == NULL) {
			puts("\ninit arguments\n");
			arguments = dstring;
			printf("\narguments is %s\n", arguments);
		} else {	
			char temp[100];
			sprintf(temp, "%s %s", arguments, dstring);
			arguments = temp;
			printf("\narguments is %s\n", arguments);
		}

	}
	if(f) {
		puts("\nconcatenating fstring and arguments\n");
		if(arguments == NULL) {
			puts("\ninit arguments\n");
			arguments = fstring;
			printf("\narguments is %s\n", arguments);
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, fstring);
			arguments = temp;
			printf("\narguments is %s\n", arguments);
		}	
	}
	if(n) {
		puts("\nconcatenating nstring and arguments\n");
		if(arguments == NULL) {
			puts("\ninit arguments\n");
			arguments = nstring;
			printf("\narguments is %s\n", arguments);
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, nstring);
			arguments = temp;
			printf("\narguments is %s\n", arguments);
		}
	}
	if(s) {
		puts("\nconcatenating sstring and arguments\n");
		if(arguments == NULL) {
			puts("\ninit arguments\n");
			arguments = sstring;
			printf("\narguments is %s\n", arguments);
		} else {	
			char temp[100];
			sprintf(temp, "%s %s", arguments, sstring);
			arguments = temp;
			printf("\narguments is %s\n", arguments);
		}
	}


	if(arguments == NULL) {
		puts("we think arguments is null");
		puts("\ncut command requires arguments. please try again.\n");
	} else {
		printf("\n\tLook, arguments is %s|\n", arguments);
		printf("\nstrlen(arguments) == %lu\n", strlen(arguments));
		char command[100];
		char cutty[] = "cut";
		sprintf(command, "%s %s", cutty, arguments);
		
		puts(command);
		

		
	













	//	if(command == NULL) {
	//		puts("command is null here.");
	//	}
		



		system(command);



	
	}
	return 0;
}