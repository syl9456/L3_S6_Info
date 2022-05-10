package projetDW2;

import java.util.Objects;

/**
 * Class pour stocker un Message
 */

public class Message {

    private static int nbMess = 0;
    private int ID;
    private int IDAuteur;
    private String PseudoAuteur;
    private String Text;

    /**
     * @param IDAuteur
     * @param text
     * @param PsAu
     */
    public Message(int IDAuteur, String text, String PsAu) {
        this.IDAuteur = IDAuteur;
        this.Text = text;
        this.PseudoAuteur = PsAu;
        nbMess++;
        this.ID = nbMess;
    }

    /**
     * @return
     */
    public static int getNbMess() {
        return nbMess;
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
    public int getIDAuteur() {
        return IDAuteur;
    }

    /**
     * @param IDAuteur
     */
    public void setIDAuteur(int IDAuteur) {
        this.IDAuteur = IDAuteur;
    }

    /**
     * @return
     */
    public String getPseudoAuteur() {
        return PseudoAuteur;
    }

    /**
     * @param pseudoAuteur
     */
    public void setPseudoAuteur(String pseudoAuteur) {
        PseudoAuteur = pseudoAuteur;
    }

    /**
     * @return
     */
    public String getText() {
        return Text;
    }

    /**
     * @param text
     */
    public void setText(String text) {
        Text = text;
    }

    /**
     * @param o
     * @return test si un Message est le meme qu'un autre
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Message message = (Message) o;
        return ID == message.ID && IDAuteur == message.IDAuteur && Objects.equals(PseudoAuteur, message.PseudoAuteur) && Objects.equals(Text, message.Text);
    }

    /**
     * @return Info de la classe Message
     */
    @Override
    public String toString() {
        return "Message{" +
                "ID=" + ID +
                ", IDAuteur=" + IDAuteur +
                ", PseudoAuteur=" + PseudoAuteur +
                ", Text='" + Text + '\'' +
                '}';
    }
}
