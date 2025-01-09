
//	Package:	sw_def_radio
//	File:		outamp.cpp
// 	Purpose:	Define the Transmitter's Output Amplifier Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "outamp.hpp"
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

OUTAMP::Outamp DUMMY_OUTAMP = {1.2,250,20,-85,50};

// Default Constructor
OUTAMP::OUTAMP() {
	OUTAMP::outamp		= DUMMY_OUTAMP;	
	OUTAMP::freq		= 1.2; 		// Current freq setting of TX Output Amp
	OUTAMP::pwr_limit	= 250; 		// Power limit in Watts
	OUTAMP::gain		= 35; 		// Output Amp gain in dB
	OUTAMP::noise		= -85; 		// Output Amp noise in dB
	OUTAMP::zout		= 50;		// Output Impedance, assume 50 Ohms
};

// DESTRUCTOR
OUTAMP::~OUTAMP() {};

// Parameterized Constructor
OUTAMP::OUTAMP(struct Outamp oamp) {
	OUTAMP::outamp		= oamp;
	OUTAMP::freq		= oamp.freq; 		// Current freq setting of TX Output Amp
	OUTAMP::pwr_limit	= oamp.pwr_limit; 	// Power limit in Watts
	OUTAMP::gain		= oamp.gain; 		// Output Amp gain in dB
	OUTAMP::noise		= oamp.noise; 		// Output Amp noise in dB
	OUTAMP::zout		= oamp.zout;		// Output Impedance, assume 50 Ohms
};
 
float OUTAMP::setFreq		(float f)	{ freq = f; 		return freq; };        
float OUTAMP::setPwrLimit	(float p)	{ pwr_limit = p; 	return pwr_limit; };       
float OUTAMP::setGain		(float g)	{ gain = g; 		return gain; };        
float OUTAMP::setNoise		(float n)	{ noise = n; 		return noise; };  
	
/// Main ///
int main(int argc, char const *argv[]) {
	
	OUTAMP t1 = OUTAMP();
	t1.setFreq(1.4);
	t1.getFreq();
	t1.setPwrLimit(500);
	t1.getPwrLimit();
	t1.setGain(30);
	t1.getGain();
	t1.setNoise(-95);
	t1.getNoise();
	
	OUTAMP::Outamp testStruct = {1.2,250,20.0,-85};
	OUTAMP t2 = OUTAMP(testStruct);	
	t2.setFreq(2.4);
	t2.getFreq();
	t2.setPwrLimit(350);
	t2.getPwrLimit();
	t2.setGain(43);
	t2.getGain();
	t2.setNoise(-73);
	t2.getNoise();
	
	return 0;
}
