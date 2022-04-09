<%@ page import="projetDW2.Coordonnee" %>
<%@ page import="projetDW2.Message" %>
<%@ page import="projetDW2.Map" %>
<%@ page import="projetDW2.Utilisateur" %>
<%@ page import="projetDW2.Donnee" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@page import="java.sql.*"%>

<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
</head>
<body>
<h1><%= "Hello World!" %></h1>
<br/>

<!-- TEST CLASSES -->

<%
    Coordonnee c = new Coordonnee(10, 10);
    Utilisateur u = new Utilisateur("Arcof", "1234");
    Message mess = new Message(u.getID(), "Salut, moi c'est Mathieu !");
    Map m = new Map(u.getID(), "Carte", "data/background.png");
    Donnee d = new Donnee(m.getID(), c, "Campus Manufacture", 1);
    m.getListeDonnee().add(d);
%>

<h3><%= c.toString() %></h3>
<h3><%= u.toString() %></h3>
<h3><%= mess.toString() %></h3>
<h3><%= d.toString() %></h3>
<h3><%= m.toString() %></h3>

<!-- TEST AJOUT BDD -->

<%
    String AjoutUtilisateur = "INSERT INTO utilisateur(Pseudo, Mdp) VALUES ('" + u.getPseudo() + "', '" + u.getMDP() + "')";
    try {
        Class.forName("com.mysql.jdbc.Driver");
        Connection cnx = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
        Statement st = cnx.createStatement();
        int requete = st.executeUpdate(AjoutUtilisateur);
        System.out.println("Utilisateur inséré !");
    }
    catch (Exception e){
        System.out.print(e);
        e.printStackTrace();
    }
%>

</body>
</html>
