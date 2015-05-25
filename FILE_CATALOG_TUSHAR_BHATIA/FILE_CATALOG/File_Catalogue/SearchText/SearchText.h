#ifndef SEARCHTEXT_H
#define SEARCHTEXT_H	
/////////////////////////////////////////////////////////////////////////////
// SearchText.h Search for a particular text in the files of file Catalogue//
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
* This module provides services to search text from files present in the 
* data store
*
* Public Interface:
* =================
* TextSearch txtsrch;
* std::vector<std::string> files = txtsrch.SearchDataStore(std::string text, FileMgr fm);
*
* Required files:
* ===============
* -SearchText.h, SearchText.cpp, FileMgr.h, DataStore.h
*
* Build Process:
* ==============
* devenv SearchText.vcxproj
*
* Maintenance History:
* ====================
* version 1.0 : 10th Feb 2015
* - First Release
*/

#include <iostream>
#include <vector>
#include "../FileMgr/FileMgr.h"
#include "../DataStore/DataStore.h"
#include "../FileMgr/FileSystem.h"

class TextSearch {
	
public:
	std::vector<std::string> SearchDataStore(std::string text, FileMgr fm);
};
#endif