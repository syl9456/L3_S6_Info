package tp9_dw2;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/links")
public class LinkStream extends HttpServlet {

	// no jdbc setup, just use a list
	List<Link> links = new ArrayList<Link>();

	private static final long serialVersionUID = 1L;

	public LinkStream() {
		super();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setAttribute("links", links);
		getServletContext().getRequestDispatcher("/WEB-INF/jsp/link-list.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String password = request.getParameter("password");
		if ("dw2".equals(password)) {
			String href = request.getParameter("href");
			String text = request.getParameter("text");
			links.add(new Link(href, text));
			response.sendRedirect(request.getContextPath() + "/links");
		} else {
			response.getWriter().append("Invalid Password");
		}
	}

}
