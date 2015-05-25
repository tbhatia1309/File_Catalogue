/////////////////////////////////////////////////////////////////////////////
// Exec.cpp - Starting point of File Catalogue  		                   //
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
* Module Purpose:
* ===============
* The purpose of this module is oversee the program flow. This is the
* entry point to the application. All the calls to the subsequent modules
* will be routed from here
*/

#include <iostream>
#include "../Cataloger/Cataloger.h"
#include "../DataStore/DataStore.h"
#include "../FileMgr/FileMgr.h"
#include "../Display/Display.h"
//<--- MAIN FUNCTION (STARTING POINT OF THE PROGRAM) --->
int main(int argc, char** argv){

	Display dsp;
	FileMgr fm;
	Cataloger ctglr;

	dsp.introPrint(); 
	bool recurse = fm.SearchRecurse(argc, argv);
	bool duplicate = ctglr.SearchDup(argc, argv);
	
	dsp.DispSummary(fm);
	dsp.DispFiles(fm); 	

if (duplicate)
	dsp.DispDupFiles(fm);
	
if (ctglr.isSearchTextEnabled(argc, argv, fm))
	dsp.DispSearchedFiles(argc, argv, fm);
	
   dsp.DispSearchTextAgain(fm);

}
