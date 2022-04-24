<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Polymap - Profil</title>
    <link rel="stylesheet" type="text/css" href="Style/styleProfil.css"/>
</head>
<body>

    <%
        if(session.getAttribute("_pseudo") == null){
            response.sendRedirect("index.jsp");
        }
    %>

    <!-------------- MENU --------------->

    <nav class="navStyle">
        <ul class="Menu">
            <li><a href="index.jsp" data-hover="Accueil">Accueil</a></li>
            <li class="current"><a href="profil.jsp" data-hover="Profil">Profil</a></li>
            <li><a href="#" data-hover="Map">Map</a></li>
            <li><a href="#" data-hover="FAQ">FAQ</a></li>
            <li><a href="#" data-hover="Contact">Contact</a></li>
        </ul>
    </nav>

    <!-------------- LOGO --------------->

    <img class="Logo" src="ressources/Polymap.png" alt="logo">

    <!-------------- RESUME PROFIL --------------->

    <div class="data1">
        <img src="<%=request.getSession().getAttribute("_imageUtil")%>" alt="Image Utilisateur" class="ImUtil">
        <p class="changePhoto">Changer d'Image de Profil</p>
        <form action="ServletUploadImage" enctype="multipart/form-data" method="post">
            <input type="file" name="upImage" accept="image/*" class="bFile"><br>
            <input type="submit" value="Envoyer" class="bEnvoi">
        </form>
        <p class="nameUtil"><%=session.getAttribute("_pseudo")%></p>
    </div>
    <iframe class="data2" src="listeAmi.jsp">
        
    </iframe>
    <iframe class="data3" src="listeMap.jsp">
        <p class="titreMap">Map Créées</p>
    </iframe>
    
    <!-- FORMULAIRE AJOUT AMI -->
    <form action="ServletAjoutAmi" method="post">
        <input class="Amiinput" type="text" name="_ami" id="_ami" size="50">
        <input type="submit" value="Valider" class="bAmi">
    </form>
    
    <p class="textAjAmi">Ajouter un Ami !</p>

</body>
</html>
