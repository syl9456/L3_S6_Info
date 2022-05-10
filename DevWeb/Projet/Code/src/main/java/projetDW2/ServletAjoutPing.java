package projetDW2;

import java.io.IOException;
import java.sql.*;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ServletAjoutPing
 */
@WebServlet("/ServletAjoutPing")
public class ServletAjoutPing extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ServletAjoutPing() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		/* ON DECLARE LES VARIABLE POUR CREER UNE DONNEE */
		String ping = request.getParameter("ping");
		int X = Integer.parseInt(request.getParameter("X"));
		int Y = Integer.parseInt(request.getParameter("Y"));
		Coordonnee c = new Coordonnee(X, Y);
		int idMap = (int)request.getSession().getAttribute("mapActuel");
		String info = "Je suis un ping de type [" + ping + "]";
		
		Donnee d = new Donnee(idMap, c, info, ping);
		
		/* On y ajoute a la BDD */
		
		String requete = "INSERT INTO donnee(MapID, CoordX, CoordY, Info, Type) VALUES(" + idMap + ", " + X + ", " + Y + ", '" + info + "', '" + ping + "')";
		
		try{
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
            Statement st = conn.createStatement();
            int rst = st.executeUpdate(requete);
            if(rst > 0) {
            	ListeDonnee LDon = (ListeDonnee)request.getServletContext().getAttribute("LDon");
            	LDon.getListeDonnee().add(d);
            	request.getServletContext().setAttribute("LDon", LDon);
            	getServletContext().setAttribute("Reload", 1);
            	/* On attends 2 sec que les autre utilisateurs ont l'info de refrsh la page */
                try {
        			Thread.sleep(120);
        		} catch (InterruptedException e1) {
        			// TODO Auto-generated catch block
        			e1.printStackTrace();
        		}
                getServletContext().setAttribute("Reload", 0);
            	st.close();
            	conn.close();
            }
	    }
	    catch(Exception e) {
	        System.out.print(e);
	        e.printStackTrace();
	    }
		
	}

}
