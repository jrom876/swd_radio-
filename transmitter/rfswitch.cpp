
//	Package:	sw_def_radio
//	File:		rfswitch.c
// 	Purpose:	Define the Transmitter's High Speed RF Switch Class
// 	Author:		jrom876

/**
 * REQUIREMENTS:
 * 	0. must have a setpoint or reference voltage and a way to change it
 * 	1. must have a pk-pk signal amplitude input
 * 	2. must have a compare() function to trigger switch
 * 	3. must have a toggle switch function
 * 	4. public setters and getters
 * 	5. private uint8_t attenuator output to ATTENUATOR objects
 * 	6. assume neglegible pass through attenuation
 * 	7. assume 50 Ohms input and output Impedance
 * **/

// g++ -g -std=c++20 -o rfswitch rfswitch.cpp -lm -lrt
// https://en.cppreference.com/w/cpp/utility/bitset

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <bitset>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <sstream>
#include "rfswitch.hpp"
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

////////////////////////
/// CREATING OBJECTS ///

RFSWITCH::RFSwitch DUMMY_SW = {1,1.6,true, 1.0, 0x77,0x5};

// Default Constructor
RFSWITCH::RFSWITCH() {
	RFSWITCH::freq_in 	= 1.2; 		// GHz
	RFSWITCH::ampl_in 	= 0.707; 	// amplitude of input signal
	RFSWITCH::swt	 	= false;	// switch state, On/Off
	RFSWITCH::setpt 	= 1.0;		// set point reference voltage
	RFSWITCH::atten 	= 0x0; 		// uint8_t 8-bit attenuator outputmask
	RFSWITCH::mask 		= {0x55};	// set point bitset<16> output
};

// DESTRUCTOR
RFSWITCH::~RFSWITCH() {};

// Parameterized Constructor
RFSWITCH::RFSWITCH(struct RFSwitch att) {
	RFSWITCH::freq_in 	= att.freq_in;	// 
	RFSWITCH::ampl_in 	= att.ampl_in;	// 
	RFSWITCH::swt 		= att.swt;		//		
	RFSWITCH::setpt 	= att.setpt;	//		
	RFSWITCH::atten 	= att.atten;	//		
	RFSWITCH::mask 		= att.mask;		//	
};

/////////////////////////
/// SETTERS - virtual ///
          
void RFSWITCH::setFin(float f)	{ 
	RFSWITCH::freq_in = f;
	//~ printf("%.2f\n",freq_in);
}; 
       
void RFSWITCH::setAtten(uint8_t a)	{ 
	RFSWITCH::atten = a;
	//~ printf("%.2f\n",atten);
}; 
     
void RFSWITCH::setSwitch(bool s)	{ 
	RFSWITCH::swt = s;
	//~ printf("%d\n",swt);
}; 
         
void RFSWITCH::setPt(float sp)	{ 
	RFSWITCH::setpt = sp;
	//~ printf("%.2f\n",setpt);
}; 
             
void RFSWITCH::setAmpIn(float ain)	{ 
	RFSWITCH::ampl_in = ain;
}; 
       
void RFSWITCH::setMask(std::bitset<8> m)	{ 
	RFSWITCH::mask = m;
	//~ printf("mask = %.2f\n",mask);
	//~ cout << "Setting Point in bitset<8>: " << mask << endl;
}; 
 
///////////////
/// GETTERS ///
     
float RFSWITCH::getFin() { 
	printf("\nRFSwitch freq_in:\t%.2f\n",RFSWITCH::freq_in);	// DBPRINT
	return RFSWITCH::freq_in; 
}; 

uint8_t RFSWITCH::getAtten() { 
	printf("RFSwitch atten:\t\t%d\n",RFSWITCH::atten);	// DBPRINT
	return RFSWITCH::atten; 
} 
  
bool RFSWITCH::getSwitch() { 
	printf("RFSwitch swt:\t\t%d\n",RFSWITCH::swt);	// DBPRINT
	return RFSWITCH::swt; 
}; 
    
float RFSWITCH::getPt() { 
	printf("RFSwitch setpt:\t\t%.2f\n",RFSWITCH::setpt); // DBPRINT
	return RFSWITCH::setpt; 
}; 

float RFSWITCH::getAmpIn() { 
	printf("RFSwitch ampl_in:\t%.2f dBm\n",RFSWITCH::ampl_in);	// DBPRINT
	return RFSWITCH::ampl_in; 
};

std::bitset<8> RFSWITCH::getMask() { 
	cout << "Mask in bitset<8>: " << RFSWITCH::mask << endl; // DBPRINT
	return RFSWITCH::mask; 
};
  
/////////////////////
/// dB converters ///

float dBm_to_float (float dbm) {
	float result = pow(10,((dbm-30)/10));
	printf("%.2f dBm = %.2f W\n",dbm, result);	// DBPRINT
	return result;
}

float float_to_dBm (float flt) {
	float dbm = (10*(log10(flt))) + 30;
	printf("%.2f W = %.2f dBm\n",flt, dbm);	// DBPRINT
	return dbm;
}

float dB_to_float (float db) {
	float result = pow(10,((db)/10));
	printf("%.2f dB = %.2f Watts\n",db, result); 	// DBPRINT
	return result;
}

float float_to_dB (float flt) {
	float db = (10*(log10(flt)));
	printf("%.2f Watts = %.2f dB\n",flt, db); 	// DBPRINT
	return db;
}

///////////////////////
/// Flip the Switch ///

bool RFSWITCH::flip_switch () {
	//~ printf("swt before:\t\t%d\n",RFSWITCH::swt); // DBPRINT
	RFSWITCH::swt = !RFSWITCH::swt;
	//~ printf("swt after:\t\t%d\n",RFSWITCH::swt); // DBPRINT
	return swt;
}

