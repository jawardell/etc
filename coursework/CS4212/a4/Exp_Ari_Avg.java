import java.math.BigDecimal;

import java.io.File;  
import java.io.PrintWriter;
import java.io.FileNotFoundException;  
import java.util.Scanner;  
import java.util.regex.Matcher;  
import java.util.regex.Pattern;  
//import java.util.ArrayList; 
import java.io.IOException;  
import java.util.Random;

public class Exp_Ari_Avg{  	 
	 public static BigDecimal expAvg(BigDecimal preExpAvg, BigDecimal newSample){
		 //compute exponetial average
		 final BigDecimal alpha = new BigDecimal(0.125);

		 BigDecimal res = new BigDecimal(1).subtract(alpha);
		 res = res.multiply(preExpAvg);
		 res = res.add(alpha.multiply(newSample));

		 return res;
	 }
	 
	 public static BigDecimal ariAvg(BigDecimal preAriAvg, BigDecimal newSample, int n){
		 //compute arithmetic average
		 BigDecimal res = preAriAvg.multiply(new BigDecimal((n - 1)/(n*1.0)));
		 res = res.add(newSample.multiply(new BigDecimal(1/(n*1.0))));

		 return res;
	 }
	 
	 public static void sampleRTT2EstimatedRTT(Scanner in, PrintWriter out)throws IOException{ 

		BigDecimal prev1 = new BigDecimal(Math.random() * 101 + 1);
		prev1 = prev1.divide(new BigDecimal(1000.0));
		BigDecimal prev2 = new BigDecimal(prev1.doubleValue());
		prev2 = prev2.divide(new BigDecimal(1000.0));


		BigDecimal curr = null;
		int n = 1;
		while(in.hasNext()) {

			 //parse data from data string
			String patternString = ".*time=.*";
			Pattern pattern = Pattern.compile(patternString);
			String token = in.next();
			Matcher matcher = pattern.matcher(token);

			//parse to double and perform calculations
			if(matcher.matches()) {
				curr =  new BigDecimal(0.001 * Double.parseDouble(token.substring(5, 7)));

				BigDecimal SampleRTT  = new BigDecimal(curr.floatValue());

				BigDecimal EstRTT1 = expAvg(prev1, curr);
				BigDecimal EstRTT2 = ariAvg(prev2, curr, n++);

				out.print(String.format("%10f,%20f,%20f\n", SampleRTT ,EstRTT1.doubleValue(), EstRTT2.doubleValue()));

				prev1 = EstRTT1;
				prev2 = EstRTT2;
			}
		}

	 }
	 public static void main (String[] args){ 
	 	try{
			
			Scanner fileScanner = new Scanner(new File("data.txt")); 
			PrintWriter filePrinter = new PrintWriter(new File("output.csv"));
			
			filePrinter.print("SampleRTTs(sec)\tExpAvgs(sec)\tAriAvgs(sec)");
			filePrinter.println();
			
			sampleRTT2EstimatedRTT(fileScanner, filePrinter);
			
			fileScanner.close();
			filePrinter.close();
	
		}catch(IOException e){
			System.out.println("Error opening file.");
			System.exit(0);
		}
		
		
	 }
}  
