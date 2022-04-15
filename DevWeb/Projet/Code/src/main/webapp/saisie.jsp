
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
<head>
    <title>Title</title>
    <link rel="stylesheet" type="text/css" href="Style/styleTchat.css"/>
</head>
<body>

    <!-- FORMULAIRE AJOUT MESSAGE -->

    <form action="ServletMessageController" method="post" target="saisie.jsp">
        <label class="Slabel" for="_mess">Message : </label>
        <input class="Sinput" type="text" name="_mess" id="_mess" size="100">
        <input type="submit" value="Valider" class="bouton">
    </form>

    <%
        if(session.getAttribute("_pseudo") == null){
            response.sendRedirect("index.jsp");
        }
    %>
</body>
</html>
