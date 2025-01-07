
//	Package:	sw_def_radio
//	File:		receiver.c
// 	Purpose:	Define the Receiver Class
// 	Author:		jrom876

// https://www.random-science-tools.com/electronics/friis.htm
// https://www.antenna-theory.com/basics/friis.php
// https://rfcafe.com/references/electrical/ew-radar-handbook/two-way-radar-equation.htm

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <float.h>	// For FLT_EPSILON
#include "receiver.hpp"
using namespace std;

/// STANDARD DEFINITIONS FOR PROJECT SCICALC 
#define PI			3.14159265358979323846 	// ad infinitum sine repeto
#define LIGHT_SPEED		299792458.0 		// meters per second
#define STACK_OVERFLOW		2147483648		// Hex 0x80000000
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
#define LED_ARRAY_RADIUS 0.35 				// meters from LED array to sample plate 

#define TXT_FILE_LB "receiver_data.txt"

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
RECEIVER::Receiver DUMMY_RX = {1.0,1.0,0.1,0.1,1};

// Default Constructor
RECEIVER::RECEIVER() {
	RECEIVER::rx 		= DUMMY_RX;
	RECEIVER::freq 		= 1.2; 	// Current freq setting of RX in GHz
	RECEIVER::gain 		= 10.0; // Current freq setting of RX in GHz
	RECEIVER::dist		= 50.0; // RX distance from Source
	RECEIVER::low		= 0.6;	// Lower edge of Bandwidth of RX
	RECEIVER::high		= 1.8;	// Upper edge of Bandwidth of RX
	RECEIVER::zout		= 50.0;	// Output Impedance in Ohms
	//RECEIVER::sensitivity;	// Upper edge of Bandwidth of RX
};

// Parameterized Constructor
RECEIVER::RECEIVER(struct Receiver rx1) {
	RECEIVER::rx 		= rx1;		// Test struct that holds our receiver data
	RECEIVER::freq 		= rx.freq; 	// Current freq setting of RX in GHz
	RECEIVER::gain 		= rx.gain; 	// Current freq setting of RX in GHz
	RECEIVER::dist		= rx.dist; 	// RX distance from Source
	RECEIVER::low		= rx.low;	// Lower edge of Bandwidth of RX
	RECEIVER::high		= rx.high;	// Upper edge of Bandwidth of RX
	RECEIVER::zout		= rx.zout;	// Output Impedance in Ohms
	//~ //RECEIVER::sensitivity;	// Upper edge of Bandwidth of RX
};

/** 
 *	One-way Path Loss, Received Signal Strength at Target 
**/

/** 
 * 	Friis Transmission Equation for
 *	Received Signal Strength at Target, One-way Path Loss
 * 	Pr = Pt * Gt * Gr * c^2 / (4Pi*R*freq)^2
**/

float RECEIVER::rxPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq){
	float result = Pt*pow(10,log10(GtdB))*pow(10,log10(GrdB))
		*(pow(LIGHT_SPEED,2))/(pow((4*PI*(R*KILO)*(freq*GIGA)),2));
	printf("RX Power at antenna: \t%.8f pico-watts\n",result*TERA); // DBPRINT
	return result;
}

float RECEIVER::rxPwrWatts(float Pt, float GtdB, struct Receiver rx){
	float result = Pt*pow(10,log10(GtdB))*pow(10,log10(rx.gain))
		*(pow(LIGHT_SPEED,2))/(pow((4*PI*(rx.dist*KILO)*(rx.freq*GIGA)),2));
	printf("RX Power at antenna with struct: \t%.8f pico-watts\n",result*TERA); // DBPRINT
	return result;
}
//////////////////////////////////////////////

float RECEIVER::rxPwrDBM(float PtxdBm, float GtxdB, float GrxdB, float dist, float freq){	
	float result;
	float rpwr = pow(10,((PtxdBm-30)/10))*pow(10,log10(GtxdB))
		*pow(10,log10(GrxdB))*(pow(LIGHT_SPEED,2))/(pow((4*PI*(dist*KILO)*(freq*GIGA)),2));
	printf("RX Power: \t%.8f dBW\n",(10*log10(rpwr))); // DBPRINT
	printf("RX Power: \t%.8f dBm\n",(10*log10(rpwr))+30); // DBPRINT
	printf("RX Power: \t%.8f dBp\n",(10*log10(rpwr))+120); // DBPRINT
	//~ printf("RX Power: \t%.8f pico-watts\n",rpwr*TERA); // DBPRINT
	result = (10*log10(rpwr))+30;
	//~ printf("result:\t%f\n",result); // DBPRINT
	return result;
}

// Print Functions 
void RECEIVER::printRxDBM( float PtxdBm, float GtxdB, float GrxdB, float dist, float freq){
	printf("\n%.4f\tPtdBm\n",PtxdBm);
	printf("%.4f\tGtdb\n",GtxdB);
	printf("%.4f\tGrdb\n",GrxdB);
	printf("%.4f\tDistance km\n",dist);
	printf("%.4f\tfreq GHz\n",freq);
	getFresnelRadius(freq,dist);
}

