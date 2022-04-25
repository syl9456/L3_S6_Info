<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
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
    
    <!-------------- LISTE DES MAPS CREEES --------------->
    <br><br><br><br><br>
    
		<c:forEach var="m" items="${ LMap.getListeMap() }">
			<div class="BoutonMap" style="background-image: url('${ m.getSrcBackground() }')">
				<a href="viewMap.jsp?name=${ m.getNom() }" class="TextMap">${ m.getNom() }</a>
			</div><br>
		</c:forEach>

</body>
</html>