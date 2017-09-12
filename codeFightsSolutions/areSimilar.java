public class areSimilar {
	boolean areSimilar(int[] a, int[] b) {
		ArrayList<Integer> lista = new ArrayList<>();
		ArrayList<Integer> listb = new ArrayList<>();
		for(int i = 0; i < a.length; i++) {
		    lista.add(a[i]);
		    listb.add(b[i]);
		}
		for(int i = lista.size()-1; i >= 0; i--) {
		    if((int)lista.get(i) == (int)listb.get(i)) {
	            	lista.remove(i);
	            	listb.remove(i);
			}
		}
		if(lista.size() > 2) {
		    return false;
		}
		Collections.sort(lista);
		Collections.sort(listb);
		return lista.equals(listb);
	}

}
