<%@ page language="java" 
		contentType="text/html; charset=ISO-8859-1"
    	pageEncoding="ISO-8859-1"
    	import="java.util.*"
    	import="javax.servlet.*"
   	 	import="tchatche.Message"
    	import="java.time.LocalDateTime"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Tchatche</title>
</head>
<body>
	<jsp:useBean id="gestMess" class ="tchatche.GestionMessages" scope="session"/>
	<%int Update = Integer.parseInt(pageContext.getServletContext().getInitParameter("Update"));%>
	<h1>Bonjour <%=request.getSession().getAttribute("Pseudo")%></h1> 
	<%=gestMess.afficheAllMess((ArrayList<Message>)pageContext.getServletContext().getAttribute("listeMessage"))%>
	<%response.setIntHeader("Refresh", Update);%>
		
			
</body>
</html>