
//	Package:	sw_def_radio
//	File:		filter.cpp
// 	Purpose:	Define the Transmitter's Filter Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "filter.hpp"
#include "tools.hpp"
using namespace std;

/////////////
// Globals //
/////////////
float tempf;	// Needed for writing data to file
FILTER::Filter DUMMY_FILTER = {1.2,250,20,-85,50, 0.12};

// Default Constructor
FILTER::FILTER() {	
	FILTER::freq_in		= 1.2; 	// Current freq setting in GHz
	FILTER::pwr_limit	= 25; 	// Power limit in Watts
	FILTER::gain		= 27; 	// gain or loss in dB
	FILTER::noise		= -85; 	// noise in dB
	FILTER::freq_out	= 1.2;	// Attenuated output signal
	FILTER::bandwidth	= 0.12;	// Bandwidth	
};

// DESTRUCTOR
FILTER::~FILTER() {std::cout << "Filter Destructor is executed\n";};

// Parameterized Constructor
FILTER::FILTER(struct Filter filt) {
	FILTER::freq_in		= filt.freq_in;		// Current freq setting in GHz
	FILTER::pwr_limit	= filt.pwr_limit; 	// Power limit in Watts
	FILTER::gain		= filt.gain; 		// gain or loss in dB
	FILTER::noise		= filt.noise; 		// noise in dB
	FILTER::freq_out	= filt.freq_out;	// Attenuated output signal	
	FILTER::bandwidth	= filt.bandwidth;	// Bandwidth		
};
  
//~ float FILTER::setFreq		(float f)	{ freq_in = f; 		return freq_in; };        
//~ float FILTER::setPwrLimit	(float p)	{ pwr_limit = p; 	return pwr_limit; };       
//~ float FILTER::setGain		(float g)	{ gain = g; 		return gain; };        
//~ float FILTER::setNoise		(float n)	{ noise = n; 		return noise; };  
//~ float FILTER::setFout		(float f)	{ freq_out = f; 	return freq_out; }; 
//~ float FILTER::setBW			(float f)	{ bandwidth = f; 	return bandwidth; }; 

void showFilterElements (FILTER t1) {
	t1.getFreq();
	t1.getPwrLimit();
	t1.getGain();
	t1.getNoise();
	t1.getBW();
}
		
/// Main ///
int main(int argc, char const *argv[]) {
	
	FILTER t1 = FILTER();	
		
	showFilterElements(t1);
	
	t1.setFreq(1.4);
	t1.getFreq();
	t1.setPwrLimit(500);
	t1.getPwrLimit();
	t1.setGain(30);
	t1.getGain();
	t1.setNoise(-95);
	t1.getNoise();
	t1.setBW(0.06);
	t1.getBW();
	
	showFilterElements(t1);
	
	FILTER::Filter testStruct = {1.2,250,20.0,-85};
	FILTER t2 = FILTER(testStruct);	
	//~ showFilterElements(t2);
	
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
