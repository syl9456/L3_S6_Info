<%@ page language="java" 
	contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"
    import="java.util.*"
    import="javax.servlet.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Tchatche</title>
</head>
<body>
	<%
	if(request.getParameter("Pseudo") == null){
		response.sendRedirect("index.html");
	}
	else{
		request.getSession().setAttribute("Pseudo", request.getParameter("Pseudo"));
		response.sendRedirect("tchatche.html");
	}
	%>
</body>
</html>