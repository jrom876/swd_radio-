
//	Package:	sw_def_radio
//	File:		preamp.cpp
// 	Purpose:	Define the Transmitter's Preamplifier Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "preamp.hpp"
#include "tools.hpp"
using namespace std;


/////////////
// Globals //
/////////////
float tempf;	// Needed for writing data to file
PREAMP::Preamp DUMMY_PREAMP = {1.2,250,20,-85,1.2};

// Default Constructor
PREAMP::PREAMP() {
	PREAMP::freq		= 1.2; 	// Current freq setting in GHz
	PREAMP::pwr_limit	= 250; 	// Power limit in Watts
	PREAMP::gain		= 20; 	// gain in dB
	PREAMP::noise		= -85; 	// noise in dB
	PREAMP::fout		= freq ;	// Impedance, assume 50 Ohms
};

// DESTRUCTOR
PREAMP::~PREAMP() {std::cout << "Preamp Destructor is executed\n";};

// Parameterized Constructor
PREAMP::PREAMP(struct Preamp pamp) {
	PREAMP::freq		= pamp.freq; 		// Current freq setting in GHz
	PREAMP::pwr_limit	= pamp.pwr_limit; 	// Power limit in Watts
	PREAMP::gain		= pamp.gain; 		// gain in dB
	PREAMP::noise		= pamp.noise; 		// noise in dB
	PREAMP::fout		= pamp.fout;		// Impedance, assume 50 Ohms	
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
