@echo off

CD platform-tools

adb shell dumpsys activity

@echo [%time:~0,8%] 系統將在 5 秒後啟動
@ping 127.0.0.1 -n 5 -w 1000 > nul

adb shell am start -n com.pasgames.tapchest/com.unity3d.player.UnityPlayerActivity

@echo [%time:~0,8%] 系統開始了 培育寶箱 腳本初始化
@echo [%time:~0,8%] 系統正在嘗試點擊

:start
adb shell input tap 560 1200
goto start