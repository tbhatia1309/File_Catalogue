@echo off
cls
echo #######################################################################################
echo # CMDLine Usage: [Build Path] [FilePath] [Pattern(s)] [/S] [/D] [/F"Text"]            #                 
echo # /S           : RECURSIVELY SEARCH DIRECTORY                                         #
echo # /D           : PRINTS FILE WITH DUPLICATE NAMES IN THE CATALOGUE                    #
echo # /f"Text"     : PRINTS THE NAME OF FILES AND THEIR PATHS WHICH CONTAIN THE GIVEN TEXT#   
echo #######################################################################################
echo #
echo #
echo NOTE: ALL THE ARGUMENTS BESIDES [Build Path] [FilePath] ARE OPTIONAL.  
echo #
echo #
echo NOTE: BESIDES [Build Path] [FilePath] REST OF THE OPTION SEQUENCE DOES NOT MATTER
echo ************************ RUNNING FILE CATALOGUE ************************
echo #
echo #
echo #     RUNNING COMMAND WITH NO PARAMETER(S)
echo #     COMMAND: [Build Path] [FilePath]

pause
".\File_Catalogue\Debug\Exec.exe" "..\OOD_Project_1\Test_Folder" 

echo #
echo #	   DEMONSTRATING REQUIREMENT # 3 , # 7 , # 8 
echo #     FILE, DIRECTORY SUMMARY IS BEING DISPLAYED EVERY TIME CODE IS RUN
echo #	   TEXT SEARCH OPTION IS PROVIDED EVERY TIME AS WELL
echo #     RUNNING COMMAND /S AND PATTERNS
echo #     COMMAND: [Build Path] [FilePath] *.log /S abc.cpp "*.h"

pause
".\File_Catalogue\Debug\Exec.exe" "..\OOD_Project_1\Test_Folder" *.log /S abc.cpp "*.h"


echo #
echo #	   DEMONSTRATING REQUIREMENT # 5
echo #     RUNNING COMMAND WITH /D /S
echo #     COMMAND: [Build Path] [FilePath] /D /S 

pause
".\File_Catalogue\Debug\Exec.exe" "..\OOD_Project_1\Test_Folder" /D  /S 

echo #
echo #	   DEMONSTRATING REQUIREMENT # 6
echo #     RUNNING COMMAND WITH /F"Text"
echo #     COMMAND: [Build Path] [FilePath] /F"string" /S

pause
".\File_Catalogue\Debug\Exec.exe" "..\OOD_Project_1\Test_Folder" /F"string" /S

