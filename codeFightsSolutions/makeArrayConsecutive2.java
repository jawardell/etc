class makeArrayConsecutive2 {
	public makeArrayConsecutive2(int[] statues) {
		for(int i = statues.length-1; i >= 0; i--) {
			for(int j = 1; j <= i; j++) {
				if(statues[j-1] > statues[j]) {
					int temp = statues[j-1];
					statues[j-1] = statues[j];
					statues[j] = temp;
				}
			}
		}
		int diff = 0;
		for(int i = 0; i < statues.length-1; i++) {
			if(statues[i+1]-statues[i] > 1) {
				diff += statues[i+1]-statues[i]-1;
			}
		}
		return diff;
	}
} 
