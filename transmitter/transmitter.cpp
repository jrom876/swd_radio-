
//	Package:	sw_def_radio
//	File:		transmitter.cpp
// 	Purpose:	Define the Transmitter Class and all of its modules
// 	Author:		jrom876

// https://www.antenna-theory.com/basics/friis.php
// https://stackoverflow.com/questions/559522/separate-header-files-for-concrete-classes-c
// https://stackoverflow.com/questions/18749375/c-calling-objects-from-another-class

///*************
///	THE TRANSMITTER
///*************
/**
 * Power Density: p = Pt/(4*PI*R^2)
 * 
 * p = (Pt/(4*PI*R^2)) * Gt
 * 
 * Pr = (PLF) * (Pt * Gt * Gr * c^2) / (4 * PI * R * freq)^2
 * 
 * 
 * **/

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "transmitter.hpp"
#include "attenuator.hpp"
#include "dds.hpp"
#include "clock.hpp"
#include "outamp.hpp"
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
#define TXT_FILE_LB "transmitter_data.txt"

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
TRANSMITTER::Transmitter DUMMY_TX = {1.0,1.0,0.1,0.1,1};	
OUTAMP::Outamp DUMMY_OUTAMP = {1.2,250,20,-85,50};

// Default Constructor
TRANSMITTER::TRANSMITTER() {
	TRANSMITTER::outamp = {1.2,250,35,-85.0,50}; 
	TRANSMITTER::preamp = {1.2,250,27,-85.0,50};
	TRANSMITTER::atten = {1.2,1.0,50.0};
	TRANSMITTER::dds = {1.2,1.2,2};
	TRANSMITTER::clock = {1.2, 2.5};
	TRANSMITTER::tx 		= DUMMY_TX;
	TRANSMITTER::freq 		= 1.2; 	// Current freq settingin GHz
	TRANSMITTER::gain 		= 62.0; // gain in dB
	TRANSMITTER::dist		= 50.0; // RX distance from Source
	TRANSMITTER::low		= 0.6;	// Lower edge of Bandwidth
	TRANSMITTER::high		= 1.8;	// Upper edge of Bandwidth
	TRANSMITTER::zout		= 50.0;	// Output Impedance in Ohms
	
};

// DESTRUCTOR
TRANSMITTER::~TRANSMITTER() {};

// Parameterized Constructor
TRANSMITTER::TRANSMITTER(struct Transmitter tx1) {
	TRANSMITTER::outamp 	= tx1.outamp;	// Test struct that holds our receiver data
	TRANSMITTER::preamp 	= tx1.preamp;	// Test struct that holds our receiver data
	TRANSMITTER::atten 		= tx1.atten;	// Test struct that holds our receiver data
	TRANSMITTER::dds 		= tx1.dds;		// Test struct that holds our receiver data
	TRANSMITTER::tx 		= tx1;			// Test struct that holds our receiver data
	TRANSMITTER::freq 		= freq; 		// Current freq setting of RX in GHz
	TRANSMITTER::gain 		= gain; 		// Current freq setting of RX in GHz
	TRANSMITTER::dist		= dist; 		// RX distance from Source
	TRANSMITTER::low		= low;		// Lower edge of Bandwidth of RX
	TRANSMITTER::high		= high;		// Upper edge of Bandwidth of RX
	TRANSMITTER::zout		= zout;		// Output Impedance in Ohms
	
};

// Parameterized Constructor
TRANSMITTER::TRANSMITTER(
	struct Output_Amp 	oa,
	struct Pre_Amp 		pa,
	struct Attenuator 	att,
	struct DDS 			dds,
	struct Clock 		clk) {
		TRANSMITTER::outamp 	= oa;	
		TRANSMITTER::preamp 	= pa;	
		TRANSMITTER::atten 		= att;	
		TRANSMITTER::dds 		= dds;		
		TRANSMITTER::clock 		= clk;	
};

// Parameterized Constructor
TRANSMITTER::TRANSMITTER(
	OUTAMP			oa, 
	PREAMP			pa,
	ATTENUATOR		att,
	DDS				ds,
	CLOCK			clk) {};
			
/** 
 *	One-way Path Loss, Received Signal Strength at Target 
**/

/** 
 * 	Friis Transmission Equation for
 *	Received Signal Strength at Target, One-way Path Loss
 * 	Pr = Pt * Gt * Gr * c^2 / (4Pi*R*freq)^2
**/

float TRANSMITTER::txPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq){
	float result = Pt*pow(10,log10(GtdB))*pow(10,log10(GrdB))
		*(pow(LIGHT_SPEED,2))/(pow((4*PI*(R*KILO)*(freq*GIGA)),2));
	printf("TX Power at antenna: \t%.2f pico-watts\n",result*TERA); // DBPRINT
	return result;
}

