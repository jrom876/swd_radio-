
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
#include "filter.hpp"
#include "outamp.hpp"
#include "preamp.hpp"
#include "rfswitch.hpp"
#include "signal.hpp"
#include "tools.hpp"
using namespace std;

#define TXT_FILE_LB "transmitter_data.txt"

/////////////
// Globals //
/////////////
float freqGHz, txpwrW, distTargetKM;
float radarXSect, antGain;
float PLF = 0; // Polarization Loss Factor
float tempf;	// Needed for writing data to file

//~ TRANSMITTER::Transmitter DUMMY_TX = {1.0,1.0,1.0,0.1,0.1,1, 1};	
CLOCK::Clock clk0 = {4.8,0.5};
DDS::DDSynth dds0 = {4.8,1.2,1};
FILTER::Filter fil0 = {1.2,250,20.0,-85};
ATTENUATOR::Attenuator att0 = {1.5, 0xFF, 0x04, (att0.sig_in/(att0.atten & att0.mask))};
PREAMP::Preamp pa0 = {1.2,250,20,-85,1.2};
RFSWITCH::RFSwitch sw0 = {1,1.6,true, 1.0, 0x77,0x5};
OUTAMP::Outamp oa0 = {1.2,250,20,-85,50};
//~ CLOCK ck1 = CLOCK();

//~ CLOCK::Clock testStruct = {4.8,0.5};
//~ CLOCK c2 = CLOCK(testStruct);

//~ CLOCK clk2 = CLOCK(clk0);
//~ DDS 		dds1;
//~ FILTER 		flt1;
//~ ATTENUATOR 		att1;
//~ PREAMP 		pa1;
//~ RFSWITCH 		sw1;
//~ OUTAMP		oa1;
	

// Default Constructor
TRANSMITTER::TRANSMITTER() {};

// DESTRUCTOR
TRANSMITTER::~TRANSMITTER() {std::cout << "Transmitter Destructor is executed\n";};

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
float TRANSMITTER::setBW(float b)	{bw = b;return bw;};             
float TRANSMITTER::setGain(float g)	{gain = g;return gain;};        
float TRANSMITTER::setNoise(float n){noise = n;return noise;};      
float TRANSMITTER::setDist(float d)	{dist = d;return dist;};          
float TRANSMITTER::setZout(float z)	{zout = z;return zout;};  

//~ float setFreq	(float f);           
        //~ float setBW		(float b);  
        //~ float setGain	(float g);           
        //~ float setNoise	(float n);          
        //~ float setDist	(float d);          
        //~ float setZout	(float z);
        
float dBm_to_float (float dbm) {
	float result = pow(10,((dbm-30)/10));
	printf("%.2f dBm = %.2f\n",dbm, result); 
	return result;
}

float float_to_dBm (float flt) {
	float dbm = (10*(log10(flt))) + 30;
	printf("%.2f = %.2f dBm\n",flt, dbm); 
	return dbm;
}

// Circle::Circle() {};

// https://en.wikipedia.org/wiki/Zero-copy
// https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem

// https://stackoverflow.com/questions/13074590/listlist-names-the-constructor-not-the-type	 
/// Main ///
int main(int argc, char const *argv[]) {
	
	//~ TRANSMITTER::Transmitter testStruct = {100.0,10.0,10.0,0.5,1.2,50.0};	
	//~ TRANSMITTER	t1 = TRANSMITTER();	
	
	TRANSMITTER* 		t1;		
	CLOCK* 			clk1;
	DDS* 			dds1;
	FILTER* 		fil1;
	ATTENUATOR* 		att1;
	PREAMP* 		pa1;
	RFSWITCH* 		sw1;
	OUTAMP* 		oa1;
	SIGNAL*			sig1;
	
	
	//~ t1->clk.setFout(2.4);
	//~ t1->clk.setFout(2.4);
	//~ t1->CLOCK::clk.getFout();
	
	//~ clk1->setFout(1.2);
	clk1->getFout();
	
	//~ clk1->setFout(gck - 1.0);
	//~ gck = clk1->getFout();
	
	//~ dds1->setClkIn(1.2);
	dds1->getClkIn();
	
	//~ dds1->setClkIn(gck);
	//~ printf(("%.4f"),dds1->getClkIn());
	
	//~ fil1->setFreq(gck);
	float ff1 = fil1->getFreq();
	printf(("%.4f"),fil1->getFreq());
	
	//~ dds1->setClkIn(2.4);
	//~ printf(("%.4f"),dds1->getClkIn());
	
	//~ dds1->getClkIn();
	//~ float gdds = clk1->getFout();
	//~ clk1->getFout();
	
	t1->txPwrWatts(100.0, 10.0, 10.0, 0.5, 1.2);
	
	//~ dds1->setClkIn(gck);	
	//~ float gddf = dds1->getFout();
	//~ printf(("%.4f"),dds1->getClkIn());
	
	//~ TRANSMITTER t3 = TRANSMITTER(
					//~ oa1, 
					//~ sw1,
					//~ pa1,
					//~ att1,
					//~ fil1,
					//~ dds1,
					//~ clk1);
	// OUTAMP t1 = OUTAMP();
	
	////////////////////////////////
	
	//~ TRANSMITTER 	t2;	
	//~ CLOCK 		clk2;	
	//~ DDS* 		dds2;
	//~ FILTER* 		fil2;
	//~ ATTENUATOR* 	att2;
	//~ PREAMP* 		pa2;
	//~ RFSWITCH* 		sw2;
	//~ OUTAMP* 		oa2;
	
	//~ TRANSMITTER t2 (OUTAMP 			oa2 = OUTAMP(), 
					//~ RFSWITCH	sw2 = RFSWITCH(),
					//~ PREAMP	pa2 = PREAMP(),
					//~ ATTENUATOR	att2 = ATTENUATOR(),
					//~ FILTER	fil2 = FILTER(),
					//~ DDS		dds2 = DDS(),
					//~ CLOCK	clk2 = CLOCK()) ;
	
	//~ clk2->setFout(2.5);
	
	//~ clk1->getFout();
	
	//~ t2.clk2.getFout();
	
	//~ TRANSMITTER t2 = TRANSMITTER(	
				//~ OUTAMP		oa, 
				//~ RFSWITCH		rfsw,
				//~ PREAMP		pa,
				//~ ATTENUATOR		att,
				//~ FILTER		flt,
				//~ DDS			ds,
				//~ CLOCK		clk) {};
	
	//~ CLOCK::CLOCK() {};
	//~ CLOCK ck1 = CLOCK();
	
	//~ TRANSMITTER t2 = TRANSMITTER(testStruct);	
	
	//~ TRANSMITTER(OUTAMP			oa, 
				//~ RFSWITCH	sw,
				//~ PREAMP	pa,
				//~ ATTENUATOR	att,
				//~ FILTER	fil,
				//~ DDS		dds,
				//~ CLOCK	clk);
		
	//~ TRANSMITTER t3 = TRANSMITTER(
				//~ OUTAMP		oa, 
				//~ RFSWITCH		sw,
				//~ PREAMP		pa,
				//~ ATTENUATOR		att,
				//~ FILTER		fil,
				//~ DDS			dds,
				//~ CLOCK		clk);	
	
	
		
	//~ OUTAMP::OUTAMP*  = new OUTAMP();
	//~ TRANSMITTER::Transmitter testStruct3 = {
		//~ TRANSMITTER::outamp	oamp = {1.2,500,10.0,-83.0,50.0}, 
		//~ TRANSMITTER::preamp	pamp = {1.2,500,10.0,-83.0,50.0},
		//~ TRANSMITTER::atten	att = {1.2,1.0,50.0},
		//~ TRANSMITTER::dds	ds = {0.15,[0,0,1,0,0,0,0,0],[1,0,0,1],50.0},
		//~ TRANSMITTER::clock	clk = {0.15,-83.0,-83.0}
	//~ };
	//~ TRANSMITTER t3 = TRANSMITTER(testStruct3);
	
	//~ t1->txPwrWatts(100.0, 10.0, 10.0, 0.5, 1.2);
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
					//~ RECEIVER::horiz, 	// Polarity
					//~ RECEIVER::mono,	// Type
					//~ 1.0,		// Gain
					//~ 2.4,		// Freq
					//~ 0.9,		// Efficiency
					//~ 1.0,		// Bandwidth
					//~ 0.01);		// Aperature Effective Area
	
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