bool checkFreqRange(float bw, float freq) {
	bool result = ((freq<=(freq+(bw/2))) && (freq >=(freq-(bw/2))));
	printf("Is freq in Range? = %d\n", result);	// DBPRINT
	return result;
	//~ return ((freq<=(freq+(bw/2))) && (freq >=(freq-(bw/2))));;
}

float getFreqRange(float low, float hi) {
	float diff = hi - low;
	printf("diff = %.2f",diff);	// DBPRINT
	return (diff);
	//~ return (hi - low);
}

/////////////////////////////////
/// Compare Signals - virtual ///

// These virtual comparators have a 5% hysteresis, meaning they toggle the switch
// at (setpoint - 5%) = 95% of the setpoint to allow for overdamped responses.
// We do not toggle at (setpoint + 5% because our signal must never get that high.

bool RFSWITCH::compare_ain_to_setpt() {	
	bool match = false;
	float hysteresis = 0.05;
	float ain = dBm_to_float(RFSWITCH::ampl_in);	
	
	if (ain >= (RFSWITCH::setpt * (1 - hysteresis))) {
		match = true; 
		printf("match:\t\t%d\n",match);	// DBPRINT
	}
	else if (ain < (RFSWITCH::setpt * (1 - hysteresis))) {
		match = false; 
		printf("match:\t\t%d\n",match);	// DBPRINT	
	}	
	return match;
	//~ return (dBm_to_float(RFSWITCH::ampl_in >= RFSWITCH::setpt);
}

bool RFSWITCH::compare_ain_to_setpt(float ain, float sp, float hys) {
	bool match = false;
	float hysteresis = hys;
	ain = dBm_to_float(ain);
	
	if (ain >= (sp * (1 - hysteresis))) {
		match = true; 
		printf("match:\t\t%d\n",match);	// DBPRINT
	}
	else if (ain < (sp * (1 - hysteresis))) {
		match = false; 
		printf("match:\t\t%d\n",match);	// DBPRINT
	}
	return match;
}
/////////////////////////////////
/////////////////////////////////

////////////
/// Main ///

int main(int argc, char const *argv[]) {
	
	/// testing bitset masks ///	
    //~ bitset<8> decimalBitset(15);
    //~ bitset<8> testBitset(0);
    //~ decimalBitset = (decimalBitset |= 0x53) &= 0xF2;
    //~ testBitset = (testBitset |= 0xFF) &= 0x07;    
    //~ cout << "decimalBitset: " << decimalBitset << endl;
    //~ cout << "testBitset: " << testBitset << endl;
    //~ cout << "testBitset[]: " << (testBitset &= decimalBitset) << endl;
    ////~ cout << "testBitset[]: " << (testBitset &= 0x3FEE) << endl;    
	/// end of testing bitset masks /// 
    
    // create test objects
	RFSWITCH::RFSwitch testStruct = {1.2,1};
	RFSWITCH t1 = RFSWITCH();
	RFSWITCH t2 = RFSWITCH(testStruct);
	RFSWITCH t3 = RFSWITCH(DUMMY_SW);
	
	// test converter functions ///	
	//~ dBm_to_float(40.0);	
	//~ float_to_dBm(10.0);   	
	/// end of testing converter functions /// 
		
	/// test battery ///	
	
	t1.setFin(2.1);
	t1.getFin();	
	t1.setAmpIn(float_to_dBm(1.60));
	t1.getAmpIn();
		
	t1.setSwitch(true);
	t1.getSwitch();
	//~ t1.flip_switch ();
	//~ t1.flip_switch ();
	t1.setPt(1.55);
	t1.getPt();

	t1.setAtten(64);
	t1.getAtten();
	t1.setMask(0x64);
	t1.getMask();

	//~ t1.compare_ain_to_setpt();
	t1.compare_ain_to_setpt(t1.getAmpIn(), t1.getPt(), 0.05);

	t3.setFin(37.5e6);
	t3.getFin();		
	t3.setAmpIn(float_to_dBm(14.0));
	t3.getAmpIn();
	
	t3.setSwitch(false);
	t3.getSwitch();
	t3.setPt(15.5);
	t3.getPt();
	
	t3.setAtten(128);
	t3.getAtten();
	t3.setMask(0xC3);
	t3.getMask();
	
	t3.compare_ain_to_setpt();
	//~ t3.compare_ain_to_setpt(t3.getAmpIn(), t3.getPt(), 0.05);
	
	//~ t2.setFin(2.8);
	//~ t2.getFin();
	//~ t2.setAtten(128);
	//~ t2.getAtten();
		
	//~ t2.setAmpIn(float_to_dBm(170.5));
	//~ t2.getAmpIn();
	//~ t2.setSetPt(0x0FFF);
	//~ t2.getSetPt();
	
	return 0;
}


// https://stackoverflow.com/questions/315948/c-catching-all-exceptions
// https://en.cppreference.com/w/cpp/language/catch

//~ try
//~ {
    //~ f();
//~ }
//~ catch (const std::overflow_error& e)
//~ {} // this executes if f() throws std::overflow_error (same type rule)
//~ catch (const std::runtime_error& e)
//~ {} // this executes if f() throws std::underflow_error (base class rule)
//~ catch (const std::exception& e)
//~ {} // this executes if f() throws std::logic_error (base class rule)
//~ catch (...)
//~ {} // this executes if f() throws std::string or int or any other unrelated typ


//// Comment these in for test
//~ int adc_value=2456, adc_min=0, adc_max=4096;
//~ float out_min=0, out_max=12, adcResult;
// adcResult = ( (((adc_value - adc_min)*(out_max-out_min)) / (adc_max-adc_min)) + out_min);




