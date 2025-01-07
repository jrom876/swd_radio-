
//	Package:	sw_def_radio
//	File:		dds.c
// 	Purpose:	Define the Transmitter's Direct Digital Synthesizer Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "dds.hpp"
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
DDS::DDSynth DUMMY_DDS = {0.3,1.2,1};

// Default Constructor
DDS::DDS() {
	DDS::dds		= DUMMY_DDS;
	DDS::clk_in		= 0.3; // GHz
	DDS::fout 		= 10.0; // GHz
	DDS::selector 	= 1; 	// 1 to 8
};

// DESTRUCTOR
DDS::~DDS() {};

// Parameterized Constructor
DDS::DDS(struct DDSynth dds) {
	DDS::dds		= dds;
	DDS::clk_in 	= dds.clk_in;	 
	DDS::fout 		= dds.fout;	 
	DDS::selector 	= dds.selector;	
};
       
float DDS::setClkIn(float c)	{ clk_in = c; return clk_in; };       
float DDS::setFout(float f)		{ fout = f; return fout; };        
float DDS::setSelector(float s)	{ selector = s; return selector; }; 
	
/// Main ///
int main(int argc, char const *argv[]) {
	
	DDS::DDSynth testStruct = {0.3,12.5,4};
	DDS t1 = DDS();
	
	printf("\nStarting DDS test:\n");
	t1.getClkIn();
	t1.getFout();
	t1.getSelector();
		
	printf("\nModifying Values\n");
	t1.setClkIn(0.5);
	t1.getClkIn();
	t1.setFout(1.4);
	t1.getFout();
	t1.setSelector(2);
	t1.getSelector();	
	printf("\nAfter that\n");
	
	DDS t2 = DDS(testStruct);	
	printf("\nNew test using teststruct\n");
	t2.setClkIn(0.5);
	t2.getClkIn();
	t2.setFout(1.4);
	t2.getFout();
	t2.setSelector(2);
	t2.getSelector();
	
	printf("\nAfter modifying it\n");
	
	
	return 0;
}
