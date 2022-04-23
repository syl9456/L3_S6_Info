
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page import="java.sql.*" %>
<html>
<head>
    <title>Polymap - Connexion</title>
    <link rel="stylesheet" type="text/css" href="Style/styleinscription.css"/>
</head>
<body>

    <!-------------- MENU --------------->

    <nav class="navStyle">
        <ul class="Menu">
            <li><a href="index.jsp" data-hover="Accueil">Accueil</a></li>
            <li><a href="#" data-hover="Profil">Profil</a></li>
            <li><a href="#" data-hover="Map">Map</a></li>
            <li><a href="#" data-hover="FAQ">FAQ</a></li>
            <li><a href="#" data-hover="Contact">Contact</a></li>
        </ul>
    </nav>

    <!-------------- LOGO --------------->

    <img class="Logo" src="ressources/Polymap.png" alt="logo">

    <!-------------- FORMULAIRE CONNEXION --------------->

    <div class="main">
        <p class="sign">Connexion</p>
        <form action="connexion.jsp" method="post">
            <input name="_pseudo" class="un" type="text" placeholder="Pseudo"/>
            <input type="password" name="_mdp" class="un" placeholder="Mot de Passe"/>
            <input type="submit" value="Connexion" name="submit" class="submit"/>
        </form>
    </div>

    <!-------------- SI ON RECOIS UNE REQUETE FORMULAIRE INSCRIPTION --------------->

    <%
        if(request.getParameter("submit") != null){
            if(request.getParameter("_pseudo") != null && request.getParameter("_mdp") != null){
                String P = request.getParameter("_pseudo");
                String M = request.getParameter("_mdp");
                String CheckUtil = "SELECT UtilID, Pseudo, Image FROM utilisateur WHERE Pseudo LIKE '" + P + "' AND Mdp LIKE '" + M + "'";
                try{
                    Class.forName("com.mysql.jdbc.Driver");
                    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
                    Statement st = conn.createStatement();
                    ResultSet rst = st.executeQuery(CheckUtil);
                    if(rst.next()){
                        session.setAttribute("_pseudo", P);
                        session.setAttribute("idUtil", rst.getInt("UtilID"));
                        session.setAttribute("_imageUtil", rst.getString("Image"));
                        rst.close();
                        st.close();
                        conn.close();
                        response.sendRedirect("index.jsp");
                    }
                    else{
                        rst.close();
                        st.close();
                        conn.close();
                        System.out.println("Erreur : Le Pseudo ou le mot de passe sont incorrect !");
    %>
                        <h3 class="Erreur">Erreur : Le Pseudo ou le mot de passe sont incorrect !</h3>
    <%
                    }
                }
                catch(Exception e)
                {
                    System.out.print(e);
                    e.printStackTrace();
                }
    }
            else{
    %>
                <h3 class="Erreur">Erreur : Les champs de connexion ne sont pas tous plein !</h3>
    <%
                System.out.println("Erreur : Les champs de connexion ne sont pas tous plein !");
            }
        }
    %>

</body>
</html>
