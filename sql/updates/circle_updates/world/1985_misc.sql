DELETE FROM `creature` WHERE `map`=607;
DELETE FROM `disables` WHERE `sourceType`=3 AND `entry`=9;
UPDATE `gameobject_template` SET `flags`=0 WHERE `entry`=191305;
UPDATE `gameobject_template` SET `flags`=0 WHERE `entry`=191306;
UPDATE `gameobject_template` SET `flags`=0 WHERE `entry`=191307;
UPDATE `gameobject_template` SET `flags`=0 WHERE `entry`=191308;
UPDATE `gameobject_template` SET `flags`=0 WHERE `entry`=191309;
UPDATE `gameobject_template` SET `faction`=1801, `flags`=0 WHERE `entry`=191310;
UPDATE `gameobject_template` SET `faction`=1802 WHERE `entry`=191309;
UPDATE `gameobject_template` SET `faction`=1801 WHERE `entry`=191308;
UPDATE `gameobject_template` SET `faction`=1802 WHERE `entry`=191307;
UPDATE `gameobject_template` SET `faction`=1801 WHERE `entry`=191306;
UPDATE `gameobject_template` SET `faction`=1802 WHERE `entry`=191305;
UPDATE `gameobject_template` SET `faction`=0, `flags`=0 WHERE `entry`=192834;
UPDATE `gameobject_template` SET `ScriptName` = 'go_seaforium_charge' WHERE `entry` = 190753;
