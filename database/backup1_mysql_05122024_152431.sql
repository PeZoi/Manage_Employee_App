-- MySQL dump 10.13  Distrib 8.0.36, for Win64 (x86_64)
--
-- Host: localhost    Database: mysql_iritech
-- ------------------------------------------------------
-- Server version	8.0.36

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `attendance_event`
--

DROP TABLE IF EXISTS `attendance_event`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `attendance_event` (
  `id` int NOT NULL AUTO_INCREMENT,
  `type_event` varchar(255) DEFAULT NULL,
  `date_event` varchar(255) DEFAULT NULL,
  `time_event` varchar(255) DEFAULT NULL,
  `exception` int DEFAULT NULL,
  `session` int DEFAULT NULL,
  `employee_id` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `employee_id` (`employee_id`),
  CONSTRAINT `attendance_event_ibfk_1` FOREIGN KEY (`employee_id`) REFERENCES `employee` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=38 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `attendance_event`
--

LOCK TABLES `attendance_event` WRITE;
/*!40000 ALTER TABLE `attendance_event` DISABLE KEYS */;
/*!40000 ALTER TABLE `attendance_event` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `department`
--

DROP TABLE IF EXISTS `department`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `department` (
  `name` varchar(255) NOT NULL,
  `description` text,
  `is_deleted` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department`
--

LOCK TABLES `department` WRITE;
/*!40000 ALTER TABLE `department` DISABLE KEYS */;
INSERT INTO `department` VALUES ('dev','',1),('Dev1','',0),('Others','',0);
/*!40000 ALTER TABLE `department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee` (
  `id` varchar(255) NOT NULL,
  `first_name` varchar(255) DEFAULT NULL,
  `last_name` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  `department` varchar(255) DEFAULT NULL,
  `date_of_birth` varchar(255) DEFAULT NULL,
  `start_date_of_work` varchar(255) DEFAULT NULL,
  `status` varchar(255) DEFAULT NULL,
  `is_enabled` tinyint(1) NOT NULL DEFAULT '1',
  `avatar` text,
  `role` varchar(255) DEFAULT NULL,
  `email` varchar(255) DEFAULT NULL,
  `phone_number` varchar(255) DEFAULT NULL,
  `address` text,
  `is_allow_password` tinyint(1) NOT NULL DEFAULT '0',
  `iri_right` longblob,
  `iri_left` longblob,
  `is_deleted` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `department` (`department`),
  CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`department`) REFERENCES `department` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
INSERT INTO `employee` VALUES ('2','LÃ¢m','LÃ¢m','123456asd','Dev1','05/12/2024','05/12/2024','OUT',1,NULL,'STAFF',NULL,'','',1,_binary '\Z~\Ä\0\0\0\0\0` i\0\Ïæ¢°\ê€b¼©‡%\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0 \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0@\0ÿÿ\0\0\0\0\0\0\0€\à\0\0\0\0\0°\0ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ\0\0`\0\0\0\r\0\0\0\0\r\0\0 \0\0\0\0\0\0\0\n\0\0\0\0\0,\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0¹¼Ž_A‘\á\ôùÛ¼¬œ|k[JIHWGVffgVUs””¶—¦Èª»Ž\\L\Z&6CeS£—…¶ªyhxiH62Q¡\ñ\õúÌ›y–·\éÎ{|]+)#b²\Ä\ç\ÙÌ{\\YZXhXXFVUddƒ¤¥¦¦¨˜˜w³\é¹\ê¿nZŒNQ¢¥•¥¶\Ç\ÉÛ¿e–ª]S™*$f%sgCs’\Çx…–˜hfft…tƒ‚Á\ôúÍ­{‰›j—œj‹\\J:1q’”’\Ã\æÉšxu³\æ\ê¾~L8Fe……¶¹«Œ\\)\'#a¢\Ã\Ö\È\Ç\ê¾;Gu¦¹›‹{kkL*(\'&%$1a±\Â\ôøÊª™™Šyxw†¦\ÈÍŸ_A‘Á\ä\èÊ«›‹{kZIGWVVUd„………ƒ²\õùÛ¬š›Š›Œ|l[JIHWWgVev†—™zJ(#Aq¡Á\Ó\å\÷\Ù\É\Ù\ÚÝ¯mM+(\'5Tu…•§¨ª‹[96Dr£\ÅÉ«‹ZIGUfvuu„•”µ´\ö\êÜ¿^M,$Br„”¥¶·¹ªŒJe§ºž.5FC£ªz[4b”•†…––¶¸™‰ŠzZH6Cr¢\Å\Æ\ØÊº«¬ŽmL+$Aq¡\Ä\ÖÉº‹jHUƒ´\×Û­m;\'4s”•¦¸ªŠiXfu…•¦¥\Ô\öûÿŸ?(WxyjijJ8GG76$1a±\Ã\Ã\Ô\÷Û«š‰w†µ\Ö\èü_Q¡\Ò\æÙ«›{jYXWVffeut“¤\ÅÇ¸¨§\×\êÞŸ_-*8VwyiZHGVeuvu•—˜™‹kJ8\'$3Qq¡Á\ã\õø\é\éû\î¿_>(FVggggfv‡xhWUc’\Ä\×Ê¼]+5Tdts“£\Ä\Õ\çù\í¿>+)GWWWVffet„”¥Ç¨¨¨º­~,\'ETƒ\ÆÊM)6duvget”´\Æ\ØË­}L*$R¢\ÄÇ¸¸¹»­Ž^-\ZBa’´¶¨˜‰iWTƒ³\ÕÙ¬kGsÅ©™ˆ†–·¹ªšzjXgfu“\Ó\÷ýß/Ct†ˆxhhhYH64Rbq¡²\Ò\õúÌœzw•\Æùý\ß/A±\ã\èËœkJ8Ed„•—‡‡v…¤\Å\è\ëÎ]ZjzkK*\'5d…—‰iYGFTcƒ“´\æÚ¬ŒlK:875CQ¡\Ò\å\çÙº¹\ÚÝ¯~n=*\'U†˜zZIGFVWVTc‚³\ÆÉ›ŠzjI74cƒ””¤µ\Å\×\é\ì\Ï?4c¥¨šjYHFDcƒ£\Å\ÇÙ¼lJGe…•¦¨©›kihxiI\'4R¡\â\öûÏO$Sƒ¥§™he”\Å\ØÛ®=+)\'6EUefTs¤¦˜xfuuur‘\ñ\õûíž‹‰©º¬]K9GFUu”¶¸º¼Ÿ?1r¤———˜š{[975CRq¡\â\õøÚ«™˜·\ÙÝ¿o.1‘\Ó×ºŒ[8%B\Ò\æÙ«Š‰˜©ª›Œ|lK)GGX8#A±\ÕÈ©‰‰yhWUr³\Õ\èÜ{k[:(&$Aq¡\Ñ\õø\ë¾~KWv‡—©Šzh‡¨ªŒmL;*A¡\á\öÚ‹iw‡‡wv…–———–·\Ç\êÞ¯?!\Ã×«l:\'Dcƒ¤¶\ÇÉºœm:7Es¤¶¸šyhw‡¨›l;$CbÁ\õúÍž]:Ge…¦©Œ\\*2q¢\ÅÇ¹ª«ŒlK)6Dds“\ÅÉ¬\\96DSq¡\Ò\õøê»º»¼mKIXXWfwww‡–\ÈÍ/3Tds“¶¸škYXGF4Aq±\Ò\ä\æ\ç\é\ë\ÜÎŸo?.\Z!q²Æ¹‹J\'#a¡\â\÷ê»›Šš›M+(6Ueu–˜Šk93Rsƒ„“´Æ¹™xv•Æ¹ª›zˆ©›m<a‘\Â\æÙ¼Œ\\95S’³\Æ\×Ú¼­~M;*(76ETdts“³Å·¨§§§¸ªšŠzjhgu–·É¼ŸOR‘\ÄÉ¬l*2q±\Ô\×Éº«mK)&Cƒ¤Æª{YWf…§™zihWVd£\ÖÚ¬m+&B‘\Ã\ç\ë¿_<\ZCr¤¦—˜™‰zYHEcƒ³\Õø\ì¯O2Q¢´µ··Èº«{yx‡—˜˜˜©«Œkjhxw§ÜŸ?3duvfet”¶©zHFCa±\ñ\ôùÿ¿]km#R“Æª‹K(#Q¡\ã\æ\êÌ¬}\\[JI8EUd„”´\ÆÉ»œ|[K:$R’¶™iVt¤¶¹šzXe”¶Ê]+\"a¡\Ô\ØÊœ{ZHEs£µ\Ç\ØË¼®?#Ba’´·¨˜‡‡†…¥¶\Ç\ÙÌžn<8Feu–§¸«]+Cƒ¥¸«|K)1q±\Ô\æ\ÙÊ»œ];)&4b¢Æ¹›[HU„•§¨˜‰yx˜™š|=\Z\á\óù\îŸm\\:Gggggfffet”•¤\Å\æùüß/(\'&%2q“•–‡v…”µÇ¸©˜—·Éº«š«^)T¶\Ì~M+(FfWWFDb’\ÄØ«{J&2q\á\ôùÿŸ]Zzl2ƒ–§ªl:\'3b’\Ã\åùÝ¯_A‚¤¶©xw…¦¸ª›{jZJ(%A‘\óûlIWvw‡™zK4c…hF3Q‘\Ñ\ò\÷\ì¬zxˆxv•¶\ÇÊ»œ›?%3Rr¢\ÅÈšyyiHDb¢\Ã\õú\îM:Ge–˜‰‰‰zZ8EƒµÉœ|L*#Q³\Å\ÆÈ¹Ê¼nM+2q³Çº{YVt”¥¶¸º›{zzzl<a\Ñ\óøÛ¬‹zyyiiXWWVUTr¢\Ó\å\÷ùýß?(GWXI8%Stuuus’\Ã\ÕÈ©™˜—§§§·\Øú\ïušl[;)5d‡yY74R’Å¹ŠiG4aÁ\óøþŸ|{l<#’ÇšzjI73q³\Æ\Ç\ÙÍNQ‘\Ã\ÖÉšˆ—¸º¬m<)88&$Rr£¥¥·¨šŠjhw˜{J977!¡\á\ò\öú\Ízwµ\ØÌŒiw§º­mZiy{Jhj:&S„¦ª{Yhi9%Br“£´\Å\Ç\ÈÊ«››Œ];)64S‘\Ó\è\Í~L*\'4b£¶¨ˆ‡†¦\ÇÚ¾>#Q‘´·™xgu”¥\Æ\ØË­|kj{],\ZaÁ\ä\è»{ig‡˜‰xxxhWFSq¡\â\õøûþÏ/&EuwhXVgWVUdƒ¤¶¨‡‡‡††•¤\Ä\õùþ¿?\ZU¨Œ];)&B“¸‹[86Stu…•—‡fƒ\Ã\çÚ¬›Œ]bµªkYHGEb²\öÜlK)6Teutƒ£\Ä\×\È\ÈÊ¼¬®O(7GGG65Cb„†uud“¤¶¨†·©‹Z\'!Á\òøû¼Š‰§\ê¯N9Vu§™‰hv–\Ç\Û\Î$T…‡wv†ˆw‡˜Šj8%B\Ñ\õúÜ½žnM*\'5S‚´Ç»\\9&S“¶¹ŠiWe„¤\×Ë­}]<\ZQ¡Å¨ˆvu”´\Ö\ØÊ«›‹‹^\Z!q³Çº{JGUt•‡‡—ˆyXFCqÁ\ò\öùû\îÏŸO=,Duv†‡ˆiXVu†‡yhWffeds’±\ã\öúÿ-Eµ\Ý-)86d•šZ85Teud’´Çšx†–§\ÇËž=¡\÷½}L)5r´\Ø\Í-%Dct„„£\Ä\ç\ÙË­Œljyzl;\'Ed•§™zihwˆ‹]1¡²¥s±\ó\÷Û›‰‡–¶\ÈÊ««\\jj:Ev†ˆwwf¥§§\ÈÜ/\ZR„––˜ˆˆ‡˜©‹\\*A¡\á\õø\ê\ÛÍŸnL:(5d”·ª|:6S”¦™zXVt…•¶\ÇÉ¼žoA±Õ¹zWT‚\ÄÈ©™˜˜©ª›|L)5sµÊ^,%Ddtt„”¥¨yWTq\Ñ\ôøýÏŸnLIhykJ8FUTƒ”¥¦¶\ÇÚ­~L:8GEUds“´\Å\×Ú½mG£ù\Ï_)86UfWFTr¤§xe£\åÛ[Fb\ÒúŸ$\ñú\Ïo,Q\Òù\Î~N\Z$c”—‡‡†¦É­n<)&UffVUtƒ¥§˜ˆ‡‡†•\Å\èÝ¿o3TW1\Ñ\åÇ¨—¦¶È¹ªº¬|Zxyw¨š‹{]Vfwwˆz[#a\ÃÇ¹›jg†˜‰ŠkJ(%3a‘\Â\Ô\å\÷ü\ïŸ_=+4c¤¨šjYVfvwXEb¢\ÄÈ©˜§¹ËŸ/q\ÔÙ­N#qÄ¹ŠXfvu•¶¨™x…\Æ\éß/4TffVUc’´·——–µ\×\éÝ¯o=\ZC„–ˆxXFTr’\Â\å\÷ú\í¿_<*(6Ueu…–——·ºŒZe\Æ\Ý\Z%DTc„…t”µ¨w„\Ôù¿OA\áû\Z1\ô\ì=\"\ã\è¼|K%\Ô\èÜ®M;99\'5Ts•˜iWe…—ˆiGTs“¤´\Å\×Ú¼lZiy‹_AQq¡\Â\ÕÇ¸¨¨¨˜˜§·Ê««­}l\\<9XY97UfFSr³\ÆÈ«{h‡˜š{[9\'4Sr‚’³\Ô\öùÿŸ^L:8Fd•¨š{ZHGVFE2q\Ñ\õû­kXv—©zg…¶Ê­>\ZQ¤¨yXWVEb¢Å¸ˆ•\Å\÷ü¿oCu†‡hVTs“´\ÖÈ¨¸¹«œ}L+4S„•—wVc‘\Ñ\ôùýÏ_LKJIHGVWUt•§˜ˆ™Š[8e–škK)!q\Ñ\öºyv–‰V‚\ôü\ZA\âý_a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',_binary '\Z~\Ä\0\0\0\0\0` i{J\õQ9\çr¢\è»B;\Ó\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0 \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0@\0ÿÿ\0\0\0\0\0\0\0€\à\0\0\0\0\0°\0ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ\0\0`\0\0\0\r\0\0\0\0\r\0\0 \0\0\0\0\0\0\0\n\0\0\0\0\0,\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0sƒ”´\×Ê‹iw‰ifv†—˜˜™Šz[9&R’\ÅÈºœkjjZI(%Cs„utr¡\á\ôøþßŸ_-\Z\'Fe†ˆyXgvwxWUc“\ÄØ«zˆ›K&txT”„\ÄØºŠ™‹jXuˆhWe……¤¦¦¦\Ä\÷ûÿ¯_4C”u¦h¤¬W§›L%¤™yziJ86DSsƒ\Ã\èH…ºM…Ga¢\áùÍžN)\'3s„¥§—¨zXVt”¶¸¹š™L(&B‚“\Ã\æù\ß<8GT¥¸‹jIGGESbqÁ\òù\ïžmYg¤\Û|l)eu·Š˜‹iixjXj)A¡Æ˜u£\Õ\èÜžlZXw™ŒM\Z$Rs’\Óø\Þ=*(&4Ca¡Ä¶§˜†¦¸Šˆ™if––¦\ÈÊ­}L)5u†˜™zZHXG7$1ÁÔ¶´\ä\÷ûÿ¯O-\Z\'5Tt†—‰yXVu•¨ygu¥¨‰xv§«kj;!Q¡\á\ôø\ì­}KWv‡ˆ‰hggfet’\ã\÷üßO4Bƒ„´§¶ÛŒ{l+r†•¦¨›jZI75R¡Öºzx‰JT‡Fs‚\Ò\÷þ>\ZRƒ¥¦–·»{IEs´Çº›y‰Š{[J)%3a¡\ãù½mJGd¤¸ªziiiI73a±\óùÿ#a£µ¸‰ˆxˆyhhVd“\Ä\ç\êÝŸ~mM3s”¶©‰yx‡©‹]*$B¢\Ã\öü¿o=\Z\'%C1•†vu„¤¥¤\å\ë­}:E„¶Èª›{kJHWgxhXWFECQ‘\Ñ\ô\÷\Ø\èúþ¿o/)\'EUuvwwgft„¤\Æ\ÈËlK986Cq²\ÖÊ­])%B²\å\èÛ­mJXgw‡ˆˆyiXFS’\Ô\èÛ­}\\K986Cr“´\Æ\ÈÌM:($R‚£\Å\ØÊ«m<Bƒ¥——¨˜™{YGC\Óù¾_B‚µ§§¨šjWd”¶É«|Xv¨¬n=\ZA\Ñ\ö\ë[HU”·©Šy‰Š[)%2\â\÷ý=)6Ud”¦§©ŠziXFTr¡\ã\öù\ëÌ½­^<*(Fevwv†§©‹[:\'64R‚¢\Ó\ö\êÎM;(54s†vwfes‚²\ôøý¯?E„–¨™ŠzYXgwxiXH64A\Ñ\ò\÷ú\Û\ÜÏŸO,)7Eeu†ˆxhXVds£\Å\×\ÙÍŸ^,&4B²\ÕÙ¼};\'Dr£\ÅØ»œlIWWfu…¦¨š{IEc£\ÖÊ«š‹{\\*Cq³\ÇÈ»]*76Cr¢\Õ\ØËœ‹‹kK)&Cr“¥µ\ÇÉ¼~<$Q±\ÕÚœ[Ge…¥·¸«Œ[9Ed”¶©yw•\ÇÌ>\Z2q¡\Ó\÷\ìŸM)5s¥©yg†—šk9%A‘\â\÷\ì|[:\'Ed¤¨‰hgfUc’³\Õ\×È¹¸\ÊË½žn];98H63q²\ÖÉ«ŒlL3Q‘\Â\æÚ¼Œ\\:7Tu†vvfer£´\Ô\öú\ï3s¥§™zig‡ˆ‰jYH6Ca¡\â\õù\Û\ËÎŸO,&Ed„¥§™ŠjHFTƒ¤\Æ\ÈÊ½~=\Z4Cb’\Ã\æ\êÍ=5c”¦¸©‹jHWfet”µÇº|J5b±\õê¼m[IHVe•¨šjYXGDƒ•”´\åûÏ/\Z5Tuvet„”´\Ö\é\Îo=%B\ÄÇ©ˆ‡—ˆ‡—¸«ŒmL\Z\"a‚’\Ã\Ö\ÙËœkYf•·¹»¬ŽNSuwG4a¡\Ô×ªŠYUƒ\Ä\ç\ë¾>\Z8GG74R‚£¥¥¶·¸™˜—·Ú½ljjZYII8%1q±\ã\öú\î¯OB‚µ¨™‰iXWefUDb‚‘\á\ö\Ù\É\É\Ú\îŸ\Zb“¦©‰hw‡—™zYGUdƒ£\Å\×\È\É\ÊÍŸ^<+2r¤·©ŠjIFc“´Èº«Œm<%3b²\Ô\÷úÞŸ?4du…–—xwwwwv…–§šjGQ±\ñøÿ\ÏoE…ˆyyhXVuu…–¦˜–\Æù\ï/qÁÆˆft”¥¶·¸©ªŠ‰ywˆˆˆ†¦È¼}\\IGV…¨‹;#A‘\ÒØª‰†¦·Éº«¬O\Z2bsttƒ£\Å\ÇÉªŠw…¶\ØÜ¯_&FFESr’³\Å\Ç\ÈÊœkhv¦È¼|[YhxxxyY8&3Q‘\Ñ\óøþ\Ïo\ZS„—‰iXGFUV5#A‘Á\ñ\÷üÍ¬»½Ÿ/Rƒ¦˜‰xgv†ˆyhfu††•¥··\Ç\Ø\ëÞ¯o?3Stt„–xe¤µØ»[YYH6Tc‚£\Ã\Õ\è\ëÎŸ_#Sr“µ§¨©ŠziXggVTb‘\â\öûÎŸO+6u—ŠZ8Ec‚\Ä\ÇÉ¼KF…·ÌN1q¤—vu„•–†„£\Õ\èË«›ŒlK8Eƒ\×\Ío,%3a¡\ÕÉšyw†§™zXd£\ÖÚ­|jŠŒn\Zq‘³µ¶·§¨©™‰h…µ\ØÍŸOCcs“”£\Ä\Ö\ØÊ¼lkZiyiYHFUt”¶¹›kJ86Ca¡\ò\÷ü\ßo\ZS•˜zZH66EE3A‘\Ñ\ñ\÷üÍœª¼Ÿ?Q“¦¨‰iWf…–˜w†—˜xv–———¦\Ç\ÙÌž~]K:)#Q‘\Ã\Æ\ÇÉ»]<1³µ·§˜§¸º¬‹|lK)\'4R³Æ¹©šzjiYHGER²\äø\ì®~<(E…—™j8Dr²\Õ\èÛ®o3r\ÄÉ«|K9FVfVUdƒ”¥•¥\Å\æúÍ|lL+#qÄºl9Fetƒ£\ÖÉº«›{jjI7C‚\Ã\çÌkizk<1¢´¶·¨˜˜©šzhf•\ÆÛ®o#Brƒ““\Ã\Õ\ç\ÚË¬Œ|kjizjJ97Dr£·©ŠyyiI&A‘\á\öü\Ïo%c•˜yYH74StdqÁ\ôùË¬z˜ªO\Z\ÄÇ»|IFc’\ÅÈª›{ZGd”·©Šif¥¸ªŒkZHGFUs£\ÆÉº«œn=1±\ñ\öÙºš˜©«|ZXXgggVd’\ÅØ»›‹jiYXWGDb’´\Õ\èÌ­n,Cƒ¶©zXUƒ´\Ö\ÙÌž^\"\Ã\×ËlK8GFUUS‚£\Å\ÆÇ¸\ÈÛ¾~\\KJ9($R“¦weƒ´·¨§¸É»¬mL:)&3a¢\ÕÚ­m:WwiH74Bq£µ·¨ˆ‡—¨©Šyhv¥\ÈÌŸ?\"Qbr’±\Ó\õø\ÚÌ­Œkihx˜š|[J8FVedƒ´×¼m)#q\Ñ\öü¿oR”§‰iYGFUUCa\ñ\ôý\Ï^ZzkK2‚µ¸«kGe”¶È»Œ[:7Dr³\×Êœ\\He—™jXe…–ˆw…¥\×ËœŒ|]-\ZAÁ\ò\÷Úªš™š‹lJGUe††vu“\Å\×Ú½~=\ZCs„•–¦§˜¨ªŒ<1\Ã×¹‰x‡¦·É¼Ž>\ZA’\Å\ÇÊ¼ŽN$Stdr²\Ôèºš™ªŒlJWgˆjHFfVDa±\óøÊ©¸Ê¼}]<)6Tt”¦¸»ŽB“¨yY8$Q‘Ô¸™w…¦·¨©›{Yg†§ªŒm,2Q‘²\Ó\Õ\æ\éÛ½ŒkYg‡˜™Š{[ZI(%A\Ñ\÷Ý,&R²\æ\ë¯^+(%c–˜yiXH65\"A\á\ñþ\ïo]\\K:7Eu†—‰igv—˜‰iGUuu…”µ\×Ë¬|JXY84r”µ·™x…\Å\èÝŸO,\Z%3b\Â\ÆÇ¸¨©ª›Œ\\*\'Dd„…†„¤\Å\×\ÚÌ®?!q£¥§¨‰igwˆhFS\Ò\ö\è\êÍž}kjkKBƒ•…¥\Æ\ØÝ\"Æ‰w‡—™{IVvwwgd£\åÚ¬_1‘\ÒÆ·¦\ÆÚ½{kJGe…¦¹«œOCtˆIG62a±Õ¸—–·¹š™šœl;(4r¤ÆºŒkK)%Dcsƒ”“¢\Ò\õùì¾ljiihxxˆš|;\"q\Ñ\öüŸ=C£\ç\Í~M;5u‡ziYH7$!Q\ñ\ñþÿmmL:7Vf†‡ˆyhwwhVTr£Å¸©˜˜¨©šŠ{Lq³·————¦\×\ë¿_Q‚³Æ¸©™ˆ—§¹«›|M$Ss”†„¤\Å\×\ÉË­Ž_\"bƒ¤¦¸ªzYVeuu…”´\Õ\æúÞ¯oN<:)\'%Cctt“´\Ö\ê­]8e¥É›Š‹l;(2q³¶™gt´\Ö\ÙÍ.$Sƒ”•”\Ô\éË›ŠŠ‹zy‰ŠŠ‹|]-EVH#1Q‘\áç©‡¦¸ª™˜ºN*\'$Rƒ¤¶¹ŠzjHGUeuvecÁ\ôù\í¯m[YXWfu•\ÆÚ½o3q\Ó\é®^*E„¨›jj[)6exˆiH6$1q\Ñ\ñúÿ¯ž_,Eu—™ŠkIGFUdƒ”¥·©š‰‰yyxyj)a\ÂÇˆ†¥¶\È\ÉÌŸ/\ZQ‚£´\ÕÙ»›Šzyˆ™‹{lK)\'6Cb“–…”µ\ÇÉº«œnQƒ¤µÇ»ŒZGUeu……”´\åúÞŸoN<*(\'%3Rr“¤´\×Ê›jg†§º››^1\Ò×ªyf„\Å\ØÌŽL97Ds”¦†µ·¸¹ª©«œ|kZYijZZJ8GX9A±\ãÙšv¦§˜–\Æ\ê\Î.S„…•¸‹ZXGEcƒ¥—xes‘\âøÜœŠŠzjXgf„´\æúß?B£È­N\ZR…w†™\\3”\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0p\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0ø\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0ø\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0ø?\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0ø\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0øÿ\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0øÿ\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',0),('3','Thiá»‡p','Thiá»‡p','123456asd','Dev1','05/12/2024','05/12/2024','IN',1,NULL,'STAFF',NULL,'','',1,_binary '\Z~\Ä\0\0\0\0\0` i\Z\Ô\æ0\èk0¨;Æœ,\Ã\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0 \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0@\0ÿÿ\0\0\0\0\0\0\0€\à\0\0\0\0\0°\0ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ\0\0`\0\0\0\r\0\0\0\0\r\0\0 \0\0\0\0\0\0\0\n\0\0\0\0\0,\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0u•¦§¨¹¬KV–¬=7H%r†wge„¦––¦Èº«Œ}M+(6G6%2a‘¢\ÃÇ¦¶¥\åù\ëÎžŽm=)&S¤¸œ[9VvˆiGC\Óù¯N\Z#Å§¨™ˆ™ŠjYGUTq\Â\å\÷û\Ïo-6efc¤\ÆÙ­lK8FEc…„´É˜·\Ë|G„\Æ\ÚÍ^=+$b¤ª;4„˜Y„«;6Ud†wWUc¡\å\Ë{igxYWe†i&2q\Ñ\õø\ížm:6ƒÇ¬n&$Q‘\Ó×ªy–¸«lXf†—¦\ØÌžn<*\'FX7$AÁ\Ô\×\ÈÚ½~M*&DSƒ–v„³\æé¼›¬\\:U–˜šlXyYhj\'b¶‹8c¦©{YGU¢\Ä\Æ\ÈË­mZhjJ&dv…§‰yXU„¥¦·Ê­^;9XI!Q\Ñ\ôù»™ˆ˜—§¸\ÉÌŸ_<)7G5B‘\Óø\Îo+\'T…‡hFc“\ÄÙœZGd”\ÆÉ«ŒkZYHGETb±\â\öû\ïO+7fxiHVv‡yXVUds“¤´\Õ\Ø\ÉÌžM\'S¢\å\êÝ¯N+(6VG5s¶ŠYfxXG4b‚³Æ§–\Åú¯?4„˜jFdtt‚\Â\õû\Î~L8Vv†˜šl*2q¢\Ä\ÖÙº»¬~,Sƒ´\ÆÙ½}[ZHWxY85R‘\Ã\×Éº¬}L\Z\'$B´¸xe“\Ô\ç\ÚÌ­~<8WgwhGTƒ¶˜—ˆ–\è¿?DwX73aƒ”¥\ÆÉ«zx‰zhw‡™Š{[96Dr“\Ä\ØËžM*\'EUVDR\á\õü\ß<(Uu–——¨ªŒkYgxiVu–¨›[Wv–ºŽ.!Q‘²\Ä\Æ\Ç\È\ÚÍŸN+\'5d„•–‡–§˜˜˜˜©º¬nNA¢¥¦——ˆ‡†–¦È»\\*A‘\ã\÷\ëÍž}n=\Z3r¥¨ŠYWffet“\Ô\é¬{z{KQ’¤¥¦µ\Æ\ØÊ¼­~N#b”––§™iVe„¥¶\Æ\ÙÜ¯O3b‚\Ã\÷\ìŸ]:8Fevwft”µ\ÇÉº«n-A\ÒÈ™ˆv¥·©ª‹kYXghWWUds’²\Ô\÷ûÝ¿O6G64QETs”¥—†¥Ç¹¹«¬ž^,\Z$Bq±\ä\èÊ¬}K9FUeetƒ\Ä\×Ê›zyxˆŠ{J\'4b‚³\Õ\ç\ì®~LJGWWU’\æ\ì5FEDQ\Â\ÕÈ¹©›kXf„¥\ÇÊœzˆ«~<%Cs´Èœ\\96EDa¡\ÔØº›[HT”¦§¸ªœlJ\'4a±\äé»ªº½~N,&TuˆXFTs“¤µ\×Ú­}KJ86Udds“´\Å\×\ØÛ½žo>Q’¤¶¸™ygv––¦·\ÉÌŸO3c‚\Ãø\Í<87Ed…†vu•µ·¨©©»­o.\Z!‘\Ò\×Éª‹{[IGVUu…–¨‰iWUSqÁ\ó\÷\ëÌ­}kz{l;)\'Rctuc¡\ä\×\Ù\ÊÌ¯oSc‚³×ºŠyxxxhv—˜ŠZ7Ds£\Å\ØËmJHX8%Bq¡\òøý¿nKXyZ8D’×­<6uˆZ(aÁÕ¸˜¨™yWt¤\ÖÚ­lY‡©n=Q¡Ä¶·¨ˆ‡¦·º›}<\"\Ã\ÆÈ»œlK84r³×ºŠy‡¨º¼?Bcc‚¢\ÔØº™¨ºœlJIWWWGER‘´¶§¦\Æ\ØÌŸ?q³\ÆÉ«|K(Ds”¤\Æ\È\ÉË®_Ds¥¸šjhf‡˜ª|<4Ssƒ¤¶¶Èº\\)4q\Ã\çÛ­}NCSa‘\ÒÖ¹šxxv–§©‰xw‡†¶\ÈÛ¾?q”—xGS‚³\Å\×\ÙË¾OEt––§¹›lIVvxHT“ÆªzYFs¤\ÅÙ½~LHfˆjJ\'1¡\ñøþ[h‰kK\'R³\Ê|IgxY&A‘\ÔÉ™ˆ˜ŠZ6R¡\ÕÙ»›‰‰©¬~M,!‘\á\õÙª‰ˆ—©š{[IFd…†”\Ä\éÍ>q\Ò\é¬{jhwxxxjI8%Aq¡\â\õú\ïo&u—ˆxˆ‰yzK$r¥Š8#Q±\â\öÚª˜¸º¬Œ|MQ¢Å¨†´\çÜkYgww–§©›‹š_E6#Q²\ÄÈªyf”\Å\ØË¬l\\L\ZDufUb¢\ÅÇ¹º›zzjZI74R‘\Ó\æ\éÜ¿_‚¦™{:Q¡\Ô\×Éº¬n3ƒ¥¦¨™™yx™‹L\"q²Æ¨ˆw•¶\ÈËž]JYiYYI!\ñ\öüŸ[x˜›[8dµºŒK97ES‘\ÔØª‰‰zYGDr²\æÚ«šŠzyšŒM!a¡\Ó×ºŠh†¶Ê]\Z$s¥˜hT¢\æ\ë¾o-1±Ø›zx‰z[(3s”–‡‡u”\Ä\öúÞŸODs¤·©šŒL4c–‰XFTc±\óø\ÚÌ­lK:(&4S‚¤·™w„\Ä\èË­}ZWv¦É­oS–yhXXG61\Ò×º{8B¡\óùÛ¬Œ{kZIFu‡‰jGT‚\Ä\×Ûž^+8G74Ba¡\Ó\æ\éÛ¾o<KIWhhI6C’\ÅÇºŠyŠl)$b“¥¦¦·\ÉÌŸO2a’´¶§§·É«Œ{jjj[\Z%3Q±\ò\÷\ìŽZf–©zh–¹›{\\*\'ETr£\ÅÇº­=Bƒ“\Ã\÷Û|kZHgxY7T„¶šJ5s¶‰f„´\Ø\Ì}JWwyI$aÁ\öë½>\ÓÈªš‹k:2q£µ·˜ˆ†¥¶\Ø\ÚÎ/$s¦©‰‰ŒM$c…vfu…ut£\Ä\Ö\ç\êÝŸo=2a¡´Æ·¨—§É»Œ|[IXf‡šmA¢¶¨zXVds³×ºŒJ%QÁ\õúÍmZXhhgw—©|*$q³\×Ê­~<9)\"q’£´\Å\×\ÙÌl=+88G6C\ÓÙ«{YgwxXEt–‡†¤\æû\Ïo\Z!a¡\ÔÇ¸¨©ªzh˜š{kJ(5c„–‡uµÉ,%R¢µ§§¶\èÝŸO\'FFER‘\Ô\×Ë[Z8Es¤¶¹©š‹[HGUƒ\ÆÊœm\Zb¤§ˆv–¦¨©š‹{KaÁ\ö\êÍŽ>#q\ÃØ»Œ\\:$Q’´µÇ©™˜ˆ˜¨¨ºœlZhˆ‹\\*F‡{:\'6EECq²Å·¨—¦\Æ\éÝŸ^-\Z#R£´µ\Æ\Ø\ÉË¬}[ik[97UvwH5b“¶©z8C³Æ¸˜˜xd±\ôüß^L*6fwgf…Èœ;5t––§º\\:A“£´\Ä\Õøü\ÏoO.2a¡\äÙ›jXf†—‰g†‰iE\óú\ÏoMQ¡\Ã×©˜˜™y‡¸œlJ8Eu–˜ŠyihiJq±\Ó\å\ç\é\ë¿o<)GFVfd„¥·É»ŽN\ZQ’¤µ\ÇÚ¾^)Fe–˜ŠiiH6C‚´¸˜ˆˆˆ—¨›kJ85Q±\å\éÝ>q\ÃÙ½n,a¢Å·¨¨˜—©™Šzhf„µ\ÙÌž^,5uˆiYH75Ca¡\Ã\ÖÈ¹¨¹Ë¯_,\ZA‚“•”µ\Æ\Ç\ÙÜ®]Ixz[9GgY8%2a¢\ÄØ›JD’Å¸‰g•§–µ\ç\ì¿oL[L)7FEB‘\ô\ëŽ[YXWv—ŠYGETt……„£\Ä\Õ\÷ûïŸ¯O2r´\Ém#a²Ö¹›jgwhD\ÓøÍŒ‹l:7Edt†e’\Ô\è\ÊË®o-Eu—‰hg‡ˆyYH%Bq‘Á\ó\öü\ï?*7FVeu††–¸ª›NA¡³\Ä\æú¿_\Z5u‡ww†§š\\B’µÇºŒK&B‘Ä··É›Šˆ©œm<2´ÈŠYD\ãùÍkjIE…¨Š[\'3q\Ñ\ö\ë¾o;HfˆiXWgWVUs“¤´\Õ\×\Ù\ë\ß\Z2q¢¥–†¥¦¶\ÈËlXˆŠkIgŠ^a‘\Â\åÊŠw•·©Šg•¨ˆ†¶Ù½{{n$CQ±\ôý\\[J(5St…–‡wfeut¢\Ô\Ç\Ç\è\êþÛ®~\\KIh™q\ÑÖ¸™ygu†…¥µ\è\ÍmZZHFeu‡gT‘\ä\éË½>Bƒ§zIDr¤§˜xf…–†•´\õû\ïŸO4s…–˜ˆ‡¨™ŠŒ]a¡\Ã\æ\ê\Í~<\'Tuvu“\ÖËK8Ec“\ÕÚK&r³\×Ê«ŒlJgyZ8EegFSƒ”„±\ôúÞŽk™M)ViI&Cdc’³\åùÝ{z{ZIWhX6Dr£¥¥µ\Æ\èû\ßoA£µ§———§·º›{ZhˆŠy‰ŒOBQq±\ó\çÉ©˜¨©©«|Ie¥Éœkx™œ=Eet¤Ç»‹‹m,&#Q‘Å¹k\'B¡Á\ôü¼h·˜¬}m]<)HZ#A´·˜xwfu„¤´\öý>\ZQ¢\ÄÙ‹X…·©ªœ\\9WH4r¥™J%a±Å¶¶\Ö\ê¾mYw¨šŠ›}<#‚¥¦©zv·«‹Œ^Q‚’\ÃÖºŠzXVu…„£\å\ê\Í<$q\ÑøÝŽLHv‡™š{K(Ffv‰I6EA¡\ô\ï-%q´¨‡¥\ÖÜlZYHVu‡gUrÁ\õúÞŽ}\\ZYYI92q¢µ·§§\ÈÊ¾3bƒ”¤¶§§¨˜—¸º\\Hv¨šŒ]Ccss‚²\Ô\ç\ÙÊº»½Oa´¨ˆˆˆškHwˆŠZHV…˜|+&EDcƒ”§y5RqÁ\ñ\öÿßŸ>H\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0À\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',_binary '\Z~\Ä\0\0\0\0\0` iƒ\Ù\îf9Ou¢<´eIÉ”\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0 \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0@\0ÿÿ\0\0\0\0\0\0\0€\à\0\0\0\0\0°\0ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ\0\0`\0\0\0\r\0\0\0\0\r\0\0 \0\0\0\0\0\0\0\n\0\0\0\0\0,\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\æ\ê\Í,7U¤\Ë\\Yi9FgWG63Q¡\ÃÆ—¤\ÖËŒjgˆiWe…–§©ªŒLA‘\Ò\ôø\ìÎMJYjJ\'Ds´Ç»}K8EuwWTr²\å\ê®]*%b£ÆºŠyˆ‰zYHFEc‚±\ó\÷ý¿_\'VVe„¤\ÆÙ­mJIGefsÄ©–Ø®]c¶¸ª›}[Zj_Bƒ†wˆYUˆHFS”fds£\ÅØ¼ŒL8GfWES„uc\Ñ\õúÜ®~\\9V…¨›l+A‘\Ò\æÙª‰§Ê\\Hf†‡•\ÇÛ®nM+5W8!q±\ã\æÙºªš›l:Fu†we“\åû½‹M;)WGfv—Šz:E†Xd¶‹Z)a¡\ÒÁ\å\èÊ«‹zŠŒL*Cs•˜yhHES‚´µ\Ö\ê¾_*6ewgfe„´\×Ê]*R‚£\Ä\æ\è\ì¯nKYiK(5c“\ÅÉ­]:6ewhG4a¡\Ó×¹šx•\ÇÊm;7VggXFTc‚¡\â\õü\ïo.\Z6fxYGT”¨‰iXVTƒ”Ä¸¦\èÝL8Es³\çÛ½ž_.$Ddu•©ZWwhGDsƒ’\Ä\Æ\Ç\é\ÎoC„—XEs„„£\äøý¯^<(Vfvv‡‰j84b’³\Õ\ØÊ¹Ë¯_B‚¤\ÆÚ­liiihyk*2aÁ\Õ\ÈÊ«Œ[IHGUu†vc¡\óù\í¿_4ugfe…‡v†u£Øº¬lij9&\"qq¢´\Õ\èÌkihXV•¸«|ZI8&2qÁ\äø\íŸ/\ZRƒ…†††•¶¸ª{YV…—ˆgT‘\òøý®^+8Gfv‡hf•¸¬^+$DSb\Ò\Õ\×\Ø\ÙÌŸNB‚\ÄÉŠhw‡ˆv•¶Éº»ž^KK<\Z!£¥§‡‡†——–¦\ÈË];\"\ñø\ë\ÏM:9\'4s¤¸ŠiXgWUc¢\ÕÙ«‹‹l;#b‚¤¥¥µ\Ö\Ø\ÚÌ¯o.$Ss”•¦§˜xgv†…´\æûßCcƒ³\çÜŽKHWfv‡xWS’³\æ\ÚË½ŸO$Suvvvu„´×ºœ{[97ETt„•–‡t¢\Ô\õúÿŸ/9jL\Z!Sdc’\ÄÉŠx†¦§¨¹¼O2QÁ\ô\÷ü¿o+\'Tt–—‰yWfvv…¥\ÆÉ¬mJ8Ecƒ¤µ\×\ÚÍžmKIhi9%q\óýo%dwY7\"q±\ÕÇ·¹«l8T“\Õ\é\Í~Jw™|;7WFS¢×¼mIX8%A‘\ÃÖ¹š‰hv†–¦\ÇËmL\ZQ±\å\èÌœŒ|]+Dt–˜iHEcs’\Ã\÷\ë½~\\:8FUVTs“¤\Å\Ç\ÈÊ»~M+A‘\ÄÇ¹ªziWe…•¥\Ö\êÝ¯?5Ts¤Ç«l:Gefe…†vs³\Õ\èË««½?q¤—‡ww‡yiXVfuvvt“´ÇªiUq\Ñ\õúÿ¯_LlN#!´—ft£\ÅÇ¸\ÉË®_Aq‘\Ã\ÖÈ¹ª‹zYWv—™zZHEdt“\ÅØ»‹y™›}<A‘\òø\íŸ\\Yw‰[)3¡\ç­LGvˆj)a±Ö¨—¨šjFc²\æ\ë®]Iv¨«|\\K\ZA¡Ä¶·˜ˆ†¦·¹«Œ\\)$r¤¶\ÈÊ¬]*R“¶¨™‡§Ê®o-\Z3cuUR‘\Ó\ÖÈ¸\ÉÌž]KIGgXH&BÅ¨w†•·¸ª|:5q\Â\çÚ¼žNB‚“´\Å\È\ÉÛ¯_\'Dt¦¨‰yhf–©Šk:&Cr“´\ÆÈ¹º­.q\ÒÇ¹šš|L)%Stt”¥§—¦È¬[HUt£\ÕÈ¹ªª¼>)A¡ÆŠH3³Æ··\ÙÌ>$b‚´\ÆÉ«{ihˆyHU…§™jXFdƒ³\ÖÙ»›z‰‹|\\AÁ\óú\ÏnIw˜{J6b\ÄÊŒZXgXGC‚Ä¸™ˆ˜ŠZ6B‘\ãè»‹‰ˆ©¬~M,‘\á\õé«‰‡§©šŠ{[84s•¥\ÇÉ»žN\Za\ÄÉ‹Yg…¨ª|[:#Q’“²\ôù\ß_9f‡ˆˆˆ‰xˆ‹]qÆŒ*Qq‘Á\õ\éÊªª«‹‹|M2a‘\ÃØ›Xs\ÅÙ«{jg‡ˆ—©›{‰«žO2TECa¡Ä·¹ŠygU“\Õ\ØË¬œŽN#bs“µ§‡–Ç»{jj95c“¤´\öû\ÏOA¢Æ«[&R’µ§§¸º­MCƒ¤Æ¹ª›jixzK3r£¶¨ygt¤\Å\×Ú¼|lKIZ91¡\òø\Ýn9e¦šZ7r\ÅÊ\\97ES“µ¹Šx‡‰jHEc’\ÔÙª™™™ªœŽNA¡\â\æÊ‹x†¶É­m;7T…—xU“\ÖÚ®_\õ\ÍlYgwyY6S„•–†…”\Ä\æú\ßN+\'Ds¥¸™™œ^\Z$r¶ŠI6Tcr¢\Ó\öÚ»«œŒl[:(%Cr¢\ÕÉ›Yd¤ÈºœkHe–\ÇÌ?\Zc¦‰hwyZQ¡´·ˆe¢\å\éËª«œ‹‹lL*&Dddƒ¤¶·È¼|ZiJ75Sq±\ôúÝž~==5…˜z9%R‘\ÄÈªŠš‹LCƒ”¥¶¸ªš›N2a’´Æ¨‡•¶\ÇÉ»­}lm,&54R\Â\ÖÙ­\\8T¥˜xf¤\è½~L96FC‚Ä¹z‡©m$b’²\õû{y‰‰Š{k:\'Dt…wt¤¹jVƒ\Ãø\Þoc–ˆWS¡\å\ê¾oQÃºzxxyj)a¢µ·¨x…µ\Ö\ÙÜ¿Cƒ¶©z‰‹^\Zb…vfu…†…•¤\Å\×\ÙÌ®~^-\ZA‘\Â\ÕÈ©˜¨¹›ŠŠzYXf–©N\Za\Ñ×ªŠyZ8D‚´·šj5\òùÍ››|ZxyjIWwiHD‚\Ã\×Û®_7G&3R¡\Ó\÷ë½Œ|>+8GXY7$a±\æÊ‹yyyZ7S”–†¥\Æ\ÙÍŸ_!a±\ÃÖºˆ—˜˜–\ÇÌ[jJHFuwge¤È¬^4r£¶¨‡¦\é¾o,)7FECq¢\Ä\Ö\êŸ<Ffet¤Çº›ŠzjYWVtµÉ«ŽQ´™gt”\ÆÊœkixj8$a\Ñ\÷\ë¾.!‘Å¹š{kJ\"q²\ÅÇ¨˜‡¦¸¹¹»žL8v˜š|;7gz:&EETc‚¢\ÅÈ¨—¦·\ÙÌŸn=1q¡´\Å\Æ\Ç\ÈÚ½nJhyzZHXWVh7#\ÔÈ›ZGDb¡\Óè»šzGr\ôû¾}lKGvˆyh‡ªm\Za³Ç»Œl;(a¡³´\Ä\öúÝ®n7\'&$B\Ò\è¬kGu—ˆhe•˜xt\Ã\÷\íM+q±\Ôç»‹yiWt\Å\Ë}9Vt¥·º\\If˜|+Br’´Æ¸·Ê­n;HHFVUdƒ´\Æ\ÈÌŽN\Zbƒ£\Å\×Ûm:GEsÆªŠzJ7S”§ˆgu¥·©š‹kKa\á\÷\ê\Í-\"\ÕÚl;$Q‘´¶§§¨¨©šzxˆ‰ˆ—¹­n=D†xXWWVUS³¶··\È\É\Ú\Î.\"a’¤¥µ¶·\Ç\Ú\Í~;WˆŠjYZ:&53Q¡Ä¸™zHC²\ÕÉ˜—·§\ÇûÏO<*6fxxhv©m*&UevxGTtg5AÁ\ò\öø\é\ê\íßŸ?Ab‚´¸ŠID“¶©‰hu‡gS±\ôý¯^L;4c”•¥¨˜—¸ªŠ‹\\)$r”´Ø«‹Šzjj[)4Bq‘\Â\õùÜžM9Vffv‡wv¥·¹»Ž?\Za¡\Ã\Ô\öü¿OEe…—yv§›[(C“¦ˆw†—‡—™zYH5Q\Ñ\öû\Ï!\ÄÚK)a¢Å¸™ˆ‡–¶É\\Xgf„µø\ßo-)7VgVu†ˆiGTs•…£\Õ\çùý\Ï/#R‚£¥¦¦§—¦\ÈË\\X‡škZi\\Q‘²\Ä×»{Xfu…–•¶§\ÆùÞŸMK<&Evgf–™zYYHFFCq£–ea\Ñ\ô\÷ûÎ½­­Nžo/4vhXY\ÒÅ·¨ye¤—t²\õü¿mZZHfvˆhgft³\èÌŽM\ZA¡\ÅÇºzg–¸š‹jZI8%Rq±\óùÝŸ=)Ee…•§‰g†¨©›}>\ZA‘\Â\Õ\æú¿OEt–˜g…Ç¬]\ZRƒ¤·©{HS£¶¦Èªyˆ¨»]+(65CsttqÁ\ôøü¿n\\K7v™k9EeUs“\Ô\è¼|jyŠkJGfxX5S’µ–•\Å\Öùý¿/Aq“¤¶§§˜——§¹«|Iw™‹[Z[Aq‘²\Õ\ØÊ¬\\Hfe”·ˆ†\ÆÚ¾oKZ\\\ZAs”¥·¹›{jJ8&1¡¶ˆWC‘\ã\æ\é\ÊË›‹‹7fyy\\9xk;+\ZQ“””vs£¥”\Ã\öú\Î}[IV„¦·ºœ\\Gu§«}+(A¡Ä·¨‰f¤×º››{kK(3q²\å\ÙÌŽ]*&T„…¶™x–¨ª›Œ^Q‘\Ã\Õ\è\Ì~JGe–ˆg„\ÅËŽMB\ÓÙ«ZFt¥¶È«‹jx‰zYXgiI#1Q¡\á\ô\÷û\ï¯oLJYYHVvxWVdƒ\Ä\ØËœ‹|[J9H7%2q¢Å¸˜—§¸Ê¾_bƒ”¤¦¦·™˜˜—\ÈÌŽ;W‡šŒ\\-Q¢´µµ\Õù¼«[Xwxg…¶\Ìm:Wy9$r”´Ç¹›zyyjHGU…—‰i8$1q\ñ\ôÿG\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0?\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0?',0),('admin',NULL,NULL,'123456asd',NULL,NULL,NULL,'OUT',1,NULL,'ADMIN','dong@gmail.com',NULL,NULL,0,NULL,NULL,0);
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-12-05 15:24:31
