package devWebTP1;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.*;

public class OpenURL {
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
			URL url = new URL("http://www.univ-st-etienne.fr");

		    // create a urlconnection object
		    URLConnection urlConnection = url.openConnection();

		    // wrap the urlconnection in a bufferedreader
		    BufferedReader dis = new BufferedReader(new InputStreamReader(urlConnection.getInputStream()));
			
			// manque qq chose
		    String inputLine;
		    while((inputLine = dis.readLine()) != null) {
		    	System.out.println(inputLine);
		    }
		    dis.close();
	
		
	}

}
