
// dds.hpp
#ifndef DEFINES_HPP
#define DEFINES_HPP


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

#define PLF(deg) pow(cos(deg*(PI/180)),2) 	// Polarization Loss Factor
#define FRBW(frange,cfreq) (frange/cfreq)	// Fractional Bandwidth of Antenna
#define UV_MAG(x,y,z) sqrt((x*x)+(y*y)+(z*z)) // Unit Vector Magnitude
#define MAX_NUM 100	// The maximum number of iterations

#endif
