class checkPalindrome {
	boolean checkPalindrome(String inputString) {
		int low = 0; 
		int high = inputString.length()-1;
		for(int i = 0; i < inputString.length(0; i++) {
			if(inputString.length() == 1) {
				return true;
			}
			if(inputString.charAt(low) != inputString.charAt(high)) {
				return false;
			}
			if(low > high) {
				return true;
			}
			low++; 
			high--;
		}
		return false;
	}
}
