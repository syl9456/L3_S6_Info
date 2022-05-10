package projetDW2;

import jakarta.servlet.http.HttpServlet;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ServletLoadData
 */
@WebServlet("/ServletLoadData")
public class ServletLoadData extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ServletLoadData() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		/* On déclare la liste de Map - Donnee - Acces - Utilisateur */
		
		ListeMap LMap = new ListeMap();
		ListeDonnee LDon = new ListeDonnee();
		ListeAcces LAcc = new ListeAcces();
		ListeUtilisateur LUtil = new ListeUtilisateur();
		
		/* On charge les donnee des Donnees */
		
        try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
	        Statement st = conn.createStatement();
	        String requete = "SELECT MapID, CoordX, CoordY, Info, Type FROM donnee";
			ResultSet rst = st.executeQuery(requete);
			while(rst.next()){
				 Donnee d = new Donnee(rst.getInt("MapID"), 
						 			   new Coordonnee(rst.getInt("CoordX"), rst.getInt("CoordY")),
						 			   rst.getString("Info"),
						 			   rst.getString("Type"));
				 LDon.getListeDonnee().add(d);
			}
			rst.close();
			st.close();
			conn.close();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
        
        /* On charge les donnee des Utilisateurs */
		
        try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
	        Statement st = conn.createStatement();
	        String requete = "SELECT UtilID, Pseudo, Image FROM utilisateur";
			ResultSet rst = st.executeQuery(requete);
			while(rst.next()){
				 Utilisateur u = new Utilisateur(rst.getInt("UtilID"),
						 						 rst.getString("Pseudo"), 
						 						 rst.getString("Image"));
				 LUtil.getListeUtilisateur().add(u);
			}
			rst.close();
			st.close();
			conn.close();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
        
        /* On charge les donnee des Acces */
		
        try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
	        Statement st = conn.createStatement();
	        String requete = "SELECT UtilID, MapID, Droit FROM utilaccesmap";
			ResultSet rst = st.executeQuery(requete);
			while(rst.next()){
				 Acces a = new Acces(rst.getInt("UtilID"),
						 			 rst.getInt("MapID"), 
						 			 rst.getInt("Droit"));
				 LAcc.getListeAcces().add(a);
			}
			rst.close();
			st.close();
			conn.close();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
        
        /* On charge les donnee des Maps */
		
        try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
	        Statement st = conn.createStatement();
	        String requete = "SELECT MapID, ProprioID, Nom, SrcBackground FROM map";
			ResultSet rst = st.executeQuery(requete);
			while(rst.next()){
				 Map m = new Map(rst.getInt("MapID"),
						 		 rst.getInt("ProprioID"),
						 		 rst.getString("Nom"),
						 		 rst.getString("SrcBackground"));
				 LMap.getListeMap().add(m);
			}
			rst.close();
			st.close();
			conn.close();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
        
        /* On stocke tout ça dans le context */
        
        request.getServletContext().setAttribute("LMap", LMap);
        request.getServletContext().setAttribute("LDon", LDon);
        request.getServletContext().setAttribute("LAcc", LAcc);
        request.getServletContext().setAttribute("LUtil", LUtil);
        request.getServletContext().setAttribute("Charge", 1);
		
        response.sendRedirect("index.jsp");
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
