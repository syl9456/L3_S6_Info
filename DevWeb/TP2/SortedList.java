package tp2;

import java.util.ArrayList;

public class SortedList<E extends Comparable<E>> extends ArrayList<E>{
	
	private static final long serialVersionUID = 1L;

	public SortedList() {
		super();
	}
	
	public boolean add(E donnee) {
		if(this.isEmpty()) {
			super.add(donnee);
			return true;
		}
		else {
			for(int i = 0; i < this.size(); i++) {
				if(donnee.compareTo(this.get(i)) < 0 || this.get(i).compareTo(donnee) == 0){
					super.add(i, donnee);
					return true;
				}
			}
			super.add(donnee);
			return true;
		}
	}
	
}
