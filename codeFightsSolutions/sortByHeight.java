class sortByHeight {
	int[] sortByHeight(int[] a) {
		for(int i = 0; i < a.length-1; i++) {
			if(a[i] == -1) {
				continue;
			}
			for(int j = i+1; j < a.length; j++) {
				if(a[j] == -1) {
					continue;
				}
				if(a[i] > a[j]) {
					int temp = a[j];
					a[j] = a[i];
					a[i] = temp;
					continue;
				}
			}
		}
		return a;
	}
}
