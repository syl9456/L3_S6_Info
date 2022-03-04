package tp3;
import java.sql.*;
import java.time.LocalDate;
import java.time.Period;

public class Connect {
	
	public Connection c;
	public Statement st;
	public ResultSet reponse;
	public int valideManipulation;
	
	public Connect() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		String url = "jdbc:mysql://localhost:3306/tp3bdd";
		try {
			c = DriverManager.getConnection(url, "root", "");
			System.out.println("Connection Réussi !");
			System.out.println("On créer le statement...");
			st = c.createStatement();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("Connection Échoué !");
		}
	}
	
	public void close() throws SQLException {
		System.out.println("On ferme la connection et le statement...");
		st.close();
		c.close();
	}
	
	public void reqSQL(String query, char type) throws SQLException{
		if(type != 's' && type != 'm'){
			System.out.println("Erreur dans le type, attendu : [s ou m] et vous avez rentrez :[" + type + "]");
		}
		else if(type == 's'){
			reponse = st.executeQuery(query);
			afficheReqIntero(query);
		}
		else{
			valideManipulation = st.executeUpdate(query);
		}
	}
	
	public void afficheReqIntero(String maRequete) throws SQLException {
		ResultSetMetaData metadata = reponse.getMetaData();
		String nomColonne = "| ";
		for (int i = 0; i < metadata.getColumnCount(); i++) {
			nomColonne += metadata.getColumnName(i+1) + " | ";
		}
		System.out.println();
		System.out.println("Requete : [" + maRequete +"]");
		System.out.println();
		System.out.println(nomColonne);
		System.out.println();
		String affiche = "| ";
		while(reponse.next()) {
			for (int i = 0; i < metadata.getColumnCount(); i++) {
				affiche += reponse.getString(i+1) + " | ";
			}
			System.out.println(affiche);
			affiche = "| ";
		}
		System.out.println();
	}
	
	public void execReqManip(int choixReq) throws SQLException {
		String maRequete;
		switch(choixReq){
			case 1:
				maRequete = "INSERT INTO utilisateur (Nom, Prenom, DateNaissance, Login, Mdp) VALUES ('Pereira', 'Jeoffrey', '1999-07-08', 'Godefroy', 'blabla')";
				this.reqSQL(maRequete, 'm');
				break;
			case 2:
				maRequete = "INSERT INTO utilisateur (Nom, Prenom, DateNaissance, Login, Mdp) VALUES ('Hauf', 'Jocelin', '1999-08-08', 'Jojo', 'boubou')";
				this.reqSQL(maRequete, 'm');
				break;
			case 3:
				maRequete = "INSERT INTO utilisateur (Nom, Prenom, DateNaissance, Login, Mdp) VALUES ('Rome', 'Sylvain', '2000-01-08', 'Xeos', 'foufou')";
				this.reqSQL(maRequete, 'm');
				break;
			case 4:
				maRequete = "DELETE FROM utilisateur WHERE Nom LIKE 'Gonzalez'";
				this.reqSQL(maRequete, 'm');
				break;
			case 5:
				maRequete = "DELETE FROM utilisateur WHERE Prenom LIKE 'Sylvain'";
				this.reqSQL(maRequete, 'm');
				break;
		}
	}
	
	public void execReqIntero(int choixReq) throws SQLException {
		String maRequete;
		switch(choixReq){
			case 1:
				maRequete = "SELECT * FROM utilisateur";
				this.reqSQL(maRequete, 's');
				break;
			case 2:
				maRequete = "SELECT * FROM utilisateur WHERE Nom LIKE 'Doffemont'";
				this.reqSQL(maRequete, 's');
				break;
			case 3:
				maRequete = "SELECT * FROM communaute";
				this.reqSQL(maRequete, 's');
				break;
			case 4:
				maRequete = "SELECT * FROM utilisateur WHERE Prenom LIKE 'Mathieu'";
				this.reqSQL(maRequete, 's');
				break;
			case 5:
				maRequete = "SELECT * FROM utilisateur WHERE Login LIKE 'Shooterah'";
				this.reqSQL(maRequete, 's');
				break;
		}
	}
	
	public void inscriptionRandom() throws SQLException{
		
		int nbLettreP;
		int nbLettreN;
		String Nom = "";
		String Prenom = "";
		String maRequete = "";
		for(int i = 0; i < 10000; i++) {
			nbLettreP = (int)(3 + (Math.random() * 10)); /* Prénom Entre 3 et 10 Lettre */
			nbLettreN = (int)(3 + (Math.random() * 10)); /* Nom Entre 3 et 10 Lettre */
			for(int y = 0; y < nbLettreP; y++) {
				Prenom += (char)(65 + (int)(Math.random() * (91 - 65))); /* Lettre en a et z */
			}
			for(int y = 0; y < nbLettreN; y++) {
				Nom += (char)(65 + (int)(Math.random() * (91 - 65))); /* Lettre en a et z */
			}
			maRequete = "INSERT INTO utilisateur (Nom, Prenom) VALUES ('" + Nom + "', '" + Prenom + "')";
			this.reqSQL(maRequete, 'm');
			Nom = "";
			Prenom = "";
			maRequete = "";
		}
	}
	
	public int getAge(int id_personne) throws SQLException{
		
		LocalDate today = LocalDate.now();
		
		reponse = st.executeQuery("SELECT DateNaissance FROM utilisateur WHERE Id = " + id_personne + "");
		
		while(reponse.next()){
			if(reponse.getDate(1) != null) {
				LocalDate anniv = Date.valueOf(reponse.getDate(1).toString()).toLocalDate();
				return  Period.between(anniv, today).getYears();
			}
			else {
				return 0;
			}
		}
		
		return 0;
	}
	
	

}
