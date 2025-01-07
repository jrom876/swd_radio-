
//	Package:	sw_def_radio
//	File:		attenuator.c
// 	Purpose:	Define the Transmitter's Attenuator Class
// 	Author:		jrom876

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "attenuator.hpp"
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
ATTENUATOR::Attenuator DUMMY_ATT = {1,0};

// Default Constructor
ATTENUATOR::ATTENUATOR() {
	ATTENUATOR::attenuator	= DUMMY_ATT;
	ATTENUATOR::freq_in 	= 1; 	// GHz
	ATTENUATOR::atten 		= 0; 	// dB
};

// DESTRUCTOR
ATTENUATOR::~ATTENUATOR() {};

// Parameterized Constructor
ATTENUATOR::ATTENUATOR(struct Attenuator att) {
	ATTENUATOR::attenuator	= att;
	ATTENUATOR::freq_in 	= att.freq_in;	// 
	ATTENUATOR::atten 		= att.atten;	// 
};
        
float ATTENUATOR::setFin(float f)	{ freq_in = f; 	return freq_in;	};          
float ATTENUATOR::setAtten(float a)	{ atten = a;	return atten; };
	
/// Main ///
int main(int argc, char const *argv[]) {
	ATTENUATOR::Attenuator testStruct = {1.2,1};
	ATTENUATOR t1 = ATTENUATOR();
	ATTENUATOR t2 = ATTENUATOR(testStruct);
	t1.setFin(2.1);
	t1.getFin();
	t1.setAtten(64);
	t1.getAtten();
	
	t2.setFin(2.8);
	t2.getFin();
	t2.setAtten(128);
	t2.getAtten();
	
	return 0;
}
