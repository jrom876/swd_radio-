
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

#include "tools.hpp"
using namespace std;

/*
 * General Tools from my Toolbox
 * */

float adc_calc (int adc_value, 
						int adc_min, int adc_max, 
						float out_min, float out_max) {
	float adcResult = (( ((adc_value - adc_min)*(out_max-out_min)) / (adc_max-adc_min) ) + out_min);	
	printf("\nadcResult: %f\n\n", adcResult);
	return adcResult;
}

/// Scaling and shifting function based on adc converter
//~ adcResult = (( ((adc_value - adc_min)*(out_max-out_min)) / (adc_max-adc_min) ) + out_min);

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
			//~ printf("value = %f\n",val);
			break;		
		case 2:
			val = (std::ceil(val * 100.0)) / 100.0;
			//~ printf("value = %f\n",val);
			break;
		case 3:
			val = (std::ceil(val * 1000.0)) / 1000.0;
			//~ printf("value = %f\n",val);
			break;
			
		case 4:
			val = std::ceil(val * 10000.0) / 10000.0;
			//~ printf("value = %f\n",val);
			break;
			
		case 5:
			val = std::ceil(val * 100000.0) / 100000.0;
			//~ printf("value = %f\n",val);
			break;
		default:
			break;
	}	
    //~ double value = 0.123;
    //~ value = std::ceil(value * 100.0) / 100.0;
    //~ std::cout << value << std::endl; // prints 0.13
    return val;
}

/// dB converters ///

float dBm_to_float (float dbm) {
	float result = pow(10,((dbm-30)/10));
	printf("%.2f dBm = %.2f W\n",dbm, result);	// DBPRINT
	return result;
	//~ return pow(10,((dbm-30)/10));
}

float float_to_dBm (float flt) {
	float dbm = (10*(log10(flt))) + 30;
	printf("%.2f W = %.2f dBm\n",flt, dbm);	// DBPRINT
	return dbm;
	//~ return (10*(log10(flt))) + 30;
}

float dB_to_float (float db) {
	float result = pow(10,((db)/10));
	printf("%.2f dB = %.2f Watts\n",db, result); 	// DBPRINT
	return result;
	//~ return pow(10,((db)/10));
}

float float_to_dB (float flt) {
	float db = (10*(log10(flt)));
	printf("%.2f Watts = %.2f dB\n",flt, db); 	// DBPRINT
	return db;
	//~ return (10*(log10(flt)));
}

/// Bandwidth Tests ///

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

