@echo off

SET PROGRAM="%~1"

if %PROGRAM%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Empty file
%PROGRAM% test\input0.txt "%TEMP%\output.txt" 3 5 || goto err
fc test\input0.txt "%TEMP%\output.txt" > nul || goto err
echo Test 1 passed

REM Input file not exists
%PROGRAM% test\notexist.txt "%TMP%\output.txt" 3 5 && goto err
echo Test 2 passed

REM Incorrect number of arguments
%PROGRAM% test\input1.txt "%TMP%\output.txt" 5 5 5 5 && goto err
echo Test 3 passed

REM Incorrect number of arguments
%PROGRAM% test\input1.txt "%TMP%\output.txt" && goto err
echo Test 4 passed

REM Replacing an empty string
%PROGRAM% test\input1.txt "%TEMP%\output.txt" "" 5 && goto err
echo Test 5 passed

REM Replacing on an empty string
%PROGRAM% test\input1.txt "%TEMP%\output.txt" 3 "" && goto err
echo Test 6 passed

REM Wrong arguments
%Program% 1 2 3 4 && goto err
echo Test 7 passed

REM Replacing on itself
%PROGRAM% test\input1.txt "%TEMP%\output.txt" 3 3 || goto err
fc test\output1.txt "%TEMP%\output.txt" > nul || goto err
echo Test 8 passed
 
REM Replacing on double substring
%PROGRAM% test\input1.txt "%TEMP%\output.txt" ma mama || goto err
fc test\output2.txt "%TEMP%\output.txt" > nul || goto err
echo Test 9 passed

REM Replacing on double substring
%PROGRAM% test\input1.txt "%TEMP%\output.txt" ma mama || goto err
fc test\output2.txt "%TEMP%\output.txt" > nul || goto err
echo Test 9 passed

REM Normal replace
%PROGRAM% test\input1.txt "%TEMP%\output.txt" replace yes  || goto err
fc test\output3.txt "%TEMP%\output.txt" > nul || goto err
echo Test 10 passed

REM Tests passed successfully
echo Tests passed successfully
exit /B 0

:err
echo Test failed
exit /B 1