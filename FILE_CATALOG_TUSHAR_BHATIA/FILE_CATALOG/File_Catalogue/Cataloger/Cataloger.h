#ifndef CATALOGER_H	
#define CATALOGER_H
/////////////////////////////////////////////////////////////////////////////
// Cataloger.h - orchestrates the functions of the File Catalogue  		   //
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
* This module does analysis for the request that the user and provides the
* display unit the data to be displayed. Also, parses commmand line to check
* if the user requested for duplicate data
*
* Public Interface:
* =================
* Cataloger ctglr;
* ctglr.isSearchTextEnabled(argc, argv, fm)
* ctglr.SearchDup(int argc, char** argv)
* SearchText(int argc, char** argv, FileMgr fm)
*
* Required files:
* ===============
* - Cataloger.h, Cataloger.cpp, FileMgr.h, DataStore.h, FileSystem.h
*
* Build Process:
* ==============
* devenv Cataloger.vcxproj
*
* Maintenance History:
* ====================
* version 1.0 : 10th Feb 2015
* - First Release
*/




#include "../DataStore/DataStore.h"
#include "../SearchText/SearchText.h"
class Cataloger{
public:	
	
	bool SearchDup(int argc, char** argv);
	bool isSearchTextEnabled(int argc, char** argv, FileMgr fm);
	std::vector<std::string> SearchText(int argc, char** argv, FileMgr fm);
};
#endif