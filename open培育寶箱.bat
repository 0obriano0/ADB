@echo off

CD platform-tools

adb shell dumpsys activity

@echo [%time:~0,8%] �t�αN�b 5 ���Ұ�
@ping 127.0.0.1 -n 5 -w 1000 > nul

adb shell am start -n com.pasgames.tapchest/com.unity3d.player.UnityPlayerActivity

@echo [%time:~0,8%] �t�ζ}�l�F ���|�_�c �}����l��
@echo [%time:~0,8%] �t�Υ��b�����I��

:start
adb shell input tap 560 1200
goto start