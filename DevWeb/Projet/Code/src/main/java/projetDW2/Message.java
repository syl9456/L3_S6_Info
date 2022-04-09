package projetDW2;

import java.util.Objects;

public class Message {

    private int ID;
    private int IDAuteur;
    private String Text;

    private static int nbMess = 0;

    public Message(int IDAuteur, String text) {
        this.IDAuteur = IDAuteur;
        this.Text = text;
        nbMess++;
        this.ID = nbMess;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public int getIDAuteur() {
        return IDAuteur;
    }

    public void setIDAuteur(int IDAuteur) {
        this.IDAuteur = IDAuteur;
    }

    public String getText() {
        return Text;
    }

    public void setText(String text) {
        Text = text;
    }

    public static int getNbMess() {
        return nbMess;
    }

    /**
     * @param o
     * @return test si un Message est le même qu'un autre
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Message message = (Message) o;
        return ID == message.ID && IDAuteur == message.IDAuteur && Objects.equals(Text, message.Text);
    }

    /**
     * @return Info de la classe Message
     */
    @Override
    public String toString() {
        return "Message{" +
                "ID=" + ID +
                ", IDAuteur=" + IDAuteur +
                ", Text='" + Text + '\'' +
                '}';
    }
}
