#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

FILE* infile;
int argc_copy;
int main(int argc, char* argv[]){
	// Get the options (-c, -d, -u, some combinations of them, or none at all)
	// ... ...
	char ch;
	argc_copy = argc;
	int c = 0, d = 0, u = 0;
	printf("\nargc value pre processing is %d\n", argc);
	while((ch = getopt(argc, argv, "cdu")) != EOF) {
		switch(ch) {
			case 'c' :
				c = 1;
				break;
			case 'd' : 
				d = 1;
				break;
			case 'u' : 
				u = 1;
				break;
		}
	}
	argc -= optind;
	argv += optind;

	if(u && d) {
		puts("\noops, can't use both -u and -d\n");
		puts("\nhow can you request duplicates and uniqueness?\n");
		puts("\ntry again.\n");
		exit(1);
	}
	
	if(c) {
		puts("we have a c");
	}
	if(d) {
		puts("we have a d");
	}
	if(u) {
		puts("we have a u");
	}
	printf("\nargc value post processing is: %d\n", argc);
	printf("\nargv[0] -- %s\n", argv[0]);
	
	// Figure out whether the input is comng from a file 
	// whose name is provided as a command line argument like
	// 	myuniq -c -d sorteddepts.lst
	// or from the stdin like
	// 	mycut .... | mysort ... | myuniq -c -d
	// ... ...


	if(argc) {
		//process input file argument
		printf("\nfilename is %s \n", argv[0]);
		infile = fopen(argv[0], "r");

	} else {
		//piped in as standard input
		infile = stdin;
	}

	char line_one[200];
	char line_two[200];
	fgets(line_one, 200, infile);
	int count = 1;
	
	while(fgets(line_two, 200, infile) != NULL) {	
		if(strcmp(line_one, line_two)) {
			count++;
		} else {
			if(d && u) {
				count = 0;
				break;
			}
			if(c) {
				printf("%d", count);
			}
			if(!d && u) {
				if(count == 1) {
					printf("%s", line_one);
				} else {
					printf("\n");
				}
			}
			if(d && !u) {
				if(count > 1) {
					printf("%s", line_one);
				} else {
					printf("\n");
				}
			}
			count = 1;
			strcopy(line_one, current);
		}
		if(count != 0) {
			if(c) {
				printf("%d", count);
			}
			if(d && !u) {
				if(count > 1) {
					printf("%s", line_one);
				}
				if(u && !d) {
					if(count == 1) {
						printf("%s", line_one);
					}
				}
			}
		}
	}



	// You may assume the input data are all sorted.
	// Read and record two lines (if any) from input and compare them.
	// Let's call them prev and curr.
	// If they are the same, update the number of repeats;
	// If they are different, output the prev according the options (-c, -d, or -u)
	// Keey doing this until hitting the end of the input. 
	// ... ...

	return 0;
}
