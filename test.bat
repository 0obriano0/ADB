@echo off

CD platform-tools

rem ************�`??�l�F
:continue
set /a var+=1
echo ��%var%���`?
adb shell input tap 560 1200
goto continue
rem ************�`??���F
echo �`??�槹?
pause