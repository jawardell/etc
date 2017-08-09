public class allLongestStrings {
	String[] allLongestStrings(String[] inputArray) {
		int maxlen = Integer.MIN_VALUE;
		int count = 0;
		for(int i = 0; i < inputArray.length; i++) {
			if(inputArray[i].length() > maxlen) {
				maxlen = inputArray[i].length();
			}
		}
		ArrayList<String> array = new ArrayList<>();
		for(int i = 0; i < inputArray.length; i++) {
			if(inputArray[i].length() == maxlen) {
				array.add(inputArray[i]);
			}
		}
		String[] array1 = new String[array.size()];
		for(int i = 0; i < array.size(); i++) {
			if(array.get(i).length() == maxlen) {
				array1[i] = array.get(i);
			}
		}
		return array1;
	}
}
