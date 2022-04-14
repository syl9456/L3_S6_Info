package projetDW2;

import java.util.ArrayList;
import java.util.Objects;

public class ListeMessage {
    private ArrayList<Message> listeMessage;

    public ListeMessage() {
        this.listeMessage = new ArrayList<Message>();
    }

    public ListeMessage(ArrayList<Message> listeMessage) {
        this.listeMessage = listeMessage;
    }

    public ArrayList<Message> getListeMessage() {
        return listeMessage;
    }

    public void setListeMessage(ArrayList<Message> listeMessage) {
        this.listeMessage = listeMessage;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ListeMessage that = (ListeMessage) o;
        return Objects.equals(listeMessage, that.listeMessage);
    }

    @Override
    public String toString() {
        String lMessage = "";
        for (Message m : listeMessage) {
            lMessage += m.toString();
        }
        return "ListeMessage{" +
                "listeMessage=" + lMessage +
                '}';
    }
}
