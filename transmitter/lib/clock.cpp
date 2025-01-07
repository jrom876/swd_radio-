
//	Package:	sw_def_radio
//	File:		clock.c
// 	Purpose:	Define the Transmitter's Attenuator Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "clock.hpp"
using namespace std;

/// STANDARD DEFINITIONS FOR PROJECT SCICALC 
#define PI	3.14159265358979323846 // ad infinitum
#define LIGHT_SPEED		299792458 // meters per second
#define DATA_SIZE 1000
#define DELTA 1.0e-6
#define KILO 1000
#define MEGA 1000000
#define GIGA 1000000000
#define TERA 1000000000000 

/////////////
// Globals //
/////////////
float tempf;	// Needed for writing data to file
CLOCK::Clock DUMMY_CLOCK = {10.0,0.5};

// Default Constructor
CLOCK::CLOCK() {
	CLOCK::clock	= DUMMY_CLOCK;
	CLOCK::fout 	= 10.0; // MHz
	CLOCK::cvolt 	= 0.5; 	// VDC
};

// Parameterized Constructor
CLOCK::CLOCK(struct Clock clk) {
	CLOCK::clock	= clk;
	CLOCK::fout 	= clk.fout;	// 
	CLOCK::cvolt	= clk.cvolt;	
};
       
float CLOCK::setCVolt(float cv){ cvolt = cv; return cvolt; }; 
	
/// Main ///
int main(int argc, char const *argv[]) {
	CLOCK::Clock testStruct = {12.5,0.75};
	CLOCK t1 = CLOCK();
	CLOCK t2 = CLOCK(testStruct);
	t1.setCVolt(1.4);
	t1.getCVolt();
	t2.setCVolt(2.8);
	t2.getCVolt();
	
	return 0;
}
