package devWebTP1;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class ClientUDP {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		/*
		if ( args.length <2) {
			System.err.println("usage : java EchoUDOClient [nom serveur] [message]");
			System.exit(1);
		}*/
		
		//byte[] message = args[1].getBytes();
		byte[] message = "qskdkqsd".getBytes();
		String host = "localhost";
		DatagramSocket socket = null;
		
		int port = 10000;
		try {
			InetAddress serveur = InetAddress.getByName(host);
			DatagramPacket envoi = new DatagramPacket(message, message.length, serveur, port);
			socket = new DatagramSocket();
			socket.send(envoi);
			
			System.out.println("Le message " +message + " a ete envoye");
			
			
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
			int taille = 1024;
		
			try {
				socket.setSoTimeout(2000);
				DatagramPacket reception = new DatagramPacket(new byte[taille], taille);
				socket.receive(reception);
				
				System.out.println("On a recu " + new String(reception.getData(), 0, reception.getLength()));
				System.out.println("depuis" + reception.getAddress() + "port" + reception.getPort());
				
				
			} catch (SocketException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		
		
		
		
		
		
		
		
		
	}

}
