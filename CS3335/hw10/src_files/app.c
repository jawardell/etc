#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define DECK_SIZE = 52


typedef struct {
	const char *face;
	const char *suit;
} card;


void make_deck(card* const deck, card* face[], card* suit[]);
void shuffle_deck(card* const deck);
void deal_deck(const card* const);
void compare(const void*, const void*);
void qsort(void* base, size_t nmemb, size_t size, 
	int(*compare)(const void*, const void*));



int main() {



}
