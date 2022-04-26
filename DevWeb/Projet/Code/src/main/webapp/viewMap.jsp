<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Polymap - Maps</title>
    <link rel="stylesheet" type="text/css" href="Style/styleMap.css"/>
</head>
<body>

    <%
        if(session.getAttribute("_pseudo") == null){
            response.sendRedirect("index.jsp");
        }
    %>

    <!-------------- MENU --------------->

    <nav class="navStyle">
        <ul class="Menu">
            <li><a href="index.jsp" data-hover="Accueil">Accueil</a></li>
            <li><a href="profil.jsp" data-hover="Profil">Profil</a></li>
            <li class="current"><a href="maps.jsp" data-hover="Map">Map</a></li>
            <li><a href="#" data-hover="FAQ">FAQ</a></li>
            <li><a href="#" data-hover="Contact">Contact</a></li>
        </ul>
    </nav>

    <!-------------- LOGO --------------->

    <img class="Logo" src="ressources/Polymap.png" alt="logo">
    
    <!-------------- MAP --------------->
	
    <iframe id="AffMap" title="AffMap" width="1600" height="800" src="affMap.jsp?name=<%= request.getParameter("name") %>" class="AffMap"></iframe>

</body>
</html>

