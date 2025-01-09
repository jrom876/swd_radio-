
//	Package:	sw_def_radio
//	File:		dds.cpp
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
#define PI		3.14159265358979323846 	// ad infinitum sine repeto
#define LIGHT_SPEED	299792458.0 		// meters per second
#define STACK_OVERFLOW	2147483648		// Hex 0x80000000
#define DATA_SIZE 1000
#define DELTA 1.0e-6
#define MILLI 1.0e-3
#define MICRO 1.0e-6
#define NANO 1.0e-9
#define PICO 1.0e-12
#define KILO 1.0e3
#define MEGA 1.0e6
#define GIGA 1.0e9
#define TERA 1.0e12 
#define true 1
#define false 0

/// STANDARD DEFINITIONS FOR LIGHT INTENSITY AND ELECTRIC FIELD CALCULATIONS
#define AIR_REFRACTIVE_INDEX 1.00027717
#define E0 8.8541878128*PICO				// Permittivity of Free Space in Farads per meter
#define MU0 1.25663706212*MICRO				// Permeability of Free Space in Newtons per square meter
#define EPSILON_0 1/(MU0*(LIGHT_SPEED*LIGHT_SPEED))	// Permittivity of Free Space Equation
#define E_CONSTANT 1/(4*PI*EPSILON_0)
#define ELECTRON_CHARGE 1.6e-19 			// Charge of an electron in Coulombs
#define RADIUS_HELIUM_ATOM 26.5e-12			// Radius of a Helium atom in meters 

/////////////
// Globals //
/////////////
float tempf;	// Needed for writing data to file

DDS::DDSynth DUMMY_DDS = {0.3,1.2,1};

// Default Constructor
DDS::DDS() {
	DDS::dds		= DUMMY_DDS;
	DDS::clk_in		= 0.3;  // GHz
	DDS::fout 		= 10.0; // GHz
	DDS::selector 		= 1; 	// 1 to 8
};

// DESTRUCTOR
DDS::~DDS() {};

// Parameterized Constructor
DDS::DDS(struct DDSynth dds) {
	DDS::dds	= dds;
	DDS::clk_in 	= dds.clk_in;	 
	DDS::fout 	= dds.fout;	 
	DDS::selector 	= dds.selector;	
};
       
float DDS::setClkIn(float c)	{ clk_in = c; return clk_in; };       
float DDS::setFout(float f)	{ fout = f; return fout; };        
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
