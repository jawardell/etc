#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "make_deck.h"
#include "shuffle_deck.h"
#include "deal_deck.h"
#include "compare.h"
#include "qsort.h"
#define DECK_SIZE = 52


typedef struct {
	const char *face;
	const char *suit;
} card;




int main() {

	card deck[DECK_SIZE];
	const char *face[] = {"Ace", "King", "Queen", "Jack", "Ten", "Nine", 
		"Eight", "Seven", "Six", "Five", "Four", "Three", "Two", "One"};
	const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	srand(time(NULL));
	make_deck(deck, face, suit);
	suffle(deck);
	int i;
	for(i = 0; i < 11; i++) {
		printf("%10s of %-10s\n", deck[i].face, deck[i].suit);
	}
	puts("\n");

}
