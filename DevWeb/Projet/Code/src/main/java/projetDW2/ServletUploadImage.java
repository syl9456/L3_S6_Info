package projetDW2;

import jakarta.servlet.annotation.MultipartConfig;
import jakarta.servlet.http.HttpServlet;

import java.io.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

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
@MultipartConfig(maxFileSize = 16177216)

public class ServletUploadImage extends HttpServlet {

    /*
     * Chemin dans lequel les images seront sauvegardées.
     */
    public static final String IMAGES_FOLDER = "/webapp/ressources/ImageUtilisateur";


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

    }


}
