/*
 Navicat Premium Dump SQL

 Source Server         : 127.0.0.1
 Source Server Type    : MySQL
 Source Server Version : 80018 (8.0.18)
 Source Host           : localhost:3306
 Source Schema         : flightdb

 Target Server Type    : MySQL
 Target Server Version : 80018 (8.0.18)
 File Encoding         : 65001

 Date: 27/12/2024 15:39:12
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for ordertable
-- ----------------------------
DROP TABLE IF EXISTS `ordertable`;
CREATE TABLE `ordertable`  (
  `OrderID` int(11) NOT NULL AUTO_INCREMENT,
  `IdNumber` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `PhoneNumber` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `FlightNumber_lmh` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `FlightNumber_lfx` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `DepartureCity` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `ArrivalCity` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `FlightDate` date NULL DEFAULT NULL,
  `FlightTime` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `TicketType` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `Price` decimal(10, 2) NULL DEFAULT NULL,
  `BoardingStatus` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `BoardingGate` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `OrderTime` datetime NULL DEFAULT NULL,
  `Seat` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `UserName` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `Status` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `UpdatedAt` datetime NULL DEFAULT NULL,
  `IsDelayed` tinyint(1) NULL DEFAULT NULL,
  `PassengerName` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `IsChanged` int(5) NULL DEFAULT NULL,
  PRIMARY KEY (`OrderID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 114 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of ordertable
-- ----------------------------
INSERT INTO `ordertable` VALUES (105, '131313', '123456', 'CZ3387', NULL, '广州', '北京', '2024-12-28', '08:20:00', '商务舱', 800.00, NULL, '214', '2024-12-27 14:43:15', NULL, '王老师', NULL, NULL, 0, 'LC', 1);
INSERT INTO `ordertable` VALUES (106, '340340', '123123', 'HU7818', NULL, '广州', '合肥', '2024-12-30', '11:07:00', '经济舱', 700.00, NULL, '227', '2024-12-27 14:55:29', NULL, '王老师', NULL, NULL, 0, '王老师', 0);
INSERT INTO `ordertable` VALUES (107, '123123', '123456', 'HU7818', NULL, '广州', '合肥', '2024-12-30', '11:07:00', '头等舱', 700.00, NULL, '212', '2024-12-27 14:55:52', NULL, '王老师', NULL, NULL, 0, '胡歌', 0);
INSERT INTO `ordertable` VALUES (108, '123456', '123456', 'CZ3387', NULL, '广州', '北京', '2024-12-28', '08:20:00', '商务舱', 800.00, NULL, '214', '2024-12-27 14:56:30', NULL, '王老师', NULL, NULL, 0, '彭于晏', 1);
INSERT INTO `ordertable` VALUES (111, 'ddd', 'ddd', 'HU7818', NULL, '广州', '合肥', '2024-12-28', '11:07:00', '商务舱', 850.00, NULL, '214', '2024-12-27 15:17:48', '17B', '王先生', NULL, NULL, 0, 'ssd', 0);
INSERT INTO `ordertable` VALUES (113, '123456', '123456', 'HU7777', NULL, '珠海', '上海', '2024-12-28', '17:51:00', '头等舱', 1480.00, NULL, '212', '2024-12-27 15:30:37', NULL, '王先生', NULL, NULL, 0, '几范德萨', 0);

SET FOREIGN_KEY_CHECKS = 1;
