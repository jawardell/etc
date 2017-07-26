import java.util.*;
public class Randu {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("V_j+1 = 65539 * V_j mod 2^(31)\n"
				+ "enter V_1:\n");
		Double vj = new Double(scanner.nextDouble());
		System.out.print("\nnow enter j for V_j:\n");
		int j = scanner.nextInt();
		System.out.print(randu(new Double(2),j));
	
	}



	//do randu
	//if j == 0, don't do it
	//else, start from the top
	//then do randu for the next numbmer
	public static Double randu(Double v1, int j) {
		return randu(v1, j, 2);
	}

	public static Double randu(Double v1, int j, int count) {
		if(count == j) {
			return v1;
		}
		else {
			return randu(new Double((65539*v1)%Math.pow(2,31)),j,count++);
		}
	}
	

}
