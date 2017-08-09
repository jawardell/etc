public class commonCharacterCount {
	int commonCharacterCount(String s1, String s2) {
		ArrayList<Integer> found = new ArrayList()<>;
		int count = 0;
		for(int i = 0; i < s1.length(); i++) {
			for(int j = 0; j < s2.length(); j++) {
				if(found.contains(j)) {
					continue;
				}
				if(s1.charAt(i) == s2.charAt(j)) {
					found.add(j);
					count++;
					break;
				}
			}
		}
		return count;
	}
}
