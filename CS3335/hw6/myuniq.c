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
	int c = 0, d = 0, u = 0;
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

	
	// Figure out whether the input is comng from a file 
	// whose name is provided as a command line argument like
	// 	myuniq -c -d sorteddepts.lst
	// or from the stdin like
	// 	mycut .... | mysort ... | myuniq -c -d
	// ... ...


	if(argc) {
		//process input file argument
		infile = fopen(argv[0], "r");

	} else {
		//piped in as standard input
		infile = stdin;
	}

	char prev[200];
	char curr[200];
	fgets(prev, 200, infile);
	int count = 1;
	
	while (fgets(curr, 200, infile) != NULL) {
		if (strcmp(prev, curr) == 0) {
			count++;
		} else {
			if (c == 1) {	
				printf("%d ", count);
			}
			if ((d != 1) && (u != 1)) {
				printf("%s", prev);
			}
			if ((d == 1) && (u != 1)) {
				if (count > 1) {
					printf("%s", prev);
				} else if(count <= 1) {	
					printf("%s", prev);
				}
			}
			if ((u == 1) && (d != 1)) {
				if (count == 1) {
					printf("%s", prev);
				}	
			}
			count = 1;
			strcpy(prev, curr);
		}
	}

	if (count != 0) {
		if (c == 1) {
			printf("%d ",count);
		}
		if ((d == 1) &&(u != 1)) {
			if (count > 1) {
				printf("%s", prev);
			}
		}
		if ((u == 1) && (d != 1)) {
			if (count == 1) {
				printf("%s", prev);
			}
		}
	}


	
	fclose(infile);


	// You may assume the input data are all sorted.
	// Read and record two lines (if any) from input and compare them.
	// Let's call them prev and curr.
	// If they are the same, update the number of repeats;
	// If they are different, output the prev according the options (-c, -d, or -u)
	// Keey doing this until hitting the end of the input. 
	// ... ...

	return 0;
}
