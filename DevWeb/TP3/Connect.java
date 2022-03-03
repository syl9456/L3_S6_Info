package devwebbdd;
import java.sql.*;
import com.mysql.*;

public class Connect {
	
	public Connect() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		String url = "jdbc:mysql://localhost:3306/tp3bdd";
		try {
			Connection c = DriverManager.getConnection(url, "root", "");
			System.out.println("Connection Réussi !");
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("Connection Échoué !");
		}
	}

}
