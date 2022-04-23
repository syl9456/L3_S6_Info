package projetDW2;

import jakarta.servlet.annotation.MultipartConfig;
import jakarta.servlet.http.HttpServlet;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.sql.*;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.Part;


/*
 * Notre serlvet permettant de récupérer les fichiers côté serveur.
 * Elle répondra à l'URL /ServletUploadImage dans l'application Web considérée.
 */


/**
 * Implémantation de la Servlet ServletUploadImage
 */

@WebServlet("/ServletUploadImage")
@MultipartConfig

public class ServletUploadImage extends HttpServlet {

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
        String pseudo = (String)request.getSession().getAttribute("_pseudo");
        /* Récupère toutes les info de l'image upload */
        Part part = request.getPart("upImage");
        /* Nom de l'image upload */
        String nomImage = part.getSubmittedFileName();
        /* Chemin de destination */
        String path = "C:/Users/flori/IdeaProjects/ProjetDevWeb/src/main/webapp/ressources/ImageUtilisateurs"+File.separator+nomImage;
        /* Prend toutes les data de l'image */
        InputStream is = part.getInputStream();
        /* On envois les data a uploadFile */
        boolean x = uploadFile(is, path);
        if(x){
            /* On stock dans BDD */
            System.out.println("Reussite");
            String updateImage = "UPDATE utilisateur SET Image = 'ressources/ImageUtilisateurs/" + nomImage + "' WHERE Pseudo LIKE '" + pseudo + "'";
            try {
                Class.forName("com.mysql.jdbc.Driver");
                Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
                Statement st = conn.createStatement();
                int rst = st.executeUpdate(updateImage);
                st.close();
                conn.close();
                request.getSession().setAttribute("_imageUtil", "ressources/ImageUtilisateurs/" + nomImage);
                response.sendRedirect("profil.jsp");

            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        else{
            /* Erreur */
            System.out.println("Erreur");
            response.sendRedirect("profil.jsp");
        }
    }

    public boolean uploadFile(InputStream is, String path){
        boolean test = false;
        try{
            /* On copie l'image */
            Files.copy(is, Paths.get(path));
            test = true;
        }
        catch (Exception e){
            e.printStackTrace();
        }
        return test;
    }


}
