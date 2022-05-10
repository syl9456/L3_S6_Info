<%@ page import="projetDW2.*" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
    <title>Polymap - Accueil</title>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="Style/styleIndex.css"/>
</head>
<body>

	<!-------------- TEST SI LES DONNEES ONT ETE CHARGEE --------------->
	
	<%
	
		if(pageContext.getServletContext().getAttribute("Charge") == null){
			response.sendRedirect("ServletLoadData");
		}
	%>
	
	

    <!-------------- MENU --------------->

    <nav class="navStyle">
        <ul class="Menu">
            <li class="current"><a href="index.jsp" data-hover="Accueil">Accueil</a></li>
            <li><a href="profil.jsp" data-hover="Profil">Profil</a></li>
            <li><a href="maps.jsp" data-hover="Map">Map</a></li>
        </ul>
    </nav>

    <!-------------- BOUTON CONNEXION / DECONNEXION--------------->

    <%
        if(session.getAttribute("_pseudo") == null){
    %>
            <a href="inscription.jsp" data-hover="INSCRIPTION" class="Inscription">INSCRIPTION</a>
            <a href="connexion.jsp" data-hover="CONNEXION" class="Connexion">CONNEXION</a>
    <%
        }
        else{
    %>
        <a href="deconnexion.jsp" data-hover="Deconnexion" class="Deconnexion">DECONNEXION</a>
    <%
        }
    %>

    <!-------------- LOGO --------------->

    <img class="Logo" src="ressources/Polymap.png" alt="logo">

    <!-------------- RECAP UTILISATEUR --------------->

    <%
        if(session.getAttribute("_pseudo") != null){
    %>
            <iframe class="recapUtil" src="recapUtil.jsp"></iframe>
    <%
        }
    %>

    <!-------------- TCHAT --------------->

    <iframe id="AffMess" title="Servlet Message" width="1500" height="600" src="tchat.jsp" class="tchat"></iframe>
    <%
        if(session.getAttribute("_pseudo") != null){
    %>
            <iframe id="SaisieMess" title="Saisie Message" width="1500" height="100" src="saisie.jsp" class="saisie"></iframe>
    <%
        }
    %>
</body>
</html>

<script>
    /* On refrech le tchat toute les secondes */
    window.setInterval("reloadIFrame();", 1000);
    function reloadIFrame() {
        document.getElementById("AffMess").src="tchat.jsp";
    }
</script>
