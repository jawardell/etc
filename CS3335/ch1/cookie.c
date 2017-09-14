#include <stdio.h>

// void fortune(char msg[]){
void fortune(char *msg){
	printf("msg: %s\n", msg);
	printf("sizeof(msg): %ld\n", sizeof(msg));

}

int main(void){
	char quote[]="Cookies are good";
	printf("\nsizeof(quote) = %d\n", sizeof(quote));
	fortune(quote);// pass quote into the function as a pointer .. char
		//pointer decay -- char *msg is the aise of the pointer space, 	size of char
		//but we can prevent decay by passing in the size of the array explicitly as 
		//		a local variable
	return 0;
}
