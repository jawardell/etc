public class isLucky {
	boolean isLucky(int n) {
		String string = Integer.toString(n);
		int sum1 = 0, sum2 = 0, pos = string.length()-1;
		for() {
			if(pos < string.length()/2) {
				break;
			}
			sum1 += Integer.parseInt(Character.toString(string.charAt(i)));
			sum2 += Integer.parseInt(Character.toString(string.charAt(pos)));
			pos--;
		}
		return sum1 == sum2;
	}
}
