package devWebTP1;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;

public class Serveur {
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub

		
		final int PORT = 8888;
		
		InetAddress localhost = InetAddress.getLocalHost();
		
		System.out.println("Bip Boop Démarrage du Service Cash Convertor");
		
		ServerSocket server = new ServerSocket(PORT, 1);
		
		System.out.println("En attente d'un montant a convertir...");
		
		while (true) {
			
			Socket s = server.accept();
			
			BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
			
			PrintWriter out = new PrintWriter(s.getOutputStream());
			
			//TODO 
			
			String input = in.readLine();
			boolean finis = false;
			double valeur;
			
			if(input.compareTo("xyz") == 0) {
				System.out.println("BYE!");
				s.close();
				finis = true;
			}
			
			while(!finis) {
				String commande = "La somme [" + input + "$] converti en Euros donne [" + Integer.valueOf(input)*0.88 + "€]\n";
				out.print(commande);
				out.flush();
				input = in.readLine();
				if(input.compareTo("xyz") == 0) {
					System.out.println("BYE!");
					s.close();
					finis = true;
				}
			}
		}
	}

	private static double valueOf(String input) {
		// TODO Auto-generated method stub
		return 0;
	}		
}

