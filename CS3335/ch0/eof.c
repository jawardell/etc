#include <stdio.h>
#include <limits.h>

int main(){
	// Won't work
	 unsigned char c;



//why?? 

//input is read in 
//type that varible as an int or signed char
//DO NOT type is as unsigned char because control d will NOT allow the program to exit!!!!

//unsigned chars are not automatically promoted to int type!!!!!!!



//sizeof(EOF)   , make this function your friend!!! bffls <3 [sizeof()]



	// Will work. signed char, char will do too.
	//int c;

	// To find out if char is signed or unsigned by default
	printf ("CHAR_MIN=%d\n", CHAR_MIN);

	printf("sizeof(EOF) = %ld\n", sizeof(EOF));

	do{
		c=getchar();
	}while (c!=EOF);

	return 0;
}
