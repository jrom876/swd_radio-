//	Package:	sw_def_radio
//	File:		sw_def_radio.cpp
// 	Purpose:	Define the Radio Class
// 	Author:		jrom876

/**
	Copyright (C) 2019, 2021, 2024 
	Jacob Romero, Creative Engineering Solutions, LLC
	cesllc876@gmail.com

	This program is free software; you can redistribute it
	and/or modify it under the terms of the GNU General Public  
	License as published by the Free Software Foundation, version 2.

	This program is distributed in the hope that it will be
	useful, but WITHOUT ANY WARRANTY; without even the implied 
	warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	
	See the GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public
	License along with this program; if not, write to:
	The Free Software Foundation, Inc.
	59 Temple Place, Suite 330
	Boston, MA 02111-1307 USA

**/

// https://www.random-science-tools.com/electronics/friis.htm
// https://www.antenna-theory.com/basics/friis.php
// https://rfcafe.com/references/electrical/ew-radar-handbook/two-way-radar-equation.htm

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>	// For FLT_EPSILON
#include <check.h>
#include "sw_def_radio.hpp"

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

#define TXT_FILE_LB "linkBudgetData.txt"

#define PLF(deg) pow(cos(deg*(PI/180)),2) 	// Polarization Loss Factor
#define FRBW(frange,cfreq) (frange/cfreq)	// Fractional Bandwidth of Antenna
#define UV_MAG(x,y,z) sqrt((x*x)+(y*y)+(z*z)) // Unit Vector Magnitude
#define MAX_NUM 100	// The maximum number of iterations

//
// Globals //
float freqGHz, txpwrW, distTargetKM;
float radarXSect, antGain;
//~ float PLF = 0; // Polarization Loss Factor
float tempf;	// Needed for writing data to file
//int exitFlag = 0;

///********************
///	THE SIGNAL
///********************

struct RX_SIGNAL {
	float 			PtxdBm;		// Tx Power in dBm
	float 			GtxdB;		// Gain of TX Antenna in dB
	float 			GrxdB; 		// Gain of RX Antenna in dB
	float 			distkm; 	// Distance to Rx in km
	float 			freqGHz;	// Signal Frequency in GHz	
	float 			plf;		// Polarization Loss Factor
};

///*************
///	THE RECEIVER
///*************

struct RECEIVER {
	struct RX_SIGNAL 	rx_signal;	// Rx Signal
	struct ANTENNA		antenna;	// Antenna 
	float 			freq; 		// Center freq of RX
	float 			bw;			// Bandwidth of RX
};

struct UNIT_VECTOR {
	float 	x_val;	// x coordinate / magnitude
	float 	y_val;	// y coordinate / magnitude
	float 	z_val;	// z coordinate / magnitude
	float 	mag;	// magnitude
};

// Functions //
/**
 * Two-way Path Loss, Monostatic Radar
 **/

/** twoWayPathLossDB(float freq, float dist, float rxs)
 * 	Returns RX Signal Strength in dB at radar antenna
 *  given the following parameters:
 *		freq		Signal Frequency in GHz
 * 		dist		Distance to Target in km
 * 		rxs		radar target cross-sectional area
**/

float twoWayPathLossDB(float freq, float dist, float rxs){
  float result = ((20*log(freq))+(40*log(dist))+163.43-(10*log(rxs)))*(-1);
  printf("Path Loss (dB): \t%.5f\n",result); // DBPRINT
  return result;
}

/** 
 *	One-way Path Loss, Received Signal Strength at Target 
**/

/** 
 * 	Friis Transmission Equation for
 *	Received Signal Strength at Target, One-way Path Loss
 * 	Pr = Pt * Gt * Gr * c^2 / (4Pi*R*freq)^2
**/

/** rxPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq)
 * 	Returns RX Signal Strength in Watts given the following parameters:
 *		Pt		Tx Power in Watts
 * 		Gtdb		Gain of TX Antenna in dB
 * 		Grdb		Gain of RX Antenna in dB
 * 		R		Distance to Target in km
 * 		freq		Signal Frequency in GHz
**/

float rxPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq){
	float result = Pt*pow(10,log10(GtdB))*pow(10,log10(GrdB))
		*(pow(LIGHT_SPEED,2))/(pow((4*PI*(R*KILO)*(freq*GIGA)),2));
	printf("RX Power at antenna: \t%.8f pico-watts\n",result*TERA); // DBPRINT
	return result;
}

/** rxPwrDBM(float PtdBm, float GtdB, float GrdB, float R, float freq)
 * 	Returns RX Signal strength in dBm given the following parameters:
 *		PtdBm		Tx Power in dBm
 * 		Gtdb		Gain of TX Antenna in dB
 * 		Grdb		Gain of RX Antenna in dB
 * 		R		Distance to Target in km
 * 		freq		Signal Frequency in GHz
**/

float rxPwrDBM(float PtxdBm, float GtxdB, float GrxdB, float dist, float freq){	
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

void printRxDBM( float PtxdBm, float GtxdB, float GrxdB, float dist, float freq){
	printf("\n%.4f\tPtdBm\n",PtxdBm);
	printf("%.4f\tGtdb\n",GtxdB);
	printf("%.4f\tGrdb\n",GrxdB);
	printf("%.4f\tDistance km\n",dist);
	printf("%.4f\tfreq GHz\n",freq);
	getFresnelRadius(freq,dist);
}

// Fresnel Radius
float getFresnelRadius( float freqGHz, float distKM ) {
	float result = (8.656*sqrt(distKM/(4*freqGHz)));
	printf("\nFresnel Radius = %.4f meters\n", result); // DBPRINT
	return result;
}

// Polarization Loss Factor
float getPLF(float phi) {
	phi = phi*(PI/180);
	float plf = pow(cos(phi),2);
	printf("\nPolarization Loss Factor = %.4f\n\n", plf); // DBPRINT
	return plf;
}

// Antenna Gain calculated using frequency
float antGainFromFreq(float efficiency, float aperature_area, float freq){
  float lam = LIGHT_SPEED/freq;
  //~ float lam = getLambda(freq);
  float antgain = ((10*log10((efficiency*4*PI*aperature_area)/(lam*lam))));
  printf("Antenna Gain = %f\n\n",antgain); // DBPRINT
  return antgain;
}

float getLambda(float freq){
  float clambda = (LIGHT_SPEED/freq);
  //~ printf("\nwavelength = %.6f meters\n",clambda); // DBPRINT
  return clambda;
}
// use lambda in meters 
float getFreq(float lam){
  float freq = (LIGHT_SPEED/lam);
  //~ printf("\nfrequency = %.4f MHz\n",freq/MEGA); // DBPRINT
  return freq;
}
////////////////////////////////
////////////////////////////////

double sqrt(double num){	
	int i;
	double x0, x1, x2;
	x0 = num;		// an initial guess for x0
	x1 = x0;		// Set x1 to x0
	for (i=1; i<=MAX_NUM; i++) {
		x2 = (x1 + num/x1)/2.0;
		if (fabs(x2-x1) < FLT_EPSILON)
			break;
		x1 = x2;	// update x1 for next iteration
		//~ printf("x2 = %lf\n",x2); // DBPRINT
	}
	if (i<MAX_NUM)	// Number of iterations < N
	{
		//~ printf("\nsqrtx(%.2f) = %lf\n", num, x2); // DBPRINT
		return x2;
	}
	else {		// Number of iterations = N
		//~ printf("sqrtx failed to converge\n");
		return -1;
	}
}
////////////////////////////////
////////////////////////////////
char * floatToStringLB(float f){
	char buffer[DATA_SIZE];
	return gcvt(f,DATA_SIZE,buffer);
}

void storeDataInFileLB(float input){
	FILE * fPtr = fopen(TXT_FILE_LB, "a");
	char * data = floatToStringLB(input);
	//fgets(data, DATA_SIZE, fPtr);
	fputs(data, fPtr);
	fputs("\n", fPtr);
  	fclose(fPtr);
}

void clearDataFromFileLB(){
  	FILE * fPtr = fopen(TXT_FILE_LB, "w");
  	fclose(fPtr);
}

int getUserInputLB(){
	float f, d, xs, txp, gtdb, grdb;
  	int exitFlag = 0;
	int var;
	printf("Please choose from the following: \n");
	printf("1 to calculate twoWayPathLossDB \n");
	printf("2 to calculate rxPwrWatts \n");
	printf("3 to calculate rxPwrDBM \n");
  	printf("6 to clear all data from linkBudgetData.txt\n");
	printf("7 for store to file\n");
	printf("8 for quit\n");
	scanf(" %i", &var);
	switch (var) {
		case 1:
			printf("Please enter freq in Ghz: \n");
			scanf(" %f", &f);
			printf("Please enter distance in km: \n");
			scanf(" %f", &d);
			printf("Please enter radar cross section area in m^2: \n");
			scanf(" %f", &xs);
			twoWayPathLossDB(f,d,xs);
      			break;
		case 2:
			printf("Please enter freq in Ghz: \n");
			scanf(" %f", &f);
			printf("Please enter distance in km: \n");
			scanf(" %f", &d);
			printf("Please enter TX power in Watts: \n");
			scanf(" %f", &txp);
			printf("Please enter TX Antenna Gain in dB: \n");
			scanf(" %f", &gtdb);
			printf("Please enter RX Antenna Gain in dB: \n");
			scanf(" %f", &grdb);
			rxPwrWatts(txp,gtdb,grdb,d,f);

			break;
		case 3:
			printf("Please enter freq in Ghz: \n");
			scanf(" %f", &f);
			printf("Please enter distance in km: \n");
			scanf(" %f", &d);
			printf("Please enter TX power in dBm: \n");
			scanf(" %f", &txp);
			printf("Please enter TX Antenna Gain in dB: \n");
			scanf(" %f", &gtdb);
			printf("Please enter RX Antenna Gain in dB: \n");
			scanf(" %f", &grdb);
			rxPwrDBM(txp,gtdb,grdb,d,f);
			break;
		case 6:
			clearDataFromFileLB();
			printf("linkBudgetData.txt is now cleared of all data");
			break;
		case 7:
			printf("Writing data to file\n");
			storeDataInFileLB(tempf);
			break;
		case 8:
			printf("Quitting\n");
			exitFlag = 1;
			break;
		default:
			printf("Wrong choice. Now exiting.\n");
			exit(0);
			break;
	}
	if(0 != exitFlag) return 0;
	getUserInputLB();
	return 0;
}
////////////////////////
/// Main ///
int main(int argc, char const *argv[]) {
	twoWayPathLossDB(24, 50, 10);
	getUserInputLB();
	return 0;
}


//////////////////////////
/////// TX ANTENNA ///////
//////////////////////////
//// TX Power Density ////
//// p = Pt/(4Pi*R^2) * Gt 
//// power density = TX power * Gain

//////////////////////////
/////// RX ANTENNA ///////
//////////////////////////

//// RX Power Density ////
//	Pr = Pt/(4Pi*R^2) * Gt * Aer 
//// Pr = TX power * Gain * Effective Aperature Area of RX antenna (m^2)

//// Effective Aperatue Area ////
// Aer = (lambda^2/4Pi) * Gr 
//// Aer = (c^2/(4Pi*freq^2)) * Gr

//// Friis Transmission Formulas ////

// Pr = Pt * Gt * Gr * lambda^2 / (4Pi*R)^2
// Pr = Pt * Gt * Gr * c^2 / (4Pi*R*freq)^2
