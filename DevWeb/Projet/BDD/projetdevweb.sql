-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le : mar. 10 mai 2022 à 21:11
-- Version du serveur : 5.7.36
-- Version de PHP : 7.4.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `projetdevweb`
--

-- --------------------------------------------------------

--
-- Structure de la table `amitie`
--

DROP TABLE IF EXISTS `amitie`;
CREATE TABLE IF NOT EXISTS `amitie` (
  `UtilID1` int(11) NOT NULL COMMENT 'PK de L''utilisateur 1',
  `UtilID2` int(11) NOT NULL COMMENT 'PK de L''utilisateur 2',
  PRIMARY KEY (`UtilID1`,`UtilID2`),
  KEY `FK_Util2_Ami2` (`UtilID2`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Déchargement des données de la table `amitie`
--

INSERT INTO `amitie` (`UtilID1`, `UtilID2`) VALUES
(2, 1),
(6, 1),
(6, 2),
(2, 3),
(6, 3),
(6, 7);

-- --------------------------------------------------------

--
-- Structure de la table `donnee`
--

DROP TABLE IF EXISTS `donnee`;
CREATE TABLE IF NOT EXISTS `donnee` (
  `DataID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'PK de la Donnee',
  `MapID` int(11) NOT NULL COMMENT 'PK de la Map dans laquelle la Donnée est Présente',
  `CoordX` int(11) NOT NULL COMMENT 'Coord X de la Donnée',
  `CoordY` int(11) NOT NULL COMMENT 'Coord Y de la Donnée',
  `Info` text COLLATE utf8mb4_unicode_ci NOT NULL,
  `Type` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'Type de la donnée',
  PRIMARY KEY (`DataID`),
  KEY `FK_Donnee_Map` (`MapID`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Déchargement des données de la table `donnee`
--

INSERT INTO `donnee` (`DataID`, `MapID`, `CoordX`, `CoordY`, `Info`, `Type`) VALUES
(1, 1, 691, 1019, 'Je suis un ping de type [key]', 'key'),
(2, 1, 209, 254, 'Je suis un ping de type [key]', 'key'),
(3, 1, 677, 257, 'Je suis un ping de type [key]', 'key'),
(4, 1, 385, 600, 'Je suis un ping de type [key]', 'key'),
(5, 3, 3407, 1480, 'Je suis un ping de type [key]', 'key'),
(6, 1, 231, 1573, 'Je suis un ping de type [key]', 'key'),
(7, 1, 1747, 2152, 'Je suis un ping de type [key]', 'key'),
(8, 1, 1540, 440, 'Je suis un ping de type [key]', 'key'),
(9, 1, 2203, 1665, 'Je suis un ping de type [key]', 'key'),
(10, 1, 1320, 1351, 'Je suis un ping de type [key]', 'key'),
(11, 1, 3363, 1897, 'Je suis un ping de type [key]', 'key'),
(12, 1, 2731, 599, 'Je suis un ping de type [key]', 'key'),
(13, 1, 2531, 433, 'Je suis un ping de type [key]', 'key'),
(14, 1, 3177, 1073, 'Je suis un ping de type [key]', 'key'),
(15, 1, 2592, 325, 'Je suis un ping de type [key]', 'key'),
(16, 1, 299, 595, 'Je suis un ping de type [key]', 'key'),
(17, 1, 480, 696, 'Je suis un ping de type [key]', 'key'),
(18, 1, 497, 332, 'Je suis un ping de type [key]', 'key'),
(19, 1, 890, 1281, 'Je suis un ping de type [key]', 'key'),
(20, 1, 945, 288, 'Je suis un ping de type [key]', 'key'),
(21, 1, 1160, 557, 'Je suis un ping de type [key]', 'key'),
(23, 1, 909, 2181, 'Je suis un ping de type [heart]', 'heart'),
(24, 7, 304, 1989, 'Je suis un ping de type [wood]', 'wood'),
(25, 1, 2123, 1804, 'Je suis un ping de type [heart]', 'heart');

-- --------------------------------------------------------

--
-- Structure de la table `map`
--

DROP TABLE IF EXISTS `map`;
CREATE TABLE IF NOT EXISTS `map` (
  `MapID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'PK de la Map',
  `ProprioID` int(11) NOT NULL COMMENT 'Pk du Créateur de la Map',
  `Nom` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'Nom de la Map',
  `SrcBackground` text COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'Chemin vers l''Image de la Map',
  PRIMARY KEY (`MapID`),
  UNIQUE KEY `Nom_Map` (`Nom`),
  KEY `FK_Map_Util` (`ProprioID`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Déchargement des données de la table `map`
--

INSERT INTO `map` (`MapID`, `ProprioID`, `Nom`, `SrcBackground`) VALUES
(1, 2, 'Link\'s Awakening Cocolint', 'ressources/Maps/link-awakening-remake-cartes-cocolint-hd-000.jpg'),
(2, 1, 'Dofus - Frigost', 'ressources/Maps/frigost.png'),
(3, 6, 'Dofus - Incarnam', 'ressources/Maps/Incarnam.png'),
(7, 2, 'Pokemon', 'ressources/Maps/mapPokemon.jpg'),
(8, 2, 'Pokemon2', 'ressources/Maps/mapPokemon2.jpg');

-- --------------------------------------------------------

--
-- Structure de la table `message`
--

DROP TABLE IF EXISTS `message`;
CREATE TABLE IF NOT EXISTS `message` (
  `MessID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'PK du Message',
  `AutorID` int(11) NOT NULL COMMENT 'PK du créateur du Message',
  `Text` text COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'Contenue du Message',
  PRIMARY KEY (`MessID`),
  KEY `FK_Util_Mess` (`AutorID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `utilaccesmap`
--

DROP TABLE IF EXISTS `utilaccesmap`;
CREATE TABLE IF NOT EXISTS `utilaccesmap` (
  `UtilID` int(11) NOT NULL COMMENT 'PK de l''utilisateur',
  `MapID` int(11) NOT NULL COMMENT 'PK de la Map',
  `Droit` int(11) NOT NULL COMMENT 'Droit de L''utilisateur sur la Map',
  PRIMARY KEY (`UtilID`,`MapID`),
  KEY `FK_UAM_Map` (`MapID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Déchargement des données de la table `utilaccesmap`
--

INSERT INTO `utilaccesmap` (`UtilID`, `MapID`, `Droit`) VALUES
(1, 2, 1),
(2, 1, 1),
(2, 7, 1),
(2, 8, 1),
(6, 3, 1);

-- --------------------------------------------------------

--
-- Structure de la table `utilisateur`
--

DROP TABLE IF EXISTS `utilisateur`;
CREATE TABLE IF NOT EXISTS `utilisateur` (
  `UtilID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'PK de L''utilisateur',
  `Pseudo` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'Pseudo de L''utilisateur (Max 50 carac)',
  `Mdp` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'Mdp de L''utilisateur',
  `Image` text COLLATE utf8mb4_unicode_ci NOT NULL COMMENT 'Photo de profil',
  PRIMARY KEY (`UtilID`),
  UNIQUE KEY `Pseudo` (`Pseudo`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Déchargement des données de la table `utilisateur`
--

INSERT INTO `utilisateur` (`UtilID`, `Pseudo`, `Mdp`, `Image`) VALUES
(1, 'Arcof', '1234', 'ressources/ImageUtilisateurs/kwqapqrgxjatnolkjznv.png'),
(2, 'Shooterah', 'dada', 'ressources/ImageUtilisateurs/mahou-tsukai-no-yome-elias-ainsworth-the-ancient-magus-bri-2.jpg'),
(3, 'Xeos', 'Sylvanus', 'ressources/ImageUtilisateurs/biere-sylvanus-triple.png'),
(6, 'Mahmoud', 'admin', 'ressources/ImageUtilisateurs/16-Sabib-Al-Mamoud.png'),
(7, 'Jojo', 'ricard', 'ressources/ImageUtilisateurs/default.png');

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `amitie`
--
ALTER TABLE `amitie`
  ADD CONSTRAINT `FK_Util1_Ami1` FOREIGN KEY (`UtilID1`) REFERENCES `utilisateur` (`UtilID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_Util2_Ami2` FOREIGN KEY (`UtilID2`) REFERENCES `utilisateur` (`UtilID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `donnee`
--
ALTER TABLE `donnee`
  ADD CONSTRAINT `FK_Donnee_Map` FOREIGN KEY (`MapID`) REFERENCES `map` (`MapID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `map`
--
ALTER TABLE `map`
  ADD CONSTRAINT `FK_Map_Util` FOREIGN KEY (`ProprioID`) REFERENCES `utilisateur` (`UtilID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `message`
--
ALTER TABLE `message`
  ADD CONSTRAINT `FK_Util_Mess` FOREIGN KEY (`AutorID`) REFERENCES `utilisateur` (`UtilID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `utilaccesmap`
--
ALTER TABLE `utilaccesmap`
  ADD CONSTRAINT `FK_UAM_Map` FOREIGN KEY (`MapID`) REFERENCES `map` (`MapID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `FK_UAM_Util` FOREIGN KEY (`UtilID`) REFERENCES `utilisateur` (`UtilID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
