package graphs;
import java.util.*;
public class Rands {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("enter number vertices:");
		int numVertices = scanner.nextInt();

		for(int i = 0; i < 40; i++) {
			int rand  = (int)(Math.random() * (numVertices-1) + 1);
			System.out.print(" " + rand + " ");

		}
	}
}
