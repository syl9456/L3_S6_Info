package projetDW2;

import jakarta.servlet.http.HttpServlet;
import java.io.IOException;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

/**
 * Implémantation de la Servlet ServletMessageController
 */

@WebServlet("/ServletMessageController")

public class ServletMessageController extends HttpServlet {

    static ListeMessage LM = new ListeMessage();

    /**
     * @see HttpServlet#HttpServlet()
     */
    public ServletMessageController() {
        super();
    }

    /**
     * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        /*  ON ENREGISTRE LA LISTE DE MESSAGE DANS LE CONTEXT PUIS ON REDIRIGE A L'INDEX */
        this.getServletConfig().getServletContext().setAttribute("LM", LM);
        RequestDispatcher requestDispatcher = request.getRequestDispatcher("WEB-INF/lib/index.jsp");
        requestDispatcher.forward(request, response);
    }

    /**
     * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        /* ON AJOUTE UN NOUVEAU MESSAGE */
    }

}
