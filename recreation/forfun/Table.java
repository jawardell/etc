/*
This program computes and displays the Cayley Table for 
various operators. The operators accepted by the program are

+ addition
- subtraction
\ division
* muliplication
| logical OR
^ logical XOR
& logical AND

The modulo base determines the demensions of the Cayley table.
For example, the Cayley Table for logical AND modulo 12 
is a 12 by 12 matrix.

Run this program in a bash terminal because it uses ANSI
escape sequences. 

To run, first build the program using the java compiler: 

javac Table.java

then execute using java: 

java Table


Enjoy your tables! :)

*/

import java.util.*;

public class Table {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("\nHello! Please enter your operator!\n");
		String op = scanner.next();
		System.out.print("\nThank you! Now enter your integer modulo base.\n");
		int n = scanner.nextInt();
		System.out.print("\n\tHere is your Cayley table. Enjoy!\n\n\n");
		arrprint(maketable(op,n));
	}

	public static void arrprint(int[][] array) {
		for(int i = 0; i < array.length; i++) {
			for(int j = 0; j < array[0].length; j++) {
				if(j == array[0].length - 1) {
					if(array[i][j] == 0) {
						System.out.printf("\u001b[1;34m%5d\u001b[0m\n", array[i][j]);
						continue;
					}
					System.out.printf("%5d\n", array[i][j]);
				} else {
					if(array[i][j] == 0) {
						System.out.printf("\u001b[1;34m%5d\u001b[0m", array[i][j]);
						continue;
					}
					System.out.printf("%5d", array[i][j]);
				}
			}
		}
	}

	public static int[][] maketable(String op, int n) {
		int[][]	array = new int[n][n];
		switch(op) {
			case "*" :
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					array[i][j] = (i*j) % n;
				}
			}
			break;
			case "+" :
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					array[i][j] = (i+j) % n;
				}
			}
			break;
			case "-" :
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					array[i][j] = (i-j) % n;
				}
			}
			break;
			case "^" :
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					array[i][j] = (i^j) % n;
				}
			}
			break;
			case "|" :
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					array[i][j] = (i|j) % n;
				}
			}
			break;
			case "&" :
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					array[i][j] = (i&j) % n;
				}
			}
			break;
		}
		return array;
	}
}
