#include "shuffle_deck.h"
#include <stdlib.h>
#include <time.h>
void shuffle_deck(card* const deck) {
	srand(time(NULL));
	//do something in here that shuffles the deck
	int i, j;
	Card temp;
	for(i = 0; i < DECK_SIZE; i++) {
		j = rand() % DECK_SIZE;
		temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}

}



