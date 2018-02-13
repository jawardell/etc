import java.util.*;
import java.io.*;

public class Main() {
	public static int[][] mat1;
	public static int[][] mat2;
	public static int[][] finmat;
	
	
	public static void Main(String[] args) {
		
		
		parseMatrices(mat1, mat2);
		
		ExecutorService executor = Executors.newFixedThreadPool(mat1.length);
		
		for(int i = 0; i < mat1.length; i++) {
			executor.execute(new Task())
			
		}
		
	}		
	
	
	
	
	public static int[][] mult(int[][] mat1, int[][] mat2) {
		int[][] mat3 = new int[mat1.length][mat2[0].length];
		
		boolean areConformable = mat1[0].length == mat1.length;
		
		if(areConformable) {
			for(int x = 0; x < mat.length; x++) {
				for(int y = 0; y < mat2[0].length; y++) {
					for(int z = 0; z < mat2[0].length; z++) {
						mat3[x][y] += mat1[x][z] * mat2[z][y];
					}
					
				}
				
			}
			return mat3;
		} else {
			System.out.println("\n\tthe matrices are not conformable\n");
			for(int i = 0; i < mat3.length; i++) {
				for(int j = 0; j < mat3[0].length; j++) {
					mat3[i][j] = Integer.MIN_VALUE;
				}
			}
			return mat3;
		}
		
	}
	
	
	

	
	

	public static void parseMatrices(mat1, mat2) throws Exception {
		File file = new File("file");
		Scanner scanner = new Scanner(file);
		mat1 = new int[scanner.nextInt()][scanner.nextInt()];
		mat2 = new int[scanner.nextInt()][scanner.nextInt()];
		if(mat1[0].length != mat2.length) {
			throw new Exception("\n\tthe matrices are not conformable\n");
		}
		int row = 0;
		for(int i = 0; i < mat1.length; i++) {
			char[] array = scanner.nextLine().split(" ");
			int nums = new int[array.length];
			for(int i = 0; i < array.length; i++) {
				mat1[row][i] = Character.getNumericValue(array[i]);
			}
			row++;
		}
		row = 0;
		for(int i = 0; i < mat2.length; i++) {
			char array = scanner.nextLine();
			int nums = new int[array.length];
			for(int i = 0; i < array.length; i++) {
				mat1[row][i] = Character.getNumericValue(array[i]);
			}
			row++;
		}
		scanner.close();
	}



	public class Task implements Runnable {
		int[][] A, B;
		int id;

		public Task(int[][] A, int[][] B, int id) {
			this.A = new int[A.length][A[0].length];
			this.B = new int[B.length][B[0].length];
			this.id = id;
		
			for(int i = 0; i < A.length; i++) {
				for(int j = 0; j < A[0].length; j++) {
					this.A[i][j] = A[i][j];
				}	
			}
		
			for(int i = 0; i < B.length; i++) {
				for(int j = 0; j < B[0].length; j++) {
					this.B[i][j] = B[i][j];
				}
			}
		}
	
		public void run() {
			try {
				System.out.print(mult(A,B));
			} catch(InterruptedException e) {
				System.out.print("\n\tthe thread was interrupted.\n");
			}
		
		
		}
		
	}
	
	
	
	public class Matrix {
		int numRows, numCols;
		int[][] data;
		
		
		public Matrix(int[][] data) {
			this.data = new int[data.length][data[0].length];
			for(int i = 0; i < data.length; i++) {
				for(int j = 0; j < data[0].length; j++) {
					this.data[i][j] = data[i][j];
				}
			}
			
			numRows = this.data.length;
			numCols = this.data[0].length;
		}
		
		
		public int[][] getCol(int colInd) {
			int[][] res = new int[numRows][1];
			for(int i = 0; i < numRows; i++) {
				res[i][colInd] = data[i][colInd];
			}
			return res;
		}
		
	}
}