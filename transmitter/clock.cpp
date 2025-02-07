
//	Package:	sw_def_radio
//	File:		clock.cpp
// 	Purpose:	Define the Transmitter's Clock Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "clock.hpp"
#include "tools.hpp"
using namespace std;


/////////////
// Globals //
/////////////
float tempf;	// Needed for writing data to file
CLOCK::Clock DUMMY_CLOCK = {4.8,0.5};

// Default Constructor
CLOCK::CLOCK() {
	CLOCK::fout 			= 4.8; // GHz
	CLOCK::control_volt 	= 0.5; 	// VDC
};

// DESTRUCTOR
CLOCK::~CLOCK() {std::cout << "Clock Destructor is executed\n";};

// Parameterized Constructor
CLOCK::CLOCK(struct Clock clk) {
	CLOCK::fout 	= clk.fout;	// 
	CLOCK::control_volt	= clk.control_volt;	
};
       
//~ float CLOCK::setFout(float f){ fout = f; return fout; }; 	     
//~ float CLOCK::setCVolt(float cv){ control_volt = cv; return control_volt; }; 
	
/// Main ///
int main(int argc, char const *argv[]) {
	
	CLOCK::Clock testStruct = {4.8,0.5};
	CLOCK t1 = CLOCK();
	CLOCK t2 = CLOCK(testStruct);
	t1.setFout(1.2);
	t1.getFout();
	t1.setCVolt(1.2);
	t1.getCVolt();
		
	t2.getFout();
	t2.getCVolt();
	
	t2.setFout(0.6);
	t2.getFout();
	t2.setCVolt(0.6);
	t2.getCVolt();
	
	return 0;
}
