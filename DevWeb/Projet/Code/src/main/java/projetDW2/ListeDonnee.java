package projetDW2;

import java.util.ArrayList;
import java.util.Objects;

public class ListeDonnee {
	
	private ArrayList<Donnee> listeDonnee;
	
	public ListeDonnee() {
        this.listeDonnee = new ArrayList<Donnee>();
    }
	
	public ListeDonnee(ArrayList<Donnee> listeDonnee) {
        this.listeDonnee = listeDonnee;
    }

    public ArrayList<Donnee> getListeDonnee() {
        return listeDonnee;
    }

    public void setListeDonnee(ArrayList<Donnee> listeDonnee) {
        this.listeDonnee = listeDonnee;
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ListeDonnee that = (ListeDonnee) o;
        return Objects.equals(listeDonnee, that.listeDonnee);
    }

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
