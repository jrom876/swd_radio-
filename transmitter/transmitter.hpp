
// transmitter.hpp
#ifndef TRANSMITTER_HPP
#define TRANSMITTER_HPP

#include <bitset>
#include <iostream>
#include <cstdint>

#include "attenuator.hpp"
#include "dds.hpp"
#include "clock.hpp"
#include "filter.hpp"
#include "outamp.hpp"
#include "preamp.hpp"
#include "rfswitch.hpp"
#include "defines.hpp"

class TRANSMITTER {

    public:
    	
		//~ OUTAMP		oa = OUTAMP(); 
		//~ RFSWITCH		sw = RFSWITCH();
		//~ PREAMP		pa = PREAMP();
		//~ ATTENUATOR		att = ATTENUATOR();
		//~ FILTER		fil = FILTER();
		//~ DDS			dds = DDS();
		//~ CLOCK		clk = CLOCK();
	
    
		float 		freq; 		// Current freq setting of TX		
		float 		bw;		// Band width of TX signal
		float 		gain; 		// TX gain in dB
		float 		noise; 		// TX noise in dB
		float 		dist; 		// TX distance from target
		float 		zout;		// TX Line Impedance in Ohms
    
	
		struct Output_Amp {
			float 		freq; 		// Current freq setting of TX Output Amp
			float 		pwr_limit; 	// Power limit in Watts
			float 		gain; 		// Output Amp gain in dB
			float 		noise; 		// Output Amp noise in dB
			float 		zout;		// Output Impedance, assume 50 Ohms
		};
			
		struct RFSwitch {
			float 		freq_in; 	// Freq setting of RF Switch
			float 		ampl_in; 	// Amplitude reading of RF Switch
			bool 		swt; 		// High Speed Switch --> 0 == Off, 1 == On
			float		ref_v; 		// Reference Voltage for scaling
			uint8_t		atten; 		// TX attenuator feedback setting, 2^8 range
			uint8_t		setpt;		// Cutoff Set Point, 2^8 range
		};
			
		struct Pre_Amp {
			float 		freq; 		// Current freq setting of Pre--Amp
			float 		pwr_limit; 	// Power limit in Watts
			float 		gain; 		// Pre Amp gain in dB
			float 		noise; 		// Pre Amp noise in dB
			float 		zout;		// Output Impedance, assume 50 Ohms
		};
					
		struct Attenuator {
			float 		freq_in; 	// Current freq setting of Attenuator
			float 		atten; 		// TX attenuator setting, 2^7 range
			float 		zout;		// Output Impedance, assume 50 Ohms
		};
			
		struct Filter {
			float 		freq_in;	// Current input freq 
			float 		pwr_limit; 	// Power limit in Watts or dBm 
			float 		gain; 		// Filter gain in dB
			float 		noise; 		// Filter noise in dB
			float 		zout;		// Filter Impedance, assume 50 Ohms
		};
							
		struct DDSynth {			// Direct Digital Synthesizer
			float 		clk_in; 	// Freq input from clock
			float 		fout; 		// Freq outputs of DDS
			float 		selector;	// 3-bit frequency selector
		};
					
		struct Clock {				// VCO - Frequency Standard
			float 		freq; 		// Current freq setting of Clock
			float 		jitter; 	// TX attenuation
			float 		noise;		// Output Impedance, assume 50 Ohms
		};

			
		struct Transmitter {
			float 		freq; 		// Current freq setting of TX		
			float 		bw;		// Band width of TX signal
			float 		gain; 		// TX gain in dB
			float 		noise; 		// TX noise in dB
			float 		dist; 		// TX distance from target
			float 		zout;		// TX Line Impedance in Ohms
		};
	
	
		/// CONSTRUCTORS
		TRANSMITTER();
		
		//~ TRANSMITTER();
		
		TRANSMITTER (struct Transmitter tx1);
		
		//~ TRANSMITTER (struct OUTAMP		outamp, 
				//~ struct RFSwitch	rfsw,
				//~ struct Preamp	preamp,
				//~ struct Attenuator	atten,
				//~ struct Filter	filter,
				//~ struct DDS		dds,
				//~ struct Clock	clock,
										
				//~ float	freq 	= 1.2 * GIGA, 	// Current freq setting of TX 
				//~ float 	bw 	= 0.1 * GIGA,	// Upper edge of TX response
				//~ float	gain 	= 33, 		// TX gain in dB
				//~ float 	noise 	= 23, 		// TX noise in dBm
				//~ float 	dist	= 50, 		// TX distance from target in km
				//~ float 	zout 	= 50.0,		// TX Line Impedance in Ohms
		//~ );
		
		TRANSMITTER (OUTAMP		oa, 
				RFSWITCH	sw,
				PREAMP		pa,
				ATTENUATOR	att,
				FILTER		fil,
				DDS		dds,
				CLOCK		clk,
					
				float	freq 	= 1.2 * GIGA, 	// Current freq setting of TX 
				float 	bw 	= 0.1 * GIGA,	// Upper edge of TX response
				float	gain 	= 33, 		// TX gain in dB
				float 	noise 	= 23, 		// TX noise in dBm
				float 	dist	= 50, 		// TX distance from target in km
				float 	zout 	= 50.0		// TX Line Impedance in Ohms
		);
				
