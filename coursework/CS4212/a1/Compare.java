import java.util.*;
import java.io.*;

public class Compare {
	public static void main(String[] args) {
		try {
			printsoln(accumulate_delays(0, "zero"));
			printsoln(accumulate_delays(10, "ten"));
			printsoln(accumulate_delays(20, "twenty"));
		} catch(Exception e) {
			System.out.print("\n\twe threw an excpetion..");
		}
	}


	public static ArrayList<ArrayList> accumulate_delays(int header_bits, String file_name) {
		//capture each packet's length and delay for later
		ArrayList<Integer> sizes = new ArrayList<>();
		ArrayList<Double> delays = new ArrayList<>();
		ArrayList<String> holders = new ArrayList<>();
		holders.add(new Integer(header_bits).toString());
		holders.add(file_name);

		//the transmission rate, gap size, and total message size are invariant
		final int trans_rate = 4000;
		final int msg_len = 16000;
		final int gap = 2;


		//calculate and accumulate delays
		for(double i = 4000; i >= 125; i/=2) {
			double pkt_len = i + header_bits;
			
		
			
			/*
			* using formula derived in submission document, 
			* see the chart on pg 8 ass1.pdf
			*
			* n is the number of packets
			* h is the number of header bits
			*
			*/
			
			double n = 16000 / i;
			int h = header_bits;
			delays.add((((1/(4*n))*((n*n + 2*n) * (h * Math.pow(10,-3))+ 16*n + 32))));
			sizes.add(new Integer((int)pkt_len));

		}
		
		ArrayList<ArrayList> list = new ArrayList<>();
		list.add(sizes);
		list.add(delays);
		list.add(holders);

		return list;

	
	}

	
	public static void printsoln(ArrayList<ArrayList> list) throws Exception {
		System.out.printf("\n\n-------with %d header bits--------\n\n", Integer.parseInt(list.get(2).get(0).toString()));
		for(int i = 0; i < list.get(0).size(); i++) {
			System.out.printf("size: %4d bits\t\tdelay: %1.4f seconds\n\n", list.get(0).get(i), list.get(1).get(i));
		}
		System.out.print("\n\n---------------\n\n");

		
		/* -- write to a csv file to plot later -- */
		//String file_name = list.get(2).get(1).toString();

		//File file = new File(file_name + "HB.csv");

		//PrintWriter pw = new PrintWriter(file);

		//for(int i = 0; i < list.get(0).size(); i++) {
		//	pw.write(String.format("%d,%f\n", list.get(0).get(i), list.get(1).get(i)));
		//}

		//pw.close();
	}
}
