class reverseParenthesis {
	String reverseParenthesis(String s) {
		int start = s.lastIndexOf('(');
		while(start != -1) {
			int end = s.indexOf(')', start);
			String rev = s.substring(0, start);
			rev += new StringBuilder(s.substring(start + 1, end)).reverse().toString();
			rev += s.substring(end+1);
			s = rev;
			start = s.lastIndexOf(')');
		}
		return s;
	}
}
