@echo off
chcp 65001

set data=%1
set data1=%2
cd %data%

dir %data% > list2.txt

find /c /i "%data1%" <list2.txt > list3.txt
for /f %%i in (list3.txt) do set /a result = %%i & set /a resfiles = %%i%%2

echo %result%

if %result%==0 echo Не существует файла с данным типом файла & goto END

if %resfiles%==0 (
tasklist > tasklist1.txt
find /c /i " K" <tasklist1.txt > tasklist2.txt
for /f %%j in (tasklist2.txt) do echo Число активных процессов - %%j
del tasklist1.txt
del tasklist2.txt
) else (timeout 7)

:END
del list2.txt
del list3.txt
pause