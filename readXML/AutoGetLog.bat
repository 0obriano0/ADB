@echo off

CD platform-tools

adb shell dumpsys activity

@echo [%time:~0,8%] �t�αN�b 5 ���Ұ�
@ping 127.0.0.1 -n 5 -w 1000 > nul


:start
@echo [%time:~0,8%] �t�Υ��b���է��
adb shell uiautomator dump
adb pull /sdcard/window_dump.xml ..\index.xml
@ping 127.0.0.1 -n 5 -w 1000 > nul
goto start