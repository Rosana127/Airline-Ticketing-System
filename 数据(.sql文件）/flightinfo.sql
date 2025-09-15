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

 Date: 27/12/2024 15:38:59
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for flightinfo
-- ----------------------------
DROP TABLE IF EXISTS `flightinfo`;
CREATE TABLE `flightinfo`  (
  `FlightNumber` varchar(255) CHARACTER SET gbk COLLATE gbk_chinese_ci NULL DEFAULT NULL,
  `AirlineCompany` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `DepartureCity` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `ArrivalCity` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `AircraftModel` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `DepartureAirport` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `ArrivalAirport` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `IsDelayed` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `Date` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `DepartureTime` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `ArrivalTime` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `Price` int(11) NULL DEFAULT NULL,
  `booktickets` int(11) NULL DEFAULT NULL,
  `SeatType` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `Capacity` int(11) NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of flightinfo
-- ----------------------------
INSERT INTO `flightinfo` VALUES ('CZ3387', '深圳航空', '广州', '北京', '大机型', '广州白云机场T1', '北京首都机场T2', '0', '2024-12-28', '2024-12-28 08:20:00:00', '2024-12-28 10:50:00:00', 800, 0, '经济舱', 126);
INSERT INTO `flightinfo` VALUES ('CZ3387', '深圳航空', '广州', '北京', '大机型', '广州白云机场T1', '北京首都机场T2', '0', '2024-12-28', '2024-12-28 08:20:00:00', '2024-12-28 10:50:00:00', 1500, 2, '商务舱', 16);
INSERT INTO `flightinfo` VALUES ('CZ3387', '深圳航空', '广州', '北京', '大机型', '广州白云机场T1', '北京首都机场T2', '0', '2024-12-28', '2024-12-28 08:20:00:00', '2024-12-28 10:50:00:00', 2500, 0, '头等舱', 6);
INSERT INTO `flightinfo` VALUES ('BK2779', '东方航空', '广州', '北京', '中型机', '广州白云机场T2', '北京首都机场T2', '0', '2024-12-29', '2024-12-29 09:00:00', '2024-12-29 11:20:00', 750, 0, '经济舱', 153);
INSERT INTO `flightinfo` VALUES ('BK2779', '东方航空', '广州', '北京', '中型机', '广州白云机场T2', '北京首都机场T2', '0', '2024-12-29', '2024-12-29 09:10:00', '2024-12-29 11:30:00', 1300, 0, '商务舱', 24);
INSERT INTO `flightinfo` VALUES ('BK2779', '东方航空', '广州', '北京', '中型机', '广州白云机场T2', '北京首都机场T2', '0', '2024-12-29', '2024-12-29 09:15:00', '2024-12-29 11:35:00', 2200, 0, '头等舱', 8);
INSERT INTO `flightinfo` VALUES ('MF8147', '东方航空', '上海', '深圳', '大机型', '浦东国际机场T1', '深圳宝安机场T2', '1', '2024-12-30', '2019-12-30 08:00:00', '2024-12-30 10:30:00', 650, 0, '经济舱', 120);
INSERT INTO `flightinfo` VALUES ('MF8147', '东方航空', '上海', '深圳', '大机型', '浦东国际机场T1', '深圳宝安机场T2', '1', '2024-12-30', '2019-12-30 08:05:00', '2024-12-30 10:35:00', 1250, 0, '商务舱', 12);
INSERT INTO `flightinfo` VALUES ('MF8147', '东方航空', '上海', '深圳', '大机型', '浦东国际机场T1', '深圳宝安机场T2', '1', '2024-12-30', '2019-12-30 08:10:00', '2024-12-30 10:40:00', 2200, 0, '头等舱', 6);
INSERT INTO `flightinfo` VALUES ('SC4789', '南方航空', '深圳', '武汉', '大机型', '深圳宝安机场T2', '武汉天河机场T1', '0', '2024-12-30', '2024-12-30 08:45:00', '2024-12-30 11:15:00', 600, 0, '经济舱', 153);
INSERT INTO `flightinfo` VALUES ('SC4789', '南方航空', '深圳', '武汉', '大机型', '深圳宝安机场T2', '武汉天河机场T1', '0', '2024-12-30', '2024-12-30 08:50:00', '2024-12-30 11:20:00', 1200, 0, '商务舱', 24);
INSERT INTO `flightinfo` VALUES ('SC4789', '南方航空', '深圳', '武汉', '大机型', '深圳宝安机场T2', '武汉天河机场T1', '0', '2024-12-30', '2024-12-30 08:55:00', '2024-12-30 11:25:00', 2200, 0, '头等舱', 8);
INSERT INTO `flightinfo` VALUES ('MU2384', '海南航空', '武汉', '南京', '中型机', '武汉天河机场T2', '南京禄口机场T2', '0', '2024-12-30', '2024-12-30 09:00:00', '2024-12-30 09:45:00', 450, 0, '经济舱', 126);
INSERT INTO `flightinfo` VALUES ('MU2384', '海南航空', '武汉', '南京', '中型机', '武汉天河机场T2', '南京禄口机场T2', '0', '2024-12-30', '2024-12-30 09:05:00', '2024-12-30 09:50:00', 900, 0, '商务舱', 16);
INSERT INTO `flightinfo` VALUES ('MU2384', '海南航空', '武汉', '南京', '中型机', '武汉天河机场T2', '南京禄口机场T2', '0', '2024-12-30', '2024-12-30 09:10:00', '2024-12-30 09:55:00', 1600, 0, '头等舱', 6);
INSERT INTO `flightinfo` VALUES ('HU7819', '南方航空', '广州', '上海', '大机型', '广州白云机场T1', '上海虹桥机场T1', '0', '2024-12-24', '2024-12-24 17:51:00', '2024-12-24 19:51:00', 500, 0, '经济舱', 80);
INSERT INTO `flightinfo` VALUES ('HU7819', '南方航空', '广州', '上海', '大机型', '广州白云机场T1', '上海虹桥机场T1', '0', '2024-12-24', '2024-12-24 17:51:00', '2024-12-24 19:51:00', 1480, 0, '头等舱', 30);
INSERT INTO `flightinfo` VALUES ('HU7819', '南方航空', '广州', '上海', '大机型', '广州白云机场T1', '上海虹桥机场T1', '0', '2024-12-24', '2024-12-24 17:51:00', '2024-12-24 19:51:00', 950, 0, '商务舱', 50);
INSERT INTO `flightinfo` VALUES ('HU7813', '南方航空', '广州', '合肥', '大机型', '广州白云机场T1', '合肥新桥机场T1', '0', '2024-12-30', '2024-12-30 19:07:00', '2024-12-30 21:12:00', 500, 0, '经济舱', 80);
INSERT INTO `flightinfo` VALUES ('HU7813', '南方航空', '广州', '合肥', '大机型', '广州白云机场T1', '合肥新桥机场T1', '0', '2024-12-30', '2024-12-30 19:07:00', '2024-12-30 21:12:00', 1480, 0, '头等舱', 30);
INSERT INTO `flightinfo` VALUES ('HU7813', '南方航空', '广州', '合肥', '大机型', '广州白云机场T1', '合肥新桥机场T1', '0', '2024-12-30', '2024-12-30 19:07:00', '2024-12-30 21:12:00', 950, 0, '商务舱', 50);
INSERT INTO `flightinfo` VALUES ('HK7878', '南方航空', '重庆', '上海', '大机型', '重庆江北机场T1', '上海虹桥机场T1', '0', '2024-12-27', '2024-12-27 17:51:00', '2024-12-27 19:51:00', 500, 0, '经济舱', 80);
INSERT INTO `flightinfo` VALUES ('HK7878', '南方航空', '重庆', '上海', '大机型', '重庆江北机场T1', '上海虹桥机场T1', '0', '2024-12-27', '2024-12-27 17:51:00', '2024-12-27 19:51:00', 1480, 0, '头等舱', 30);
INSERT INTO `flightinfo` VALUES ('HK7878', '南方航空', '重庆', '上海', '大机型', '重庆江北机场T1', '上海虹桥机场T1', '0', '2024-12-27', '2024-12-27 17:51:00', '2024-12-27 19:51:00', 950, 0, '商务舱', 50);
INSERT INTO `flightinfo` VALUES ('HU7777', '南方航空', '珠海', '上海', '小机型', '珠海机场', '上海虹桥机场T1', '0', '2024-12-28', '2024-12-28 17:51:00', '2024-12-28 19:51:00', 500, 0, '经济舱', 80);
INSERT INTO `flightinfo` VALUES ('HU7777', '南方航空', '珠海', '上海', '小机型', '珠海机场', '上海虹桥机场T1', '0', '2024-12-28', '2024-12-28 17:51:00', '2024-12-28 19:51:00', 1480, 1, '头等舱', 30);
INSERT INTO `flightinfo` VALUES ('HU7777', '南方航空', '珠海', '上海', '小机型', '珠海机场', '上海虹桥机场T1', '0', '2024-12-28', '2024-12-28 17:51:00', '2024-12-28 19:51:00', 950, 0, '商务舱', 50);

SET FOREIGN_KEY_CHECKS = 1;
