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

	<p class="titreAmis">Liste des Maps</p>
	
	<%
		int utilID = (int)session.getAttribute("idUtil");
		 try {
	         /* Database */
	         Class.forName("com.mysql.jdbc.Driver");
	         Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/projetdevweb", "root", "");
	         String requete = "SELECT map.Nom, utilaccesmap.Droit FROM utilaccesmap, map WHERE utilaccesmap.UtilID = " + utilID + " AND utilaccesmap.MapID = map.MapID";
	         Statement st = conn.createStatement();
	         ResultSet rst = st.executeQuery(requete);
	         while(rst.next()){
	        	 String nomMap = rst.getString("Nom");
	        	 int droit = rst.getInt("Droit");
	%>
				<p class="lAmis"><%=nomMap%> | Droit : <%=droit%></p>
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