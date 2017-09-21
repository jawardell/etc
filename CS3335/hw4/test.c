#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	int temp = &"hello" - &"test";
	printf("%d", temp);

}
