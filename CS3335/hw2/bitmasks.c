#include <stdio.h>
#include <limits.h>
#include <math.h>


void bit_print(int);
int pack(char, char, char, char);
char unpack(int, int);
unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invertbits(unsigned x, int p, int n);


unsigned setbits(unsigned x, int p, int n, unsigned y) {
	double ybm = 0; 
	double i; 
	for(i = 0; i < n; i++) {
		ybm += pow(2,i); //positions of y bits
		printf("ybm is %d\n\n", ybm);
	}
	unsigned ybm1 = (unsigned)ybm;
	unsigned yex = y&ybm1; // GRAB bits from y
	printf("yex is %u\n\n", yex);
	double xbm = 0;
	double p2 = (double)p;
	unsigned xcopy = x;
	for(i = 0; i < p2-n-1; i++) {
		xbm += pow(2,p2-i); //postions of x bits
		printf("xbm is %d\n\n", xbm);
	}	
	unsigned xbm1 = (unsigned)xbm;
	xbm1 = xbm1^xcopy;// find positions in x
	printf("xbm1(postion finder) is: %u\n\n", xbm1);
	int pos = 0;
	for(i = 0; i <= pos; i++) {
		if(pos == n-1) {
			break;
		}
		yex<<1;//shift y mask into position
		pos++;
	}
	printf("yex post shift is: %u\n\n", yex);
	printf("xcopy | yex is: %u\n\n", xcopy | yex);
	return xcopy | yex;//set and return bits
}


unsigned invertbits(unsigned x, int p, int n) {
	//follow the formula to make the mask
	double p2 = (double)p;
	double i;	
	double mask  = 0;	
	for(i = 0; i < p2-n-1; i++) {
		mask += pow(2.0,p2-i);
	}	
	unsigned m = (unsigned)mask;	
	return x^m;
}


void bit_print(int a){
	int i;
	int n = sizeof(int) * CHAR_BIT;
	int mask = 1 << (n-1); // mask = 100...0
	

	invertbits(14955555, 7, 4);
	for (i=1; i<=n; i++){
		putchar(((a & mask) == 0)? '0' : '1');
		a <<= 1;
		if (i % CHAR_BIT == 0 && i < n)
			putchar(' ');
	}
	putchar('\n');
}

int pack(char a, char b, char c, char d){
	int p=a;
	p = (p << CHAR_BIT) | b;
	p = (p << CHAR_BIT) | c;
	p = (p << CHAR_BIT) | d;
	return p;
}

char unpack(int p, int k){    // k=0, 1, 2, or 3
	int n = k * CHAR_BIT; // n = 0, 8, 16, 24
	unsigned mask = 255;  // mask = low-order byte
	
	mask <<= n;
	return ((p & mask) >> n);	
}

// getbits() extracts n bits from position p(start counting from the right-most bit) in x
unsigned getbits(unsigned x, int p, int n){
	unsigned temp = x >> (p+1-n);
	
	unsigned mask = 0;
	mask = ~mask;
	mask = mask << n;
	mask = ~mask;

	return temp & mask;
	// return (x >> (p+1-n)) & ~(~0<<n);
}

int main(){
	int x = 19;
	printf("\n\tsetbits: x = 2004384122, y = 1634952294, p = 20, n = 4\t\t%u\n\n", setbits(2004384122, 20, 4,  1634952294 ));	
	printf("The binary rep. of %d is:\n", x);
	bit_print(x);

	int p=pack('w', 'x', 'y', 'z');
	printf("\n'w', 'x', 'y', and 'z' packed together is equal to %d. Its binary rep. is:\n", p);
	bit_print(p);
	printf("calling unpack(p, 0) to extract the byte # 0 from the right:\n");
	bit_print(unpack(p, 0));
	printf("calling unpack(p, 1) to extract the byte # 1 from the right:\n");
	bit_print(unpack(p, 1));
	printf("calling unpack(p, 2) to extract the byte # 2 from the right:\n");
	bit_print(unpack(p, 2));
	printf("calling unpack(p, 3) to extract the byte # 3 from the right:\n");
	bit_print(unpack(p, 3));

	unsigned result = getbits(p, 20, 7);
	printf("\ncalling getbits(p, 20, 7) to extract 7 bits from bit # 20 returns %d:\n", result);
	bit_print(result);

	return 0;
}