float TRANSMITTER::txPwrDBM(float PtxdBm, float GtxdB, float GrxdB, float dist, float freq){	
	float result;
	float tpwr = pow(10,((PtxdBm-30)/10))*pow(10,log10(GtxdB))
		*pow(10,log10(GrxdB))*(pow(LIGHT_SPEED,2))/(pow((4*PI*(dist*KILO)*(freq*GIGA)),2));
	printf("TX Power: \t%.8f dBW\n",(10*log10(tpwr))); // DBPRINT
	printf("TX Power: \t%.8f dBm\n",(10*log10(tpwr))+30); // DBPRINT
	printf("TX Power: \t%.8f dBp\n",(10*log10(tpwr))+120); // DBPRINT
	//~ printf("RX Power: \t%.8f pico-watts\n",rpwr*TERA); // DBPRINT
	result = (10*log10(tpwr))+30;
	//~ printf("result:\t%f\n",result); // DBPRINT
	return result;
}

//~ void TRANSMITTER::printRxDBM( float PtxdBm, float GtxdB, float GrxdB, float dist, float freq){
	//~ printf("\n%.4f\tPtdBm\n",PtxdBm);
	//~ printf("%.4f\tGtdb\n",GtxdB);
	//~ printf("%.4f\tGrdb\n",GrxdB);
	//~ printf("%.4f\tDistance km\n",dist);
	//~ printf("%.4f\tfreq GHz\n",freq);
	//~ getFresnelRadius(freq,dist);
//~ }
         
float TRANSMITTER::setFreq(float f)	{freq = f;return freq;};          
float TRANSMITTER::setGain(float g)	{gain = g;return gain;};          
float TRANSMITTER::setDist(float d)	{dist = d;return dist;};           
float TRANSMITTER::setLow(float l)	{low = l;return low;};          
float TRANSMITTER::setHigh(float h)	{high = h;return high;};          
float TRANSMITTER::setZout(float z)	{zout = z;return zout;};  

// https://stackoverflow.com/questions/13074590/listlist-names-the-constructor-not-the-type	 
/// Main ///
int main(int argc, char const *argv[]) {
	
	//~ TRANSMITTER::Transmitter testStruct = {100.0,10.0,10.0,0.5,1.2,50.0};
	TRANSMITTER t1 = TRANSMITTER();
	//~ TRANSMITTER t2 = TRANSMITTER(testStruct);	
	
	//~ OUTAMP::OUTAMP*  = new OUTAMP();
	//~ TRANSMITTER::Transmitter testStruct3 = {
		//~ TRANSMITTER::outamp	oamp = {1.2,500,10.0,-83.0,50.0}, 
		//~ TRANSMITTER::preamp	pamp = {1.2,500,10.0,-83.0,50.0},
		//~ TRANSMITTER::atten	att = {1.2,1.0,50.0},
		//~ TRANSMITTER::dds		ds = {0.15,[0,0,1,0,0,0,0,0],[1,0,0,1],50.0},
		//~ TRANSMITTER::clock		clk = {0.15,-83.0,-83.0}
	//~ };
	//~ TRANSMITTER t3 = TRANSMITTER(testStruct3);
	
	t1.txPwrWatts(100.0, 10.0, 10.0, 0.5, 1.2);
	//~ t1.txPwrDBM(20, 10.0, 10.0, 50.0, 1.2);
	
	//~ t2.txPwrWatts(testStruct.freq,
					//~ testStruct.gain,
					//~ testStruct.dist,
					//~ testStruct.low,
					//~ testStruct.high);
					
	//~ t3.txPwrWatts(t3.freq,
					//~ t3.gain,
					//~ t3.dist,
					//~ t3.low,
					//~ t3.high);
					
	//~ rcvr2.rxPwrDBM(20, 10.0, 10.0, 50.0, 1.2);
	//~ t2.txPwrWatts(100.0, 10.0, 10.0, 50.0, 1.2);
	//~ t2.txPwrDBM(20, 10.0, 10.0, 50.0, 1.2);
	//~ RECEIVER rcvr2 = RECEIVER(
					//~ RECEIVER::horiz, // Polarity
					//~ RECEIVER::mono,	// Type
					//~ 1.0,			// Gain
					//~ 2.4,			// Freq
					//~ 0.9,			// Efficiency
					//~ 1.0,			// Bandwidth
					//~ 0.01);			// Aperature Effective Area
	
	//~ rcvr1.setPol(rcvr1.getPol());
	//~ ant1.setType(ant1.getType());
	//~ ant1.setEff(0.9);
	//~ ant1.setArea(3);
	//~ ant1.setFreq(2.4);
	//~ ant1.setArea(ant1.calcAeff(ant1.freq));
	//~ ant1.setGain(ant1.antGainFromFreqGHz(ant1.eff, ant1.area, ant1.freq));
	
	//~ ant2.setArea(ant2.calcAeff(ant2.freq));
	//~ ant2.setGain(ant2.antGainFromFreqGHz(ant2.getEff(), ant2.getArea(), ant2.getFreq()));
	//~ ant2.setGain(ant2.antGainFromFreqGHz(ant2.eff, ant2.area, ant2.freq));
	
	return 0;
}



//~ struct UNIT_VECTOR {
	//~ float 	x_val;	// x coordinate / magnitude
	//~ float 	y_val;	// y coordinate / magnitude
	//~ float 	z_val;	// z coordinate / magnitude
	//~ float 	mag;	// magnitude
//~ };

// Functions //
