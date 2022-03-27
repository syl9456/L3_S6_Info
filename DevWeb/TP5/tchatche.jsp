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
	<h1>Bonjour <%=request.getSession().getAttribute("Pseudo")%></h1>
	<p>
	<%
		if(pageContext.getServletContext().getAttribute("listeMessage") != null){
			%><jsp:forward page="affichage.jsp" /><%
		}
	%>
	</p>
</body>
</html>