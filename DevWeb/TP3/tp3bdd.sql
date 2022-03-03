-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : jeu. 03 mars 2022 à 10:09
-- Version du serveur :  10.3.31-MariaDB-0+deb10u1
-- Version de PHP : 7.3.31-1~deb10u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `df01546t`
--

-- --------------------------------------------------------

--
-- Structure de la table `Amitie`
--

CREATE TABLE `Amitie` (
  `Id` int(11) NOT NULL,
  `IdUtil1` int(11) DEFAULT NULL,
  `IdUtil2` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `Commentaire`
--

CREATE TABLE `Commentaire` (
  `Id` int(11) NOT NULL,
  `IdUtilisateur` int(11) DEFAULT NULL,
  `Text` text COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `IdCommu` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `Communaute`
--

CREATE TABLE `Communaute` (
  `Id` int(11) NOT NULL,
  `Nom` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `IdProprio` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `CommunauteUtilisateur`
--

CREATE TABLE `CommunauteUtilisateur` (
  `Id` int(11) NOT NULL,
  `IdCommunaute` int(11) DEFAULT NULL,
  `IdUtilisateur` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `Ressource`
--

CREATE TABLE `Ressource` (
  `Id` int(11) NOT NULL,
  `URL` text COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `IdUtilisateur` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `Utilisateur`
--

CREATE TABLE `Utilisateur` (
  `Id` int(11) NOT NULL,
  `Nom` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Prenom` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `DateNaissance` date DEFAULT NULL,
  `Login` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `Mdp` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Amitie`
--
ALTER TABLE `Amitie`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `AmitieUtil1` (`IdUtil1`),
  ADD KEY `AmitieUtil2` (`IdUtil2`);

--
-- Index pour la table `Commentaire`
--
ALTER TABLE `Commentaire`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `CommIdUtil_UtilId` (`IdUtilisateur`),
  ADD KEY `CommIdCommu_CommId` (`IdCommu`);

--
-- Index pour la table `Communaute`
--
ALTER TABLE `Communaute`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `IdUtil_IdProprio` (`IdProprio`);

--
-- Index pour la table `CommunauteUtilisateur`
--
ALTER TABLE `CommunauteUtilisateur`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `ComuUtilCom_ComuId` (`IdCommunaute`),
  ADD KEY `ComuUtilUtil_UtilId` (`IdUtilisateur`);

--
-- Index pour la table `Ressource`
--
ALTER TABLE `Ressource`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `RessIdUtil_UtilId` (`IdUtilisateur`);

--
-- Index pour la table `Utilisateur`
--
ALTER TABLE `Utilisateur`
  ADD PRIMARY KEY (`Id`);

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `Amitie`
--
ALTER TABLE `Amitie`
  ADD CONSTRAINT `AmitieUtil1` FOREIGN KEY (`IdUtil1`) REFERENCES `Utilisateur` (`Id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `AmitieUtil2` FOREIGN KEY (`IdUtil2`) REFERENCES `Utilisateur` (`Id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `Commentaire`
--
ALTER TABLE `Commentaire`
  ADD CONSTRAINT `CommIdCommu_CommId` FOREIGN KEY (`IdCommu`) REFERENCES `Communaute` (`Id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `CommIdUtil_UtilId` FOREIGN KEY (`IdUtilisateur`) REFERENCES `Utilisateur` (`Id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `Communaute`
--
ALTER TABLE `Communaute`
  ADD CONSTRAINT `IdUtil_IdProprio` FOREIGN KEY (`IdProprio`) REFERENCES `Utilisateur` (`Id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `CommunauteUtilisateur`
--
ALTER TABLE `CommunauteUtilisateur`
  ADD CONSTRAINT `ComuUtilCom_ComuId` FOREIGN KEY (`IdCommunaute`) REFERENCES `Communaute` (`Id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `ComuUtilUtil_UtilId` FOREIGN KEY (`IdUtilisateur`) REFERENCES `Utilisateur` (`Id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `Ressource`
--
ALTER TABLE `Ressource`
  ADD CONSTRAINT `RessIdUtil_UtilId` FOREIGN KEY (`IdUtilisateur`) REFERENCES `Utilisateur` (`Id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
