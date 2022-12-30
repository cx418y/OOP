@ECHO OFF
IF %1%-==-wait- (
TASKKILL /F /IM lab3.exe
IF ERRORLEVEL 128 (START /B run -wait) ELSE (START /B run -exec)
) ELSE IF %1%-==-exec- (
TASKKILL /F /IM lab3.exe
START "lab3" cmake-build-debug/lab3 -t
) ELSE (
START run -wait
)
EXIT 0