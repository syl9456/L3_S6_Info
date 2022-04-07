
<%@page import="fr.dw2.Portion"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<jsp:include page="/header.jsp">
	<jsp:param value="Aliments" name="titre"/>
</jsp:include>
			 
<jsp:useBean id="tabPortion" 
			 scope="application" 
             class="fr.dw2.JournalAliment"/>

<%
// tab.add(new Portion("Amandes", "10g", "gouter,noix"));
%>

<c:if test="${ not empty param.nom and not empty param.qtty and not (param.tags eq null) }">
	<jsp:useBean id="p" class="fr.dw2.Portion" scope="page"></jsp:useBean>
	<c:set target="${ p }" property="nom" value="${ param.nom }"></c:set>
	<c:set target="${ p }" property="quantite" value="${ param.qtty }"></c:set>
	<c:set target="${ p }" property="tags" value="${ param.tags }"></c:set>
	${ tabPortion.getListePortion().add(p) }
</c:if>


<form action="aliments.jsp" method="post">
	<label for="t1">Nom de l'aliment</label> : <input type="text" name="nom" id="t1" />
	<br/>
	<label for="t2">Quantité </label> : <input type="text" name="qtty" id="t2" />
	<br/>
	<label for="t3">Tags </label> : <input type="text" name="tags" id="t3" />
	<br/>
	<button type="submit">Ajouter !</button>
</form>

<ul>
	<c:forEach var="a" items="${ tabPortion.getListePortion() }">
		<li><span>${ a.nom }</span> <span>${ a.quantite }</span>
		<span>${ a.date }</span>
		<c:forTokens var="tag" items="${ a.tags }" delims=",">
		   <span class="tag">${ tag }</span>
		</c:forTokens>
	</c:forEach>
</ul>

${ tabPortion.getListePortion().size() }

<jsp:include page="/footer.jsp" />
