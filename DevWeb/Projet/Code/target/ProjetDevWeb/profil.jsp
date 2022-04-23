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
        <img src="<%=session.getAttribute("_imageUtil")%>" alt="Image Utilisateur" class="ImUtil">
        <p class="nameUtil">Changer d'Image de Profil</p>
        <form action="ServletUploadImage" enctype="multipart/form-data" method="post">
            <input type="file" name="upImage" id="upImage" accept="image/*">
            <input type="submit" value="Envoyer">
        </form>
        <p class="nameUtil"><%=session.getAttribute("_pseudo")%></p>
    </div>
    <div class="data2">
        <p class="titreAmis">Liste des Amis</p>
    </div>
    <div class="data3">
        <p class="titreMap">Map Créées</p>
    </div>

</body>
</html>
