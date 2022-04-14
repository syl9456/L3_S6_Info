<%@ page import="projetDW2.*" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath}/Style/style.css"/>
</head>
<body>
    <!-------------- MENU --------------->
    <nav class="navStyle">
        <ul class="Menu">
            <li class="current"><a href="#" data-hover="Accueil">Accueil</a></li>
            <li><a href="#" data-hover="Profil">Profil</a></li>
            <li><a href="#" data-hover="Map">Map</a></li>
            <li><a href="#" data-hover="FAQ">FAQ</a></li>
            <li><a href="#" data-hover="Contact">Contact</a></li>
        </ul>
    </nav>
    <!-------------- LOGO --------------->
    <img class="Logo" src="${pageContext.request.contextPath}/ressources/Polymap.png" alt="logo">
    <!-------------- TCHAT --------------->
    <iframe id="AffMess" title="Servlet Message" width="1500" height="600" src="tchat.jsp" class="tchat"></iframe>
    <iframe id="SaisieMess" title="Saisie Message" width="1500" height="100" src="saisie.html" class="saisie"></iframe>
</body>
</html>
