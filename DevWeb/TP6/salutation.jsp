<%@ page language="java" 
		 contentType="text/html; charset=ISO-8859-1"
    	 pageEncoding="ISO-8859-1"
    	 import="java.util.*"
    	 import="java.text.*"
    	 import="javax.servlet.*"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/sql" prefix="sql" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/xml" prefix="x" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Salutation</title>
</head>
<body>
	<h1>Bonjour ${param.user} </h1>
	<%
		Date d = new Date();
		SimpleDateFormat monFormat = new SimpleDateFormat("'On est le' yyyy-MM-dd ' et il est ' H' heures,' m ' minutes et ' s ' secondes'");
		String maDate = monFormat.format(d);
	%>
	<h3><%=maDate%></h3>
	<br><h2>Avec JSTL :</h2><br>
	<jsp:useBean id="da" class="java.util.Date" scope="application"/>  
	<h3><fmt:formatDate pattern="'On est le' yyyy-MM-dd ' et il est ' H' heures,' m ' minutes et ' s ' secondes'" value="${da}"/></h3>
</body>
</html> 