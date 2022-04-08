package fr.dw2;

import jakarta.servlet.http.HttpServlet;
import java.io.IOException;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;


/**
 * Servlet implementation class AlimentController
 */
@WebServlet("/AlimentController")
public class AlimentController extends HttpServlet {
	private static final long serialVersionUID = 1L;
	static JournalAliment JA = new JournalAliment();
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AlimentController() {
        super();
        JA.getListePortion().add(new Portion("Chips", "25", "Apéro"));
        
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.getServletConfig().getServletContext().setAttribute("JA", JA);
		this.getServletConfig().getServletContext().setAttribute("cible", "aliments");
		RequestDispatcher requestDispatcher = request.getRequestDispatcher("WEB-INF/lib/aliments.jsp");
		requestDispatcher.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		JA.getListePortion().add(new Portion(request.getParameter("nom"), 
											 request.getParameter("qtty"), 
											 request.getParameter("tags")));
		response.sendRedirect("aliments");
	}

}
