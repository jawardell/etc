import java.util.*;
import java.io.*;
import java.util.concurrent.*;

public class Main {
   public static int[][] mat1, mat2, finmat;
	
	
   public static void main(String[] args) {
      try {
         init();
      } catch(Exception e) {
         System.out.print("\nwe threw an exception.\n\texiting gracefully..");
      }
      
      printsoln();
   }		
	
	
   public static void init() throws Exception {
      parseMatrices();
   	
      ExecutorService executor = Executors.newFixedThreadPool(mat1.length);
   		
      for(int i = 0; i < mat1.length; i++) {
         Matrix matrix = new Matrix(mat1);
         executor.execute(new Task(matrix.getRow(i), mat2, i));
      }
      executor.shutdown();
      while(!executor.isTerminated()) { /*wait for each thread to complete*/ }
   }
	
	
	
   public static int[][] mult() {
      int[][] mat3 = new int[mat1.length][mat2[0].length];
   	
      boolean areConformable = mat1[0].length == mat2.length;
   	
      if(areConformable) {
         for(int x = 0; x < mat1.length; x++) {
            for(int y = 0; y < mat2[0].length; y++) {
               for(int z = 0; z < mat1[0].length; z++) {
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
	

   public static void parseMatrices() throws Exception {
      File file = null;
      try {
         file = new File("C:/Users/jawardell_admin/etc/threading/file.txt");
      } catch(Exception e) {
         System.out.print("\n\n\tthe file was not found. please check the path...\ntry again please.");
      }
      Scanner scanner = new Scanner(file);
      mat1 = new int[scanner.nextInt()][scanner.nextInt()];
      mat2 = new int[scanner.nextInt()][scanner.nextInt()];
      if(mat1[0].length != mat2.length) {
         throw new Exception("\n\tthe matrices are not conformable\n");
      } 
      int row = 0;
      scanner.nextLine();
      scanner.nextLine();
      for(int i = 0; i < mat1.length; i++) {
         String[] array = scanner.nextLine().split("  ");
         int[] nums = new int[array.length];
         for(int j = 0; j < array.length; j++) {
            mat1[row][j] = Integer.parseInt(array[j]);
         }
      	
         row++;
      }
      row = 0;
      scanner.nextLine();
      for(int i = 0; i < mat2.length; i++) {
         String[] array = scanner.nextLine().split("  ");
         int[] nums = new int[array.length];
         for(int j = 0; j < array.length; j++) {
            mat2[row][j] = Integer.parseInt(array[j]);
         }
         row++;
      }
      scanner.close();
      finmat = new int[mat1.length][mat2[0].length];
   }



   public static class Task implements Runnable {
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
         int[][] resRow = mult();
         for(int i = 0; i < resRow.length; i++) {
            finmat[id][i] = resRow[0][i];
         }
         System.out.print("\nthread " + id + " successfully ran.\n");
      }
   	
   }
	
	
	
   public static class Matrix {
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
   	
      public int[][] getRow(int rowInd) {
         int[][] res = new int[1][numCols];
         for(int i = 0; i < numCols; i++) {
            res[0][i] = data[rowInd][i];
         }
         return res;
      }
   	
   }
   
   
   public static void printsoln() {
      System.out.print("\nthank you for using my program!\n");
      System.out.print("\nthe following is the solution matrix:\n");
      for(int i = 0; i < finmat.length; i++) {
         for(int j = 0; j < finmat[0].length; j++) {
            if(j == finmat[0].length - 1) {
               System.out.print(finmat[i][j] + "\n");
            } else {
               System.out.print(finmat[i][j] + " ");
            }
         }
      }
   
   }
}