
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
#include "tools.hpp"
using namespace std;

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
OUTAMP::~OUTAMP() {std::cout << "Output Amp Destructor is executed\n";};

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

 
float OUTAMP::getFreq() 	{ printf("\nOutput amp Frequency:\t%.2f\n",freq); 		return freq; }         
float OUTAMP::getPwrLimit() { printf("Output amp Power Limit:\t%.2f\n",pwr_limit); 	return pwr_limit; }         
float OUTAMP::getGain() 	{ printf("Output amp Gain Limit:\t%.2f\n",gain);		return gain; } 
float OUTAMP::getNoise() 	{ printf("Output amp Noise:\t%f\n",noise); 				return noise; }   
       

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
