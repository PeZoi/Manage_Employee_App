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
INSERT INTO `employee` VALUES ('2','Lâm','Lâm','123456asd','Dev1','05/12/2024','05/12/2024','OUT',1,NULL,'STAFF',NULL,'','',1,_binary '\Z~\�\0\0\0\0\0`�i\0\�械\��b�����%\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0@\0��\0\0\0\0\0\0\0�\�\0\0\0\0\0�\0��������������������������������\0\0`\0\0\0\r\0\0\0\0\r\0\0 \0\0\0\0\0\0\0\n\0\0\0\0\0,\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0���_A�\�\��ۼ��|k[JIHWGVffgVUs�����Ȫ��\\L\Z&6CeS�����yhxiH62Q�\�\��̛y��\�΍{|]+)#b��\�\�\�̍{\\YZXhXXFVUdd��������w�\�\�nZ�NQ�����\�\�ۿe��]S�*$f%sgCs�\�x���hfft�t���\��ͭ{��j��j�\\J:1q���\�\�ɚxu�\�\�~L8Fe������\\)\'#a�\�\�\�\�\�;Gu����{kkL*(\'&%$1a��\�\��ʪ���yxw��\�͟_A��\�\�ʫ��{kZIGWVVUd������\��۬�����|l[JIHWWgVev���zJ(#Aq��\�\�\�\�\�\�\�ݯmM+(\'5Tu������[96Dr�\�ɫ�ZIGUfvuu�����\�\�ܿ�^M,$Br��������Je���.5FC��z[4b�����������zZH6Cr�\�\�\�ʺ���mL+$Aq�\�\�ɺ�jHU��\�ۭm;\'4s������iXfu����\�\����?(WxyjijJ8GG76$1a��\�\�\�\�۫��w��\�\���_Q�\�\�٫�{jYXWVffeut��\�Ǹ��\�\�ޟ_-*8VwyiZHGVeuvu�����kJ8\'$3Qq��\�\��\�\��\�_>(FVggggfv�xhWUc�\�\�ʼ�]+5Tdts��\�\�\��\�>+)GWWWVffet���Ǩ����~,\'ET�\�ʝM)6duvget��\�\�˭}L*$R��\�Ǹ�����^-\ZBa������iWT��\�٬kGsũ��������zjXgfu�\�\��ߏ/Ct��xhhhYH64Rbq��\�\��̜zw�\���\�/A�\�\�˜kJ8Ed�����v��\�\�\�Ώ]ZjzkK*\'5d���iYGFTc���\�ڬ�lK:875CQ��\�\�\�ٺ�\�ݯ~n=*\'U��zZIGFVWVTc��\�ɛ�zjI74c�����\�\�\�\�\�?4c���jYHFDc��\�\�ټ�lJGe������kihxiI\'4R��\�\��ϏO$S����he�\�\�ۮ=+)\'6EUefTs���xfuuur�\�\��힋�����]K9GFUu������?1r������{[975CRq�\�\��ګ���\�ݿo.1�\�׺�[8%B�\�\�٫�������|lK)GGX8#A��\�ȩ��yhWUr�\�\�ܝ{k[:(&$Aq�\�\��\�~KWv����zh����mL;*A�\�\�ڋiw��wv�������\�\�ޯ?!�\�׫l:\'Dc���\�ɺ�m:7Es����yhw���l;$Cb��\��͞]:Ge����\\*2q�\�ǹ���lK)6Dds�\�ɬ\\96DSq�\�\��껺����mKIXXWfwww��\�͏/3Tds����kYXGF4Aq�\�\�\�\�\�\�\�Οo?.\Z!q�ƹ�J\'#a�\�\�껛����M+(6Ueu���k93Rs����ƹ�xv�ƹ��z���m<a�\�\�ټ�\\95S��\�\�ڼ�~M;*(76ETdts��ŷ��������zjhgu��ɼ�OR�\�ɬl*2q�\�\�ɺ��mK)&C��ƪ{YWf���zihWVd�\�ڬm+&B�\�\�\�_<\ZCr������zYHEc��\��\�O2Q������Ⱥ�{yx��������kjhxw�ܟ?3duvfet���zHFCa�\�\����]km#R�ƪ�K(#Q�\�\�\�̬}\\[JI8EUd���\�ɻ�|[K:$R���iVt����zXe��ʝ]+\"a�\�\�ʜ{ZHEs��\�\�˼�?#Ba�����������\�\�̞n<8Feu�����]+C����|K)1q�\�\�\�ʻ��];)&4b�ƹ�[HU������yx���|=\Z�\�\��\�m\\:Gggggfffet���\�\���ߏ/(\'&%2q����v���Ǹ����ɺ����^)T�\�~M+(FfWWFDb�\�ث{J&2q\�\����]Zzl2����l:\'3b�\�\��ݯ_A����xw�����{jZJ(%A�\���lIWvw��zK4c�hF3Q�\�\�\�\�zx�xv��\�ʻ���?%3Rr�\�ȚyyiHDb�\�\��\�M:Ge�����zZ8E��ɜ|L*#Q��\�\�ȹʼ�nM+2q�Ǻ{YVt������{zzzl<a\�\��۬�zyyiiXWWVUTr�\�\�\���ߏ?(GWXI8%Stuuus�\�\�ȩ�������\��\�u�l[;)5d�yY74R�Ź�iG4a�\����|{l<#�ǚzjI73q�\�\�\�͏NQ�\�\�ɚ������m<)88&$Rr�������jhw�{J977!�\�\�\��\�zw�\�̌iw���mZiy{Jhj:&S���{Yhi9%Br���\�\�\�ʫ���];)64S�\�\�\�~L*\'4b�������\�ھ>#Q����xgu��\�\�˭|kj{],\Za�\�\�{ig���xxxhWFSq�\�\����Ϗ/&EuwhXVgWVUd�����������\�\����?\ZU��];)&B���[86Stu����f�\�\�ڬ��]b��kYHGEb�\�ܝlK)6Teut��\�\�\�\�ʼ���O(7GGG65Cb��uud��������Z\'!��\�������\�N9Vu���hv�\�\�\�$T��wv��w���j8%B�\�\��ܽ�nM*\'5S��ǻ�\\9&S����iWe��\�˭}]<\ZQ�Ũ�vu��\�\�ʫ����^\Z!q�Ǻ{JGUt�����yXFCq�\�\���\�ϟO=,Duv���iXVu��yhWffeds��\�\����-E�\�-)86d��Z85Teud��ǚx���\�˞=�\��}L)5r�\�\�-%Dct���\�\�\�˭�ljyzl;\'Ed���zihw��]1���s�\�\�ۛ����\�ʫ��\\jj:Ev��wwf���\�܏/\ZR����������\\*A�\�\��\�\�͟nL:(5d���|:6S���zXVt���\�ɼ�oA�չzWT�\�ȩ������|L)5s�ʝ^,%Ddtt����yWTq\�\���ϟnLIhykJ8FUT�����\�ڭ~L:8GEUds��\�\�ڽmG��\�_)86UfWFTr��xe�\�ۍ[Fb\���$\��\�o,Q\��\�~N\Z$c������ɭn<)&UffVUt���������\�\�ݿo3TW1�\�\�Ǩ���ȹ���|Zxyw���{]Vfww�z[#a\�ǹ�jg����kJ(%3a�\�\�\�\��\�_=+4c���jYVfvwXEb�\�ȩ���˟/q\�٭N#qĹ�Xfvu����x�\�\�ߏ/4TffVUc�������\�\�ݯo=\ZC���xXFTr�\�\�\��\�_<*(6Ueu�������Ze\�\�\Z%DTc��t���w�\���OA\��\Z1\�\�=\"�\�\�|K%�\�\�ܮM;99\'5Ts��iWe���iGTs���\�\�ڼ�lZiy�_AQq�\�\�Ǹ�������ʫ��}l\\<9XY97UfFSr�\�ȫ{h���{[9\'4Sr���\�\����^L:8Fd���{ZHGVFE2q\�\���kXv��zg��ʭ>\ZQ��yXWVEb�Ÿ��\�\���oCu��hVTs��\�Ȩ����}L+4S���wVc�\�\���Ϗ_LKJIHGVWUt������[8e��kK)!q\�\��yv��V�\���\ZA\��_a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',_binary '\Z~\�\0\0\0\0\0`�i{J\�Q9\�r�\�B�;\�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0@\0��\0\0\0\0\0\0\0�\�\0\0\0\0\0�\0��������������������������������\0\0`\0\0\0\r\0\0\0\0\r\0\0 \0\0\0\0\0\0\0\n\0\0\0\0\0,\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0s���\�ʋiw�ifv������z[9&R�\�Ⱥ�kjjZI(%Cs�utr�\�\���ߟ_-\Z\'Fe��yXgvwxWUc�\�ثz��K&txT��\�غ���jXu�hWe������\�\����_4C�u�h��W��L%��yziJ86DSs�\�\�H��M�Ga�\��͞N)\'3s�����zXVt�������L(&B��\�\��\�<8GT���jIGGESbq�\��\�mYg�\�|l)eu����iixjXj)A�Ƙu�\�\�ܞlZXw��M\Z$Rs�\��\�=*(&4Ca�Ķ��������if���\�ʭ}L)5u���zZHXG7$1��Զ�\�\����O-\Z\'5Tt���yXVu��ygu���xv��kj;!Q�\�\��\�}KWv���hggfet�\�\��ߏO4B�����ی{l+r�����jZI75R�ֺzx�JT�Fs�\�\���>\ZR������{IEs�Ǻ�y��{[J)%3a�\���mJGd���ziiiI73a�\���#a�����x�yhhVd�\�\�\�ݟ~mM3s����yx���]*$B��\�\���o=\Z\'%C1���vu����\�\�}:E��Ȫ�{kJHWgxhXWFECQ�\�\�\�\�\����o/)\'EUuvwwgft��\�\�˝lK986Cq�\�ʭ])%B��\�\�ۭmJXgw���yiXFS�\�\�ۭ}\\K986Cr��\�\�̏M:($R��\�\�ʫ�m<B�������{YGC�\���_B������jWd��ɫ|Xv��n=\ZA�\�\�\�[HU����y��[)%2�\�\���=)6Ud�����ziXFTr�\�\��\�̽��^<*(Fevwv����[:\'64R��\�\�\�ΏM;(54s�vwfes��\����?E�����zYXgwxiXH64A�\�\�\��\�\�ϟO,)7Eeu��xhXVds�\�\�\�͟^,&4B��\�ټ};\'Dr�\�ػ�lIWWfu����{IEc�\�ʫ��{\\*Cq�\�Ȼ�]*76Cr�\�\�˜��kK)&Cr���\�ɼ~<$Q�\�ڜ[Ge������[9Ed���yw�\�̏>\Z2q�\�\�\�M)5s��yg���k9%A�\�\�\�|[:\'Ed���hgfUc��\�\�ȹ�\�˽�n];98H63q�\�ɫ�lL3Q�\�\�ڼ�\\:7Tu�vvfer��\�\��\�3s���zig���jYH6Ca�\�\��\�\�ΟO,&Ed�����jHFT��\�\�ʽ~=\Z4Cb�\�\�\�͏=5c�����jHWfet��Ǻ|J5b�\�꼝m[IHVe���jYXGD����\��Ϗ/\Z5Tuvet���\�\�\�o=%B�\�ǩ���������mL\Z\"a��\�\�\�˜kYf������NSuwG4a�\�ת�YU�\�\�\�>\Z8GG74R�����������ڽ�ljjZYII8%1q�\�\��\�OB�����iXWefUDb��\�\�\�\�\�\�\�\Zb����hw���zYGUd��\�\�\�\�\�͟^<+2r����jIFc��Ⱥ��m<%3b��\�\��ޟ?4du���xwwwwv����jGQ�\���\�oE��yyhXVuu�����\��\�/q�ƈft���������yw�����ȼ}\\IGV���;#A�\�ت����ɺ���O\Z2bstt��\�\�ɪ�w��\�ܯ_&FFESr��\�\�\�ʜkhv�ȼ|[YhxxxyY8&3Q�\�\���\�o\ZS���iXGFUV5#A��\�\��ͬ���/R����xgv��yhfu������\�\�\�ޯo?3Stt��xe��ػ�[YYH6Tc��\�\�\�\�Ο_#Sr������ziXggVTb�\�\��ΟO+6u��Z8Ec�\�\�ɼ�KF��̏N1q��vu������\�\�˫��lK8E�\�\�o,%3a�\�ɚyw���zXd�\�ڭ|j��n\Zq����������h��\�͟OCcs���\�\�\�ʼ�lkZiyiYHFUt����kJ86Ca�\�\��\�o\ZS��zZH66EE3A�\�\�\��͜���?Q����iWf���w���xv�����\�\�̞~]K:)#Q�\�\�\�ɻ�]<1�����������|lK)\'4R��ƹ��zjiYHGER��\��\�~<(E���j8Dr�\�\�ۮo3r\�ɫ|K9FVfVUd�����\�\��͝|lL+#qĺl9Fet��\�ɺ��{jjI7C�\�\�̍kizk<1����������zhf�\�ۮo#Br���\�\�\�\�ˬ�|kjizjJ97Dr����yyiI&A�\�\��\�o%c��yYH74Stdq�\��ˬz���O\Z�\�ǻ|IFc�\�Ȫ�{ZGd����if����kZHGFUs�\�ɺ��n=1�\�\�ٺ����|ZXXgggVd�\�ػ��jiYXWGDb��\�\�̭n,C���zXU��\�\�̞^\"�\�\�˝lK8GFUUS��\�\�Ǹ\�۾~\\KJ9($R��we������ɻ��mL:)&3a�\�ڭm:WwiH74Bq����������yhv�\�̟?\"Qbr��\�\��\�̭�kihx��|[J8FVed��׼m)#q\�\���oR���iYGFUUCa\�\��\�^ZzkK2����kGe��Ȼ�[:7Dr�\�ʜ\\He��jXe���w��\�˜�|]-\ZA�\�\�ڪ����lJGUe��vu�\�\�ڽ�~=\ZCs���������<1�\�׹�x���ɼ�>\ZA�\�\�ʼ�N$Stdr�\�躚���lJWg�jHFfVDa�\��ʩ�ʼ�}]<)6Tt�����B��yY8$Q�Ը�w������{Yg����m,2Q���\�\�\�\�۽�kYg����{[ZI(%A�\�\�ݏ,&R�\�\�^+(%c��yiXH65\"A\�\��\�o]\\K:7Eu���igv���iGUuu���\�ˬ|JXY84r����x�\�\�ݟO,\Z%3b�\�\�Ǹ�����\\*\'Dd�����\�\�\�̮?!q�����igw�hFS�\�\�\�\�͞}kjkKB����\�\�ݏ\"�Ɖw���{IVvwwgd�\�ڬ�_1�\�Ʒ�\�ڽ�{kJGe������OCt�IG62a�ո��������l;(4r�ƺ�kK)%Dcs����\�\��쾍ljiihxx��|;\"q\�\���=C�\�\�~M;5u�ziYH7$!Q\�\���mmL:7Vf���yhwwhVTr�Ÿ�������{Lq�������\�\�_Q��Ƹ��������|M$Ss����\�\�\�˭�_\"b�����zYVeuu���\�\��ޯoN<:)\'%Cctt��\�\�]8e�ɛ��l;(2q���gt�\�\�͏.$S����\�\�˛���zy����|]-EVH#1Q�\�穇�������N*\'$R�����zjHGUeuvec��\��\�m[YXWfu�\�ڽo3q\�\�^*E���jj[)6ex�iH6$1q\�\������_,Eu���kIGFUd��������yyxyj)a\�ǈ���\�\�̟/\ZQ���\�ٻ��zy���{lK)\'6Cb�����\�ɺ��nQ���ǻ�ZGUeu����\��ޟoN<*(\'%3Rr���\�ʛjg������^1�\�תyf�\�\�̎L97Ds�����������|kZYijZZJ8GX9A��\�ٚv����\�\�\�.S�����ZXGEc���xes�\��ܜ��zjXgf��\��ߏ?B�ȭN\ZR�w��\\3�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0p\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0�?\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0��\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0��\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',0),('3','Thiệp','Thiệp','123456asd','Dev1','05/12/2024','05/12/2024','IN',1,NULL,'STAFF',NULL,'','',1,_binary '\Z~\�\0\0\0\0\0`�i\Z\�\�0\�k0�;Ɯ,\�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0@\0��\0\0\0\0\0\0\0�\�\0\0\0\0\0�\0��������������������������������\0\0`\0\0\0\r\0\0\0\0\r\0\0 \0\0\0\0\0\0\0\n\0\0\0\0\0,\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0u������KV��=7H%r�wge�����Ⱥ��}M+(6G6%2a��\�Ǧ��\��\�Ξ�m=)&S���[9Vv�iGC�\���N\Z#�ŧ�����jYGUTq\�\�\��\�o-6efc�\�٭lK8FEc���ɘ�\�|G�\�\�͏^=+$b��;4��Y��;6Ud�wWUc�\�\�{igxYWe�i&2q\�\��\�m:6�Ǭn&$Q�\�תy���lXf���\�̞n<*\'FX7$A��\�\�\�ڽ~M*&DS��v��\�鼛��\\:U���lXyYhj\'b��8c��{YGU�\�\�\�˭mZhjJ&dv���yXU����ʭ^;9XI!Q�\�\���������\�̟_<)7G5B�\��\�o+\'T��hFc�\�ٜZGd�\�ɫ�kZYHGETb��\�\��\�O+7fxiHVv�yXVUds���\�\�\�̞M\'S�\�\�ݯN+(6VG5s��YfxXG4b��Ƨ�\���?4��jFdtt�\�\��\�~L8Vv���l*2q�\�\�ٺ��~,S��\�ٽ}[ZHWxY85R�\�\�ɺ�}L\Z\'$B���xe�\�\�\�̭~<8WgwhGT������\�?DwX73a���\�ɫzx�zhw���{[96Dr�\�\�˞M*\'EUVDR�\�\��\�<(Uu������kYgxiVu���[Wv���.!Q��\�\�\�\�\�͟N+\'5d��������������nNA�����������Ȼ�\\*A�\�\�\�͞}n=\Z3r���YWffet�\�\�{z{KQ�����\�\�ʼ�~N#b�����iVe���\�\�ܯO3b�\�\�\�]:8Fevwft��\�ɺ��n-A�\�ș�v�����kYXghWWUds��\�\��ݿO6G64QETs�����ǹ����^,\Z$Bq�\�\�ʬ}K9FUeet�\�\�ʛzyx��{J\'4b��\�\�\�~LJGWWU�\�\�5FEDQ�\�\�ȹ��kXf��\�ʜz��~<%Cs�Ȝ\\96EDa�\�غ�[HT������lJ\'4a�\�黪��~N,&Tu�XFTs���\�ڭ}KJ86Udds��\�\�\�۽�o>Q�����ygv����\�̟O3c�\��\�<87Ed��vu��������o.\Z!�\�\�ɪ�{[IGVUu����iWUSq�\�\�\�̭}kz{l;)\'Rctuc�\�\�\�\�̯oSc��׺�yxxxhv���Z7Ds�\�\�˝mJHX8%Bq�\����nKXyZ8D�׭<6u�Z(a�ո���yWt�\�ڭlY���n=Q�Ķ��������}<\"�\�\�Ȼ�lK84r�׺�y�����?Bcc��\�غ����lJIWWWGER�����\�\�̟?q�\�ɫ|K(Ds��\�\�\�ˮ_Ds���jhf���|<4Ss����Ⱥ�\\)4q\�\�ۭ�}NCSa�\�ֹ�xxv����xw���\�۾?q��xGS��\�\�\�˾OEt�����lIVvxHT�ƪzYFs�\�ٽ~LHf�jJ\'1�\����[h�kK\'R�\�|IgxY&A�\�ə���Z6R�\�ٻ�����~M,!�\�\�٪�����{[IFd���\�\�͏>q\�\�{jhwxxxjI8%Aq�\�\��\�o&u��x��yzK$r��8#Q�\�\�ڪ�����|MQ��Ũ��\�܍kYgww�������_E6#Q��\�Ȫyf�\�\�ˬ�l\\L\ZDufUb�\�ǹ��zzjZI74R�\�\�\�ܿ_���{:Q�\�\�ɺ�n3������yx��L\"q�ƨ�w��\�˞]JYiYYI!�\�\���[x��[8d���K97ES�\�ت��zYGDr�\�ګ��zy��M!a�\�׺�h��ʝ]\Z$s��hT�\�\�o-1�؛zx�z[(3s����u�\�\��ޟODs�����L4c��XFTc��\��\�̭�lK:(&4S����w�\�\�˭}ZWv�ɭoS�yhXXG61�\�׺{8B�\��۬�{kZIFu��jGT�\�\�۞^+8G74Ba�\�\�\�۾o<KIWhhI6C�\�Ǻ�y�l)$b�����\�̟O2a������ɫ�{jjj[\Z%3Q��\�\�\�Zf��zh���{\\*\'ETr�\�Ǻ�=B��\�\�۝|kZHgxY7T���J5s��f��\�\�}JWwyI$a�\�뽏>�\�Ȫ��k:2q��������\�\�Ώ/$s�����M$c�vfu�ut�\�\�\�\�ݟo=2a��Ʒ���ɻ�|[IXf��mA���zXVds�׺�J%Q�\��͝mZXhhgw��|*$q�\�ʭ~<9)\"q���\�\�\�̝l=+88G6C�\�٫{YgwxXEt����\��\�o\Z!a�\�Ǹ���zh��{kJ(5c���u�ɝ,%R�����\�ݟO\'FFER�\�\�˝[Z8Es������[HGU�\�ʜm\Zb���v������{Ka�\�\�͎>#q\�ػ�\\:$Q���ǩ��������lZh��\\*F�{:\'6EECq�ŷ���\�\�ݟ^-\Z#R����\�\�\�ˬ}[ik[97UvwH5b���z8C��Ƹ��xd�\��ߏ^L*6fwgf�Ȝ;5t�����\\:A����\�\���\�oO.2a�\�ٛjXf���g��iE�\��\�oMQ�\�ש���y���lJ8Eu���yihiJq�\�\�\�\�\�o<)GFVfd���ɻ�N\ZQ���\�ھ^)Fe���iiH6C����������kJ85Q�\�\�ݏ>q\�ٽn,a�ŷ�������zhf��\�̞^,5u�iYH75Ca�\�\�ȹ��˯_,\ZA�����\�\�\�ܮ]Ixz[9GgY8%2a�\�؛JD�Ÿ�g����\�\�oL[L)7FEB�\�\�[YXWv��YGETt����\�\�\��O2r�\�m#a�ֹ�jgwhD�\��͌�l:7Edt�e�\�\�\�ˮo-Eu��hg��yYH%Bq��\�\��\�?*7FVeu�������NA��\�\���_\Z5u�ww���\\B��Ǻ�K&B�ķ�ɛ����m<2��ȊYD�\��͍kjIE���[\'3q\�\�\�o;Hf�iXWgWVUs���\�\�\�\�\�\Z2q�������\�˝lX��kIg�^a�\�\�ʊw����g�����ٽ�{{n$CQ�\���\\[J(5St���wfeut�\�\�\�\�\��ۮ~\\KIh��q\�ָ�ygu����\�\�mZZHFeu�gT�\�\�˽�>B��zIDr���xf�����\��\�O4s���������]a�\�\�\�\�~<\'Tuvu�\�ˍK8Ec�\�ڝK&r�\�ʫ�lJgyZ8EegFS����\��ގk��M)ViI&Cdc��\��ݍ{z{ZIWhX6Dr����\�\��\�oA�����������{Zh��y��OBQq�\�\�ɩ�����|Ie�ɜkx��=Eet�ǻ��m,&#Q�Źk\'B���\����h���}m]<)HZ#A����xwfu���\���>\ZQ�\�ًX�����\\9WH4r��J%a�Ŷ�\�\�mYw����}<#����zv����^Q��\�ֺ�zXVu���\�\�\�<$q\��ݎLHv���{K(Ffv�I6EA�\�\�-%q����\�܍lZYHVu�gUr�\��ގ}\\ZYYI92q�����\�ʾ3b������������\\Hv���]Ccss��\�\�\�ʺ���Oa������kHw��ZHV��|+&EDc���y5Rq�\�\��ߟ>H\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0',_binary '\Z~\�\0\0\0\0\0`�i�\�\�f9Ou�<�eIɔ\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0�\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0@\0��\0\0\0\0\0\0\0�\�\0\0\0\0\0�\0��������������������������������\0\0`\0\0\0\r\0\0\0\0\r\0\0 \0\0\0\0\0\0\0\n\0\0\0\0\0,\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\�\�\�,7U�\�\\Yi9FgWG63Q�\�Ɨ�\�ˌjg�iWe������LA�\�\��\�ΏMJYjJ\'Ds�ǻ}K8EuwWTr�\�\�]*%b�ƺ�y��zYHFEc��\�\���_\'VVe��\�٭mJIGefsĩ�خ]c����}[Zj_B��w�YU�HFS�fds�\�ؼ�L8GfWES�uc�\�\��ܮ~\\9V���l+A�\�\�٪��ʝ\\Hf���\�ۮnM+5W8!q�\�\�ٺ���l:Fu�we�\������M;)WGfv��z:E�Xd��Z)a�\��\�\�ʫ�z��L*Cs��yhHES���\�\�_*6ewgfe��\�ʝ]*R��\�\�\�\�nKYiK(5c�\�ɭ]:6ewhG4a�\�׹�x�\�ʝm;7VggXFTc��\�\��\�o.\Z6fxYGT���iXVT��ĸ�\�ݏL8Es�\�۽�_.$Ddu��ZWwhGDs��\�\�\�\�\�oC��XEs���\����^<(Vfvv��j84b��\�\�ʹ˯_B��\�ڭliiihyk*2a�\�\�ʫ�[IHGUu�vc�\��\�_4ugfe��v�u�غ�lij9&\"qq��\�\�̍kihXV���|ZI8&2q�\��\�/\ZR���������{YV���gT�\������^+8Gfv�hf���^+$DSb�\�\�\�\�\�̟NB�\�Ɋhw��v��ɺ��^KK<\Z!�����������\�˝];\"�\��\�\�M:9\'4s���iXgWUc�\�٫��l;#b�����\�\�\�̯o.$Ss�����xgv���\��ߏCc��\�܎KHWfv�xWS��\�\�˽�O$Suvvvu��׺�{[97ETt����t�\�\����/9jL\Z!Sdc�\�Ɋx�������O2Q��\�\���o+\'Tt���yWfvv��\�ɬmJ8Ec���\�\�͞mKIhi9%q\��o%dwY7\"q�\�Ƿ��l8T�\�\�\�~Jw�|;7WFS�׼mIX8%A�\�ֹ��hv���\�˝mL\ZQ�\�\�̜�|]+Dt��iHEcs�\�\�\�~\\:8FUVTs��\�\�\�ʻ�~M+A�\�ǹ�ziWe���\�\�ݯ?5Ts�ǫl:Gefe��vs�\�\�˫���?q���ww�yiXVfuvvt��ǪiUq\�\����_LlN#!���ft�\�Ǹ\�ˮ_Aq�\�\�ȹ��zYWv��zZHEdt�\�ػ�y��}<A�\��\�\\Yw�[)3�\�LGv�j)a�֨���jFc�\�\�]Iv��|\\K\ZA�Ķ���������\\)$r��\�ʬ�]*R������ʮo-\Z3cuUR�\�\�ȸ\�̞]KIGgXH&B�Ũw�����|:5q\�\�ڼ�NB���\�\�\�ۯ_\'Dt���yhf���k:&Cr��\�ȹ��.q\�ǹ��|L)%Stt�����Ȭ[HUt�\�ȹ����>)A�ƊH3��Ʒ�\�̏>$b��\�ɫ{ih�yHU���jXFd��\�ٻ�z��|\\A�\��\�nIw�{J6b\�ʌZXgXGC�ĸ����Z6B�\�軋����~M,�\�\�髉�����{[84s��\�ɻ�N\Za\�ɋYg���|[:#Q���\��\�_9f�����x��]qƌ*Qq��\�\�ʪ����|M2a�\�؛Xs\�٫{jg�����{���O2TECa�ķ��ygU�\�\�ˬ��N#bs�����ǻ{jj95c���\��\�OA�ƫ[&R�������MC��ƹ��jixzK3r���ygt�\�\�ڼ�|lKIZ91�\��\�n9e��Z7r\�ʝ\\97ES����x��jHEc�\�٪������NA�\�\�ʋx��ɭm;7T��xU�\�ڮ_�\�\�lYgwyY6S������\�\��\�N+\'Ds�����^\Z$r��I6Tcr�\�\�ڻ���l[:(%Cr�\�ɛYd�Ⱥ�kHe�\�̏?\Zc��hwyZQ����e�\�\�˪����lL*&Ddd����ȼ|ZiJ75Sq�\��ݞ~==5��z9%R�\�Ȫ���LC���������N2a��ƨ���\�ɻ�}lm,&54R�\�\�٭\\8T��xf�\�~L96FC�Ĺz��m$b��\���{y���{k:\'Dt�wt��jV�\��\�oc��WS�\�\�oQúzxxyj)a����x��\�\�ܿC���z��^\Zb�vfu�����\�\�\�̮~^-\ZA�\�\�ȩ������zYXf���N\Za\�ת�yZ8D����j5�\��͛�|ZxyjIWwiHD�\�\�ۮ_7G&3R��\�\�뽌|>+8GXY7$a�\�ʋyyyZ7S����\�\�͟_!a�\�ֺ�����\�̍[jJHFuwge�Ȭ^4r�����\�o,)7FECq�\�\�\�<Ffet�Ǻ��zjYWVt�ɫ�Q��gt�\�ʜkixj8$a\�\�\�.!�Ź�{kJ\"q�\�Ǩ��������L8v��|;7gz:&EETc��\�Ȩ���\�̟n=1q��\�\�\�\�ڽnJhyzZHXWVh7#�\�țZGDb�\�軚zGr\���}lKGv�yh��m\Za�ǻ�l;(a���\�\��ݮn7\'&$B�\�\�kGu��he��xt\�\�\�M+q�\�绋yiWt\�\�}9Vt����\\If�|+Br��Ƹ�ʭn;HHFVUd��\�\�̎N\Zb��\�\�۝m:GEsƪ�zJ7S���gu�����kKa\�\�\�\�-\"�\�ڝl;$Q���������zx������n=D�xXWWVUS�����\�\�\�\�.\"a������\�\�\�~;W��jYZ:&53Q�ĸ�zHC��\�ɘ���\��ϏO<*6fxxhv�m*&UevxGTtg5A�\�\��\�\�\�ߟ?Ab����ID����hu�gS�\���^L;4c����������\\)$r��ث��zjj[)4Bq�\�\��ܞM9Vffv�wv�����?\Za�\�\�\���OEe��yv��[(C���w�����zYH5Q\�\��\�!�\�ڍK)a�Ÿ�����ɝ\\Xgf���\�o-)7VgVu��iGTs���\�\���\�/#R��������\�˝\\X��kZi\\Q��\�׻{Xfu�����\��ޟMK<&Evgf��zYYHFFCq��ea\�\�\��ν���N�o/4vhXY�\�ŷ�ye��t�\���mZZHfv�hgft�\�̎M\ZA�\�Ǻzg����jZI8%Rq�\��ݟ=)Ee����g����}>\ZA�\�\�\���OEt��g�Ǭ]\ZR����{HS���Ȫy����]+(65Csttq�\����n\\K7v�k9EeUs�\�\�|jy�kJGfxX5S����\�\����/Aq�����������|Iw��[Z[Aq��\�\�ʬ\\Hfe����\�ھoKZ\\\ZAs�����{jJ8&1���WC�\�\�\�\�˝���7fyy\\9xk;+\ZQ����vs���\�\��\�}[IV�����\\Gu��}+(A�ķ��f�׺��{kK(3q�\�\�̎]*&T����x�����^Q�\�\�\�\�~JGe��g�\�ˎMB�\�٫ZFt��ȫ�jx�zYXgiI#1Q�\�\�\��\�oLJYYHVvxWVd�\�\�˜�|[J9H7%2q�Ÿ����ʾ_b����������\�̎;W���\\-Q�����\�����[Xwxg��\�m:Wy9$r��ǹ�zyyjHGU���i8$1q\�\���G\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0?\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0?',0),('admin',NULL,NULL,'123456asd',NULL,NULL,NULL,'OUT',1,NULL,'ADMIN','dong@gmail.com',NULL,NULL,0,NULL,NULL,0);
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
