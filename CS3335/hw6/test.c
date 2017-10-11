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
		//this won't work because the program doesn't see 
		//input redirection in the argv or argc info
		//	.. i don't think this part is neccesary though.. 
		//i just have to use the system function and pass the 
		//final string concatenation as the argument. . . 
		if(strstr(argv[i], "<")) {
			puts("look where we are! we have a < input redirection");
			puts("proceeding with next character check.. what is the index?");
			printf("\nthe current index is %f, going to check index %f\n", i, i+1);
			if(i != (argc-1)) {
				puts("going to assign filename = argv[i+1]..");
				file_name = argv[i+1];
				printf("\nfile_name is %s\n", file_name);
			}
		}

	}
	if(b){
		puts("\nconcatenating bstring and arguments\n");
		arguments = bstring;
		char temp[100];
		sprintf(temp, "%s ", arguments);
		printf("\ntemp is %s\n", temp);
		arguments = temp;
		printf("\narguments is %s\n", arguments);
	}
	if(c){
		puts("\nconcatenating cstring and arguments\n");
		char temp[100];
		sprintf(temp, "%s %s", arguments);
		printf("\ntemp is %s\n", temp);
		arguments = temp;
		printf("\narguments is %s\n", arguments);
	}
	if(d){
		puts("\nconcatenating dstring and arguments\n");
		arguments = strcat(dstring, "");
		printf("\narguments is %s\n", arguments);
	}
	if(f){
		puts("\nconcatenating fstring and arguments\n");


		printf("\narguments is %s\n", arguments);
	}
	if(n){
		puts("\nconcatenating nstring and arguments\n");


		printf("\narguments is %s\n", arguments);
	}
	if(s){
		puts("\nconcatenating sstring and arguments\n");


		printf("\narguments is %s\n", arguments);
	}

	
	return 0;
}
