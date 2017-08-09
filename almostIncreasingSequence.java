class almostIncreasingSequence {
	boolean almostIncreasingSequence(int[] sequence) {
		ArrayList<Integer> array = new ArrayList<>();
		ArrayList<Integer> arraycopy = new ArrayList<>();
		for(int i = 0; i < sequence.length; i++) {
			array.add(sequence[i]);
			arraycopy.add(sequence[i]);
		}
		for(int i = 0; i < array.size(); i++) {
			if(i == array.size()-1) {
				return true;
			}
			boolean increasing = array.get(i) - array.get(i+1) < 0;
			if(!increasing && i == 0) {
				array.remove(i);
				arraycopy.remove(i);
				break;
			}
			if(!increasing && i > 0) {
				array.remove(i+1);
				arraycopy.remove(i);
				break;
			}
			return ((arrayCheck(array)) && (arrayCheck(arraycopy))) 
				|| ((arrayCheck(array)) || (arrayCheck(arraycopy)));
		}
	}
	boolean arrayCheck(ArrayList<Integer> array) {
		for(int i = 0; i < array.size(); i++) {
			if(i == array.size()-1) {
				return true;
			}
			boolean increasing = array.get(i) - array.get(i+1) > 0;
			if(!increasing) {
				return false;
			}
		}
		return true;
	}
}
