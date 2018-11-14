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
					System.out.printf("%5d\n", array[i][j]);
				} else {
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
					array[i][j] = (i*j) % n;
				}
			}
			break;
		}
		return array;
	}
}
