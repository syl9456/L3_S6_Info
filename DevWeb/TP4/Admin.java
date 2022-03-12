package tchatche;

import java.io.IOException;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Map.Entry;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Admin
 */
@WebServlet("/Admin")
public class Admin extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Admin() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		/* On affiche la liste des utilisateurs et leurs nombre de messages */
	    if(getServletContext().getAttribute("listeUtil") != null){
	    	@SuppressWarnings("unchecked")
			Iterator<Entry<String, Integer>> itr = ((Hashtable<String, Integer>) getServletContext().getAttribute("listeUtil")).entrySet().iterator();
	    	Entry<String, Integer> entry = null;
	    	while(itr.hasNext()) {
	    		entry = itr.next();
	    		response.getWriter().println(entry.getKey() + " a posté " + entry.getValue() + " messages");
	    	}
	    } 
	    /* On affiche le bouton pour enregistrer la conv */
	    response.setContentType("text/html");
        response.setCharacterEncoding("UTF-8");
	    response.getWriter().println("<br><br><iframe name=\"hiddenFrame\" width=\"0\" height=\"0\" border=\"0\" style=\"display: none;\"></iframe>"
	    		+ "<form action=\"Save\" method=\"post\" class=\"formSave\" target=\"hiddenFrame\"> \r\n"
	    		+ "	    <input type=\"submit\" value=\"Enregistrer la Conversation\">\r\n"
	    		+ "	</form><br>");
	    /* On affiche nb affichage et taille donnée envoyé a l'utilisateur */
	    response.getWriter().println("Nombre d'affichage : " + getServletContext().getAttribute("nbAffichages") + "<br>");
	    response.getWriter().println("Taille données reçu : " + getServletContext().getAttribute("tailleDonnees"));
	    /* On rafraichis la page toute les secondes */
	    response.setIntHeader("Refresh", 1);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}
	
	protected void save() {
		
	}

}
