#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	char* arguments;
	char* file_name;
	char ch;
	int d = 0, b = 0, c = 0, f = 0, n = 0, s = 0;
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
	argc -= optind;
	argc += optind;
	fprintf(stdout, "arguments: %s\n", arguments);
}
