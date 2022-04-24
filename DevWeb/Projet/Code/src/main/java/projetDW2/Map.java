package projetDW2;

import java.util.Objects;

public class Map {

    private int ID;
    private int IDProprio;
    private String Nom;
    private String SrcBackground;

    public Map(int ID, int IDProprio, String nom, String srcbackground) {
    	this.ID = ID;
        this.IDProprio = IDProprio;
        this.Nom = nom;
        this.SrcBackground = srcbackground;
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

    /**
     * @param o
     * @return Test si une map est la même qu'une autre
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Map map = (Map) o;
        return ID == map.ID && IDProprio == map.IDProprio && Objects.equals(Nom, map.Nom);
    }

    /**
     * @return Info de la classe Map
     */
    @Override
    public String toString() {
        return "Map{" +
                "ID=" + ID +
                ", IDProprio=" + IDProprio +
                ", Nom='" + Nom + '\'' +
                ", SrcBackground='" + SrcBackground + '\'' +
                '}';
    }
}
