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

 Date: 27/12/2024 15:39:25
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for userinfo
-- ----------------------------
DROP TABLE IF EXISTS `userinfo`;
CREATE TABLE `userinfo`  (
  `UserName` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Password` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Gender` varchar(5) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `Age` tinyint(4) NULL DEFAULT NULL,
  `PhoneNumber` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`UserName`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of userinfo
-- ----------------------------
INSERT INTO `userinfo` VALUES ('刘先生', 'lxs123456', '男', 20, '6668888');
INSERT INTO `userinfo` VALUES ('刘医生', 'lys123456', '女', NULL, '11111');
INSERT INTO `userinfo` VALUES ('刘女士', 'lls123456', '女', NULL, '14444');
INSERT INTO `userinfo` VALUES ('刘女士1', '123456ab', '男', NULL, '19999');
INSERT INTO `userinfo` VALUES ('张三', 'zs123456', '男', 40, '3333333');
INSERT INTO `userinfo` VALUES ('张女士', '123456ab', '女', NULL, '6666888');
INSERT INTO `userinfo` VALUES ('张老师', 'zls123456', '男', NULL, '169169');
INSERT INTO `userinfo` VALUES ('李四', 'ls123456', '男', 50, '4444444');
INSERT INTO `userinfo` VALUES ('李工程师', 'lgcs123456', '男', NULL, '1338888');
INSERT INTO `userinfo` VALUES ('李律师', 'lls123456', '女', 25, '7777777');
INSERT INTO `userinfo` VALUES ('王五', 'ww123456', '男', 60, '5555555');
INSERT INTO `userinfo` VALUES ('王先生', 'wxs123456', '男', NULL, '1111111');
INSERT INTO `userinfo` VALUES ('王经理', '123456as', NULL, NULL, '1333333');
INSERT INTO `userinfo` VALUES ('王老师', 'wls123456', '男', NULL, '123456');
INSERT INTO `userinfo` VALUES ('蒋医生', 'jys123456', '女', 35, '8888888');
INSERT INTO `userinfo` VALUES ('赵六', 'zl123456', '男', 35, '6666666');
INSERT INTO `userinfo` VALUES ('黄女士', 'hns123456', '女', 30, '1333333');

SET FOREIGN_KEY_CHECKS = 1;
