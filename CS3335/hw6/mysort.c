#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char* arguments;
int b = 0, d = 0, f = 0, g = 0, i = 0, M = 0, n = 0, r = 0, j;
char *bstring, *dstring, *fstring, *gstring, *istring, *Mstring, *nstring, *rstring;


int main(int argc, char* argv[]) {

	for(j = 1; j < argc; j++) {

		if(strstr(argv[j], "b")) {
			b = 1; 
			bstring = argv[j];
		}
		if(strstr(argv[j], "d")) {
			d = 1;
			dstring = argv[j];
		}
		if(strstr(argv[j], "f")) {
			f = 1;
			fstring = argv[j];
		}
		if(strstr(argv[j], "g")) {
			g = 1;
			gstring = argv[j];
		}
		if(strstr(argv[j], "i")) {
			i = 1;
			istring = argv[j];
		}
		if(strstr(argv[j], "M")) {
			M = 1;
			Mstring = argv[j];
		}
		if(strstr(argv[j], "n")) {
			n = 1;
			nstring = argv[j];
		}
		if(strstr(argv[j], "r")) {
			r = 1;
			rstring = argv[j];
		}
	}


	if(b) {
		char temp[100];
		sprintf(temp, "%s ", bstring);
		arguments = temp;
	}
	if(d) {
		if(arguments == NULL) {
			char temp[100];
			sprintf(temp, "%s ", dstring);
			arguments = temp;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, dstring);
			arguments = temp;
		}
	}
	if(f) {
		if(arguments == NULL) {
			char temp[100];
			sprintf(temp, "%s ", fstring);
			arguments = temp;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, fstring);
			arguments = temp;
		}
	}
	if(g) {
		if(arguments == NULL) {
			char temp[100];
			sprintf(temp, "%s ", gstring);
			arguments = temp;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, gstring);
			arguments = temp;
		}
	}
	if(i) {
		if(arguments == NULL) {
			char temp[100];
			sprintf(temp, "%s ", istring);
			arguments = temp;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, istring);
			arguments = temp;
		}
	}
	if(M) {
		if(arguments == NULL) {
			char temp[100];
			sprintf(temp, "%s ", Mstring);
			arguments = temp;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, Mstring);
			arguments = temp;
		}
	}
	if(n) {
		if(arguments == NULL) {
			char temp[100];
			sprintf(temp, "%s ", nstring);
			arguments = temp;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, nstring);
			arguments = temp;
		}
	}
	if(r) {
		if(arguments == NULL) {
			char temp[100];
			sprintf(temp, "%s ", rstring);
			arguments = temp;
		} else {
			char temp[100];
			sprintf(temp, "%s %s", arguments, rstring);
			arguments = temp;
		}
	}


	if(arguments == NULL) {
		puts("\nwe think arguments is null. . . \n");
		puts("\nthe sort command requires arguments, please try again. . . \n");
	} else {
		char command[100];
		char sorty[] = "sort";
		sprintf(command, "%s %s", sorty, arguments);
		system(command);	
	}

}
