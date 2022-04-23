<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Liste de liens</title>
<style>
#all-links { border: 3px solid grey; }
#all-links.connected { border-color: teal; }
#all-links:not(.connected) { border-color: orange; }
</style>
</head>
<body>

	<h5>Liste de liens</h5>

	<ul id="all-links">
		<%-- use the JSTL --%>
		<c:forEach var="link" items="${links}">
		<li><a href="${link.href}" target="_blank" title="${link.href}"><c:out value="${link.text}"/></a></li>
		</c:forEach>
	</ul>
	
	<hr/>
	<hr/>

	<h5>Admin (ajout de liens)</h5>
	<form method="POST">
		<c:forTokens var="n" items="password href text" delims=" ">
		<label>${n} <input placeholder="${n}" name="${n}"/></label><br/>
		</c:forTokens>
		<input type="submit"/>
	</form>


	<script type="text/javascript">
	/* modifier/ajouter le code javascript ici ou dans un autre fichier à inclure */
	async function updateList() {
		/* recupérer la page depuis le serveur */
		let resp = await fetch(document.location.href)
		let content = await resp.text()
		/* puis mettre à jour de DOM */
        DOMParser doc = new DOMParser();
		doc.parse(content);
		doc.all-links.innerHTML;
		
	}
	/* rafraichissement périodique */
	setInterval(updateList, 2000);
     
	</script>
</body>
</html>