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
	<%int Update = Integer.parseInt(pageContext.getServletContext().getInitParameter("Update"));%>
	<h1>Bonjour <%=request.getSession().getAttribute("Pseudo")%></h1>
	<p>
	<%
		if(pageContext.getServletContext().getAttribute("listeMessage") != null){
			ArrayList<Message> tmpListeMessage = (ArrayList<Message>)pageContext.getServletContext().getAttribute("listeMessage");
			for(int i = 0; i < tmpListeMessage.size(); i++) {
				String ligne = "[";
				ligne += tmpListeMessage.get(i).dateMessage.getHour() + ":";
				ligne += tmpListeMessage.get(i).dateMessage.getMinute() + ":";
				ligne += tmpListeMessage.get(i).dateMessage.getSecond() + "]";
				ligne += " " + tmpListeMessage.get(i).Pseudo;
				ligne += " : " + tmpListeMessage.get(i).Texte;
				%><%=ligne %><br><%
			}
		}
	%>
	</p>
	<%response.setIntHeader("Refresh", Update);%>
</body>
</html>