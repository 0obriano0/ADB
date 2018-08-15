@echo off

CD platform-tools

adb shell dumpsys activity

@echo [%time:~0,8%] 系統將在 5 秒後啟動
@ping 127.0.0.1 -n 5 -w 1000 > nul


:start
@echo [%time:~0,8%] 系統正在嘗試抓取
adb shell uiautomator dump
adb pull /sdcard/window_dump.xml ..\index.xml
@ping 127.0.0.1 -n 5 -w 1000 > nul
goto start