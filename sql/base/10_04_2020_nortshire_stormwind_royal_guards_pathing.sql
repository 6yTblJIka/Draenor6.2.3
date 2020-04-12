-- Northshire  - Stormwind Royal Guard Patrol Data
DELETE FROM `creature_addon` WHERE `guid`=177931;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`, `animkit`) VALUES
(177931, 17793100, 29284, 0, 1, 0, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (177929, 177930, 177932);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(177929,0,29284,0,1,0,""),
(177930,0,29284,0,1,0,""),
(177932,0,29284,0,1,0,"");

-- Pathing for Stormwind Royal Guard Entry: 42218
UPDATE `creature` SET `spawndist`=0, `MovementType`=2, `position_x`=-9005.9619,`position_y`=-85.5667,`position_z`=86.1989 WHERE `guid`=177931;
UPDATE `creature` SET `spawndist`=0, `MovementType`=2, `position_x`=-9001.2119,`position_y`=-85.6553,`position_z`=86.0481 WHERE `guid`=177929;
UPDATE `creature` SET `spawndist`=0, `MovementType`=2, `position_x`=-9002.0205,`position_y`=-89.2966,`position_z`=86.0691 WHERE `guid`=177930;
UPDATE `creature` SET `spawndist`=0, `MovementType`=2, `position_x`=-9006.6436,`position_y`=-89.7125,`position_z`=86.1360 WHERE `guid`=177932;

DELETE FROM `waypoint_data` WHERE `id`=177931 * 100;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(177931 * 100, 1,-9005.645508, -83.137894, 86.375259,0,0,0,0,100,0), -- 14:02:18   1
(177931 * 100, 2,-9007.370117, -60.200249, 87.063187,0,0,0,0,100,0), -- 14:02:19   2
(177931 * 100, 3,-9009.031250, -22.187466, 88.372444,0,0,0,0,100,0), -- 14:02:27   8
(177931 * 100, 4,-9015.897461, 0.414059, 88.730171,0,0,0,0,100,0), -- 14:02:28   9
(177931 * 100, 5,-9025.3271, 6.0375, 88.1329,0,0,0,0,100,0), -- 14:02:29  10
(177931 * 100, 6,-9036.4648, 0.0251, 88.2919,0,0,0,0,100,0), -- 14:02:40  19
(177931 * 100, 7,-9041.9795, -22.5555, 88.2442,0,0,0,0,100,0), -- 14:02:41  20
(177931 * 100, 8,-9048.4121, -45.0212, 88.3123,0,0,0,0,100,0), -- 14:02:43  21
(177931 * 100, 9,-9050.6338, -72.9850, 88.1754,0,0,0,0,100,0), -- 14:02:49  26
(177931 * 100,10,-9050.9365, -91.7413, 87.9492,0,0,0,0,100,0), -- 14:02:52  29
(177931 * 100,11,-9037.2959, -102.4238, 87.7869,0,0,0,0,100,0), -- 14:02:56  32
(177931 * 100,12,-9016.4717, -93.1798, 86.8121,0,0,0,0,100,0), -- 14:03:01  36
(177931 * 100,13,-9008.1172, -87.3591, 86.2610,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=177931;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES 
(177931, 177931, 0,   0, 2, 0, 0),
(177931, 177929, 5,  90, 2, 0, 0),
(177931, 177930, 5, 135, 2, 0, 0),
(177931, 177932, 5, 180, 2, 0, 0);



-- Pathing for Northshire Guard Entry: 1642
UPDATE `creature` SET `spawndist`=0, `MovementType`=2, `position_x`=-9008.0371,`position_y`=-82.4518,`position_z`=86.4993 WHERE `guid`=177881;
DELETE FROM `creature_addon` WHERE `guid`=177881;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`, `animkit`) VALUES
(177881, 17788100, 0, 0, 1, 0, NULL, 0);
DELETE FROM `waypoint_data` WHERE `id`=177881 * 100;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(177881 * 100, 1,-9031.0391, -100.4405, 87.5631, 0,0,0,0,100,0), -- 14:02:18   1
(177881 * 100, 2,-9041.8086, -98.2317, 87.9276,  0,0,0,0,100,0), -- 14:02:18   2
(177881 * 100, 3,-9049.4941, -87.2658, 88.0292,  0,0,0,0,100,0), -- 14:02:18   3
(177881 * 100, 4,-9044.9043, -50.3985, 88.2246,  0,0,0,0,100,0), -- 14:02:18   4
(177881 * 100, 5,-9050.9707, -87.6814, 87.9444, 0,0,0,0,100,0), -- 14:02:18   5
(177881 * 100, 6,-9041.2725, -100.3984, 87.8779,  0,0,0,0,100,0), -- 14:02:18   6
(177881 * 100, 7,-9032.0859, -100.2963, 87.5668,  0,0,0,0,100,0), -- 14:02:18   7
(177881 * 100, 8,-9012.7607, -88.6014, 86.4809,  0,0,0,0,100,0); -- 14:02:18   8


