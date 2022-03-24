<%@ page language="java" 
	contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" 
    import="java.util.*"
    import="javax.servlet.*"%>
<%@ taglib prefix = "c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix = "x" uri="http://java.sun.com/jsp/jstl/xml" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Tchatche</title>
</head>
<body>
	<c:import var = "Infos" url="http://localhost:8080/web.xml"/>
	<x:parse xml = "${Infos}" var = "output"/>
	<h1>Bonjour <%=request.getSession().getAttribute("Pseudo")%></h1>
</body>
</html>