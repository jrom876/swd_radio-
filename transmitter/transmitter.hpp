
// transmitter.hpp
#ifndef TRANSMITTER_HPP
#define TRANSMITTER_HPP

#include "attenuator.hpp"
#include "dds.hpp"
#include "clock.hpp"
#include "outamp.hpp"
#include "preamp.hpp"

class TRANSMITTER {
	private:
		float 		freq; 		// Current freq setting of TX
		float 		gain; 		// TX gain in dB
		float 		noise; 		// TX noise in dB
		float 		dist; 		// TX distance from target
		float 		low;		// Lower edge of TX response
		float 		high;		// Upper edge of TX response
		float 		zout;		// TX Line Impedance in Ohms
		float 		pwr_limit; 	// Power Limit in Watts	
		
	public:
		struct Output_Amp {
			float 		freq; 		// Current freq setting of TX Output Amp
			float 		pwr_limit; 	// Power limit in Watts
			float 		gain; 		// Output Amp gain in dB
			float 		noise; 		// Output Amp noise in dB
			float 		zout;		// Output Impedance, assume 50 Ohms
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
					
		struct DDS {				// Direct Digital Synthesizer
			float 		clk_in; 	// Freq input from clock
			float 		fout; 		// Freq outputs of DDS
			float 		selector;	// 3-bit frequency selector
		};
					
		struct Clock {			// VCO - Frequency Standard
			float 		freq; 	// Current freq setting of Clock
			float 		jitter; 	// TX attenuation
			float 		noise;	// Output Impedance, assume 50 Ohms
		};
		
		/// This data structure will hold the transmitter data
		struct Transmitter {
			Output_Amp	outamp;
			Pre_Amp		preamp;
			Attenuator	atten;
			DDS			dds;
			Clock		clock;
			
		};
		
		union TX_Module {
			Output_Amp	outamp;
			Pre_Amp		preamp;
			Attenuator	atten;
			DDS			dds;
			Clock		clock;
		} tx_module; 
		
		//~ OUTAMP::OUTAMP 		oa1;
		struct Output_Amp	outamp;	// 
		struct Pre_Amp		preamp;	// 
		struct Attenuator	atten;	// 
		struct DDS			dds;	// 
		struct Clock		clock;	//
		struct Transmitter	tx;		// TX data holder

	
		/// CONSTRUCTORS
		TRANSMITTER();
		
		TRANSMITTER(struct Transmitter tx1);
		
		TRANSMITTER(struct Output_Amp	outamp, 
					struct Pre_Amp		preamp,
					struct Attenuator	atten,
					struct DDS			dds,
					struct Clock		clock);
		
		TRANSMITTER(OUTAMP			oa, 
					PREAMP			pa,
					ATTENUATOR		att,
					DDS				dds,
					CLOCK			clk);
				
		/// DESTRUCTOR
		~TRANSMITTER();
			
		/// FUNCTIONS		
		/** float txPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq)
		 * 	Returns TX Signal Strength in Watts given the following parameters:
		 *		Pt			Tx Power in Watts
		 * 		Gtdb		Gain of TX Antenna in dB
		 * 		Grdb		Gain of RX Antenna in dB
		 * 		R			Distance to Target in km
		 * 		freq		Signal Frequency in GHz
		**/
		float txPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq);
		
		/** float txPwrDBM(float PtdBm, float GtdB, float GrdB, float R, float freq)
		 * 	Returns TX Signal Strength in dBm given the following parameters:
		 *		PtdBm		Tx Power in dBm
		 * 		Gtdb		Gain of TX Antenna in dB
		 * 		Grdb		Gain of RX Antenna in dB
		 * 		R			Distance to Target in km
		 * 		freq		Signal Frequency in GHz
		**/
		float txPwrDBM(float PtdBm, float GtdB, float GrdB, float R, float freq);
		
		/// SETTERS   
        float setGain	(float g);           
        float setFreq	(float f);           
        float setDist	(float d);           
        float setLow	(float l);            
        float setHigh	(float h);           
        float setZout	(float z);
        
        /// GETTERS           
        float getFreq() 	{ return freq; } 
        float getGain() 	{ return gain; }            
        float getDist() 	{ return dist; }           
        float getLow() 		{ return low; }            
        float getHigh() 	{ return high; }           
        float getZout() 	{ return zout; }
       
};


#endif