void printRxData( RECEIVER::Receiver rx ){ // using struct Receiver
	printf("\n%.4f\tfreq GHz\n",rx.freq);
	printf("%.4f\tgain dB\n",rx.gain);
	printf("%.4f\tdist km\n",rx.dist);
	printf("%.4f\tlow km\n",rx.low);
	printf("%.4f\thigh GHz\n",rx.high);
	printf("%.4f\tzout Ohmz\n",rx.zout);
	printf("%.4f\tBW GHz\n",(rx.high-rx.low));
	printf("%.4f\tFractBW \n",(rx.high-rx.low)/rx.freq);
	};

void printRxData( RECEIVER rx ){ // using RECEIVER object
	printf("\n%.4f\tfreq GHz\n",rx.freq);
	printf("%.4f\tgain dB\n",rx.gain);
	printf("%.4f\tdist km\n",rx.dist);
	printf("%.4f\tlow km\n",rx.low);
	printf("%.4f\thigh GHz\n",rx.high);
	printf("%.4f\tzout Ohmz\n",rx.zout);
	printf("%.4f\tBW GHz\n",(rx.high-rx.low));
	printf("%.4f\tFractBW \n",(rx.high-rx.low)/rx.freq);
	};
/////////////////////////////////////////////////////////////////////

// Fresnel Radius
float RECEIVER::getFresnelRadius( float freqGHz, float distKM ) {
	float result = (8.656*sqrt(distKM/(4*freqGHz)));
	printf("\nFresnel Radius = %.4f meters\n", result); // DBPRINT
	return result;
}

// Polarization Loss Factor
float RECEIVER::getPLF(float phi) {
	phi = phi*(PI/180);
	float plf = pow(cos(phi),2);
	printf("\nPolarization Loss Factor = %.4f\n\n", plf); // DBPRINT
	return plf;
}

// Fractional Bandwidth
float RECEIVER::getFBW(void) {
	float fbwidth = (RECEIVER::high - RECEIVER::low)/RECEIVER::freq;
	printf("Fractional Bandwidth = %.4f\n\n", fbwidth); // DBPRINT
	return fbwidth;
}

///////////////////////////////////////////////////////////////////      
float RECEIVER::setFreq(float f)	{ freq = f*GIGA; 	return freq; };          
float RECEIVER::setGain(float g)	{ gain = g; 		return gain; };          
float RECEIVER::setDist(float d)	{ dist = d*KILO; 	return dist; };           
float RECEIVER::setLow(float l)		{ low = l*GIGA; 	return low;  };          
float RECEIVER::setHigh(float h)	{ high = h*GIGA; 	return high; };          
float RECEIVER::setZout(float z)	{ zout = z;		return zout; };  
///////////////////////////////////////////////////////////////////
	 
/// Main ///
int main(int argc, char const *argv[]) {
	
	RECEIVER::Receiver testStruct = {
			1.2, // freq
			10.0, // gain
			50.0, // dist
			0.5, // low
			2.4, // high
			50.0 // zout
			};
	RECEIVER rcvr1 = RECEIVER();
	//~ RECEIVER rcvr2 = RECEIVER(testStruct);
	RECEIVER rcvr3 = RECEIVER(testStruct);
	
	printf("\nRCVR3 Freq: %.4f GHz\n",rcvr3.getFreq());
	
	rcvr1.rxPwrWatts(1.2, 10.0, 50.0, 0.5, 2.4);
	//~ rcvr1.rxPwrDBM(20, 10.0, 50.0, 0.5, 2.4);
	//~ rcvr3.getFresnelRadius(1.2,50.0);
	//~ rcvr3.getPLF(500);
	//~ rcvr3.getFBW();
	
	//~ rcvr3.rxPwrWatts(testStruct.freq,
			//~ testStruct.gain,
			//~ testStruct.dist,
			//~ testStruct.low,
			//~ testStruct.high);
		
	//~ rcvr3.rxPwrWatts(testStruct.freq,
			//~ testStruct.gain,
			//~ testStruct);
					
	//~ rcvr3.rxPwrWatts(rcvr3.freq,
			//~ rcvr3.gain,
			//~ rcvr3.dist,
			//~ rcvr3.low,
			//~ rcvr3.high);
	//~ printRxData(testStruct);			
	//~ printRxData(rcvr3);	
	//~ rcvr2.rxPwrDBM(20, 10.0, 10.0, 50.0, 1.2);
	//~ rcvr2.rxPwrWatts(100.0, 10.0, 10.0, 50.0, 1.2);
	//~ rcvr2.rxPwrDBM(20, 10.0, 10.0, 50.0, 1.2);
	return 0;
}
