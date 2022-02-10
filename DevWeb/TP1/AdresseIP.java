package devWebTP1;
import java.net.*;

public class AdresseIP {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		try {
			InetAddress localhost = InetAddress.getLocalHost();
			
			System.out.println("On est sur : " + localhost);
			System.out.println("  nom : " + localhost.getHostName());
			System.out.println("  adresse : " + localhost.getHostAddress());
			System.out.println();
			
			String nom = "www.google.com";
			
			
			System.out.println("Machines dont le nom est " + nom);
			InetAddress[] adressesIP = InetAddress.getAllByName(nom);
			
			for (int i=0; i<adressesIP.length;i++) {
				System.out.println(adressesIP[i]);
				System.out.print("  nom: " + adressesIP[i].getHostName());
				System.out.print("  adresse  "  + adressesIP[i].getHostAddress());
				
			}
			System.out.println();
		
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}

