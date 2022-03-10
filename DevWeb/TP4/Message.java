package tchatche;
import java.time.LocalDate;

public class Message {
	
	public int NUM_MESSAGE;
	public static int nbMessages = 0;
	public String Pseudo;
	public String Texte;
	public LocalDate dateMessage;
	
	public Message(String P, String T, LocalDate D){
		Pseudo = P;
		Texte = T;
		dateMessage = D;
		nbMessages++;
		NUM_MESSAGE = nbMessages;
	}
	
}
