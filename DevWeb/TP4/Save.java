package tchatche;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Save
 */
@WebServlet("/Save")
public class Save extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final String cheminFichier = "C:\\Users\\flori\\eclipse-workspace\\Tchatche\\src\\main\\webapp\\WEB-INF\\ressources\\save.txt";
       
    /**
     * @see HttpServlet#HttpServlet()
     */

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		/* On cherche le fichier de sauvegarde */
		File outFile = new File(cheminFichier);
		FileWriter writer = new FileWriter(outFile);
		/* On récupere la liste de Message */
		@SuppressWarnings("unchecked")
		ArrayList<Message> tmpListeMessage = (ArrayList<Message>)getServletContext().getAttribute("listeMessage");
		/* On fait un string avec les données */
		for(int i = 0; i < tmpListeMessage.size(); i++) {
			String donnee = "[";
			donnee += tmpListeMessage.get(i).dateMessage.getHour() + ":";
			donnee += tmpListeMessage.get(i).dateMessage.getMinute() + ":";
			donnee += tmpListeMessage.get(i).dateMessage.getSecond() + "]";
			donnee += " " + tmpListeMessage.get(i).Pseudo;
			donnee += " : " + tmpListeMessage.get(i).Texte + "\n";
			writer.write(donnee);
		}
		writer.close();
		/* On met en place le téléchargement */
		response.setContentType("application/octet-stream");
		response.setContentLength((int) outFile.length());
		PrintWriter out = response.getWriter();
		/* Page de téléchargement */
		String headerKey = "Content-Disposition";
		String headerValue = String.format("attachement; filename=\"%s\"", outFile.getName());
		response.setHeader(headerKey, headerValue);
		FileInputStream in = new FileInputStream(outFile);
		int i;
		while((i = in.read()) != -1) {
			out.write(i);
		}
		in.close();
		out.close();
		
		
	}

}
