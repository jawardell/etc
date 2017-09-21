#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mymemmove(void *, const void *, size_t);
int i, j;


int main(int argc, char *argv[])
{
  char x[30] = "That's not what I said.";
  char a[30] = "The original contents of a.";

  // "src" does not overlap "to"
  mymemmove(a, x, 24);
  puts(a); // prints "That's not what I said."

  // end of "to" overlaps beginning of "src"
  mymemmove(a+7, a+11, 13);
  puts(a); // prints "That's what I said."

  // end of "src" overlaps beginning of "to" 
  mymemmove(a+11, a+7, 13);
  puts(a); // prints "That's whatwhat I said."

  // "src" does not overlap "to"
  mymemmove(a+7, "not ", 4);
  puts(a); // prints "That's not what I said."

  double y[10], y_verify[10]; 

  int i; 
  for (i=0; i<10; i++){
    y[i] = (double)i/2;
    y_verify[i] = (double)i/2;
  }
  for (i=0; i<10; i++){
    printf("y[%2d] = %lf\t\ty_verify[%2d] = %lf\n", i, y[i], i, y_verify[i]);
  }

  printf("--------\n");

  // "src" does not overlap "to"
  mymemmove(y, y+6, sizeof(double) * 3);
  memmove(y_verify, y_verify+6, sizeof(double) * 3);
  for (i=0; i<10; i++){
    if(y[i]!=y_verify[i]){
      printf("Error: \"src\" does not overlap \"to\"\n");
      return 1;
    }
  }

  for (i=0; i<10; i++){
    printf("y[%2d] = %lf\t\ty_verify[%2d] = %lf\n", i, y[i], i, y_verify[i]);
  }
  printf("Pass: \"src\" does not overlap \"to\"\n"); // Expected output
  printf("--------\n");

  // end of "to" overlaps beginning of "src"
  mymemmove(y+2, y+4, sizeof(double) * 4);
  memmove(y_verify+2, y_verify+4, sizeof(double) * 4);
  for (i=0; i<10; i++){
    if(y[i]!=y_verify[i]){
      printf("Error: end of \"to\" overlaps beginning of \"src\"\n"); 
      return 1;
    }
  }

  for (i=0; i<10; i++){
    printf("y[%2d] = %lf\t\ty_verify[%2d] = %lf\n", i, y[i], i, y_verify[i]);
  }
  printf("Pass: end of \"to\" overlaps beginning of \"src\"\n"); // Expected output
  printf("--------\n");

  // end of "src" overlaps beginning of "to" 
  mymemmove(y+4, y+2, sizeof(double) * 4);
  memmove(y_verify+4, y_verify+2, sizeof(double) * 4);
  for (i=0; i<10; i++){
    if(y[i]!=y_verify[i]){
      printf("Error: end of \"src\" overlaps beginning of \"to\"\n"); 
      return 1;
    }
  }

  for (i=0; i<10; i++){
    printf("y[%2d] = %lf\t\ty_verify[%2d] = %lf\n", i, y[i], i, y_verify[i]);
  }
  printf("Pass: end of \"src\" overlaps beginning of \"to\"\n"); // Expected output

  getchar();
  return 0;
}

void *mymemmove(void *to, const void *src, size_t n){
//  return memmove(to, src, n);
// Replace the return statement above with your implementation of the function...



	char *to_1 = (char*)to;//we now know it's not a void, but a char(pointer)!
	char *src_1 = (char*)src;//complete the casting.. 


	char safe_to[n];
	char safe_src[n];
	for(i = 0; i < n; i++) {//put TO into safety array -- could be an anonymous string literal...
		safe_to[i] = *(to_1 + i); 
	}


	for(i = 0; i < n; i++){//put SRC into safety array -- could be an anonymous string literal...
		safe_src[i] = *(src_1 + i);
	}


	
	int toDiff = safe_to - safe_src; // compute the DIFFERENCE between the .. 
	int srcDiff = safe_src - safe_to;  //memory addresses of the SRC and TO and TO and SRC
	if(abs(toDiff) < n) {//min distance not satisfied
	

		//this is redundant, but listed it for better explainability
		if(toDiff < 0) {//to overlaps src
			for(i = 0; i < n; i++) {
				*(safe_to + i) = *(safe_src + i);
			}
			printf("\t\tmin dist not satisfied, in here!!! abs((toDiff) = %d)\n", abs(toDiff));	
			return NULL;
		}

		if(srcDiff < 0) {//from overlaps to
			printf("\t\t woah, we are in here..... from over to...  abs((toDiff) = %d)\n", abs(toDiff));	
			for(i = 0; i < n; i++) {
				*(safe_to + i) = *(safe_src + j);
				j--;
			}
			return NULL;
		}


	}
	

	for(i = 0; i < n; i++) {//to and src are independent
		*(safe_to + i) = *(safe_src + i);
	}
	printf("\t\twhat is src pointer value?? to pointer is: %p\tsrc pointer is: %p...\n", to , src);
	printf("\t\tmin dist IS satisfied, over here!!! abs((toDiff) = %d)\n", abs(toDiff));
}

