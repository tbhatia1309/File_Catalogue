#ifndef DISPLAY_H	
#define DISPLAY_H
/////////////////////////////////////////////////////////////////////////////
// Display.h -  Displays the required results on the console screen 	   //
// ver  1.0                                                                //
// ----------------------------------------------------------------------- //
// copyright © Tushar Bhatia, 2015                                         //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2013                             //
// Platform:    Dell Inspiron 15R, Core i5, Windows 8                      //
// Application: OOD Project # 1, 2015                                      //
// Author:      Tushar Bhatia, Syracuse University                         //
//              (315) 728-8606, tbhatia@syr.edu                            //
/////////////////////////////////////////////////////////////////////////////
/*
* Module Operations:
* ==================
* This module provides a class that provides services to display the file catalogue
* as requested by the User (based on the user inputs)
*
* Public Interface:
* =================
* FileMgr fm;
* Display dsp;
* Cataloger ctglr;
* dsp.introPrint(); 
* dsp.DispSummary(fm);
* dsp.DispFiles(fm); 	
* dsp.DispDupFiles(fm);	
* bool result = ctglr.isSearchTextEnabled(argc, argv, fm)
* dsp.DispSearchedFiles(argc, argv, fm);	
* dsp.DispSearchTextAgain(fm);
*
* Required files:
* ===============
* Display.h, Display.cpp, Cataloger.h, FileMgr.h
*
* Build Process:
* ==============
* devenv Display.vcxproj
*
* Maintenance History:
* ====================
* version 1.0 : 10th Feb 2015
* - First Release
*/

#include <iostream>
#include <string>
#include <set>
#include"../FileMgr/FileMgr.h"
#include "../DataStore/DataStore.h"
#include "../Cataloger/Cataloger.h"

class Display{

public:	


void introPrint();
// with  /s or w/o /s
void Display::DispFiles(FileMgr fm);
void DispSummary(FileMgr fm);
// /d
void DispDupFiles(FileMgr fm);
void printDataStore(FileMgr fm);
void DispSearchedFiles(int argc, char** argv, FileMgr fm);
void printDupFiles(FileMgr fm);
void DisplSearchedFileAndPath(std::vector<std::string> FullFileNames);
void DispSearchTextAgain(FileMgr fm);

};

#endif