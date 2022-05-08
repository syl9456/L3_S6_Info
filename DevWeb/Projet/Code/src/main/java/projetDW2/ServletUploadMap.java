package projetDW2;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
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
 * Servlet implementation class ServletUploadMap
 */
@WebServlet("/ServletUploadMap")
@MultipartConfig
public class ServletUploadMap extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ServletUploadMap() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub

	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		/* ID de l'utilisateur */
        int ID = (int)request.getSession().getAttribute("idUtil");
        /* Nom de la map */
        String nom = request.getParameter("_nom");
        /* Recuperation donnees de l'image */
        Part image = request.getPart("ImMap");
        /* Nom de l'image */
        String imageName = image.getSubmittedFileName();
        /* Destination upload image */
        String path = "C:/Users/flori/eclipse-workspace/ProjetDevWeb/src/main/webapp/ressources/Maps/" + imageName;
        try{
            /* Outils pour enregistrer l'image */
            FileOutputStream fos = new FileOutputStream(path);
            /* On charge l'image */
            InputStream is = image.getInputStream();
            byte[] data = new byte[is.available()];
            /* On enregistre l'image */
            is.read(data);
            fos.write(data);
            /* On ferme la lecture de donnÃ©es */
            fos.close();
        }
        catch (Exception e){
            e.printStackTrace();
        }
        /* On enregistre dans la base de donnÃ©e */
        try {
            /* Database */
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
            String requete = "INSERT INTO map(ProprioID, Nom, SrcBackground) VALUES (" + ID + ", '" + nom + "', '" + "ressources/Maps/" + imageName + "')";
            Statement st = conn.createStatement();
            int result = st.executeUpdate(requete);
            if(result > 0){
                System.out.println("Map Inséré");
                /* On attends 5 sec que l'image s'enregistre */
                try {
        			Thread.sleep(5000);
        		} catch (InterruptedException e1) {
        			// TODO Auto-generated catch block
        			e1.printStackTrace();
        		}
                /* On insère que l'utilisateur qui a upload la map a le droit de la modifier */
                /* On récup l'id de la map ajouté */
                requete = "SELECT MapID FROM map WHERE SrcBackground LIKE 'ressources/Maps/" + imageName + "'";
                ResultSet rst = st.executeQuery(requete);
                if(rst.next()){
                	int IDmap = rst.getInt("MapID");
                	/* On update UtilAccessMap */
                    requete = "INSERT INTO utilaccesmap(UtilID, MapID, Droit) VALUES(" + ID + ", " + IDmap + ", 1)";
                    result = st.executeUpdate(requete);
                    if(result > 0){
                        System.out.println("UtilAccessMap bien Update");
                        rst.close();
                        st.close();
                        conn.close();
                        /* On modifie la liste des maps du context */
                        Map m = new Map(IDmap, ID, nom, "ressources/Maps/" + imageName);
                        ListeMap lm = (ListeMap)request.getServletContext().getAttribute("LMap");
                        lm.getListeMap().add(m);
                        request.getServletContext().setAttribute("LMap", lm);
                        /* On redirige */
                        response.sendRedirect("maps.jsp");
                    }
                }
            }
            else{
                System.out.println("Erreur Update");
                st.close();
                conn.close();
                response.sendRedirect("maps.jsp");
            }

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }
}
