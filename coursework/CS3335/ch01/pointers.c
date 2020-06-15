#include <stdio.h>

int main(){
	double d=10.34, *p;//what is p? --- p is a pointer to a double



	p = &d;  //the value of p is the address of d
	printf("d=%lf\n", *p);
	printf("sizeof(d)=%ld\n", sizeof(*p));
	printf("p=%p\n", p);
	printf("sizeof(p)=%ld\n", sizeof(p));
	printf("address of p=%p\n", &p);

	// printf("\nProvid a new value for d: ");
	// scanf("%lf", &d);
	// scanf("%lf", p);
	*p = 30.2;
	printf("d=%lf\n", *p);
	printf("sizeof(d)=%ld\n", sizeof(*p));
	printf("p=%p\n", p);
	printf("sizeof(p)=%ld\n", sizeof(p));
	printf("address of p=%p\n", &p);
	
	p=NULL;






	//every var has to have a name -- d
	//every var has to have a type -- double
	//every var has to have a value -- 10.34
	//every var has an address -- 
	//memory is a table 
	//the best way for us to understant the memory is to use a table
	//tabular memory
	//d is in the table... 
	//..and there are other slots
	//typlically we don't care avout the actual address value itself
	//...the next value in memory
	// the next slot in memroy must depend on the size of the one previous
	//8 this is called a word




	//address of current minus that size
	//410F
	//after it is size plus 410F
	//before it is size minus 410F



	//the asterik means that this is a pointer valu e
	//grab the address of seomthing eslse, then assign it to p
	//the value of p will be fixed,
	//it won't be garbage any more 
	//              

	//dereferenceing the pointer and following the target
	//this is waht happensn when you see *  
	//leaving the pointer 
	//folloqing the line
	//and arriving at the target




	//what if you print the value of p itself
	//most of the time we don't care what the value of p is
	//waht if you insit on printing out p 
	//this value that no one understand 
		//then you will be printing out the poiter value itself,.. something we don;t usualy do
	//right associative

	//    f =  *&d

			//do the one on the right first!!! 
	//1 grab the address of d
 
	//then you use that value as a pointer 


		//so     f =  (&d)
	//grab the pointer value of d
	//then DEREFERENCE * the pionter value and follow the line to the target


	//..so essentially, this is like assisnging the value of d to f.


}
