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
