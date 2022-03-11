package tchatche;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Hashtable;

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
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession();
		/* On instancie la veriable de session pseudo le pseudo renseigné */
	    session.setAttribute("Pseudo", request.getParameter("Pseudo"));
	    response.sendRedirect("tchatche.html");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	@SuppressWarnings("unchecked")
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession();
		
		/* Instanciation de la liste de message si elle n'existe pas */
	    if(getServletContext().getAttribute("listeMessage") == null){
	    	ArrayList<Message> tmpListeMessage = new ArrayList<Message>();
	    	getServletContext().setAttribute("listeMessage", tmpListeMessage);
	    }
	    
	    /* Instanciation de la liste d'utilisateur si elle n'existe pas */
	    if(getServletContext().getAttribute("listeUtil") == null){
	    	Hashtable<String, Integer> tmpListUtil= new Hashtable<String, Integer>();
	    	tmpListUtil.put(request.getParameter("Pseudo"), 0);
	      	getServletContext().setAttribute("listeUtil", tmpListUtil);
	    }
	    else{
	    	((Hashtable<String, Integer>)getServletContext().getAttribute("listeUtil")).put(request.getParameter("Pseudo"), 0);
	    }
	    /* On instancie la veriable de session pseudo le pseudo renseigné */
	    session.setAttribute("Pseudo", request.getParameter("Pseudo"));
	    response.sendRedirect("tchatche.html");
	}

}
