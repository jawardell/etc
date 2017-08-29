import java.util.*;
public class Anagram  {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);	
		System.out.print("enter word 1:\n");
		ArrayList<Character> word1 = new ArrayList<Character>();
		for(char c : scanner.next().toCharArray()) {
			word1.add(new Character(Character.toLowerCase(c)));
		}
		System.out.print("enter word 2:\n");
		ArrayList<Character> word2 = new ArrayList<Character>();
		for(char c: scanner.next().toCharArray()) {
			word2.add(new Character(Character.toLowerCase(c)));
		}
		Collections.sort(word1);
		Collections.sort(word2);
		System.out.printf("%b\n\n", word1.equals(word2));
	}
}
