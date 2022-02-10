package devWebTP1;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {

	public static void main(String[] args) throws UnknownHostException, IOException {
		// TODO Auto-generated method stub
		
		String commande = "5\n";
		System.out.println("Envoi : " + commande);
		
		final int PORT =8888;
		Socket s = new Socket("localhost", PORT);
	
		// obtention des flux d'octets
		
		InputStream in1 = s.getInputStream();
		OutputStream out1 = s.getOutputStream();
				
		BufferedReader reader = new BufferedReader(new InputStreamReader(in1));
				
		PrintWriter writer = new PrintWriter(out1);
			
			
		writer.print(commande);
		writer.flush();
			
		String reponse = reader.readLine();
		System.out.println(" RECU :" + reponse);
			
		commande = "xyz";
		writer.print(commande);
		writer.flush();
		
		s.close();
			
			
	}

}
