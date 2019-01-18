import java.util.regex.*;
import java.util.*;
import java.io.*;

public class Process_TCPProbe_joanne_wardell {
	public static void main(String[] args) {
		try {

			processfile(args);

		} catch(Exception e) {
			if(e instanceof FileNotFoundException)
				System.out.printf("%s%s",
				"\n\tI couldn't find your file..",
				" \n\ntry again.\n");
			System.out.println("\n" + e.getLocalizedMessage()+"\n\n");
		}
	}
	
	static void processfile(String[] args) throws Exception {
		File rawdata = clip(new File(args[0])), 
			 output1 = new File(args[1]),
			 output2 = new File(args[2]),
			 output3 = new File(args[3]);
		
		PrintWriter pw1 = new PrintWriter(output1), 
				pw2 = new PrintWriter(output2), 
				pw3 = new PrintWriter(output3);
		
		String port1 = null, 
			   port2 = null,
			   port3 = null;

		try {
			 port1 = args[1].split("_")[1];
			 port2 = args[2].split("_")[1];
			 port3 = args[3].split("_")[1];
		} catch(Exception e) {
			System.out.println("\n\tPlease include _PORT_ in the file naming convetion:\n"
				+ "\n\tjava Process_TCPProbe_joanne_wardell rawdata "
				+ "chars_PORT_chars chars_PORT_chars chars_PORT_chars\n"
				+ "\n\t... where PORT is the port number. \n");
			System.exit(1);
		}
		
		
		pw1.write(extract(port1, rawdata));
		pw2.write(extract(port2, rawdata));
		pw3.write(extract(port3, rawdata));
		clip(output1);
		clip(output2);
		clip(output3);
	}

	
	static String extract(String port, File file) throws Exception {
		final String patternString = String.format(".*%s.*", port);
		final Pattern pattern = Pattern.compile(patternString);
		String res = "";
		Matcher matcher = null;
		Scanner scanner = new Scanner(file);
		while(scanner.hasNext()) {
			String candidate = scanner.nextLine();
			for(String token : candidate.split(" ")) {
				matcher = pattern.matcher(token);

				if(matcher.matches()) 
					res += String.format("%s\n", candidate.replaceAll(" ", ","));
			}
		}
		scanner.close();
		return res;
	}

	static File clip(File file) throws Exception {
		int len = getnumlines(file);
		String[] string = new String[len];
		Scanner scanner = new Scanner(file);
		int i = 0;
		while(scanner.hasNext())
			string[i++] = scanner.nextLine()+"\n";
		string[len-1] = "";
		String content = "", fname = file.getName();
		file.delete();
		for(String s : string)
			content += s;
		File clipped = new File(fname);
		PrintWriter pw = new PrintWriter(clipped);
		pw.write(content);
		pw.close();
		scanner.close();
		return clipped;
	}

	static int getnumlines(File file) throws Exception {
		int count = 0;
		Scanner s = new Scanner(file);
		while(s.hasNext()) {
			s.nextLine();
			count++;
		}
		return count;
	}
}

