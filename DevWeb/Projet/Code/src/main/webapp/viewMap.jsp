<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="projetDW2.ListeMap" %>
<%@ page import="projetDW2.Map" %>
<%@ page import="projetDW2.Acces" %>
<%@ page import="projetDW2.ListeAcces" %>
<%@ page import="java.util.ArrayList" %>
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
    
    <!-------------- LES PINGS --------------->
    
    <%
    
    	/* ON TEST SI L'UTILISATEUR A LE DROIT DE MODIFIER LA MAP */
    	
	    ListeMap LMap = (ListeMap)getServletContext().getAttribute("LMap");    
	    ArrayList<Map> lm = LMap.getListeMap();
	    ListeAcces LAcc = (ListeAcces)getServletContext().getAttribute("LAcc");    
	    ArrayList<Acces> la = LAcc.getListeAcces();
	    
	    int droit = 0;
	    int idMap = 0;
	    
	    for(int i = 0; i < lm.size(); i++){
	    	if(request.getParameter("name").compareTo(lm.get(i).getNom()) == 0){
	    		idMap = lm.get(i).getID();
	    	}
	    }
	    
	    for(int i = 0; i < la.size(); i++){
	    	if(la.get(i).getUtilID() == (int)session.getAttribute("idUtil") && la.get(i).getMapID() == idMap){
	    		droit = 1;
	    	}
	    }
	    
	    /* SI IL A LE DROIT ALORS ON AFFICHE LES BOUTON DE PING */
	    
	    if(droit == 1){
	%>
			
			<a href="viewMap.jsp?name=<%= request.getParameter("name") %>&ping=key">
  				<img src="ressources/key.png" style="height: 100px; width: 100px;"/>
 			</a>
	
	<%
	    }
	    
    %>

</body>
</html>

