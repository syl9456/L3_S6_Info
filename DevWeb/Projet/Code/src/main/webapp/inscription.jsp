<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page import="java.sql.*" %>
<html>
<head>
    <title>Polymap</title>
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

<!-------------- FORMULAIRE INSCRIPTION --------------->

<div class="main">
    <p class="sign">Inscription</p>
    <form action="inscription.jsp" method="post">
        <input name="_pseudo" class="un" type="text" placeholder="Pseudo"/>
        <input type="password" name="_mdp" class="un" placeholder="Mot de Passe"/>
        <input type="submit" value="Inscription" name="submit" class="submit"/>
    </form>
</div>

<!-------------- SI ON RECOIS UNE REQUETE FORMULAIRE INSCRIPTION --------------->

<%
    if(request.getParameter("submit") != null){
        if(request.getParameter("_pseudo") != null && request.getParameter("_mdp") != null){
            String P = request.getParameter("_pseudo");
            String M = request.getParameter("_mdp");
            String CheckPseudo = "SELECT Pseudo FROM utilisateur WHERE Pseudo LIKE '" + P + "'";
            String InsertUtil = "INSERT INTO utilisateur(Pseudo, Mdp) VALUES ('" + P + "', '" + M + "')";
            try{
                Class.forName("com.mysql.jdbc.Driver");
                Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
                Statement st = conn.createStatement();
                ResultSet rst = st.executeQuery(CheckPseudo);
                if(rst.next()){
    %>
    <h3 class="Erreur">Erreur : Le Pseudo n'est pas disponible !</h3>
    <%
                rst.close();
                st.close();
                conn.close();
                System.out.println("Erreur : Le Pseudo n'est pas disponible !");
            }
            else{
                int rst2 = st.executeUpdate(InsertUtil);
                session.setAttribute("_pseudo", P);
                rst.close();
                st.close();
                conn.close();
                response.sendRedirect("index.jsp");
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
    <h3 class="Erreur">Erreur : Les champs de l'inscription ne sont pas tous plein !</h3>
    <%
            System.out.println("Erreur : Les champs de l'inscription ne sont pas tous plein !");
    }
}
%>

</body>
</html>
