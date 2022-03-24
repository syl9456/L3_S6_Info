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
	<%if(pageContext.getServletContext().getAttribute("listeMessage") == null){
		pageContext.getServletContext().setAttribute("listeMessage", new ArrayList<Message>());
	}
	else{
		ArrayList<Message> tmpListeMessage = (ArrayList<Message>)pageContext.getServletContext().getAttribute("listeMessage");
		String textMessage = request.getParameter("Message");
		String Pseudo = (String)session.getAttribute("Pseudo");
		LocalDateTime maintenant = LocalDateTime.now();
		Message mess = new Message(Pseudo, textMessage, maintenant);
		tmpListeMessage.add(mess);
		pageContext.getServletContext().setAttribute("listeMessage", tmpListeMessage);
	}%>
	<jsp:forward page="tchatche.html"></jsp:forward>
</body>
</html>