		/// DESTRUCTOR
		~TRANSMITTER();
			
		/// FUNCTIONS		
		/** float txPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq)
		 * 	Returns TX Signal Strength in Watts given the following parameters:
		 *		Pt		Tx Power in Watts
		 * 		Gtdb		Gain of TX Antenna in dB
		 * 		Grdb		Gain of RX Antenna in dB
		 * 		R		Distance to Target in km
		 * 		freq		Signal Frequency in GHz
		**/
		float txPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq);
		
		/** float txPwrDBM(float PtdBm, float GtdB, float GrdB, float R, float freq)
		 * 	Returns TX Signal Strength in dBm given the following parameters:
		 *		PtdBm		Tx Power in dBm
		 * 		Gtdb		Gain of TX Antenna in dB
		 * 		Grdb		Gain of RX Antenna in dB
		 * 		R		Distance to Target in km
		 * 		freq		Signal Frequency in GHz
		**/
		float txPwrDBM(float PtdBm, float GtdB, float GrdB, float R, float freq);
		
		/// SETTERS             
        float setFreq	(float f);           
        float setBW	(float b);  
        float setGain	(float g);           
        float setNoise	(float n);          
        float setDist	(float d);          
        float setZout	(float z);
        
        /// GETTERS           
        float getFreq() 	{ return freq; }           
        float getBW() 		{ return bw; }  
        float getGain() 	{ return gain; }    
        float getNoise() 	{ return noise; }           
        float getDist() 	{ return dist; }         
        float getZout() 	{ return zout; }
       
        float dBm_to_float (float dbm);
        float float_to_dBm (float flt);
};

#endif


		//~ struct Output_Amp {
			//~ float 	freq; 		// Current freq setting of TX Output Amp
			//~ float 	pwr_limit; 	// Power limit in Watts
			//~ float 	gain; 		// Output Amp gain in dB
			//~ float 	noise; 		// Output Amp noise in dB
			//~ float 	zout;		// Output Impedance, assume 50 Ohms
		//~ };
			
		//~ struct RFSwitch {
			//~ float 	freq_in; 	// Freq setting of RF Switch
			//~ float 	ampl_in; 	// Amplitude reading of RF Switch
			//~ bool 	swt; 		// High Speed Switch --> 0 == Off, 1 == On
			//~ float	ref_v; 		// Reference Voltage for scaling
			//~ uint8_t	atten; 		// TX attenuator feedback setting, 2^8 range
			//~ uint8_t	setpt;		// Cutoff Set Point, 2^8 range
		//~ };
			
		//~ struct Pre_Amp {
			//~ float 	freq; 		// Current freq setting of Pre--Amp
			//~ float 	pwr_limit; 	// Power limit in Watts
			//~ float 	gain; 		// Pre Amp gain in dB
			//~ float 	noise; 		// Pre Amp noise in dB
			//~ float 	zout;		// Output Impedance, assume 50 Ohms
		//~ };
					
		//~ struct Attenuator {
			//~ float 	freq_in; 	// Current freq setting of Attenuator
			//~ float 	atten; 		// TX attenuator setting, 2^7 range
			//~ float 	zout;		// Output Impedance, assume 50 Ohms
		//~ };
			
		//~ struct Filter {
			//~ float 	freq_in;	// Current freq setting of TX Output Amp
			//~ float 	pwr_limit; 	// Power limit in Watts or dBm 
			//~ float 	gain; 		// Pre Amp gain in dB
			//~ float 	noise; 		// Pre Amp noise in dB
			//~ float 	zout;		// Pre Impedance, assume 50 Ohms
		//~ };
							
		//~ struct DDS {			// Direct Digital Synthesizer
			//~ float 	clk_in; 	// Freq input from clock
			//~ float 	fout; 		// Freq outputs of DDS
			//~ float 	selector;	// 3-bit frequency selector
		//~ };
					
		//~ struct Clock {		// VCO - Frequency Standard
			//~ float 	freq; 	// Current freq setting of Clock
			//~ float 	jitter; // TX attenuation
			//~ float 	noise;	// Output Impedance, assume 50 Ohms
		//~ };

		//~ /// This data structure will hold the transmitter data
		//~ struct Transmitter {
			//~ Output_Amp	outamp;
			//~ RFSwitch	rfsw;
			//~ Pre_Amp	preamp;
			//~ Attenuator	atten;
			//~ Filter	filter;
			//~ DDS		dds;
			//~ Clock	clock;
			
		//~ };

		//~ struct Output_Amp	outamp;	// 
		//~ struct RFSwitch	rfsw;	// 
		//~ struct Pre_Amp	preamp;	// 
		//~ struct Attenuator	atten;	// 
		//~ struct Filter	filter;	// 
		//~ struct DDS		dds;	// 
		//~ struct Clock	clock;	//
		//~ struct Transmitter	tx;	// TX data holder
