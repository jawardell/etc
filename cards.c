#include <stdio.h>
#inlude <stdlib.h>
int main()
{
	char card_name[3];
	puts("Enter the card_name");
	scanf("%2s", card_name);
	int val = 0;
	if (card_name[0] == 'K') {
		val = 10;
	} else if (card_name[0] == 'Q') {
		val = 10;
	} else if (card_name == 'J') {
		val = 10;
	} else if (card_name == 'A') {
		val = 11;
	} else {
		val = atoi(card_name);
	}
	printf("The card value is: %i\n", val);
	return 0;
	
}
