#include <stdio.h>
#include <stdlib.h>

int main(){
	char card_name[3]; // make room for sentinel value, \0, this is ASCII value of zero. (c is dumb..)
	//why do we need 3 spaces
		//need room for single letter for digits 2-9 and letters for King, Queen, and Jack, Ace
		//BUT, we also need room for two letters for the number 10
		//and we need room for the sentinel character \0
		//soo.. we need three spaces: it is your reponsibility to decide and manage our space in C...
	int count = 0;
	while (card_name[0]!='X'){
		puts ("Enter the card_name: ");
		scanf("%2s", card_name); //this is a FORMAT SCAN!! only give me two characters! ;)
		int val = 0;
		switch(card_name[0]){
			case 'K':
			case 'Q':
			case 'J':
				val = 10;
				break;
			case 'A':
				val = 11;
				break;
			case 'X':
				continue;
			default:
				val = atoi(card_name);
				if ((val<1) || (val>10)){
					puts("I don't understand that value!");
					continue;
				}

		}
		if ((val > 2) && (val < 7)){
			count ++;
		}else if (val == 10) {
			count --;
		}

		printf("Current count : %i\n", count);
	}
	return 0;

}
