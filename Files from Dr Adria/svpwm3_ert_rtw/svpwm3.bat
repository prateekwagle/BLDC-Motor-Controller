
cd .

chcp 1252

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2020b\bin\win64\gmake"  -B DEPRULES=0 -j7  -f svpwm3.mk all) else ("C:\PROGRA~1\MATLAB\R2020b\bin\win64\gmake"  -B DEPRULES=0 -j7  -f svpwm3.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1