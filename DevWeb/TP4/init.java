package tchatche;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Map;

import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class init
 */
@WebServlet("/init")
public class init extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @throws ServletException 
     * @see HttpServlet#HttpServlet()
     */
	
	public init() throws ServletException {
		super();
	}
	
	
	public init(ServletConfig config) throws ServletException {
        super.init(config);
        ServletContext servletContext = this.getServletContext();
        /* On déclare la liste des Utilisateur et des Messages et on les met dans le context */
        ArrayList<Message> listeMessage = new ArrayList<Message>();
        Hashtable<String, Integer> listeUtil = new Hashtable<String, Integer>();
        /* On enregistre les 2 listes dans le context */
        servletContext.setAttribute("listeMessage", listeMessage);
        servletContext.setAttribute("listeUtil", listeUtil);
        
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	@SuppressWarnings("unchecked")
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		ServletContext servletContext = request.getServletContext();
		String Pseudo = request.getParameter("Pseudo");
		HttpSession session = request.getSession(true);
		session.setAttribute("Pseudo", Pseudo);
		/* On récupère la HashTable des Utilisateur et */ /* On rajoute l'utilisateur */
		Hashtable<String, Integer> tmpListeUtil = (Hashtable<String, Integer>) servletContext.getAttribute("listeUtil");
		/* On rajoute l'utilisateur */
		tmpListeUtil.put(Pseudo, 0);
		/* On met a jour le context */
		servletContext.setAttribute("listeUtil", tmpListeUtil);
		 /* On redirige */
		response.sendRedirect("tchatche.html");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
