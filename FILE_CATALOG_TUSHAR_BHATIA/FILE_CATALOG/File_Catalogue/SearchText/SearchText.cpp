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

#include "SearchText.h"

// <--- SEARCHES THE DATA STORE FOR A GIVEN TEXT --->//
std::vector<std::string> TextSearch::SearchDataStore(std::string text, FileMgr fm){
	
	using File = FileSystem::File;
	using Path = FileSystem::Path;
	

	std::vector<std::string> files;
	std::vector<std::string> result;
	
	files = fm.getDataStoreRef().getFilesFromDataStore(fm.getDataStoreRef());

	
	for (size_t i = 0; i < files.size(); ++i)
	{
		std::string ext = Path::getExt(files[i]);
	if (ext == "exe" || ext == "dll" || ext == "bmp" || ext == "jpg" || ext == "obj" || ext == "vsdx" || files[i] == "run.dat")
	{
		std::cout << "\nSKIPPING FILE : ";
		std::cout << files[i];
		continue;
	}
		
	File testAll(files[i]);
	testAll.open(File::in);
	if (testAll.isGood())
	{
		std::string all = testAll.readAll();
		
			 
	if (all.find(text) != std::string::npos)
		result.push_back(files[i]);
	}
		testAll.close();
	}

	std::cout << "\n";
	return result;
	}

// <--- TEST STUB --->//
#ifdef TEST_TEXTSEARCH
int main(int argc, char **argv)
{
	std::cout << "Testing Text Search Module\n";
	FileMgr fm;
	TextSearch txtsrch;
	//ds = fm.getDataStoreRef();
	std::string path = "D:\\Tushar Exam prep\\syr_uni\\OOD\\unzip\\FileMgr - directories fetching";
	std::cout << "path : " << path << "\n";
	argv[0] = "//s"; argv[1] = ".";	argv[2] = "/s";	argv[3] = "/s";

	bool result = fm.SearchRecurse(3, argv);
	
	fm.getFiles(path, true);

	std::cout << "Testing for the Text :\" String \"";
	std::vector<std::string> files = txtsrch.SearchDataStore("string", fm);
	std::vector<std::string>::iterator fItr;
	std::cout << "Displaying all the files with Text included \n";
	for (fItr = files.begin(); fItr != files.end(); fItr++){

		std::cout << (*fItr) << "\n";
	}


}

#endif