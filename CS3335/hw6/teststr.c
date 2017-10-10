#include <string.h>
#include <stdlib.h>
#include <stdio.h>



//char string[15];
//int main() {
//	sprintf(string, "hello");
//	printf("%s", string);	
//	sprintf(string, " friend");
//	printf("%s", string);	
//}


//char string[] = "hello";
//int main() {
//	printf("%s\n", string);
//	sprintf(string, "friend");
//	printf("%s", string);
//	puts("\n\tthis doesn't fucking work");
//}



/*
 *some testing.. 
 *

char string[100] = "i will be gone";
//char* const string;
int main() {
	sprintf(string, "hey what's up boo? look at the space we have here ");
	printf("%s\n", string);
	char* temp = "fuck u";
	sprintf(string, temp);
	printf("%s\n", string);
	char* test = " friend";
	sprintf(string, test);
	printf("%s", string);
}
 *
 *
 *
 * */




char* arguments = "some bullshit";
int main() {
	puts("wtf");
	char empty[0];puts("ok");
	sprintf(empty, "%s _", arguments);puts("more ok");
	puts(empty);
	printf("%s", empty);	
	puts(empty);
}
