// antenna.hpp
#ifndef ANTENNA_HPP
#define ANTENNA_HPP

/**
	Copyright (C) 2024 
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

class ANTENNA {
	//~ private:
    public:            
        enum ANT_POL {
		horiz,	// horizontal
		vert,	// vertical
		rhcirc,	// right hand circular
		lhcirc	// left hand circular
	};

	enum ANT_TYPE {
		mono,	// 1/4 wavelength dipole
		dipole,	// 1/2 wavelength dipole
		patch,	// PCB patch
		horn,	// microwave horn
		spiral,	// spiral, frequency independent
		logpt, 	// log periodic tooth, frequency independant
		parab,	// parabolic
		arr	// phased-array
	};	
  
	ANTENNA();
	ANTENNA(enum ANT_POL pol,enum ANT_TYPE type,float gain,float freq,float eff,float bw,float area,float zin);
	
	enum ANT_POL	pol; 	// Antenna Polarization
	enum ANT_TYPE	type;	// Antenna Type
	float 		gain; 	// Gain of RX Antenna in dB
	float 		freq;	// Center Frequency in MHz
	float 		eff;	// Antenna Efficiency in %
	float 		bw;		// Antenna Bandwidth in GHz
	float 		area;	// Effective Aperature Area	
	float 		zin;	// Impedance in Ohms
	
	float antGainFromFreqGHz(float efficiency, float aperature_area, float freqGHz);
	float calcAeff(float freqGHz);
		
        float setPol(enum ANT_POL p);   
        float setType(enum ANT_TYPE t);   
        float setGain(float g);           
        float setFreq(float f);           
        float setEff(float e);           
        float setBW(float b);            
        float setArea(float a);            
        float setZin(float z);
            
        enum ANT_POL getPol() 		{ return pol; }            
        enum ANT_TYPE getType() 	{ return type; }      
        float getGain() 		{ return gain; }            
        float getFreq() 		{ return freq; }            
        float getEff() 			{ return eff; }           
        float getBW() 			{ return bw; }            
        float getArea() 		{ return area; }           
        float getZin() 			{ return zin; }

};

#endif

