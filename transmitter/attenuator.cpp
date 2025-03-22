
//	Package:	sw_def_radio
//	File:		attenuator.cpp
// 	Purpose:	Define the Transmitter's Attenuator Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <sstream>

#include <bitset>
#include <iostream>
#include <cstdint>

#include "attenuator.hpp"
#include "tools.hpp"
using namespace std;

/////////////
// Globals //
/////////////
float tempf;	// Needed for writing data to file
ATTENUATOR::Attenuator DUMMY_ATT = {1,0};

// Default Constructor
ATTENUATOR::ATTENUATOR() {
	ATTENUATOR::sig_in 		= 1; 	// GHz
	ATTENUATOR::atten 		= 0x01; // hex value
	ATTENUATOR::mask 		= 0xFF; // hex value
	ATTENUATOR::sig_out 	= (sig_in * GIGA)/(ATTENUATOR::atten & ATTENUATOR::mask); 	// GHz
};

// DESTRUCTOR
ATTENUATOR::~ATTENUATOR() {std::cout << "Attenuator Destructor is executed\n";};

// Parameterized Constructor
ATTENUATOR::ATTENUATOR(struct Attenuator att) {
	ATTENUATOR::sig_in	 	= att.sig_in;	// 
	ATTENUATOR::atten 		= att.atten;	// 
	ATTENUATOR::mask 		= att.mask;	// 
	ATTENUATOR::sig_out 	= att.sig_out;	// 
};
        
void ATTENUATOR::setSig(float s)	{ sig_in = s; };          
void ATTENUATOR::setAtten(float a)	{ atten = a; };         
void ATTENUATOR::setMask(float m)	{ mask = m; };
void ATTENUATOR::setSout(float f)	{ sig_out = f; }; 
	
/// Main ///
int main(int argc, char const *argv[]) {
	ATTENUATOR::Attenuator testStruct = {1.5, 0xFF, 0x04, (testStruct.sig_in/(testStruct.atten & testStruct.mask))};
	ATTENUATOR t1 = ATTENUATOR();
	ATTENUATOR t2 = ATTENUATOR(testStruct);
	//~ t1.setFin(2.1);
	t1.getSig();
	//~ t1.setAtten(64);
	t1.getAtten();
	
	//~ t2.setFin(2.8);
	t2.getSig();
	//~ t2.setAtten(128);
	t2.getAtten();
	t2.getMask();
	t2.getSout();
	
	return 0;
}
