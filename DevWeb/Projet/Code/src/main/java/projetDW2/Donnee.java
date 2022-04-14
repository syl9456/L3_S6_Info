package projetDW2;

import java.util.Objects;

public class Donnee {

    private static int nbDonnee = 0;
    private int ID;
    private int IDMap;
    private Coordonnee Coord;
    private String Info;
    private int Type;

    public Donnee(int IDMap, Coordonnee coord, String info, int type) {
        this.IDMap = IDMap;
        this.Coord = coord;
        this.Info = info;
        this.Type = type;
        nbDonnee++;
        this.ID = nbDonnee;
    }

    public static int getNbDonnee() {
        return nbDonnee;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public int getIDMap() {
        return IDMap;
    }

    public void setIDMap(int IDMap) {
        this.IDMap = IDMap;
    }

    public Coordonnee getCoord() {
        return Coord;
    }

    public void setCoord(Coordonnee coord) {
        Coord = coord;
    }

    public String getInfo() {
        return Info;
    }

    public void setInfo(String info) {
        Info = info;
    }

    public int getType() {
        return Type;
    }

    public void setType(int type) {
        Type = type;
    }

    /**
     * @param o
     * @return Test si une Donnee est la même qu'une autre
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Donnee donnee = (Donnee) o;
        return ID == donnee.ID && IDMap == donnee.IDMap && Type == donnee.Type && Objects.equals(Coord, donnee.Coord) && Objects.equals(Info, donnee.Info);
    }

    /**
     * @return Info de la classe Donnee
     */
    @Override
    public String toString() {
        return "Donnee{" +
                "ID=" + ID +
                ", IDMap=" + IDMap +
                ", " + Coord.toString() +
                ", Info='" + Info + '\'' +
                ", Type=" + Type +
                '}';
    }
}
