package tchatche;
import java.time.LocalDateTime;

public class Message {
	
	public int NUM_MESSAGE;
	public static int nbMessages = 0;
	public String Pseudo;
	public String Texte;
	public LocalDateTime dateMessage;
	
	public Message(String P, String T, LocalDateTime D){
		Pseudo = P;
		Texte = T;
		dateMessage = D;
		nbMessages++;
		NUM_MESSAGE = nbMessages;
	}
	
}
