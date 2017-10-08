#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	// Gather the command line arguments (options included) and combine them in one string.
	// Create a command string that begins with "cut ", followed by the argument string above. 
	// Finally replace the hardwired "cut ...." in the following system call with your command string.  
	char arguments[30];
	char* dargs;
	char* fargs;
	char* bargs;
	char* cargs;
	char ch;
	char* string;
	int i;
	
	while((ch = getopt(argc, argv, "d:f:b:c:ns")) != EOF) {
		switch(ch) {
			case 'd' :
				puts("here in case d");
				//dargs = optarg;
				dargs = strcat(optarg, "d");
				sprintf(arguments, "%s", dargs);
				printf("dargs: %s\narguments: %s\n", dargs, arguments);
				continue;	
			case 'f' :
				puts("here in case f");
				fargs = optarg;
				sprintf(arguments, "-%s ", strcat(&ch, dargs));
				continue;
			case 'b' :
				puts("here in case b");
				bargs = optarg;
				sprintf(arguments, "-%s", strcat(&ch, bargs));
				continue;
			case 'c' :
				puts("here in case c");
				cargs = optarg;
				sprintf(arguments, "-%s", strcat(&ch, cargs));
				continue;
			case 'n' :
				puts("here in case n");
				string =  "n";
				sprintf(arguments, "-%s", string);
				continue;
			case 's' :
				puts("here in case s");
				string = "s";
				sprintf(arguments, "-%s", string);
				continue;
			default :
				puts("\n\tInvalid argument.\n");
		}
	}
	puts("at end of loop");
	argc -= optind;
	argv += optind;
	puts("last about to print. . . ");
	fprintf(stdout, "\n%s\n", arguments);
	return 0;
}
