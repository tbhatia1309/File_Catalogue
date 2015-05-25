/////////////////////////////////////////////////////////////////////////////
// FielMgr.h    -   Fetches all the file names & paths from the machine    //
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
#include "FileMgr.h"
#include "FileSystem.h"
#include "../DataStore/DataStore.h"
#include <iostream>
#include<string>


// <--- SEARCHES IF THE USER WISHES TO ENABLE COMPLETE DIRECTORY SEARCH--->//
bool FileMgr::SearchRecurse(int argc, char** argv) {
	bool recurse = false;
	std::string patt;
	std::string path = "";		
	path = argv[1];
	if (path.empty()|| path == " ") {
		std::cout << "\nNo Path Provided. Assuming Current Directory.\n";
		path = ".";
	}

for (int i = 2; i < argc; i++){

	if (((std::string(argv[i]).find(".")) != std::string::npos) && 
					(!(((std::string(argv[i]).find("/f")) != std::string::npos) ||
								((std::string(argv[i]).find("/F")) != std::string::npos)))){
			
		patt = std::string(argv[i]);
		if ((std::string(argv[i]).find("*.")) == std::string::npos){

		unsigned found = std::string(argv[i]).find_last_of(".");
		patt = "*." + std::string(argv[i]).substr(found + 1);

		}			
		FileMgr::addPattern(patt);
		continue;	
		}
		if ((std::string(argv[i]) == "/s") || (std::string(argv[i]) == "/S")){
		recurse = true;
		continue;
		}

	
	}
	path = FileSystem::Path::getFullFileSpec(path);
	FileMgr::getFiles(path, recurse);
	return recurse;
}

// <--- CALLS DIRECTORYSEARCH FUNCTION --->//
void FileMgr::getFiles(std::string path, bool recurse)
{
	std::string curDir = path;
	FileMgr::directorySearch(curDir, recurse);
}



// <--- SETS THE FILE PATH , FILE NAME WITH REFERENCE IN THE DATASTORE --->//
void FileMgr::getAllFiles(std::string pathSet){
	std::string ext;
	std::vector<std::string> files;
	files = FileSystem::Directory::getFiles(pathSet);

	
	ds.save_(pathSet);
	for (size_t i = 0; i < files.size(); i++) {
		if ((patterns_.size() == 1) && (patterns_[0].compare("*.*") == 0))
			ds.save_(files[i], pathSet);
		
		ext = "*."+ FileSystem::Path::getExt(files[i]);

		if (std::find(patterns_.begin(), patterns_.end(), ext) != patterns_.end())
			ds.save_(files[i], pathSet);

	}
}
// <--- SEARCHES THE MACHINE FOR DIRECTORIES (BASED ON THE USER INPUT,
//                        MAY JUST SEARCH FOR DIRECTORIES IN CURRENT DIRECTORY  OR RECURSIVELY SEARCH ALL THE DIRECTORIES     ) --->//
void FileMgr::directorySearch(std::string pathSet, bool recurse)  {
	std::string curDir;
	std::string dirName;
	FileSystem::FileSystemSearch fss;
	std::vector<std::string> currDirs;
	
	dirName = fss.firstDirectory(pathSet);

	if (dirName.size() > 0)
		getAllFiles(pathSet);
	if (recurse)
	while (true){
		dirName = fss.nextDirectory();
		if (dirName.compare("..") == 0)
			continue;
		else if (dirName.size() > 0){
			directorySearch(pathSet + '\\' + dirName, true);
		}
		else
			break;
	}
}

#ifdef TEST_FILEMGR

int main(int argc, char** argv)
{
	DataStore ds;
	std::cout << "Testing File Manager \n";
	FileMgr fm;
	//ds = fm.getDataStoreRef();
	std::string path = "D:\\Tushar Exam prep\\syr_uni\\OOD\\unzip\\FileMgr - directories fetching\\FileMgr";
	std::cout << "The path provided : " << path<<"\n";
	argv[0] = "//s"; argv[1] = ".";	argv[2] = "/s";	argv[3] = "/s";
	
	bool result = fm.SearchRecurse(3, argv);
	std::cout << "The result for search recurse is :" << result;
	fm.getFiles(path, true);

	std::vector<std::string> files =fm.getDataStoreRef().getFilesFromDataStore(fm.getDataStoreRef());
	std::cout << "Printing the files from data store \n";
	std::vector<std::string>::iterator vItr;
	for (vItr = files.begin(); vItr != files.end(); vItr++){
		std::cout << (*vItr) << "\n";
	}

	return 0;
}
#endif