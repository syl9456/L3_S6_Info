package projetDW2;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Objects;

public class Map {

    private int ID;
    private int IDProprio;
    private String Nom;
    private String SrcBackground;
    private ArrayList<Donnee> ListeDonnee;
    private Hashtable<Integer, Integer> UtilAcces;

    private static int nbMap = 0;

    public Map(int IDProprio, String nom, String srcbackground) {
        this.IDProprio = IDProprio;
        this.Nom = nom;
        this.SrcBackground = srcbackground;
        nbMap++;
        this.ID = nbMap;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public int getIDProprio() {
        return IDProprio;
    }

    public void setIDProprio(int IDProprio) {
        this.IDProprio = IDProprio;
    }

    public String getNom() {
        return Nom;
    }

    public void setNom(String nom) {
        Nom = nom;
    }

    public String getSrcBackground() {
        return SrcBackground;
    }

    public void setSrcBackground(String srcBackground) {
        SrcBackground = srcBackground;
    }

    public ArrayList<Donnee> getListeDonnee() {
        return ListeDonnee;
    }

    public void setListeDonnee(ArrayList<Donnee> listeDonnee) {
        ListeDonnee = listeDonnee;
    }

    public Hashtable<Integer, Integer> getUtilAcces() {
        return UtilAcces;
    }

    public void setUtilAcces(Hashtable<Integer, Integer> utilAcces) {
        UtilAcces = utilAcces;
    }

    public static int getNbMap() {
        return nbMap;
    }

    /**
     * @param o
     * @return Test si une map est la meme qu'une autre
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Map map = (Map) o;
        return ID == map.ID && IDProprio == map.IDProprio && Objects.equals(Nom, map.Nom) && Objects.equals(ListeDonnee, map.ListeDonnee) && Objects.equals(UtilAcces, map.UtilAcces);
    }

    /**
     * @return Info de la classe Map
     */
    @Override
    public String toString() {
        String lDonnee = "";
        for (Donnee d : ListeDonnee) {
            lDonnee += d.toString();
        }
        return "Map{" +
                "ID=" + ID +
                ", IDProprio=" + IDProprio +
                ", Nom='" + Nom + '\'' +
                ", SrcBackground='" + SrcBackground + '\'' +
                ", ListeDonnee= " + lDonnee +
                ", UtilAcces=" + UtilAcces +
                '}';
    }
}
