class addBorder {
	String[] addBorder(String[] picture) {
		int len = picuture[0].length() + 2;
		String temp = "";
		for(int i = 0; i < len; i++) {
			temp += "*";
		}
		ArrayList<String> array = new ArrayList<>();
		array.add(temp);
		for(int i = 0; i < picture.length; i++) {
			array.add("*" + a[i] + "*");
		}
		array.add(temp);
		String[] res = new String[array.size()];
		for(int i = 0; i < res.length; i++) {
			res[i] = array.get(i);
		}
		return res;
	}
}
