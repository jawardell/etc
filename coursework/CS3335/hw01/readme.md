# Homework Assignment 1

### Assignment Purpose

The purpose of this assignment was to write a program to find the

* first non-repeated element
* last non-repeated element
* first repeated element
* last repeated element 

in an array consisting of 

* single-digit or double-digit
* non-negative numbers 
* ranging from 0-99

in an O(n) time complexity.

### Solution Algorithm

The program uses a hash table from 0-99. 

It iterates forward over the array to find the first non-repeated and repeated  element. 

It iterates backward through the array to find the last non-repeated and repeated element. 

The `foundrep` and `firstnonrep` are variables which will contain the value which repeats or doesn't repeat itself in the array. 

The `foundrep` and `foundnonrep` are integer flags which are non zero if the repeated or non repeated value is located in the array, respectively.

Similarly, on the second pass through the array, which is backwards,  the `foundrep` and `foundnonrep` flags are reset to use again for finding the last repeated and last non-repeated values in the array. 

The `lastrep` and `lastnonrep` are variables which will hold the values of the last repeating and last non-repeating element in the array repectively.

The program operates in O(n) time complexity because there is one for-loop which iterates to the length of the list, which is a variable number, n.
