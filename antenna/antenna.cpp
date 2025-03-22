
//	Package:	sw_def_radio
//	File:		antenna.c
// 	Purpose:	Define the Antenna Class
// 	Author:		jrom876

///*************
///	THE ANTENNA
///*************

/**
 * 	ANTENNA APERATURE EQUATIONS
 * 	https://www.antenna-theory.com/basics/aperature.php
 * 	
 * 	Tx Power = power density * effective aperature
 * 	Ptx = p * Aeff
 * 
 * 	Aeff = ((lam^2)/(4*pi)) * Gain
 *		 = ((c^2)/(4*pi*f)) * Gain
 * 	
 * 	ANTENNA POLARIZATION EQUATIONS
 * 	https://www.antenna-theory.com/basics/polarization.php
 * 	
 * 	Linear Polarization
 * 	E = cos(2*PI*f*(t-(z/c)))*xhat
 * 
 * 	Circular Polarization
 * 	E = cos(2*PI*f*(t-(z/c)))*xhat + sin(2*PI*f*(t-(z/c)))*yhat
 * 
 * 	Elliptical Polarization
 * 	E = xcoeff*cos(2*PI*f*(t-(z/c)))*xhat + ycoeff*sin(2*PI*f*(t-(z/c)))*yhat
 * **/
 
// https://www.random-science-tools.com/electronics/friis.htm
// https://www.antenna-theory.com/basics/friis.php
// https://rfcafe.com/references/electrical/ew-radar-handbook/two-way-radar-equation.htm

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "antenna.hpp"
using namespace std;

/// C Libraries
#include <math.h>
#include <check.h>
#include <float.h>	// For FLT_EPSILON

/// STANDARD DEFINITIONS FOR PROJECT SCICALC 
#define PI	3.14159265358979323846 // ad infinitum
#define LIGHT_SPEED		299792458 // meters per second
#define DATA_SIZE 1000
#define DELTA 1.0e-6
#define KILO 1000
#define MEGA 1000000
#define GIGA 1000000000
#define TERA 1000000000000 
#define TXT_FILE_LB "linkBudgetData.txt"

#define PLF(deg) pow(cos(deg*(PI/180)),2) 	// Polarization Loss Factor
#define FRBW(frange,cfreq) (frange/cfreq)	// Fractional Bandwidth of Antenna
#define UV_MAG(x,y,z) sqrt((x*x)+(y*y)+(z*z)) // Unit Vector Magnitude
#define MAX_NUM 100	// The maximum number of iterations

/////////////
// Globals //
/////////////
float freqGHz, txpwrW, distTargetKM;
float radarXSect, antGain;
//~ float PLF = 0; // Polarization Loss Factor
float tempf;	// Needed for writing data to file
//int exitFlag = 0;


// Default Constructor
ANTENNA::ANTENNA() {
	pol = horiz; 	// Antenna Polarization
	type = mono;	// Antenna Type
	gain = 1.0; 	// Gain of RX Antenna in dB
	freq = 1.0;		// Center Frequency in MHz
	eff = 0.0;		// Antenna Efficiency %
	bw = 1.0;		// Antenna Bandwidth
	area = 1;		// Effective Aperature Area
	zin = 50.0;		// Impedance of Antenna
};

// Parameterized Constructor
ANTENNA::ANTENNA(enum ANT_POL p,enum ANT_TYPE t,float g,float f,float e,float b,float a,float z) {
	pol 	= p; 	// Antenna Polarization
	type 	= t;	// Antenna Type
	gain 	= g; 	// Gain of RX Antenna in dB
	freq 	= f;	// Center Frequency in MHz
	eff 	= e;	// Antenna Efficiency %
	bw 		= b;	// Antenna Bandwidth
	area 	= a;	// Effective Aperature Area
	zin 	= z;	// Impedance of Antenna
};

// Antenna Gain - calculated using frequency
float ANTENNA::antGainFromFreqGHz(float efficiency, float aperature_area, float freqGHz){
	float lam = LIGHT_SPEED/(freqGHz*GIGA);
	//~ float lam = getLambda(freq);
	float antgain = ((10*log10((efficiency*4*PI*aperature_area)/(lam*lam))));
	printf("Antenna Gain = %f\n\n",antgain); // DBPRINT
	return antgain;
};

/// Aeff = ((lam^2)/(4*pi)) * Gain
/// Aeff = ((c^2)/(4*pi*f)) * Gain	
// Antenna Aeff - Effective Aperature Area
float ANTENNA::calcAeff(float freqGHz){
	float lam = LIGHT_SPEED/(freqGHz*GIGA);
	float gainer = getGain();
	float aeff_result = gainer*((lam*lam)/(4*PI));
	printf("Antenna Effective Area = %f\n\n",aeff_result); // DBPRINT
	return aeff_result;
};
           
float ANTENNA::setPol(enum ANT_POL p){pol = p;return pol;};          
float ANTENNA::setType(enum ANT_TYPE t){type = t;return type;};          
float ANTENNA::setGain(float g){gain = g;return gain;};           
float ANTENNA::setFreq(float f){freq = f;return freq;};          
float ANTENNA::setEff(float e){eff = e;return eff;};  
float ANTENNA::setBW(float b){bw = b;return bw;};
float ANTENNA::setArea(float a){area = calcAeff(getFreq());return area;};           
float ANTENNA::setZin(float z){zin = z;return zin;};
            
/// Main ///
int main(int argc, char const *argv[]) {
	ANTENNA ant1 = ANTENNA();
	ANTENNA ant2 = ANTENNA(
					ANTENNA::horiz, // Polarity
					ANTENNA::mono,	// Type
					1.0,			// Gain
					2.4,			// Freq
					0.9,			// Efficiency
					1.0,			// Bandwidth
					1.0,			// Aperature Effective Area
					50.0);			// Impedance
	
	//~ ant1.setPol(ant1.getPol());
	//~ ant1.setType(ant1.getType());
	ant1.setEff(0.9); ant1.setArea(3); ant1.setFreq(2.4);
	//~ ant1.setArea(ant1.calcAeff(ant1.freq));
	ant1.setGain(ant1.antGainFromFreqGHz(ant1.eff, ant1.area, ant1.freq));
	
	//~ ant2.setArea(ant2.calcAeff(ant2.freq));
	//~ ant2.setGain(ant2.antGainFromFreqGHz(ant2.getEff(), ant2.getArea(), ant2.getFreq()));
	ant2.setGain(ant2.antGainFromFreqGHz(ant2.eff, ant2.area, ant2.freq));
	
	return 0;
}


//~ struct UNIT_VECTOR {
	//~ float 	x_val;	// x coordinate / magnitude
	//~ float 	y_val;	// y coordinate / magnitude
	//~ float 	z_val;	// z coordinate / magnitude
	//~ float 	mag;	// magnitude
//~ };

// Functions //
