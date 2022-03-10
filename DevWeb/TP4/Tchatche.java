package tchatche;

import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class Tchatche
 */
@WebServlet("/Tchatche")
public class Tchatche extends HttpServlet {
	private static final long serialVersionUID = 1L;
	ArrayList<Message> listeMessage = new ArrayList<Message>();
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Tchatche() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		HttpSession session = request.getSession(true); /* On récup la session */
		String Pseudo = (String)session.getAttribute("Pseudo");
	    /* On affiche le Pseudo */
		response.getWriter().println("<h1>Bonjour " + Pseudo + "</h1><br><br>");
		/* On affiche la liste des messages */
		for(int i = 0; i < listeMessage.size(); i++) {
			String ligne = "";
			ligne += listeMessage.get(i).dateMessage;
			ligne += " " + listeMessage.get(i).Pseudo;
			ligne += " : " + listeMessage.get(i).Texte;
			response.getWriter().println(ligne + "<br>");
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession(true); /* On récup la session */
		/* On setup le message */
		String textMessage = request.getParameter("Message");
		String Pseudo = (String)session.getAttribute("Pseudo");
		LocalDate maintenant = LocalDate.now();
		Message mess = new Message(Pseudo, textMessage, maintenant);
		listeMessage.add(mess);
		response.sendRedirect("tchatche.html");
		doGet(request, response);
	}

}
