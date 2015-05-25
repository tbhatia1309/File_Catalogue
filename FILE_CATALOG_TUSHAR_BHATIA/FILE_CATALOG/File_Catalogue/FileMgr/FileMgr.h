#ifndef FILEMGR_H
#define FILEMGR_H
/////////////////////////////////////////////////////////////////////////////
// FielMgr.cpp -   	Fetches all the file names & paths from the machine    //
//					and stores it in the datastore						   //
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
* This module provides a class that provides services to search the directories 
* and get all the files. These files and their paths are  stored into the DataStore
* Based on the user input the directories are searched recursively or only the given 
* directory is searched.
* 
* Public Interface:
* =================
* FileMgr fm;
* bool recurse = fm.SearchRecurse(argc, argv);
* fm.getFiles(std::string path, bool recurse);
* fm.getAllFiles(std::string pathSet);
* fm.directorySearch(std::string pathSet, bool recurse);
* DataStore& datastore = fm.getDataStoreRef();
*
* Required files: 
* ===============
* -FileMgr.h, DataStore.h, FileSystem.h, FileMgr.cpp, FileSystem.cpp, DataStore.cpp
* 
* Build Process:
* ==============
* devenv FileMgr.vcxproj
* 
* Maintenance History:
* ====================
* version 1.0 : 10th Feb 2015
* - First Release
*/
#include <string>
#include<set>
#include "FileSystem.h"
#include "../DataStore/DataStore.h"

class FileMgr
{
public:
  using iterator = DataStore::iterator;
  using patterns = std::vector<std::string>;

  FileMgr::FileMgr() 
  {
	  patterns_.push_back("*.*");
  }

  void FileMgr::addPattern(std::string patt)
  {
    if (patterns_.size() == 1 && patterns_[0] == "*.*")
      patterns_.pop_back();
    patterns_.push_back(patt);
  }


  bool SearchRecurse(int argc, char** argv);
  void getFiles(std::string path, bool recurse);
  void getAllFiles(std::string pathSet);
  void directorySearch(std::string pathSet, bool recurse);
  
  DataStore& getDataStoreRef() {
	  return ds;
  }

private:
  DataStore ds;
  patterns patterns_;
};

#endif
