<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
<head>
    <title>Tchat</title>
    <jsp:useBean id="LMess"
                 scope="application"
                 class="projetDW2.ListeMessage"/>
</head>
<body>
<!-- ON AFFICHE LA LISTE DES MESSAGES -->
<c:forEach var="m" items="${ LMess.listeMessage }">
    <span> ${m.pseudoAuteur} : ${m.text} </span>
</c:forEach>
</body>
</html>
