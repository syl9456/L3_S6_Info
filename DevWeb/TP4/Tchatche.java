package tchatche;

import java.io.IOException;
import java.time.LocalDateTime;
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
	private long lastModified = 0;
       
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
		/* On récupère le ifmodified since */
		long lastModifiedClient = request.getDateHeader("If-Modified-Since");
		/* Si aucun nouveau message */
		if(lastModifiedClient > this.lastModified) {
			/* On envois HTTP 304 */
			response.setStatus(HttpServletResponse.SC_NOT_MODIFIED);
		}
		else{
			/* Si nouveau message */
			/* On affiche le Pseudo */
			response.getWriter().println("<h1>Bonjour " + Pseudo + "</h1>");
			/* On affiche le nb d'utilisateurs connecté */
			int nbUtil = ((Hashtable<String,Integer>)getServletContext().getAttribute("listeUtil")).size();
			response.getWriter().println("<h3>Nombre d'utilisateur connecté : [" + nbUtil + "]</h3><br><br>");
			/* On récup la liste des message dans le context */
			ArrayList<Message> tmpListeMessage = (ArrayList<Message>)getServletContext().getAttribute("listeMessage");
			/* On affiche la liste des messages */
			for(int i = 0; i < tmpListeMessage.size(); i++) {
				String ligne = "[";
				ligne += tmpListeMessage.get(i).dateMessage.getHour() + ":";
				ligne += tmpListeMessage.get(i).dateMessage.getMinute() + ":";
				ligne += tmpListeMessage.get(i).dateMessage.getSecond() + "]";
				ligne += " " + tmpListeMessage.get(i).Pseudo;
				ligne += " : " + tmpListeMessage.get(i).Texte;
				response.getWriter().println(ligne + "<br>");
				/* Met a jour la taille des données envoyé */
				getServletContext().setAttribute("tailleDonnees", (int)getServletContext().getAttribute("tailleDonnees") + ligne.length());
			}
			/* On fait nbAffichage ++ */
			getServletContext().setAttribute("nbAffichages", (int)getServletContext().getAttribute("nbAffichages") + 1);
			/* On redirige */
			response.setIntHeader("Refresh", 1);
		}
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
		LocalDateTime maintenant = LocalDateTime.now();
		/* On enregistre l'heure du dernier message et on l'envois  au client via l’en-tête HTTP Last-Modified */
		this.lastModified = System.currentTimeMillis();
		response.setDateHeader("Last-Modified", this.lastModified);
		/* On créer le nouveau message */
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
	}

}
