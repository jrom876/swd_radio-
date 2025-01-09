
//	Package:	sw_def_radio
//	File:		attenuator.cpp
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

//////////////////
// Constructors //
//////////////////

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
	ATTENUATOR::atten 	= att.atten;	// 
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
