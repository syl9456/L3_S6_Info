package tchatche;

import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Hashtable;

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
	@SuppressWarnings("unchecked")
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		HttpSession session = request.getSession(true); /* On récup la session */
		String Pseudo = (String)session.getAttribute("Pseudo");
	    /* On affiche le Pseudo */
		response.getWriter().println("<h1>Bonjour " + Pseudo + "</h1><br><br>");
		/* On récup la liste des message dans le context */
		ArrayList<Message> tmpListeMessage = (ArrayList<Message>)getServletContext().getAttribute("listeMessage");
		/* On affiche la liste des messages */
		for(int i = 0; i < tmpListeMessage.size(); i++) {
			String ligne = "";
			ligne += tmpListeMessage.get(i).dateMessage;
			ligne += " " + tmpListeMessage.get(i).Pseudo;
			ligne += " : " + tmpListeMessage.get(i).Texte;
			response.getWriter().println(ligne + "<br>");
		}
		response.setIntHeader("Refresh", 1);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	@SuppressWarnings("unchecked")
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession(true); /* On récup la session */
		/* On setup le message */
		String textMessage = request.getParameter("Message");
		String Pseudo = (String)session.getAttribute("Pseudo");
		LocalDate maintenant = LocalDate.now();
		Message mess = new Message(Pseudo, textMessage, maintenant);
		/* On récup la liste des message et la HashTable des Utilisateurs dans le context */
		ArrayList<Message> tmpListeMessage = (ArrayList<Message>)getServletContext().getAttribute("listeMessage");
		Hashtable<String, Integer> tmpListeUtil = (Hashtable<String, Integer>)getServletContext().getAttribute("listeUtil");
		/* On ajoute le Message */
		tmpListeMessage.add(mess);
		/* On met a jour la HashTable Utilisateur (+1 au nb de message posté) */
		tmpListeUtil.put(Pseudo, tmpListeUtil.get(Pseudo) + 1);
		/* On remet tout dans le context */
		getServletContext().setAttribute("listeUtil", tmpListeUtil);
		getServletContext().setAttribute("listeMessage", tmpListeMessage);
		/* On redirige */
		response.sendRedirect("tchatche.html");
		doGet(request, response);
	}

}
