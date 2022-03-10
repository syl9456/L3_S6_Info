package tchatche;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class SalutMonde
 */
@WebServlet("/SalutMonde")
public class SalutMonde extends HttpServlet {
	private static final long serialVersionUID = 1L;

    /**
     * Default constructor. 
     */
    public SalutMonde() {
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String MessageAcceuil = "Vous êtes connecté avec le navigateur : ";
		MessageAcceuil += request.getHeader("User-Agent");
		MessageAcceuil += " Installé sur la machine : [";
		MessageAcceuil += request.getRemoteAddr();
		MessageAcceuil+= "] à l'application de tchatche : ";
		MessageAcceuil += request.getRequestURL();
		MessageAcceuil += " via le port : ";
		MessageAcceuil += request.getServerPort();
		response.getWriter().append(MessageAcceuil);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
