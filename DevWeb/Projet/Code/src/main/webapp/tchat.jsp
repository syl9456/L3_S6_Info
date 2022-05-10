<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
<head>
    <title>Tchat</title>
    <link rel="stylesheet" type="text/css" href="Style/styleTchat.css"/>
</head>
<body>
    <!-- ON AFFICHE LA LISTE DES MESSAGES -->
    <%--@elvariable id="LM" type="projetDW2.ListeMessage"--%>
    <c:forEach var="m" items="${ LM.listeMessage }">
        <span class="lPseudo"> ${m.pseudoAuteur} </span> <span class="lMess"> : ${m.text} </span> <br>
    </c:forEach>
</body>
</html>

<script>
	/* On check si on doit reload le tchat toute les 0.1 seconde */
	var intervalId = window.setInterval(function(){
		getReload();
	}, 100);
	
	/* Fonction qui va demander a une servlet si on doit reload le tchat */
	
	function getReload(){
		var client;
		var data;
		var url_action="http://localhost:8080/ProjetDevWeb/ServletReloadMess";
		if(window.XMLHttpRequest){
		    client=new XMLHttpRequest();
		}
		else{
		    client=new ActiveXObject("Microsoft.XMLHTTP");
		}
		client.onreadystatechange=function(){
		    if (client.readyState==4 && client.status==200){
		         console.log(client.responseText);
		         if(client.responseText == 1){
		        	 window.location.reload();
		         }
		    }
		};
		data="";
		client.open("POST",url_action,true);
		client.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		client.send(data);
	}
</script>
