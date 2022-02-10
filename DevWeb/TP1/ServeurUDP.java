package devWebTP1;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class ServeurUDP {

	
	public static final int PORT_ECHO = 10000;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int taille =1024;
		byte[] tampon = new byte[taille];
		
		String message = null;
		
		try {
			DatagramSocket socket = new DatagramSocket(PORT_ECHO);
			
			do {
				// format du paquet a recevoir
				DatagramPacket paquet = new DatagramPacket(tampon, taille);
				// recevoir paquet du client
				socket.receive(paquet);
				// l'extraire dans la variable message
				message = new String(paquet.getData(),0, paquet.getLength());
				//afficher le paquet recu
				
				System.out.println("message :" +message);
				// et d'ou il provient
				System.out.println("machine " + paquet.getAddress() + " port " + paquet.getPort());
				
				// envoie la reponse au client, ici on envoie la meme chose qu'on a recu
				
				
				
				byte[] abou = "abouche".getBytes();
				DatagramPacket paquet1 = new DatagramPacket(abou, abou.length, paquet.getAddress(), paquet.getPort());
				
			
				
				socket.send(paquet1);
				
				
			} while (! message.equals("stop"));
			
			
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		
	}

}
