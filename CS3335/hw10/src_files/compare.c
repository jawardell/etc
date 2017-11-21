#include "compare.h"

#include "struct.h"

int compare(const void* card_a, const void* card_b) {
	if((*(card*)card_a).facevalue - (*(card*)card_b).facevalue) {
		return 	(*(card*)card_a).suitvalue - (*(card*)card_b).suitvalue; 
	
	}

	return (*(card*)card_a).facevalue - (*(card*)card_b).facevalue;
}
