package projetDW2;

import java.util.Objects;

public class Utilisateur {

    private static int nbUtil = 0;
    private String Pseudo;
    private String MDP;
    private int ID;

    public Utilisateur(String pseudo, String MDP) {
        this.Pseudo = pseudo;
        this.MDP = MDP;
        nbUtil++;
        this.ID = nbUtil;
    }

    public static int getNbUtil() {
        return nbUtil;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getMDP() {
        return MDP;
    }

    public void setMDP(String MDP) {
        this.MDP = MDP;
    }

    public String getPseudo() {
        return Pseudo;
    }

    public void setPseudo(String pseudo) {
        Pseudo = pseudo;
    }


    /**
     * @return Infos de la classe Utilisateur
     */
    @Override
    public String toString() {
        return "Utilisateur{" +
                "Pseudo='" + Pseudo + '\'' +
                ", MDP='" + MDP + '\'' +
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
        return Objects.equals(Pseudo, that.Pseudo) && Objects.equals(MDP, that.MDP);
    }
}
