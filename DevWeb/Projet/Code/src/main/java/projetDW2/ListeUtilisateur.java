package projetDW2;

import java.util.ArrayList;
import java.util.Objects;

public class ListeUtilisateur {
	
	private ArrayList<Utilisateur> listeUtilisateur;

    public ListeUtilisateur() {
        this.listeUtilisateur = new ArrayList<Utilisateur>();
    }

    public ListeUtilisateur(ArrayList<Utilisateur> listeUtilisateur) {
        this.listeUtilisateur = listeUtilisateur;
    }

    public ArrayList<Utilisateur> getListeUtilisateur() {
        return listeUtilisateur;
    }

    public void setListeMessage(ArrayList<Utilisateur> listeUtilisateur) {
        this.listeUtilisateur = listeUtilisateur;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ListeUtilisateur that = (ListeUtilisateur) o;
        return Objects.equals(listeUtilisateur, that.listeUtilisateur);
    }

    @Override
    public String toString() {
        String lUtil = "";
        for (Utilisateur u : listeUtilisateur) {
        	lUtil += u.toString();
        }
        return "ListeUtilisateur{" +
                "Liste des Utilisateurs = " + lUtil +
                '}';
    }

}
