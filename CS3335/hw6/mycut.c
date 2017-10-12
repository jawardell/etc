#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


char command[200];
char* arguments;
char *bstring, *cstring, *dstring, *fstring, *nstring, *sstring;
int b = 0, c = 0, d = 0, f = 0, n = 0, s = 0, i;
char* file_name;
int main(int argc, char* argv[]) {
	for(i = 1; i < argc; i++) {	
		if(strstr(argv[i], "b")) {
			b = 1;
			bstring = argv[i];
		}
		if(strstr(argv[i], "c")) {
			c = 1;
			cstring = argv[i];
		}
		if(strstr(argv[i], "d")) {
			d = 1;
			dstring = argv[i];
		}
		if(strstr(argv[i], "f")) {
			f = 1;
			fstring = argv[i];
		}
		if(strstr(argv[i], "n")) {
			n = 1;
			nstring = argv[i];
		}
		if(strstr(argv[i], "s")) {
			s = 1;
			sstring = argv[i];
		}
	}
	if(b) {	
		arguments = bstring;
	}
	if(c) {
		if(arguments == NULL) {
			arguments = cstring;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, cstring);
			arguments = temp;
		}
	}
	if(d) {
		if(arguments == NULL) {
			arguments = dstring;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, dstring);
			arguments = temp;
		}
	}
	if(f) {
		if(arguments == NULL) {
			arguments = fstring;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, fstring);
			arguments = temp;
		}	
	}
	if(n) {
		if(arguments == NULL) {
			arguments = nstring;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, nstring);
			arguments = temp;
		}
	}
	if(s) {
		if(arguments == NULL) {
			arguments = sstring;
		} else {	
			char temp[100];
			sprintf(temp, "%s %s", arguments, sstring);
			arguments = temp;
		}
	}
	if(arguments == NULL) {
		puts("we think arguments is null");
		puts("\ncut command requires arguments. please try again.\n");
	} else {
		char cutty[] = "cut";
		sprintf(command, "%s %s", cutty, arguments);
		puts(command);
		system(command);	
	}
	return 0;
}
