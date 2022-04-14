<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
<head>
    <title>Tchat</title>
</head>
<body>
<!-- ON AFFICHE LA LISTE DES MESSAGES -->
<%--@elvariable id="LM" type="projetDW2.ListeMessage"--%>
<c:forEach var="m" items="${ LM.listeMessage }">
    <span> ${m.pseudoAuteur} : ${m.text} </span>
</c:forEach>
</body>
</html>
