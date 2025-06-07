
//	Package:	sw_def_radio
//	File:		signal.cpp
// 	Purpose:	Define the Transmitter's Attenuator Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <sstream>

#include <bitset>
#include <iostream>
#include <cstdint>

#include "signal.hpp"
#include "tools.hpp"
using namespace std;

/////////////
// Globals //
/////////////
float tempf;	// Needed for writing data to file

// DEFAULT CONSTRUCTOR
SIGNAL::SIGNAL() {
	SIGNAL::freq 	= 4.8; 		// GHz
	SIGNAL::amp 	= 0.25; 	// mVpp
	SIGNAL::bw 	= freq/10; 	// GHz
	SIGNAL::modul 	= 1; 		// Modulation Type
	SIGNAL::id 	= 0x01;		// unique identifier
};

// DESTRUCTOR
SIGNAL::~SIGNAL() {std::cout << "Signal Destructor is executed\n";};

SIGNAL::SIGNAL(struct Signal sig) {
	SIGNAL::freq 	= sig.freq;	
	SIGNAL::amp 	= sig.amp;	 
	SIGNAL::bw 	= sig.bw;	
	SIGNAL::modul 	= sig.modul;
	SIGNAL::id 	= sig.id;
};
        
void SIGNAL::setFreq(float f)	{ freq = f; };          
void SIGNAL::setAmp(float a)	{ amp = a; };         
void SIGNAL::setBW(float b)	{ bw = b; };
void SIGNAL::setMod(int m)	{ modul = m; }; 
void SIGNAL::setID(uint8_t i) 	{ id = i; }; 
	
/// Main ///
int main(int argc, char const *argv[]) {
	
	/// Testing First Signal
	printf("\nTesting First Signal\n");
	SIGNAL s1 = SIGNAL();	
	
	//~ t1.setFreq(4.8);
	//~ t1.setAmp(1.17);
	//~ t1.setBW(64);
	//~ t1.setMod(3);
	//~ s1.setID(0x07);
	
	s1.getFreq();
	s1.getAmp();
	s1.getBW();
	s1.getMod();
	s1.getID();
	
	printf("\nChanging First Signal Parameters\n");
	s1.setFreq(5.0);
	s1.setAmp(1.17);
	s1.setBW(s1.freq/10);
	s1.setMod(2);
	s1.setID(0x07);
	
	s1.getFreq();
	s1.getAmp();
	s1.getBW();
	s1.getMod();
	s1.getID();
	
	/// Testing Second Signal
	printf("\n\nTesting Second Signal\n");
	
	float testFreq = 4.8;
	float testAmp = 0.75;
	float testBW = testFreq/10;
	int testMod = 1;
	uint8_t testID = 0x02;
	SIGNAL::Signal testStruct = {testFreq, testAmp, testBW, testMod, testID};
	SIGNAL s2 = SIGNAL(testStruct);
	
	//~ t2.setFreq(2.4);
	//~ t2.setAmp(1.28);
	//~ t2.setBW(64);
	//~ t2.setMod(3);
	//~ s2.setID(0x05);
	
	s2.getFreq();
	s2.getAmp();
	s2.getBW();
	s2.getMod();
	s2.getID();
		
	printf("\nChanging Second Signal Parameters\n");
	s2.setFreq(2.4);
	s2.setAmp(1.28);
	s2.setBW(s2.freq/20);
	s2.setMod(3);
	s2.setID(0x05);
	
	s2.getFreq();
	s2.getAmp();
	s2.getBW();
	s2.getMod();
	s2.getID();
	
	return 0;
}
