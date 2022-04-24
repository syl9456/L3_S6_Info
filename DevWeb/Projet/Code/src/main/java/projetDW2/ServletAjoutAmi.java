package projetDW2;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;


/**
 * Servlet implementation class ServletAjoutAmi
 */
@WebServlet("/ServletAjoutAmi")
public class ServletAjoutAmi extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ServletAjoutAmi() {
        super();
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		int idUtil = (int)request.getSession().getAttribute("idUtil");
		String ami = request.getParameter("_ami");
		int idAmi;
		/* On récupère l'id de l'amis que l'ont veux ajouter */
		try {
	         /* Database */
	         Class.forName("com.mysql.jdbc.Driver");
	         Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
	         String requete = "SELECT UtilID FROM utilisateur WHERE Pseudo LIKE '" + ami + "'";
	         Statement st = conn.createStatement();
	         ResultSet rst = st.executeQuery(requete);
	         if(rst.next()){
	        	 idAmi = rst.getInt("UtilID");
	        	 /* On insere l'amis vue quue l'on a son ID */
	        	 String insertAmi = "INSERT INTO amitie (UtilID1, UtilID2) VALUES (" + idUtil + ", " + idAmi + ")";
	        	 int rst2 = st.executeUpdate(insertAmi);
	        	 rst.close();
	             st.close();
	             conn.close();
	             response.sendRedirect("profil.jsp");
	         }
	         else {
	        	 rst.close();
	             st.close();
	             conn.close();
	             response.sendRedirect("profil.jsp");
	         }
		}
		catch(Exception e) {
			e.getStackTrace();
			response.sendRedirect("profil.jsp");
		}
	}

}
