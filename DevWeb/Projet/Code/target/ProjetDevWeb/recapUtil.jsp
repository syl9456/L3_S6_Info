<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page import="java.sql.*" %>
<html>
<head>
    <title>Polymap</title>
    <link rel="stylesheet" type="text/css" href="Style/styleIndex.css"/>
</head>
<body>
    <%
        if(session.getAttribute("_pseudo") != null){
    %>
            <img src="<%=session.getAttribute("_imageUtil")%>" alt="Image Utilisateur" class="ImUtil">
            <hr class="separateur">
            <p class="pseudoRecap">
                <%=session.getAttribute("_pseudo")%>
            </p>

    <%
        }
    %>
</body>
</html>

