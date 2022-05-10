package projetDW2;

import java.util.Objects;

/**
 * Class pour stocker un ping
 */

public class Donnee {

    private static int nbDonnee = 0;
    private int ID;
    private int IDMap;
    private Coordonnee Coord;
    private String Info;
    private String Type;

    /**
     * @param IDMap
     * @param coord
     * @param info
     * @param type
     */
    public Donnee(int IDMap, Coordonnee coord, String info, String type) {
        this.IDMap = IDMap;
        this.Coord = coord;
        this.Info = info;
        this.Type = type;
        nbDonnee++;
        this.ID = nbDonnee;
    }

    /**
     * @return
     */
    public static int getNbDonnee() {
        return nbDonnee;
    }

    /**
     * @return
     */
    public int getID() {
        return ID;
    }

    /**
     * @param ID
     */
    public void setID(int ID) {
        this.ID = ID;
    }

    /**
     * @return
     */
    public int getIDMap() {
        return IDMap;
    }

    /**
     * @param IDMap
     */
    public void setIDMap(int IDMap) {
        this.IDMap = IDMap;
    }

    /**
     * @return
     */
    public Coordonnee getCoord() {
        return Coord;
    }

    /**
     * @param coord
     */
    public void setCoord(Coordonnee coord) {
        Coord = coord;
    }

    /**
     * @return
     */
    public String getInfo() {
        return Info;
    }

    /**
     * @param info
     */
    public void setInfo(String info) {
        Info = info;
    }

    /**
     * @return
     */
    public String getType() {
        return Type;
    }

    /**
     * @param type
     */
    public void setType(String type) {
        Type = type;
    }

    /**
     * @param o
     * @return Test si une Donnee est la meme qu'une autre
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
