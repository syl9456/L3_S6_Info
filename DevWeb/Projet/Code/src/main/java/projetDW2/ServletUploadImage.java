package projetDW2;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.MultipartConfig;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.Part;



/**
 * Implemantation de la Servlet ServletUploadImage
 */

@WebServlet("/ServletUploadImage")
@MultipartConfig

public class ServletUploadImage extends HttpServlet {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public ServletUploadImage() {
        super();
    }

    /**
     * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }

    /**
     * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        /* Pseudo de l'utilisateur */
        String Pseu = (String)request.getSession().getAttribute("_pseudo");
        /* Récupération données de l'utilisateur */
        Part image = request.getPart("upImage");
        /* Nom de l'image */
        String imageName = image.getSubmittedFileName();
        /* Destination upload image */
        String path = "C:/Users/flori/eclipse-workspace/ProjetDevWeb/src/main/webapp/ressources/ImageUtilisateurs/" + imageName;
        try{
            /* Outils pour enregistrer l'image */
            FileOutputStream fos = new FileOutputStream(path);
            /* On charge l'image */
            InputStream is = image.getInputStream();
            byte[] data = new byte[is.available()];
            /* On enregistre l'image */
            is.read(data);
            fos.write(data);
            /* On ferme la lecture de données */
            fos.close();
        }
        catch (Exception e){
            e.printStackTrace();
        }
        /* On enregistre dans la base de donnée */
        try {
            /* Database */
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
            String requete = "UPDATE utilisateur SET Image = 'ressources/ImageUtilisateurs/" + imageName + "' WHERE Pseudo LIKE '" + Pseu + "'";
            Statement st = conn.createStatement();
            int result = st.executeUpdate(requete);
            if(result > 0){
                System.out.println("Image bien Update");
                st.close();
                conn.close();
                request.getSession().setAttribute("_imageUtil", "ressources/ImageUtilisateurs/"+imageName);
                /* On attends 5 sec que l'image s'enregistre */
                try {
        			Thread.sleep(5000);
        		} catch (InterruptedException e1) {
        			// TODO Auto-generated catch block
        			e1.printStackTrace();
        		}
                response.sendRedirect("profil.jsp");
            }
            else{
                System.out.println("Erreur Update");
                st.close();
                conn.close();
                response.sendRedirect("profil.jsp");
            }

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }

}
