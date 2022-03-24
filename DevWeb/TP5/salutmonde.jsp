<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	<h1>SalutMonde !</h1>
	<p>
		Le port local utilisé est :
		<%=request.getHeader("User-Agent")%>
	</p>
	<p>
		L'adresse IP est :
		<%=request.getRemoteAddr()%>
	</p>
	<p>
		URL de la Servlet utilisé :
		<%=request.getRequestURL()%>
	</p>
	<p>
		Port serveur utilisé :
		<%=request.getServerPort()%>
	</p>
</body>
</html>