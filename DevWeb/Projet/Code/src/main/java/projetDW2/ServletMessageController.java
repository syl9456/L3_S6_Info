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

    static ListeMessage LM;

    /**
     * @see HttpServlet#HttpServlet()
     */
    public ServletMessageController() {
        super();
        LM = new ListeMessage();
    }

    /**
     * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        RequestDispatcher requestDispatcher = request.getRequestDispatcher("index.jsp");
        requestDispatcher.forward(request, response);
    }

    /**
     * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        /* ON AJOUTE UN NOUVEAU MESSAGE */
        String t = request.getParameter("_mess") + "\n";
        String u = (String)request.getSession().getAttribute("_pseudo");
        int uID = (int)request.getSession().getAttribute("idUtil");
        Message M = new Message(uID, t, u);
        LM.getListeMessage().add(M);
        this.getServletConfig().getServletContext().setAttribute("LM", LM);
        RequestDispatcher requestDispatcher = request.getRequestDispatcher("index.jsp");
        requestDispatcher.forward(request, response);
    }

}
