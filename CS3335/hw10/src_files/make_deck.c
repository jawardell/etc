#include "makedeck.h"

void make_deck(card* const deck, card* face[], card* suit[]) {

	//do something in here that makes the deck
	int i;
	for(i = 0; i < DECK_SIZE-1; i++) {
		deck[i].face = face[i%13];
		deck[i].suit = suit[i/13]
	}

}
