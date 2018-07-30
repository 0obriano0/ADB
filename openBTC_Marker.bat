@echo off

CD E:\Desktop\ADB\platform-tools

@echo [%time:~0,8%] 系統將在 5 秒後啟動 BTC Marker
@ping 127.0.0.1 -n 5 -w 100 > nul
CALL :start

@echo [%time:~0,8%] 系統開始了 BTC Marker 腳本初始化
@echo [%time:~0,8%] 系統正在嘗試點擊 CLAIM
adb shell input tap 848 1193

CALL :claimforminuteset

@echo [%time:~0,8%] 系統開始了 BTC Marker 的廣告掛機腳本~

:go
CALL :claimforminute
adb shell input tap 940 1390
@ping 127.0.0.1 -n 35 -w 100 > nul
adb shell input keyevent 4
@echo [%time:~0,8%] 系統延遲 2 秒 來防腳本BUG
adb shell am start -n com.kronan.bittimake/com.kronan.bittimake.ui.MainActivity
@ping 127.0.0.1 -n 2 -w 100 > nul
goto go

:start
adb shell am start -n com.kronan.bittimake/com.kronan.bittimake.ui.MainActivity
@echo [%time:~0,8%] 系統延遲 2 秒 來等待 BTC Marker 開啟完成
@ping 127.0.0.1 -n 2 -w 100 > nul
exit /B 

:close
adb shell am force-stop com.kronan.bittimake
@echo [%time:~0,8%] 系統延遲 2 秒 來等待 BTC Marker 關閉完成
@ping 127.0.0.1 -n 2 -w 100 > nul
exit /B

:restart
@echo [%time:~0,8%] 系統將在 2 秒後重新啟動 BTC Marker
@ping 127.0.0.1 -n 2 -w 100 > nul
CALL :close
CALL :start
exit /B

:claimforminute
SET B=%TIME%
SET B_HOUR=%B:~0,2%
SET B_MINS=%B:~3,2%
SET B_SECS=%B:~6,2%
SET B_MSEC=%B:~9,2%

SET /A C_MSEC=B_MSEC-A_MSEC
SET /A C_HOUR=B_HOUR-A_HOUR
SET /A C_MINS=B_MINS-A_MINS
SET /A C_SECS=B_SECS-A_SECS

IF %C_MSEC% LSS 0  SET /A C_MSEC+=100 & SET /A C_SECS-=1
IF %C_MSEC% LSS 10 SET C_MSEC=0%C_MSEC%

IF %C_SECS% LSS 0  SET /A C_SECS+=60  & SET /A C_MINS-=1
IF %C_SECS% LSS 10 SET C_SECS=0%C_SECS%

IF %C_MINS% LSS 0  SET /A C_MINS+=60  & SET /A C_HOUR-=1
IF %C_MINS% LSS 10 SET C_MINS=0%C_MINS%

IF %C_HOUR% LSS 0  SET /A C_HOUR+=24
IF %C_HOUR% LSS 10 SET C_HOUR=0%C_HOUR%

IF %C_MINS% GTR 5 @echo [%time:~0,8%] 系統判定 5 分鐘已到，嘗試點擊了 CLAIM 距離上一次點擊 CLAIM 差了 %C_MINS% 分 %C_SECS% 秒 & adb shell input tap 848 1193 & CALL :claimforminuteset

IF NOT %C_MINS% GTR 5 @echo [%time:~0,8%] 系統判定 5 分鐘未到，距離上一次嘗試點擊 CLAIM 差了 %C_MINS% 分 %C_SECS% 秒

exit /B

:claimforminuteset

SET A=%TIME%
SET A_HOUR=%A:~0,2%
SET A_MINS=%A:~3,2%
SET A_SECS=%A:~6,2%
SET A_MSEC=%A:~9,2%
CALL :restart

exit /B
