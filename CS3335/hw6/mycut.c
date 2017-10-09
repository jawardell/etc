#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

<<<<<<< HEAD
int main(int argc, char *argv[]){
	char* arguments;
	char ch;
	while((ch = getopt(argc, argv, "d:b:c:f:ns")) != EOF) {
		switch(ch) {
			case 'd' :
				puts("we are here in case d");
				arguments = strcat(optarg, "d");
				puts("case d successful");
				continue;	
			case 'b' :
				puts("we are here in case b");
				arguments = strcat(optarg, "b");
				puts("case b successful");
				continue;
			case 'c' :
				puts("we are here in cse c");
				arguments = strcat(optarg, "c");
				puts("case c successful");
				continue;
			case 'f' :
				puts("we are here in case f");
				arguments = strcat(optarg, "f");
				puts("case f successful");
				continue;
			case 'n' :
				puts("we are here in case n");
				arguments = strcat(optarg, "n");
				puts("case n successful");
				continue;
			case 's' :
				puts("we are here in case s");
				arguments = strcat(optarg, "s");
				puts("case s successful");
				continue;
			default : 
				puts("invalid argument");
		}
	}
	fprintf(stdout, "arguments: %s\n", arguments);
=======
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
>>>>>>> c939009b6d43eff47e042eba29f1416a67f17039
}

