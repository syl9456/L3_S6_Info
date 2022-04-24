<%@ page import="projetDW2.*" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Polymap</title>
<link rel="stylesheet" type="text/css" href="Style/styleProfil.css"/>
</head>
<body>

	<p class="titreAmis">Liste des Amis</p>
	
	<%
		int utilID = (int)session.getAttribute("idUtil");
		 try {
	         /* Database */
	         Class.forName("com.mysql.jdbc.Driver");
	         Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
	         String requete = "SELECT Pseudo FROM utilisateur, amitie WHERE utilisateur.UtilID = amitie.UtilID2 AND amitie.UtilID1 = " + utilID;
	         Statement st = conn.createStatement();
	         ResultSet rst = st.executeQuery(requete);
	         while(rst.next()){
	        	 String PseuAmi = rst.getString("Pseudo");
	%>
				<p class="lAmis"><%=PseuAmi%></p>
	<%
	         }
	         rst.close();
             st.close();
             conn.close();
		 }
		 catch(Exception e){
			 e.getStackTrace();
		 }
	%>
	
</body>
</html>