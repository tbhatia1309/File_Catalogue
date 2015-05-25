/////////////////////////////////////////////////////////////////////////////
// DataStore.cpp - 	Stores the data of the file	                           //
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
#include "DataStore.h"
#include "../FileMgr/FileMgr.h"
#include <iostream>
#include <algorithm>
#include <string>

void DataStore::save_( std::string filePath) {
	filePath_.insert(filePath);
}
//<--- CHECKS IF ANY FILE WITH THE SAME NAME EXISTS IN THE DATASTORE   --->
bool DataStore::doesFileExist(std::string filename){

	bool result = FileMap.find(filename) != FileMap.end();

	return result;
}
//<--- INCASE ANY FILE WITH THE SAME NAME EXISTS IN THE DATASTORE, THEN APPENDS THE REFERENCE TO THE LIST OF REFERENCES   --->
void DataStore::appendMap(std::string filename, std::string path){
	std::list<Ref> pathList;
	Ref setItr = filePath_.find(path);
	pathList = FileMap[filename];
	pathList.push_back(setItr);
	FileMap[filename] = pathList;
}
///<--- SAVES THE FILE PATH AND NAME IN THE DATASTORE   --->
void DataStore::save_(std::string filename, std::string path) {
	std::list<Ref> pathList;
	Ref setItr = filePath_.find(path);
	bool result = doesFileExist(filename);
if (result){
	appendMap(filename, path);
	return;
	}
	pathList.push_back(setItr);
	FileMap.insert({ filename, pathList });
	return;
}

//<--- FETCHES FILE FROM DATASTORE USING DATASTORE ITERATOR   --->
std::vector<std::string>DataStore::getFilesFromDataStore(DataStore ds){
	std::vector<std::string> result;
	std::set<std::string>::iterator fItr ;
	std::list<std::set<std::string>::iterator>::iterator List;
	std::list<std::set<std::string>::iterator>::iterator findItr;
	std::map<std::string, std::list<std::set<std::string>::iterator>>::iterator MapItr;
	 
	for (fItr = ds.FilePathBegin(); fItr != ds.FilePathEnd(); fItr++){
		for (MapItr = ds.FileMapBegin(); MapItr != ds.FileMapEnd(); MapItr++){
		std::list<std::set<std::string>::iterator> list = (MapItr->second);
			for (List = list.begin(); List != list.end(); List++){
				if (*(*List) == (*fItr))
				result.push_back((*(*List))+'\\'+MapItr->first);
			}
	}
}
	
return result;
}

//<--- TEST STUB --->
#ifdef TEST_DATASTORE

int main()
{
	std::cout << "\n  Testing DataStore Module \n";
	
	DataStore ds;
	std::cout << "Inserting files into Datastore\n";
	ds.save_("C:\\Tushar\\Apps");
	ds.save_("C:\\Tushar\\Downloads");
	ds.save_("C:\\Tushar\\Pictures");
	std::set<std::string>::iterator fItr;
	std::cout <<"Retreving files from the DataStore \n";
	for (fItr = ds.FilePathBegin(); fItr != ds.FilePathEnd(); fItr++){
	
		std::cout << (*fItr).c_str()<<"\n";
	}

	
	std::cout << "\n\n";
	}

#endif
