#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <strings.h>

int f(int);
int main(void){
	int i, t, funval;
	
    	// Make sure to change low and high when testing your program
	int low=-3, high=11;
	for (t=low; t<=high;t++){
		printf("f(%2d)=%3d\n",t,f(t));
   	 }

	// Your code here...
	

	int min = INT_MAX;
	int max = INT_MIN;
	
	for(i = low; i <= high; i++) {
		if(f(i) < min) {
			min = f(i);
		}
		if(f(i) > max) {
			max = f(i);
		}
	}
	printf("min = %d\nmax = %d\n", min, max);
	//do the x axis here, incriment by five to high
	int count = min;
	printf("%d\n", (max-min)/5);
	printf("    ");

	for(i = 0; i <= ((max-min)/5)+5; i++) {
		if(count < 0) {
			printf("%5d", count);
		}
		if(count >= 0) {
			printf(" %4d", count);
		}
		
		count += 5;
	}
	puts("\n");
	count = low;
	printf("\t");
	for(i = 0; i <= ((max-min)/5)+5; i++) {
		printf("|    ");
	}
	puts("\n");
	
	char line[(max-min) + 2];
	for(i = 0; i < (sizeof(line)/sizeof(char)) ; i++) {
		line[i] = ' ';
	}

	t = low;

	for(i = low; i <= high; i++) {
		if(f(t) == min) {
			line[0] = '*';
			line[1] = '\0';
			printf("t = %2d %s\n", t, line);
			line[0] = ' ';
			line[1] = ' ';
			t++;
			continue;
		}
		
		if(f(t) == max) {
			line[max-min] = '*';
			line[max-min+1] = '\0';
			printf("t = %2d %s\n", t, line);
			line[max-min] = ' ';
			line[max-min+1] = ' ';
			t++;
			continue;

		}
		if(f(t) < max) {
					
			line[f(t)-min] = '*';
			line[f(t)-min + 1] = '\0';
			printf("t = %2d %s\n", t, line);
			line[f(t)-min] = ' ';
			line[f(t)-min + 1] = ' ';
			t++;
		}
		if(f(t) > max) {
			line[f(t)+min] = '*';
			line[f(t)+min+1] = '\0';
			printf("t = %2d %s\n", t, line);
			line[f(t)+min] = ' ';
			line[f(t)+min+1] = ' ';
			t++;
		}
	}









		

	

	return 0;
}


int f(int t){
    // example 1
	return (t*t-4*t+5);
    
    // example 2
//  return (-t*t+4*t-1);
    
    // example 3
//  return (sin(t)*10);
    
    // example 4
	// if (t>0)
	//	return t*2;
	// else
	//	return t*8;
}
