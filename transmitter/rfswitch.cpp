
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

#include <limits>
#include <numbers>

#include "rfswitch.hpp"
#include "tools.hpp"
using namespace std;


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
	RFSWITCH::mask 		= 0x55;		// set point uint8_t output
	
	RFSWITCH::ref_v 	= 5.0;
	RFSWITCH::hyster	= 0.05;
	RFSWITCH::bandwidth	= freq_in / 10.0;
};

// DESTRUCTOR
RFSWITCH::~RFSWITCH() {std::cout << "RFSwitch Destructor\n";};

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
     
void RFSWITCH::setSwitch(bool s = false)	{ 
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
       
void RFSWITCH::setMask(uint8_t m)	{ 
	RFSWITCH::mask = m;
	//~ printf("mask = %.2f\n",mask);
	//~ cout << "Setting Point in bitset<8>: " << mask << endl;
}; 
         
void RFSWITCH::setRefV(float rv)	{ 
	RFSWITCH::ref_v = rv;
	printf("Ref_V = %.2f\n",ref_v);
}; 
         
void RFSWITCH::setBW(float bw)	{ 
	RFSWITCH::bandwidth = bandwidth;
	printf("bandwidth = %.2f\n",bandwidth);
}; 
 
///////////////
/// GETTERS ///
     
float RFSWITCH::getFin() { 
	//~ printf("\nRFSwitch freq_in:\t%.2f\n",RFSWITCH::freq_in);	// DBPRINT
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
	printf("RFSwitch ampl_in:\t%.2f \n",RFSWITCH::ampl_in);	// DBPRINT
	return RFSWITCH::ampl_in; 
};

uint8_t RFSWITCH::getMask() { 
	//~ cout << "Mask: " << RFSWITCH::mask << endl; // DBPRINT
	printf("RFSwitch mask:\t\t%d\n",RFSWITCH::mask); // DBPRINT
	return RFSWITCH::mask; 
};
    
float RFSWITCH::getRefV() { 
	printf("RFSwitch ref_v:\t\t%.2f\n",RFSWITCH::ref_v); // DBPRINT
	return RFSWITCH::ref_v; 
}; 

float RFSWITCH::getBW() {
	printf("RFSwitch bandwidth:\t\t%.2f\n",RFSWITCH::bandwidth); // DBPRINT
	return RFSWITCH::bandwidth; 
}

/////////////////////

///////////////////////
/// Flip the Switch ///

bool RFSWITCH::flip_switch () {
	printf("swt before:\t\t%d\n",RFSWITCH::swt); // DBPRINT
	RFSWITCH::swt = !RFSWITCH::swt;
	printf("swt after:\t\t%d\n",RFSWITCH::swt); // DBPRINT
	return swt;
}

///////////////////////

/////////////////////////////////
/// Compare Signals - virtual ///

// These virtual comparators have a 5% hysteresis, meaning they toggle the switch
// at (setpoint - 5%) = 95% of the setpoint to allow for overdamped responses.
// We do not toggle at (setpoint + 5% because our signal must never get that high.

bool RFSWITCH::compare_ain_to_setpt() {	
	bool match = false;
	float hysteresis = 0.05;
	//~ float ain = float_to_dBm(RFSWITCH::ampl_in);
	float ain = RFSWITCH::ampl_in;	
	
	if (ain >= (RFSWITCH::setpt * (1 - hysteresis))) {
		match = true; 
		printf("ain >= setpt:\t\t%d\n",match);	// DBPRINT
	}
	else if (ain < (RFSWITCH::setpt * (1 - hysteresis))) {
		match = false; 
		printf("ain < setp:\t\t%d\n",match);	// DBPRINT	
	}	
	setSwitch(match);
	return match;
	//~ return (dBm_to_float(RFSWITCH::ampl_in >= RFSWITCH::setpt);
}



bool RFSWITCH::compare_ain_to_setpt(float ain, float sp, float hys) {
	bool match = false;
	float hysteresis = hys;
	//~ ain = float_to_dBm(ain);
	
	if (ain >= (sp * (1 - hysteresis))) {
		match = true;
		printf("ain >= setpt:\t%d\n",match);	// DBPRINT
	}
	else if (ain < (sp * (1 - hysteresis))) {
		match = false; 
		printf("ain < setp:\t%d\n",match);	// DBPRINT
	}	
	setSwitch(match);
	return match;
}

/////////////////////////////////

/////////////////////////////////
/////////////////////////////////

/*
 * General Tools from my Toolbox -- moved to tools.hpp
 * */

float adc_calc (int adc_value, 
						int adc_min, int adc_max, 
						float out_min, float out_max) {
	float adcResult = (( ((adc_value - adc_min)*(out_max-out_min)) / (adc_max-adc_min) ) + out_min);	
	printf("\nadcResult: %f\n\n", adcResult);
	return adcResult;
}

/// Scaling and shifting function based on adc converter
//~ //// adcResult = (( ((adc_value - adc_min)*(out_max-out_min)) / (adc_max-adc_min) ) + out_min);

float scaleAndShift (float in_value, float in_max, float in_min, 
					float out_max, float out_min) {
	float ssResult = (( ((in_value - in_min)*(out_max-out_min)) / (in_max-in_min) ) + out_min);
	printf("Scaled and shifted result:\t%.4f\n", ssResult);
	return ssResult;
}

// https://stackoverflow.com/questions/25925290/c-round-a-double-up-to-2-decimal-places
/// round_to_N(float val, int n) ==> this function truncates unruly doubles

float round_to_N(float val, int n) {	
	switch (n) {
		case 1:
			val = std::ceil(val * 10.0) / 10.0;
			///~ printf("value = %f\n",val);
			break;		
		case 2:
			val = (std::ceil(val * 100.0)) / 100.0;
			////~ printf("value = %f\n",val);
			break;
		case 3:
			val = (std::ceil(val * 1000.0)) / 1000.0;
			////~ printf("value = %f\n",val);
			break;
			
		case 4:
			val = std::ceil(val * 10000.0) / 10000.0;
			////~ printf("value = %f\n",val);
			break;
			
		case 5:
			val = std::ceil(val * 100000.0) / 100000.0;
			////~ printf("value = %f\n",val);
			break;
		default:
			break;
	}	
    ////~ double value = 0.123;
    ////~ value = std::ceil(value * 100.0) / 100.0;
    ////~ std::cout << value << std::endl; // prints 0.13
    return val;
}

//~ /// dB converters ///

//~ float dBm_to_float (float dbm) {
	//~ float result = pow(10,((dbm-30)/10));
	//~ printf("%.2f dBm = %.2f W\n",dbm, result);	// DBPRINT
	//~ return result;
	//~ ////~ return pow(10,((dbm-30)/10));
//~ }

//~ float float_to_dBm (float flt) {
	//~ float dbm = (10*(log10(flt))) + 30;
	//~ printf("%.2f W = %.2f dBm\n",flt, dbm);	// DBPRINT
	//~ return dbm;
	//~ ////~ return (10*(log10(flt))) + 30;
//~ }

//~ float dB_to_float (float db) {
	//~ float result = pow(10,((db)/10));
	//~ printf("%.2f dB = %.2f Watts\n",db, result); 	// DBPRINT
	//~ return result;
	//~ ////~ return pow(10,((db)/10));
//~ }

//~ float float_to_dB (float flt) {
	//~ float db = (10*(log10(flt)));
	//~ printf("%.2f Watts = %.2f dB\n",flt, db); 	// DBPRINT
	//~ return db;
	//~ ////~ return (10*(log10(flt)));
//~ }

//~ /// Bandwidth Tests ///

//~ bool checkFreqRange(float bw, float freq) {
	//~ bool result = ((freq<=(freq+(bw/2))) && (freq >=(freq-(bw/2))));
	//~ printf("Is freq in Range? = %d\n", result);	// DBPRINT
	//~ return result;
	//~ ////~ return ((freq<=(freq+(bw/2))) && (freq >=(freq-(bw/2))));;
//~ }

//~ float getFreqRange(float low, float hi) {
	//~ float diff = hi - low;
	//~ printf("diff = %.2f",diff);	// DBPRINT
	//~ return (diff);
	//~ ////~ return (hi - low);
//~ }



/*
 * End of General Tools from my Toolbox
 * */



/////////////////////////////////
/////////////////////////////////

/**
 * ADJUSTERS -- using a Simplified IIR Filter to adjust values
 * 
 * This algorithm is VERY useful for embedded control systems!!
 * It makes control system changes very smooth and fast.
 * 
 * Doctor Jeff's simplified IIR Filter with filtering factor alpha:
 * 
 * 		speed += alpha*(speed_target - speed);
 * 
 * if alpha == 0.5, we take 2 filter samples,
 * if alpha == 0.2, we take 5 samples,
 * if alpha == 0.1, we take 10 samples...
 * You get the idea... 
 * 
 * alpha == filtering factor
 * speed_target == setpoint, m/s
 * speed == currently measured speed, m/s
 * 
 * */

float RFSWITCH::adjust_signal (float signal, float alpha) {	
	//~ signal = signal.setprecision(6);
	//~ float hysteresis = 0.05;
	//~ float att = (RFSWITCH::atten);
	//~ printf("att signal = %.4f\n", att);
	float lim = RFSWITCH::getPt();
	printf("start signal = %.4f\n", signal);
	while (signal != lim) {
		signal += alpha*(lim - signal);
		printf("signal = %.8f\tsetpoint = %.8f\n", signal, lim);
	} 
	printf("signal = %.8f\tsetpoint = %.8f\n", signal, lim);
	return signal;
} 

float RFSWITCH::adjust_setpoint (float signal, float alpha) {		
	printf("start signal = %.4f\n", signal);	
	float hysteresis = RFSWITCH::hyster;	
	//~ float hysteresis = 0.05;
	signal = signal*(1.0 - hysteresis);
	int count = 0;
	float lim =  RFSWITCH::getPt() * (1.0 - hysteresis);
	printf("end signal = %.4f\n", signal);
	while (((lim) != ((1.0 + hysteresis) * signal)) && (count < 21)) {
		lim += alpha*(signal - lim);
		//~ printf("%d signal = %.8f\tsetpoint = %.8f\n", count, signal, lim);
		printf("%d signal = %.8f\tsetpoint = %.8f\n", count, round_to_N(signal,3), round_to_N(lim, 4));
		count += 1;
	}
	printf("%d signal = %.8f\tsetpoint = %.8f\n", count, signal, lim);
	return lim;
}


/////////////////////////////////

////////////
/// Main ///

int main(int argc, char const *argv[]) {
    //~ round_to_N(45.96666, 4); // DBPRINT -- testing this method
    // create test objects
	RFSWITCH::RFSwitch testStruct = {1.2,1};
	RFSWITCH t1 = RFSWITCH();
	RFSWITCH t2 = RFSWITCH(testStruct);
	RFSWITCH t3 = RFSWITCH(DUMMY_SW);
	
	/// testing converter functions ///	
	//~ dBm_to_float(40.0);	
	//~ float_to_dBm(10.0);   	
	/// end of testing converter functions /// 
	
	/// testing scale and shift functions ///
	//~ scaleAndShift (-0.097, 0.25, -0.25, 12.0, 0);
	
	/// test battery ///		
	
	t1.setRefV(5.0);
	t1.getRefV();
	t1.setAtten(0xFF);
	t1.setMask(0x66);
    adc_calc (t1.getAtten(), 0x0, 0xFF, 0.0, t1.getRefV());
	t1.setAtten(0xFF & t1.getMask());
    adc_calc (t1.getAtten(), 0x0, 0xFF, 0.0, t1.getRefV());
	
	t1.setFin(2.1);
	t1.getFin();	
	//~ t1.setAmpIn(float_to_dBm(1.60));	
	t1.setAmpIn(1.80);
	t1.getAmpIn();
	
	t1.setPt(1.55);
	t1.getPt();
	//~ t1.setSwitch(true);
	t1.getSwitch();
	//~ t1.flip_switch ();
	//~ t1.flip_switch ();

	//~ t1.setAtten(64);
	//~ t1.getAtten();
	//~ t1.setMask(0x64);
	//~ t1.getMask();
	
	//~ t1.setRefV(12.0);
	//~ t1.getRefV();

	printf("\nTesting adjust functions\n");	
	t1.adjust_signal (t1.getAmpIn(), 0.5);
	
	t1.adjust_setpoint(t1.getAmpIn(), 0.5);	
	//~ t1.getPt();
	//~ t1.adjust_setpoint (t1.getAmpIn(), 0.5);

	printf("\nTesting compare functions\n");	
	t1.compare_ain_to_setpt();
	//~ t1.compare_ain_to_setpt(t1.getAmpIn(), t1.getPt(), 0.05);

	//~ printf("\nTesting object t3\n");

	//~ t3.setFin(37.5e6);
	//~ t3.getFin();		
	//~ ////~ t3.setAmpIn(float_to_dBm(14.0));		
	//~ t3.setAmpIn(12.0);
	//~ t3.getAmpIn();
	
	//~ t3.setPt(15.5);
	//~ t3.getPt();
	//~ t3.setSwitch(false);
	//~ t3.getSwitch();
	
	//~ t3.setAtten(128);
	//~ t3.getAtten();
	//~ t3.setMask(0xC3);
	//~ t3.getMask();
	
	//~ t3.compare_ain_to_setpt();
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
    


