package projetDW2;

import java.util.ArrayList;
import java.util.Objects;

public class ListeMap{
	
	private ArrayList<Map> listeMap;
	
	public ListeMap() {
        this.listeMap = new ArrayList<Map>();
    }
	
	public ListeMap(ArrayList<Map> listeMap) {
        this.listeMap = listeMap;
    }

    public ArrayList<Map> getListeMap() {
        return listeMap;
    }

    public void setListeMap(ArrayList<Map> listeMap) {
        this.listeMap = listeMap;
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ListeMap that = (ListeMap) o;
        return Objects.equals(listeMap, that.listeMap);
    }

    @Override
    public String toString() {
        String lMap = "";
        for (Map m : listeMap) {
        	lMap += m.toString();
        }
        return "ListeMap{" +
                "liste des Map = " + lMap +
                '}';
    }

}
