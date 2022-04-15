
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Polymap</title>
    <link rel="stylesheet" type="text/css" href="Style/styleinscription.css"/>
</head>
<body>

    <!-------------- LOGO --------------->

    <img class="Logo" src="ressources/Polymap.png" alt="logo">

    <!--
        - Si session(_pseudo) null alors renvois sur index.jsp
        - Sinon session(_pseudo) = null puis renvois sur index.jsp
    -->

    <%
        if(session.getAttribute("_pseudo") == null){
            response.sendRedirect("index.jsp");
        }
        else{
            session.setAttribute("_pseudo", null);
            response.sendRedirect("index.jsp");
        }
    %>
</body>
</html>
