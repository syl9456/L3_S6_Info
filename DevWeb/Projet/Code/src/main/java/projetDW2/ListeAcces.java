package projetDW2;

import java.util.ArrayList;
import java.util.Objects;

/**
 * Class pour stocker une liste d'Acces
 */

public class ListeAcces {
	
	private ArrayList<Acces> listeAcces;
	
	/**
	 * 
	 */
	public ListeAcces() {
        this.listeAcces = new ArrayList<Acces>();
    }
	
	/**
	 * @param listeAcces
	 */
	public ListeAcces(ArrayList<Acces> listeAcces) {
        this.listeAcces = listeAcces;
    }

    /**
     * @return
     */
    public ArrayList<Acces> getListeAcces() {
        return listeAcces;
    }

    /**
     * @param listeAcces
     */
    public void setListeAcces(ArrayList<Acces> listeAcces) {
        this.listeAcces = listeAcces;
    }
    
    /**
     *
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ListeAcces that = (ListeAcces) o;
        return Objects.equals(listeAcces, that.listeAcces);
    }

    /**
     *
     */
    @Override
    public String toString() {
    	String lAcces = "";
        for (Acces a : listeAcces) {
            lAcces += a.toString();
        }
        return "ListeMessage{" +
                "listeMessage=" + lAcces +
                '}';
    }

}
