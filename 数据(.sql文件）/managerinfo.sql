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

 Date: 15/01/2025 22:08:41
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for managerinfo
-- ----------------------------
DROP TABLE IF EXISTS `managerinfo`;
CREATE TABLE `managerinfo`  (
  `ManagerID` int(11) NOT NULL AUTO_INCREMENT,
  `ManagerName` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Password` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Gender` varchar(5) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `Age` int(11) NULL DEFAULT NULL,
  `PhoneNumber` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`ManagerID` DESC) USING BTREE,
  CONSTRAINT `managerinfo_chk_1` CHECK (`Gender` in (_utf8mb4'M',_utf8mb4'F')),
  CONSTRAINT `managerinfo_chk_2` CHECK (`Age` >= 18)
) ENGINE = InnoDB AUTO_INCREMENT = 9 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of managerinfo
-- ----------------------------
INSERT INTO `managerinfo` VALUES (8, 'manager1', '123', 'F', 30, '6662345');
INSERT INTO `managerinfo` VALUES (7, '梁经理', 'ljl654321', NULL, NULL, '1994242');
INSERT INTO `managerinfo` VALUES (4, '张经理', 'zjl654321', 'F', 18, '6664444');
INSERT INTO `managerinfo` VALUES (3, '赵经理', 'zjl654321', 'M', 48, '6663333');
INSERT INTO `managerinfo` VALUES (2, '李经理', 'ljl654321', 'M', 38, '6662222');
INSERT INTO `managerinfo` VALUES (1, '王经理', 'wjl654321', 'M', 28, '6661111');

SET FOREIGN_KEY_CHECKS = 1;
