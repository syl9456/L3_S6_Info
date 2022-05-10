package projetDW2;

import java.util.ArrayList;
import java.util.Objects;

/**
 * Class pour stocker une liste de Donnee
 */

public class ListeDonnee {
	
	private ArrayList<Donnee> listeDonnee;
	
	/**
	 * 
	 */
	public ListeDonnee() {
        this.listeDonnee = new ArrayList<Donnee>();
    }
	
	/**
	 * @param listeDonnee
	 */
	public ListeDonnee(ArrayList<Donnee> listeDonnee) {
        this.listeDonnee = listeDonnee;
    }

    /**
     * @return
     */
    public ArrayList<Donnee> getListeDonnee() {
        return listeDonnee;
    }

    /**
     * @param listeDonnee
     */
    public void setListeDonnee(ArrayList<Donnee> listeDonnee) {
        this.listeDonnee = listeDonnee;
    }
    
    /**
     *
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ListeDonnee that = (ListeDonnee) o;
        return Objects.equals(listeDonnee, that.listeDonnee);
    }

    /**
     *
     */
    @Override
    public String toString() {
        String lDon = "";
        for (Donnee d : listeDonnee) {
        	lDon += d.toString();
        }
        return "ListeDonnee{" +
                "Liste des Donnee = " + lDon +
                '}';
    }
}
