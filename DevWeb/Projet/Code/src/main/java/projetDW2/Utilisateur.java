package projetDW2;

import java.util.Objects;

/**
 * Class pour stocker un Utilisateur
 */

public class Utilisateur {

    private String Pseudo;
    private String Image;
    private int ID;

    /**
     * @param ID
     * @param pseudo
     * @param Image
     */
    public Utilisateur(int ID, String pseudo, String Image) {
        this.Pseudo = pseudo;
        this.Image = Image;
        this.ID = ID;
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
    public String getPseudo() {
        return Pseudo;
    }

    /**
     * @param pseudo
     */
    public void setPseudo(String pseudo) {
        Pseudo = pseudo;
    }
    
    /**
     * @return
     */
    public String getImage() {
        return Image;
    }

    /**
     * @param image
     */
    public void setImage(String image) {
        Image = image;
    }


    /**
     * @return Infos de la classe Utilisateur
     */
    @Override
    public String toString() {
        return "Utilisateur{" +
                "Pseudo='" + Pseudo + '\'' +
                ", Image='" + Image + '\'' +
                '}';
    }

    /**
     * @param o
     * @return Test si un Utilisateur est le meme qu'un autre
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Utilisateur that = (Utilisateur) o;
        return Objects.equals(Pseudo, that.Pseudo) && Objects.equals(Image, that.Image) && Objects.equals(ID, that.ID);
    }
}
