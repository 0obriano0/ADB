@echo off

CD platform-tools

rem ************循??始了
:continue
set /a var+=1
echo 第%var%次循?
adb shell input tap 560 1200
goto continue
rem ************循??束了
echo 循??行完?
pause