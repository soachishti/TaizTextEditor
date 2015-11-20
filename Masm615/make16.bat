@echo off
REM make16.bat
REM Revised 2/1/02
REM By: Kip R. Irvine

REM Assembles and links the current 16-bit ASM program.
REM 
REM Command-line options (unless otherwise noted, they are case-sensitive):
REM 
REM /nologo     Suppress the Microsoft logo display
REM -Cp         Enforce case-sensitivity for all identifiers
REM -Zi		Include source code line information for debugging
REM -Fl		Generate a listing file (see page 88)
REM /CODEVIEW   Generate CodeView debugging information (linker)
REM %1.asm      The name of the source file, passed on the command line

REM ************* The following lines can be customized:
PATH %~1\Masm615
SET INCLUDE=%~1\Masm615\INCLUDE
SET LIB=%~1\Masm615\LIB
REM **************************** End of customized lines

REM Invoke ML.EXE (the assembler):

ML /nologo -c -Fl -Zi %2.asm
if errorlevel 1 goto terminate

REM Run the 16-bit linker:

LINK /nologo /CODEVIEW %2,,NUL,Irvine16;
if errorlevel 1 goto terminate

REM Display all files related to this program:
DIR %1.*

:terminate
pause
