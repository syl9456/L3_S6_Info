package tp2;

import java.util.ArrayList;

public class SortedListOfString<E> extends ArrayList<String> {


	private static final long serialVersionUID = 1L;
	
	public SortedListOfString() {
		super();
	}
	
	public boolean add(String mot) {
		if(this.isEmpty()) {
			super.add(mot);
			return true;
		}
		else {
			for(int i = 0; i < this.size(); i++) {
				if(mot.compareTo(this.get(i)) < 0 || this.get(i).compareTo(mot) == 0){
					super.add(i, mot);
					return true;
				}
			}
			super.add(mot);
			return true;
		}
	}

}
