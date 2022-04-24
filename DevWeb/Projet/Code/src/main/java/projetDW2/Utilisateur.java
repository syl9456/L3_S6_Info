package projetDW2;

import java.util.Objects;

public class Utilisateur {

    private String Pseudo;
    private String Image;
    private int ID;

    public Utilisateur(int ID, String pseudo, String Image) {
        this.Pseudo = pseudo;
        this.Image = Image;
        this.ID = ID;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getPseudo() {
        return Pseudo;
    }

    public void setPseudo(String pseudo) {
        Pseudo = pseudo;
    }
    
    public String getImage() {
        return Image;
    }

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
     * @return Test si un Utilisateur est le même qu'un autre
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Utilisateur that = (Utilisateur) o;
        return Objects.equals(Pseudo, that.Pseudo) && Objects.equals(Image, that.Image) && Objects.equals(ID, that.ID);
    }
}
