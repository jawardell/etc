#include <stdio.h>
#include <stdlib.h>
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
	} else if (card_name[0] == 'J') {
		val = 10;
	} else if (card_name[0] == 'A') {
		val = 11;
	} else {
		val = atoi(card_name);
	}
	printf("The card value is: %i\n", val);

	if(val >= 3 &&  val <= 6)
		puts("The count went up!");
	else if(atoi(card_name) == 10)
		puts("The count did something, bectheuse it's the ten.");
	else
		puts("The count went down.");
	return 0;
	
}
