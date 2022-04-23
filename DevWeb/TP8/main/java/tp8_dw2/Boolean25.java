package tp8_dw2;

import java.io.IOException;
import java.util.Arrays;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Boolean25
 */
public class Boolean25 extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	boolean[] data = new boolean[25];
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Boolean25() {
        super();
		for (int i = 0; i < data.length; i++) {
			data[i] = Math.random() < 0.3;
		}
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// gestion g�n�reuse des param�tres :
		//    acc�pte plusieurs toggle et aussi un toggle s�par� par des virgules
		if (request.getParameterMap().containsKey("toggle"))
			for (String param : request.getParameterValues("toggle")) {
				for (String p : param.split(" *, *")) {
					Integer i = Integer.parseInt(p);
					data[i] = !data[i];
				}
			}
		response.setContentType("application/json");
		// no-dependency JSON
		String toSend = Arrays.toString(data);
		response.getOutputStream().write(toSend.getBytes());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response); // g�n�rer la m�me r�ponse
	}

}
