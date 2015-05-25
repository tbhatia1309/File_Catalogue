/////////////////////////////////////////////////////////////////////////////
// Display.cpp -  Displays the required results on the console screen 	   //
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
#include <iostream>
#include "Display.h"
#include "../FileMgr/FileMgr.h"


// <--- DISPLAY INTRODUCTORY TEXT --->//
void Display::introPrint(){

	std::cout << "\n\n\n" << std::string(82 , '#')<<"\n";
	std::cout << "#		                    OOD PROJECT # 1		                 #\n";
	std::cout << "#		                    DESIGNED BY 				 #\n";
	std::cout << "#		                    TUSHAR BHATIA 				 #\n";
	std::cout << std::string(82, '#') << "\n\n";

	std::cout << "			DISPLAYING ALL THE FILES FROM CATALOGUE \n";
	std::cout << std::string(82, '=') << "\n\n";

}
// <--- CALLS PRINTDATASTORE FUNCTION --->//
void Display::DispFiles(FileMgr fm){

	Display::printDataStore(fm);

}
// <---  PRINTS DATASTORE--->//
void Display::printDataStore(FileMgr fm){

	bool flag = true;
	std::vector<std::string> result;
	std::set<std::string>::iterator fItr;
	std::list<std::set<std::string>::iterator>::iterator List;
	std::list<std::set<std::string>::iterator>::iterator findItr;
	std::map<std::string, std::list<std::set<std::string>::iterator>>::iterator MapItr;

for (fItr = fm.getDataStoreRef().FilePathBegin(); fItr != fm.getDataStoreRef().FilePathEnd(); fItr++){
	flag = true;
for (MapItr = fm.getDataStoreRef().FileMapBegin(); MapItr != fm.getDataStoreRef().FileMapEnd(); MapItr++){
	std::list<std::set<std::string>::iterator> list = (MapItr->second);
for (List = list.begin(); List != list.end(); List++){
	if (*(*List) == (*fItr))
	{
	if (flag){
	std::cout << "\nPath : " << (*fItr) << "\n";
	std::cout << std::string(82, '=') << "\n\n";
	std::cout << "Files : \n\n";
	flag = false;
	}
	std::cout << MapItr->first << "\n";
	}
	}
	}
	}
}
// <--- DISPLAYS THE SUMMARY OF THE CATALOGUE --->//
void Display::DispSummary(FileMgr fm){
	int NumbrOfDirectories = 0;
	int NumbrOfFiles = 0;
	bool flag = true;
	std::vector<std::string> result;
	std::set<std::string>::iterator fItr;
	std::list<std::set<std::string>::iterator>::iterator List;
	std::list<std::set<std::string>::iterator>::iterator findItr;
	std::map<std::string, std::list<std::set<std::string>::iterator>>::iterator MapItr;

for (fItr = fm.getDataStoreRef().FilePathBegin(); fItr != fm.getDataStoreRef().FilePathEnd(); fItr++){
	NumbrOfDirectories++;
for (MapItr = fm.getDataStoreRef().FileMapBegin(); MapItr != fm.getDataStoreRef().FileMapEnd(); MapItr++){
	std::list<std::set<std::string>::iterator> list = (MapItr->second);
for (List = list.begin(); List != list.end(); List++){
	if (*(*List) == (*fItr))
	{
	NumbrOfFiles++;
	}
	}
	}
	}

std::cout << "                                          SUMMARY \n";
std::cout << std::string(82, '=') << "\n\n";
std::cout << "\nFOUND - " << NumbrOfFiles << " FILES  IN - " << NumbrOfDirectories << " DIRECTORIES \n\n";


}
// <---DISPLAYS ALL THE DUPLICATE FILES & THEIR PATHS --->//
void Display::DispDupFiles(FileMgr fm){

	Display::printDupFiles(fm);

}

