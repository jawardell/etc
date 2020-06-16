# Chapter 1 Learning Materials

Note: I didn't neccessarily write these programs as they were provided by the instructor for learning purposes.

In this portion of the course we learned: 

* pointers!
* pointers as a type
	- pointer to an integer
	- pointer to a char
	- pointer to a function
	- etc.
* reasons to use pointers
	- avoiding copies of data
	- sharing data across functions
* the importance of understanding terminology
	- allows you to communicate better with people
* understanding how data is stored in memory
	- not neccesarily adjacent
* importance of understanding what a pointer is
	- what's the name of the pointer
	- what's the type of the pointer
	- what's the value to which the pointer points
	- what's the address of the value to which the pointer points
	- what's the size of the pointer
	- what's the size of the value to which the pointer references
* to access the address of the pointer, use the & symbol
* to access the value to which the pointer points, use the * symbol
	- this is called de-referencing
* you can capture the numerical value of a pointer's address in a variable
* beware that we don't know if the value of the data a pointer references could change, depending on what system we run our program on
	- that's the beauty of using pointers; they capture the address of the data we intend to manipulate and store them in a variable

* type casting pointers
	- you can change the pointer's type

* mistakes to avoid with pointers
	- double \*p
	- p = 1234
	- you're assigning an actual value to p 
	- meaning that you're using 1234 as the address in memory
* using pointers with arrays
	- don't go out of the array bounds C will let you

