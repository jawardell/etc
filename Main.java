/**
 * Created by joannewardell on 6/4/17.
 */
import java.util.*;
public class Main {
    static double[][] matrix;
    public static void main (String[] args) {
        initMat();
        System.out.print("\nThe determinant of the matrix is " + matrixDet(matrix) + "\n");
    }


    public static double matrixDet(double[][] matrix) {
        double total = 0;
        for(int col = 0; col < matrix[0].length; col++) {
            double mult = 1;
            int pos = col;
            for(int row = 0; row < matrix.length; row++) {
                mult *= matrix[row][pos];
                if(pos < matrix.length-1) {
                    pos++;
                } else {
                    pos = 0;
                }
            }
            total += mult;
        }

        for(int col = matrix[0].length-1; col >= 0; col--) {
            int pos = col;
            double mult = 1;
            for(int row = 0; row < matrix.length; row++) {
                mult *= matrix[row][pos];
                if(pos > 0) {
                    pos--;
                }
                else {
                    pos = matrix[0].length-1;
                }
            }
            total -= mult;
        }

        return total;
    }

    public static void initMat() {
        System.out.print("enter matrix info:\n");
        System.out.print("What are the dimensions of the matrix?");
        System.out.print("[n][n]");
        System.out.print("\nn: ");
        Scanner console = new Scanner(System.in);
        int n = console.nextInt();
        matrix = new double[n][n];
        for(int row = 0; row < matrix.length; row++) {
            for(int col = 0; col < matrix[0].length; col++) {
                System.out.print("\nenter value for [" + row + "][" + col + "]\n");
                matrix[row][col] = console.nextDouble();
                printMat(matrix);
            }
        }

    }

    public static void printMat(double[][] matrix) {
        for(int row = 0; row < matrix.length; row++) {
            for(int col = 0; col < matrix[0].length; col++) {
                if(col == 0) {
                    System.out.print("[ " + matrix[row][col] + " ");
                } else if(col == matrix[0].length-1) {
                    System.out.print(" " + matrix[row][col] + " ]\n");
                } else {
                    System.out.print(" " + matrix[row][col] + " ");
                }
            }
        }
    }
}
