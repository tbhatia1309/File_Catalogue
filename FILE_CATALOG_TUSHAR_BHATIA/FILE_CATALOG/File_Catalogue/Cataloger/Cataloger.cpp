/////////////////////////////////////////////////////////////////////////////
// Cataloger.cpp - orchestrates the functions of the File Catalogue        //
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

#include "Cataloger.h"

bool Cataloger::SearchDup(int argc, char** argv){
	bool duplicate = false;
	std::string text = "";

	for (int i = 1; i < argc; i++){
		if ((std::string(argv[i]) == "/d") || (std::string(argv[i]) == "/D")){
			duplicate = true;
			break;
		}	
	}
	return duplicate;
}

bool Cataloger::isSearchTextEnabled(int argc, char** argv, FileMgr fm){
	bool result = false;

	for (int i = 1; i < argc; i++){
		if (((std::string(argv[i]).find("/f")) != std::string::npos) || 
								((std::string(argv[i]).find("/F")) != std::string::npos)){
			result = true;
			break;
		}
	}
	
	return result;
}

std::vector<std::string> Cataloger::SearchText(int argc, char** argv, FileMgr fm){
	TextSearch sText;
	bool duplicate = false;
	std::vector<std::string> files;
	std::string text = "";
	for (int i = 1; i < argc; i++){
		if (((std::string(argv[i]).find("/f")) != std::string::npos) || 
										((std::string(argv[i]).find("/F")) != std::string::npos)){
			text = (std::string(argv[i]).substr(2, (std::string(argv[i]).length() - 1)));
			std::cout << "\n\nSEARCH TEXT\n";
			std::cout << std::string(82, '=') << "\n\n";
			std::cout << "SEARCHING FOR THE TEXT  : \"" << text<<"\"\n";
			break;
		}
	}
	
	files = sText.SearchDataStore(text,fm);
	return files;
}


#ifdef TEST_CATALOGER
int main(int agrc, char** argv)
{
	Cataloger ctglr;
	std::cout << "Testing Cataloger Module\n";
	FileMgr fm;
	std::string path = "D:\\Tushar Exam prep\\syr_uni\\OOD\\unzip\\FileMgr - directories fetching";
	std::cout << "path : " << path << "\n";
	argv[0] = "//s"; argv[1] = ".";	argv[2] = "/s";	argv[3] = "/f\"string\"";

	bool result = fm.SearchRecurse(3, argv);
	result = ctglr.isSearchTextEnabled(4, argv, fm);
	std::cout << " result form Search Text enabled is :"<<result <<"\n";

	std::vector<std::string> files = ctglr.SearchText(3, argv, fm);

	std::vector<std::string>::iterator fItr;
	std::cout << "Displaying all the files with Text included - \"string\"\n";
	for (fItr = files.begin(); fItr != files.end(); fItr++){

		std::cout << (*fItr) << "\n";
	}

}
#endif