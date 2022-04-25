<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="projetDW2.ListeMap" %>
<%@ page import="projetDW2.Map" %>
<%@ page import="java.util.ArrayList" %>

<html>
<head>
    <title>Polymap - Maps</title>
    <link rel="stylesheet" type="text/css" href="Style/styleMap.css"/>
</head>
<body>

    <%
    	String envoisImageNom = request.getParameter("name");
    	String image = "";
    
        if(session.getAttribute("_pseudo") == null){
            response.sendRedirect("index.jsp");
        }
        
        ListeMap LMap = (ListeMap)getServletContext().getAttribute("LMap");
        
        ArrayList<Map> lm = LMap.getListeMap();
        
        for(int i = 0; i < lm.size(); i++){
        	if(envoisImageNom.compareTo(lm.get(i).getNom()) == 0){
        		image = lm.get(i).getSrcBackground();
        	}
        }
    
    
    %>
	
    <img alt="photoMap" src="<%=image%>">
    
    

</body>
</html>