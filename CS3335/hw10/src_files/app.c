#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "compare.h"
#include "qsort.h"
#include "makeseed.h"
#define DECK_SIZE 52

int i, j;

int main() {

	makeseed();

	card deck[DECK_SIZE];
	const char *face_names[] = { "Ace", "King", "Queen", "Jack", "Ten", "Nine", 
				"Eight", "Seven", "Six", "Five", "Four", "Three", "Two" }; 


	const char *suit_names[] = { "Clubs", "Diamonds", "Hearts", "Spades" };


	//build deck
	for(i = 0; i < DECK_SIZE; i++) {
		deck[i].facevalue = i % 13;
		deck[i].suitvalue = i / 13;
		deck[i].face = face_names[i % 13];
		deck[i].suit = suit_names[i / 13];
	}
	//build deck






	//shuffle deck
	card temp;
	for(i = 0; i < DECK_SIZE; i++) {
		j = rand() % DECK_SIZE;
		temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
	//shuffle deck





	//deal deck
	card hand[10];
	fprintf(stdout, "\nThe following is a 'random' hand of ten cards.\n\n");
	for(i = 0; i < 11; i++) {	
		hand[i] = deck[i];
		fprintf(stdout, "%10s of %-5s\n", hand[i].face, hand[i].suit);
	}
	puts("\n");
	//deal deck





	//sort deck
	qsort(hand, 10, sizeof(card), compare);
	//sort deck




	//print sorted hand
	puts("\n. . . here comes the sorted hand!\n");
	for(i = 0; i < 11; i++) {
		fprintf(stdout, "%10s of %-5s\n", hand[i].face, hand[i].suit);
	}
	puts("\n");
	//print sorted hand




}
