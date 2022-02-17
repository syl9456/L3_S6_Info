package tp2;

import java.util.ArrayList;

public class SortedListOfStringsUsingDelegation<E> {
	
	private ArrayList<String> Liste;
	
	public SortedListOfStringsUsingDelegation() {
		Liste = new ArrayList<String>();
	}
	
	public boolean add(String mot) {
		if(this.Liste.isEmpty()) {
			this.Liste.add(mot);
			return true;
		}
		else {
			for(int i = 0; i < this.Liste.size(); i++) {
				if(mot.compareTo(this.Liste.get(i)) < 0 || this.Liste.get(i).compareTo(mot) == 0){
					this.Liste.add(i, mot);
					return true;
				}
			}
			this.Liste.add(mot);
			return true;
		}
	}
	
	public String toString() {
		return Liste.toString();
	}
	
	public String get(int index) {
		return Liste.get(index);
	}
	
	public String peek() {
		return Liste.get(0);
	}
	
	public void clear() {
		while(!Liste.isEmpty()) {
			Liste.remove(0);
		}
	}
	
	public void remove(int Index) {
		Liste.remove(Index);
	}
	
	public int size() {
		return Liste.size();
	}
	
	public boolean isEmpty() {
		return Liste.isEmpty();
	}
	
	public boolean contain(String element) {
		return Liste.contains(element);
	}
	
	

}
