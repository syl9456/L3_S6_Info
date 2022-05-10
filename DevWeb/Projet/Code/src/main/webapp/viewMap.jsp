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
        </ul>
    </nav>

    <!-------------- LOGO --------------->

    <img class="Logo" src="ressources/Polymap.png" alt="logo">
    
    <!-------------- MAP --------------->
	
    <iframe onload="trackingMap()" id="Iframe1" name="Iframe1" width="1600" height="800" src="affMap.jsp?name=<%= request.getParameter("name") %>" class="AffMap"></iframe>
    
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
	    
	    session.setAttribute("mapActuel", idMap);
	    
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

<script>
	var xFinal;
	var yFinal;
	
	function trackingMap(){
		/* RECUPERE LA POSITION DE LA SOURIS SUR LA MAP */
		window.frames['Iframe1'].document.getElementById('map').onmousemove = function(e){
	            var x = e.clientX;
	            var y = e.clientY;
	            var scrollX = window.frames['Iframe1'].scrollX;
	            var scrollY = window.frames['Iframe1'].scrollY;
	            xFinal = x + scrollX;
	            yFinal = y + scrollY;
	            console.log("x: " + xFinal + " y: " + yFinal);      
	    }
		/* Si CLICK ALORS ENVOIS FORMULAIRE POUR AJOUT PING */
		document.getElementById("Iframe1").contentWindow.document.body.onclick = function() {
			/* On prend la valeur de quel a été sélectionné */
			var url_string = window.location;
			var url = new URL(url_string);
			var ping = url.searchParams.get("ping");
			/* Si on a bien sélectionné un ping */
			if(ping != null){
				/* On setup un formulaire */
				var XHR = new XMLHttpRequest();
				/* On rentre les données */
				var data  = "ping=" + encodeURIComponent(ping)
							+ "&X=" + encodeURIComponent(xFinal)
							+ "&Y=" + encodeURIComponent(yFinal);
				/* On paramètre la requete au Servlet */
				XHR.open("POST", "http://localhost:8080/ProjetDevWeb/ServletAjoutPing", true);
				XHR.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
				/* On envois la requete */
				XHR.send(data);
				/* On actualise la page pour voir le ping */
				setTimeout(function(){
					   window.location.reload();
					}, 1000);
			}
		}
	}
</script>