-- Pathing for Northshire Guard Entry: 1642
UPDATE `creature` SET `spawndist`=0, `MovementType`=2,`position_x`=-9006.5537,`position_y`=-74.1833,`position_z`=86.5180 WHERE `guid`=177885;
DELETE FROM `creature_addon` WHERE `guid`=177885;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`, `animkit`) VALUES
(177885, 17788500, 0, 0, 1, 0, NULL, 0);
DELETE FROM `waypoint_data` WHERE `id`=177885 * 100;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(177885 * 100, 1,-9008.0244, -31.6597, 88.3062,  0,0,0,0,100,0), -- 14:02:18   1
(177885 * 100, 2,-9014.8291, -1.9883, 88.7853,   0,0,0,0,100,0), -- 14:02:18   2
(177885 * 100, 3,-9023.3135, 5.0647, 88.2027,   0,0,0,0,100,0), -- 14:02:18   3
(177885 * 100, 4,-9032.4277, 2.9704, 88.2584,   0,0,0,0,100,0), -- 14:02:18   4
(177885 * 100, 5,-9038.8691, -3.6601, 88.3403,  0,0,0,0,100,0), -- 14:02:18   5
(177885 * 100, 6,-9041.7510, -20.5246, 88.2433,   0,0,0,0,100,0), -- 14:02:18   6
(177885 * 100, 7,-9045.0518, -44.2208, 88.3575,   0,0,0,0,100,0), -- 14:02:18   7
(177885 * 100, 8,-9038.6006, -13.2337, 88.2422,   0,0,0,0,100,0), -- 14:02:18   8
(177885 * 100, 9,-9033.6162, -0.1680, 88.3776,    0,0,0,0,100,0), -- 14:02:18   9
(177885 * 100, 10,-9025.8369, 3.7645, 88.2593,   0,0,0,0,100,0), -- 14:02:18   10
(177885 * 100, 11,-9017.2705, -4.1152, 88.6415,    0,0,0,0,100,0), -- 14:02:18   11
(177885 * 100, 12,-9011.4521, -20.0478, 88.2780,    0,0,0,0,100,0), -- 14:02:18   12
(177885 * 100, 12,-9009.3281, -70.9664, 86.7767,     0,0,0,0,100,0); -- 14:02:18   12


-- Pathing for Stormwind Guard Entry: 1423
UPDATE `creature` SET `spawndist`=0, `MovementType`=2, `position_x`=-9436.0488,`position_y`=50.9134,`position_z`=56.3646 WHERE `guid`=177880;
DELETE FROM `creature_addon` WHERE `guid`=177880;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`, `animkit`) VALUES
(177880, 17788000, 0, 0, 1, 0, NULL, 0);
DELETE FROM `waypoint_data` WHERE `id`=177880 * 100;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(177880 * 100,1,-9436.0488,50.9134,56.3646,0,0,0,0,100,0),
(177880 * 100,2,-9408.9658,18.9405,59.0350,0,0,0,0,100,0),
(177880 * 100,3,-9369.8223,-24.9229,62.9171,0,0,0,0,100,0),
(177880 * 100,4,-9346.2910,-46.1895,65.2385,0,0,0,0,100,0),
(177880 * 100,5,-9304.5518,-58.7395,66.8046,0,0,0,0,100,0),
(177880 * 100,6,-9254.1221,-91.9963,70.1391,0,0,0,0,100,0),
(177880 * 100,7,-9230.4082,-106.0945,71.1085,0,0,0,0,100,0),
(177880 * 100,8,-9190.6602,-115.2656,70.9643,0,0,0,0,100,0),
(177880 * 100,9,-9166.8574,-110.4353,72.1437,0,0,0,0,100,0),
(177880 * 100,10,-9132.7393,-91.7104,76.5362,0,0,0,0,100,0),
(177880 * 100,11,-9108.5332,-75.9059,82.1561,0,0,0,0,100,0),
(177880 * 100,12,-9085.6855,-57.3375,85.9384,0,0,0,0,100,0),
(177880 * 100,13,-9072.1201,-46.9985,87.9322,0,0,0,0,100,0),
(177880 * 100,14,-9074.9434,-44.1095,87.7425,0,0,0,0,100,0),
(177880 * 100,15,-9099.0273,-62.6385,84.1677,0,0,0,0,100,0),
(177880 * 100,16,-9123.2813,-80.9513,78.8992,0,0,0,0,100,0),
(177880 * 100,17,-9151.0410,-99.6152,73.9392,0,0,0,0,100,0),
(177880 * 100,18,-9171.6328,-109.6959,71.8225,0,0,0,0,100,0),
(177880 * 100,19,-9199.3643,-109.4113,71.2133,0,0,0,0,100,0),
(177880 * 100,20,-9233.9639,-99.6605,70.9578,0,0,0,0,100,0),
(177880 * 100,21,-9264.3447,-78.6362,68.9227,0,0,0,0,100,0),
(177880 * 100,22,-9285.7715,-63.0402,68.0952,0,0,0,0,100,0),
(177880 * 100,23,-9322.2148,-52.5678,66.4237,0,0,0,0,100,0),
(177880 * 100,24,-9343.0820,-45.1754,65.3870,0,0,0,0,100,0),
(177880 * 100,25,-9374.5654,-13.9794,62.2965,0,0,0,0,100,0),
(177880 * 100,26,-9404.4131,19.2410,59.1318,0,0,0,0,100,0),
(177880 * 100,27,-9423.9170,42.4920,57.0241,0,0,0,0,100,0),
(177880 * 100,28,-9432.0938,51.3583,56.5469,0,0,0,0,100,0),
(177880 * 100,29,-9435.6025,51.3600,56.3343,0,0,0,0,100,0);
