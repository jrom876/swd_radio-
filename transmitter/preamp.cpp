
//	Package:	sw_def_radio
//	File:		preamp.c
// 	Purpose:	Define the Transmitter's Preamplifier Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "preamp.hpp"
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
PREAMP::Preamp DUMMY_PREAMP = {1.2,250,20,-85,50};

// Default Constructor
PREAMP::PREAMP() {
	PREAMP::preamp		= DUMMY_PREAMP;	
	PREAMP::freq		= 1.2; 	// Current freq setting in GHz
	PREAMP::pwr_limit	= 250; 	// Power limit in Watts
	PREAMP::gain		= 27; 	// gain in dB
	PREAMP::noise		= -85; 	// noise in dB
	PREAMP::zout		= 50;	// Impedance, assume 50 Ohms
};

// DESTRUCTOR
PREAMP::~PREAMP() {};

// Parameterized Constructor
PREAMP::PREAMP(struct Preamp pamp) {
	PREAMP::preamp		= pamp;	
	PREAMP::freq		= pamp.freq; 		// Current freq setting in GHz
	PREAMP::pwr_limit	= pamp.pwr_limit; 	// Power limit in Watts
	PREAMP::gain		= pamp.gain; 		// gain in dB
	PREAMP::noise		= pamp.noise; 		// noise in dB
	PREAMP::zout		= pamp.zout;		// Impedance, assume 50 Ohms	
};
  
float PREAMP::setFreq		(float f)	{ freq = f; 		return freq; };        
float PREAMP::setPwrLimit	(float p)	{ pwr_limit = p; 	return pwr_limit; };       
float PREAMP::setGain		(float g)	{ gain = g; 		return gain; };        
float PREAMP::setNoise		(float n)	{ noise = n; 		return noise; };  
		
/// Main ///
int main(int argc, char const *argv[]) {
	
	PREAMP t1 = PREAMP();
	t1.setFreq(1.4);
	t1.getFreq();
	t1.setPwrLimit(500);
	t1.getPwrLimit();
	t1.setGain(30);
	t1.getGain();
	t1.setNoise(-95);
	t1.getNoise();
	
	PREAMP::Preamp testStruct = {1.2,250,20.0,-85};
	PREAMP t2 = PREAMP(testStruct);	
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
