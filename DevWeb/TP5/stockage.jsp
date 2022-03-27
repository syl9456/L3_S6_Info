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
	<%
		String textMessage = request.getParameter("Message");
		String Pseudo = (String)session.getAttribute("Pseudo");
		LocalDateTime maintenant = LocalDateTime.now();
		Message mess = new Message(Pseudo, textMessage, maintenant);
		pageContext.getServletContext().setAttribute("listeMessage", (ArrayList<Message>)gestMess.ajouteMessage(mess, (ArrayList<Message>)pageContext.getServletContext().getAttribute("listeMessage")));
		response.sendRedirect("tchatche.html");%>
	
</body>
</html>