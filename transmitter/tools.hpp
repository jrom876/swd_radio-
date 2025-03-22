
// dds.hpp
#ifndef TOOLS_HPP
#define TOOLS_HPP


#include <bitset>
#include <iostream>
#include <cstdint>

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
//~ #define true 1
//~ #define false 0

/// STANDARD DEFINITIONS FOR LIGHT INTENSITY AND ELECTRIC FIELD CALCULATIONS
#define AIR_REFRACTIVE_INDEX 1.00027717
#define E0 8.8541878128*PICO				// Permittivity of Free Space in Farads per meter
#define MU0 1.25663706212*MICRO				// Permeability of Free Space in Newtons per square meter
#define EPSILON_0 1/(MU0*(LIGHT_SPEED*LIGHT_SPEED))	// Permittivity of Free Space Equation
#define E_CONSTANT 1/(4*PI*EPSILON_0)
#define ELECTRON_CHARGE 1.6e-19 			// Charge of an electron in Coulombs
#define RADIUS_HELIUM_ATOM 26.5e-12			// Radius of a Helium atom in meters 

#define PLF(deg) pow(cos(deg*(PI/180)),2) 	// Polarization Loss Factor
#define FRBW(frange,cfreq) (frange/cfreq)	// Fractional Bandwidth of Antenna
#define UV_MAG(x,y,z) sqrt((x*x)+(y*y)+(z*z)) // Unit Vector Magnitude
#define MAX_NUM 100	// The maximum number of iterations
#define MIN_NUM 1	// The minimum number of iterations

/// STANDARD FREQUENCY BANDS ///
/** 
 * MICS		Medical Implant Communication System
 * https://medicalconnectivity.com/2006/03/03/medical-implant-communications-service-tutorial/
 * 
 * In 1999 the FCC set aside the 402-405 MHz band for MICS because the
 * signal propagation characteristics in the band are particularly well suited 
 * for implantable applications due to signal propagation characteristics in the human body.
 * The MICS band is broken into 300 kHz wide channels.
 * 
**/
#define MICS_MIN			float(402.0*MEGA)	// Lower limit of MICS Band in MHz
#define MICS_MAX			float(405.0*MEGA)	// Upper limit of MICS Band in MHz
#define MICS_CH_BW			float(300.0*KILO)	// MICS is broken into 300kHz wide channels
#define MICS_CH_NUM			int((MICS_MAX - MICS_MIN) / MICS_CH_BW)	// MICS has 10 channels
#define MICS_CH_VAL(num)	((num >= 0) && (num < MICS_CH_NUM)) \
							? float(MICS_MIN + (num*(MICS_CH_BW)) + (0.5*MICS_CH_BW)) \
							: float(MICS_MIN) + (0.5*MICS_CH_BW)

/*
 * General Tools from my Toolbox
 * */

float adc_calc (int adc_value, int adc_min, int adc_max,  
				float out_min, float out_max);

/// Scaling and shifting function based on adc converter
//~ adcResult = (( ((adc_value - adc_min)*(out_max-out_min)) / (adc_max-adc_min) ) + out_min);
float scaleAndShift (float in_value, float in_max, float in_min, 
					float out_max, float out_min);

/// Frequency <==> Lambda converters
float getLambda(float freq);
float getFreq(float lam);

float adjust_signal (float signal, float alpha, float lim);
float adjust_setpoint (float signal, float alpha, float lim);

// https://stackoverflow.com/questions/25925290/c-round-a-double-up-to-2-decimal-places
/// round_to_N(float val, int n) ==> this function truncates unruly doubles
float round_to_N(float val, int n);

/// dB converters ///
float dBm_to_float (float dbm);
float float_to_dBm (float flt);
float dB_to_float (float db);
float float_to_dB (float flt);

/// Bandwidth Tests ///
bool checkFreqRange(float bw, float freq);
float getFreqRange(float low, float hi);

#endif
