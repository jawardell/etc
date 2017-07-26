//coding bat solutions

public class Driver {
	public static void main(String[] args) {}

	



	/* 
	Return an array that contains exactly the same numbers as the given
 	array,but rearranged so that every 3 is immediately followed by a 4. Do not
 	move the 3's, but every other number may move. The array contains the same
 	number of 3's and 4's, every 3 has a number after it that is not a 3, and a
 	3 appears in the array before any 4.
	*/
	public static int[] fix34(int[] nums) {
		int index = 0;
		for(int i = 0; i < nums.length-1; i++) {
			if(nums[i] == 3) {
				index = i == 1 ? i : index;
				for(int j = index; j < nums.length; j++) {
					if(nums[j] == 4) {
						int temp = nums[i + 1];
						nums[i + 1] = nums[j];
						nums[j] = temp;
						index = j+1;
						break;
					}
				}
			}
		}
		return nums;
	}



	
	/* 
	(This is a slightly harder version of the fix34 problem.) Return an array
 	that contains exactly the same numbers as the given array, but rearranged
	so that every 4 is immediately followed by a 5. Do not move the 4's, but
 	every other number may move. The array contains the same number of 4's and
 	5's, and every 4 has a number after it that is not a 4. In this version, 	
	5's may appear anywhere in the original array.
	*/
	public static int[] fix45(int[] nums) {
		for(int i = 0; i < nums.length-1; i++) {
			if(nums[i] == 4) {
				if(nums[i+1] == 5) {
					nums[i+1] = -1;
					continue;
				}
				for(int j = 0; j < nums.length; j++) {
					if(nums[j] == 5) {
						int temp = nums[i+1];
						nums[i+1] = -1;
						nums[j] = temp;
						break;
					}
				}
			}
		}
		for(int i = 0; i < nums.length; i++) {
			if(nums[i] == -1) {
				nums[i] = 5;
			}
		}
		return nums;
	}

	

	/*
	Given a non-empty array, return true if there is a place to split the
 	array so that the sum of the numbers on one side is equal to the sum of the
 	numbers on the other side.
	*/
	public static boolean canBalance(int[] nums) {
		int sum1 = 0, sum2 = 0, pos = 0;
		for(int i = 0; i < nums.length-2; i++) {
			for(int j = 0; j < i; j++) {
				sum1 += nums[j];
				pos = j+1;
			}
			for(int j = pos; j < nums.length-1; j++) {
				sum2 += nums[j];
			}
			if(sum1 == sum2) {
				return true;
			}
			sum1 = 0;
			sum2 = 0;
		}
		return false;
	}



	/*
	Given two arrays of ints sorted in increasing order, outer and inner,
 	return true if all of the numbers in inner appear in outer. The best
 	solution makes only a single "linear" pass of both arrays, taking advantage
 	of the fact that both arrays are already in sorted order.	 
	*/
	public static boolean linearIn(int[] outer, int[] inner) {
		int pos = 0;
		for(int i = 0; i < outer.length; i++) {
			if(pos == inner.length) {
				return true;
			}
			if(outer[i] < inner[pos]) {
				continue;
			}
			if(outer[i] == inner[pos]) {
				pos++;
				continue;
			}
			if(outer[i] > inner[pos]) {
				return false;
			}
		}
		return pos == inner.length;
	}
}
