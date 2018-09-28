/**
* Print's the powerset of a set defined in a text file
* argument. Make sure to separate each element by a comma. 
* The powerset is printed in decending order. 
* Have a nice day!
*/
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Print256 {
	
	public static void main(String[] args) {
		ArrayList<String[]> sets = new ArrayList<>();
		for(String s : args) {
			try {
				String res = "";
				File file = new File(s);
				Scanner scanner = new Scanner(file);
				while(scanner.hasNext()) {
					res += scanner.nextLine();
				}
				res.replaceAll("\n", "");
				sets.add(res.split(","));
				scanner.close();
			} catch(Exception e) {
				if(e instanceof FileNotFoundException) {
					FileNotFoundException f = (FileNotFoundException)e;
					System.out.println("\n\tI don't see your file...\n\ntry again\n");
					System.out.println(f.getLocalizedMessage());
				}
			}
		}
		
		
		try {
			int count = 0;
			for(String[] set : sets)
				getPowerSet(set, String.format("pset%d.csv", count++));
			
		} catch(Exception e) {
			e.printStackTrace();
		}
		
	}
	
	static void getPowerSet(String[] array, String filename) throws Exception {
		File file = new File(filename);
		PrintWriter pw = new PrintWriter(file);
		String fin = "";
		for(int i = (int)Math.pow(2, array.length)-1; i > 0; i--) {
			ArrayList<Integer> powers = getlist(i);
			for(Integer n : powers) {
				if (n == -1) {
					fin += ",";
				} else {
					fin += String.format("%s,", array[n]);
				}
			}
			fin += "\n";
		}
		for(int i = 0; i < array.length; i++)
			fin += ",";
		fin += "\n";
		pw.write(fin);
		pw.close();
	}
	
	
	static ArrayList<Integer> getlist(int n) {
		String res = "";
		int count = 0;
		while(n > 0) {
			if((1&n) == 1) {
				res += count + " ";
			} else {
				res += -1 + " ";
			}
			n = n >> 1;
			count++;
		}
		String[] a = res.split(" ");
		ArrayList<Integer> list = new ArrayList<>();
		for(int i = 0; i < a.length; i++)
			list.add(Integer.parseInt(a[i]));
		
		return list;
	}
	
}
