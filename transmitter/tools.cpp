
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
	printf("\nadcResult: %f\n\n", adcResult); // DBPRINT
	return adcResult;
}

/// Scaling and shifting function based on adc converter
//~ adcResult = (( ((adc_value - adc_min)*(out_max-out_min)) / (adc_max-adc_min) ) + out_min);

float scaleAndShift (float in_value, float in_max, float in_min, 
					float out_max, float out_min) {
	float ssResult = (( ((in_value - in_min)*(out_max-out_min)) / (in_max-in_min) ) + out_min);
	printf("Scaled and shifted result:\t%.4f\n", ssResult); // DBPRINT
	return ssResult;
}

/// Frequency <==> Lambda converters

// use frequency in Hertz
float getLambda(float freq){
  float clambda = (LIGHT_SPEED/freq);
  printf("\nwavelength =\t%.8f meters\n",clambda); // DBPRINT
  return clambda;
}
// use lambda in meters 
float getFreq(float lam){
  float freq = (LIGHT_SPEED/lam);
  printf("\nfrequency = %.8f MHz\n\n",freq/MEGA); // DBPRINT
  return freq;
}

/**
 * ADJUSTERS -- using a Simplified IIR Filter to adjust values
 * 
 * This algorithm is VERY useful for embedded control systems!!
 * 
 * It provides Critically Damped control system changes 
 * which are very smooth and fast.
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
 * speed_target == setpoint
 * speed == currently measured value
 * 
 * */

float adjust_signal (float signal, float alpha, float lim) {		
	int count = 0;
	printf("start signal = %.4f\n", signal);
	while (signal != lim) {
		signal += alpha*(lim - signal);
		count +=1;
		printf("%d\tsignal = %.8f\tsetpoint = %.8f\n", count, signal, lim);
	} 
	printf("signal = %.8f\tsetpoint = %.8f\n", signal, lim);
	return signal;
} 

float adjust_setpoint (float signal, float alpha, float lim) {		
	printf("start signal = %.4f\n", signal);	
	float hysteresis = 0.000;	
	//signal = signal*(1.0 - hysteresis);
	////~ float roundo = round(signal,4);
	int count = 0;
	lim =  lim * (1.0 - hysteresis);
	printf("end signal = %.4f\n", signal);
	while (((lim) != ((1.0 + hysteresis) * signal)) && (count < 21)) {
		lim += alpha*(signal - lim);
		////~ printf("%d signal = %.8f\tsetpoint = %.8f\n", count, signal, lim);
		printf("%d signal = %.8f\tsetpoint = %.8f\n", count, round_to_N(signal,3), round_to_N(lim, 4));
		count += 1;
	}
	printf("%d signal = %.8f\tsetpoint = %.8f\n", count, signal, lim);
	return lim;
}


// https://stackoverflow.com/questions/25925290/c-round-a-double-up-to-2-decimal-places
/// round_to_N(float val, int n) ==> this function truncates unruly doubles

float round_to_N(float val, int n) {	
	switch (n) {
		case 0:
			val = std::ceil(val * 1.0) / 1.0;
			//~ printf("value = %.2lf\n",val);
			break;	
		case 1:
			val = std::ceil(val * 10.0) / 10.0;
			//~ printf("value = %.2lf\n",val);
			break;		
		case 2:
			val = (std::ceil(val * 100.0)) / 100.0;
			//~ printf("value = %.2lf\n",val);
			break;
		case 3:
			val = (std::ceil(val * KILO)) / KILO;
			//~ printf("value = %.3lf\n",val);
			break;			
		case 4:
			val = std::ceil(val * (10*KILO)) / (10*KILO);
			//~ printf("value = %.4lf\n",val);
			break;			
		case 5:
			val = std::ceil(val * (100*KILO)) / (100*KILO);
			//~ printf("value = %.5lf\n",val);
			break;				
		case 6:
			val = std::ceil(val * MEGA) / MEGA;
			//~ printf("value = %.6lf\n",val);
			break;				
		case 7:
			val = std::ceil(val * (10*MEGA)) / (10*MEGA);
			//~ printf("value = %.7lf\n",val);
			break;
		case 8:
			val = std::ceil(val * (100*MEGA)) / (100*MEGA);
			//~ printf("value = %.8lf\n",val);
			break;	
		case 9:
			val = std::ceil(val * GIGA) / GIGA;
			//~ printf("value = %.9lf\n",val);
			break;
		case 10:
			val = std::ceil(val * (10*GIGA)) / (10*GIGA);
			//~ printf("value = %.10lf\n",val);
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
	
/// Main ///
int main(int argc, char const *argv[]) {
	int i = 0;
	for (i=0; i<MICS_CH_NUM; i++) {
		printf("\nMICS Channel %d\t%.4f MHz",i+1, (MICS_CH_VAL(i))*MICRO);
		getLambda(MICS_CH_VAL(i));
		
		//~ float channel = getLambda(MICS_CH_VAL(i)); // DEBUG TEST PASSED
		//~ round_to_N(channel,i); // DEBUG TEST PASSED
	}
}
