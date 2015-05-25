#ifndef DATASTORE_H
#define DATASTORE_H

/////////////////////////////////////////////////////////////////////////////
// DataStore.h -   	Stores the data of the file	                           //
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
* This module provides a class that provides the service of storing the file Catalogue
* in a map and a set. The DataStore provies interface in the form of iterator to access the 
* the data stored in the data store
*
* Public Interface:
* =================
* DataStore ds;
* FileMgr fm;
* ds.save_(filePath);
* ds.save_(filename, path);
* bool result =  ds.doesFileExist(filename);
* ds.appendMap( filename, path); 
* std::vector<std::string> files=  ds.getFilesFromDataStore(fm.getDataStoreRef()); 
*
* Required files:
* ===============
* DataStore.h, DataStore.cpp
*
* Build Process:
* ==============
* devenv DataStore.vcxproj
*
* Maintenance History:
* ====================
* version 1.0 : 10th Feb 2015
* - First Release
*/

#include <vector>
#include <map>
#include <set>
#include <list>

class DataStore
{
public:
  using Ref    = std::set<std::string>::iterator;
  using MapRef = std::map<std::string, std::list<Ref>>::iterator;
  
  using iterator  =  std::vector<std::string>::iterator;
  using iterator_ =  std::list<Ref>::iterator ;
  

  Ref FilePathBegin() { return filePath_.begin(); }
  Ref FilePathEnd() { return filePath_.end(); }

  MapRef FileMapBegin() { return FileMap.begin(); }
  MapRef FileMapEnd() { return FileMap.end(); }

  
  void save_(std::string filePath);
  void save_(std::string filename, std::string path);
  bool doesFileExist(std::string filename);
  void appendMap(std::string filename, std::string path);
  
  std::vector<std::string> getFilesFromDataStore(DataStore ds); 
    
private:
	std::set<std::string> filePath_;
	std::map<std::string, std::list<Ref>> FileMap;
    std::vector<std::string> store;
};
#endif