// <---RETRIEVES ALL THE FILES AND CALLES DISPLSEARCHEDFILES FUNCTION --->//
void Display::DispSearchedFiles(int argc, char** argv, FileMgr fm){
	
	Cataloger ctglr;
	std::vector<std::string> SearchedFiles;

	SearchedFiles = ctglr.SearchText(argc, argv, fm);
	if (SearchedFiles.size() > 0){
		DisplSearchedFileAndPath(SearchedFiles);
	}
	else{
		std::cout << "\nNO FILES CONTAINING THE GIVEN TEXT FOUND\n\n";

	}
}
// <--- DISPLAYS ALL THE FILES & PATH CONTAINING SEARCHED DATA --->//
void Display::DisplSearchedFileAndPath(std::vector<std::string> FullFileNames){

	std::string filePath = "";
	std::string fileName = "";

	std::cout << "\nFILES FOUND: \n";
	std::cout << std::string(82, '=') << "\n\n";
	for (size_t i = 0; i < FullFileNames.size(); i++){

	unsigned found = FullFileNames[i].find_last_of("\\");
	std::cout << "\nPath: " << FullFileNames[i].substr(0, found) << '\n';
	std::cout << std::string(82, '=') << "\n\n";
	std::cout << "File: " << FullFileNames[i].substr(found + 1) << '\n';

	}
	std::cout << "\n";
}

// <--- PRINTS ALL THE DUPLICATE FILES AND ITS PATH --->//
void Display::printDupFiles(FileMgr fm){

	bool flag = true;
	std::vector<std::string> result;
	std::set<std::string>::iterator fItr;
	std::list<std::set<std::string>::iterator>::iterator List;
	std::list<std::set<std::string>::iterator>::iterator findItr;
	std::map<std::string, std::list<std::set<std::string>::iterator>>::iterator MapItr;

for (MapItr = fm.getDataStoreRef().FileMapBegin(); MapItr != fm.getDataStoreRef().FileMapEnd(); MapItr++){
	std::list<std::set<std::string>::iterator> list = (MapItr->second);
if (list.size() > 1){
if (flag){
	std::cout << "\n\nDUPLICATE FILES \n";
	std::cout << std::string(82, '=') << "\n\n";
	flag = false;
	}
	std::cout << "File Name : "<<(MapItr->first) << "\n";
	std::cout << "File Present at : \n\n";
for (List = list.begin(); List != list.end(); List++){
	std::cout << *(*List) << "\n";
	}
			
	std::cout << "\n";
	}
}

if (flag){
	std::cout << "\n\nDUPLICATE FILES \n";
	std::cout << std::string(82, '=') << "\n\n";
	std::cout << "\nNo Duplicate files found in the catalogue.\n\n";
		
	}
		
}
//<--- METHOD THAT ASKS USER FOR SEARCHING TEXT IN THE FILE CATALOGUE --->
void Display::DispSearchTextAgain(FileMgr fm){
	std::string input;
	TextSearch txtsrch;
	Display dsp;
	while (true){
		std::cout << "\nDO YOU WISH TO SEARCH ANY TEXT ? (Y/N) (COMMONLY USED WORD IN TEXT FILES IS string or iostream) \n";
		std::cin >> input;
		if (input == "y" || input == "Y") {
			std::cout << "PLEASE ENTER THE TEXT ONLY \n";
			std::cin >> input;
			std::cout << "SEARCHING FOR : \"" << input << "\"\n";
			std::vector<std::string> files = txtsrch.SearchDataStore(input, fm);
			if (files.size() > 0)
				dsp.DisplSearchedFileAndPath(files);
			else
				std::cout << "\nNO FILES CONTAINING THE GIVEN TEXT FOUND\n\n";
			continue;
		}
		if (input == "n" || input == "N")
			break;
		else{
			std::cout << "PLEASE ENTER Y OR N \n";
			continue;
		}
	}


}


// <--- TEST STUB --->//
#ifdef TEST_DISPLAY
int main(int argc, char** argv) {
	std::cout << "Testing Display package \n";

	Display dsp;
	FileMgr fm;
	std::string path = "D:\\Tushar Exam prep\\syr_uni\\OOD\\unzip\\FileMgr - directories fetching\\FileMgr";
	std::cout << "path : " << path << "\n";
	argv[0] = "//s"; argv[1] = ".";	argv[2] = "/s";	argv[3] = "/s";
	
	bool result = fm.SearchRecurse(3, argv);
	//std::cout << "The result for search recurse is :" << result;
	fm.getFiles(path, true);
	dsp.introPrint();
	dsp.printDataStore(fm);

}
#endif