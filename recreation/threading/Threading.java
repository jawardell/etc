package assignment1;

import java.util.*;
import java.io.*;
import java.time.LocalDateTime;
import java.util.concurrent.*;

class Threading {
	static int n, m;
	static float[][] matrix;
	static String[][] solnMatrix;

	public static void main(String[] args) {
		// create file from filename argument
		if(args.length == 0) {
			System.out.println("\n\n\tyou must provide a filename argument to use this program\n\n");
			System.out.println("\n\n\ttry again\n\n\n");
			System.exit(1);
		}
		try {
			n = m = 0;
			//if this is placed in an eclipse package
			String path = "src/assignment1/" + args[0];  
			//String path = args[0];
			detectMatrixDemensions(path);
			matrix = new float[n][m];
			parseMatrix(path);
			sumRowCol(matrix);
			printSoln();
		} catch (Exception e) {
			if (e instanceof FileNotFoundException) {
				System.out.print("\n\n\tsorry, we couldn't find that file. try again.\n\n\n");
				System.exit(1);
			}
			System.out.print("\n\n\tthere was a problem\n\n");
			e.printStackTrace();
			System.exit(-1);
		}

	}

	static void detectMatrixDemensions(String path) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(path));
		while (scanner.hasNext()) {
			String[] array = scanner.nextLine().split(" |\t");
			n++;
			m = array.length;
		}
		scanner.close();
		/*
		 * initialize an empty solution matrix of format:
		 * [
		 * ["sum", "r/c", "index"],  ==> ROW 0
		 * ["sum", "r/c", "index"],  ==> ROW 1
		 * ["sum", "r/c", "index"],  ==> ROW 2
		 * 			....		  ,	 ==> ROW ...
		 * ["sum", "r/c", "index"]   ==> ROW (n+m) - 1
		 * ]
		 */
//		for(int i = 0; i < n+m; i++) {
//			solnMatrix[i] = new String[3];
//		}
		solnMatrix = new String[n+m][3];
	}

	static void sumRowCol(float[][] array) throws FileNotFoundException {
		Matrix matrix = new Matrix(array);
		// create and submit threads to sum rows and cols
		ExecutorService executor = Executors.newFixedThreadPool(array[0].length + array.length);
		int ix = 0;
		ArrayList<Task> tasks = new ArrayList<>();
		for (int i = 0; i < array.length; i++) {
			Task task = new Task(String.format("row %d", i), matrix.getRow(i));
			//executor.submit(task);
			tasks.add(task);
			System.out.print(String.format("\n**thread %s submitted at %s", 
					task.id, LocalDateTime.now().toString()));
			solnMatrix[ix][0] = Float.toString(task.sum);
			solnMatrix[ix][1] = task.id.contains("row") ? "r" : "c";
			solnMatrix[ix][2] = Integer.toString(i);
			ix++;
		}
		for (int i = 0; i < array[0].length; i++) {
			Task task = new Task(String.format("col %d", i), matrix.getCol(i));
			//executor.submit(task);
			tasks.add(task);
			System.out.print(String.format("\n** thread %s submitted at %s", 
					task.id, LocalDateTime.now().toString()));
			solnMatrix[ix][0] = Float.toString(task.sum);
			solnMatrix[ix][1] = task.id.contains("row") ? "r" : "c";
			solnMatrix[ix][2] = Integer.toString(i);
			ix++;
		}
		executor.invokeAll(tasks);
		executor.shutdown();
		while (!executor.isTerminated()) {}
	}

	static class Task implements Runnable {
		String id;
		float[] sequence;
		float sum;

		Task(String id, float[] sequence) {
			this.id = id;
			this.sequence = sequence;
			sum = 0;
		}

		public void run() {
			long start = System.nanoTime();
			for (int i = 0; i < sequence.length; i++) {
				sum += sequence[i];
			}
			long time = System.nanoTime() - start;
			System.out.printf("\n\n\ttask %s finished in %dns with sum %f \n\n", id, (int)time, sum);
		}

	}

	static class Matrix {
		// helper class used to extract certain rows or columns from the matrix
		ArrayList<ArrayList<Float>> matrix;

		Matrix(float[][] array) {
			matrix = new ArrayList<>();
			
			for(int i = 0; i < array.length; i++) {
				matrix.add(new ArrayList<>());
			}
			
			for (int i = 0; i < array.length; i++) {
				for (int j = 0; j < array[0].length; j++) {
					matrix.get(i).add(array[i][j]);
				}
			}
			
		}

		float[] getRow(int index) {
			float[] array = new float[matrix.get(index).size()];
			for (int i = 0; i < matrix.get(index).size(); i++) {
				array[i] = matrix.get(index).get(i);
			}
			return array;
		}

		float[] getCol(int index) {
			float[] array = new float[matrix.size()];
			for (int i = 0; i < matrix.size(); i++) {
				array[i] = matrix.get(i).get(index);
			}
			return array;
		}
	}
	
	static void parseMatrix(String path) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(path));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {//more logic here? might work
				matrix[i][j] = Integer.parseInt(scanner.next());
			}
		}
		scanner.close();
	}
	
	static void printSoln() {
		float[] rsums = new float[n];
		float[] csums = new float[m];
		for(int i = 0; i < solnMatrix.length; i++) {
			if(solnMatrix[i][1].equals("r")) {
				rsums[Integer.parseInt(solnMatrix[i][2])] = Float.parseFloat(solnMatrix[i][0]);
			}
			if(solnMatrix[i][1].equals("c")) {
				csums[Integer.parseInt(solnMatrix[i][2])] = Float.parseFloat(solnMatrix[i][0]);
			}
		}
		System.out.println("\n\n\n\n\nThank you for using my program! The following is the solution: \n\n\n");
		System.out.println("The row sums are: ");
		for(int i = 0; i < rsums.length; i++) {
			System.out.printf("\n%10.3f",(double)rsums[i]);
		}
		System.out.println("\n\n");
		System.out.println("The column sums are: ");
		for(int i = 0; i < csums.length; i++) {
			System.out.printf("\n%10.3f",(double)csums[i]);
		}
		System.out.println("\n\n\n\t\tgoodbye!");
		System.exit(0);
	}

}
