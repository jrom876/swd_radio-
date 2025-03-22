
// receiver.hpp
#ifndef RECEIVER_HPP
#define RECEIVER_HPP

class RECEIVER {
    public:
		struct Receiver {
			float 		freq; 	// Current freq setting of RX in GHz
			float 		gain; 	// RX gain in dB
			float 		dist; 	// RX distance from Source
			float 		low;	// Lower edge of RX response
			float 		high;	// Upper edge of RX response
			float 		zout;	// Output Impedance in Ohms
		};
		
		struct Receiver	rx;		// RX definition holder
		float 			freq; 	// Current freq setting of RX 
		float 			gain; 	// RX gain in dB
		float 			dist; 	// RX distance from Source
		float 			low;	// Lower edge of Bandwidth of RX
		float 			high;	// Upper edge of Bandwidth of RX
		float	 		zout;	// Output Impedance in Ohms
		
		/// CONSTRUCTORS
		RECEIVER();
		RECEIVER(struct Receiver rx1);
		
		/// FUNCTIONS		
		/** float rxPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq)
		 * 	Returns RX Signal Strength in Watts given the following parameters:
		 *		Pt			Tx Power in Watts
		 * 		Gtdb		Gain of TX Antenna in dB
		 * 		Grdb		Gain of RX Antenna in dB
		 * 		R			Distance to Target in km
		 * 		freq		Signal Frequency in GHz
		**/
		float rxPwrWatts(float Pt, float GtdB, float GrdB, float R, float freq);
		/// Overloaded Method
		float rxPwrWatts(float Pt, float GtdB, struct Receiver rx);
		
		/** float rxPwrDBM(float PtdBm, float GtdB, float GrdB, float R, float freq)
		 * 	Returns RX Signal Strength in dBm given the following parameters:
		 *		PtdBm		Tx Power in dBm
		 * 		Gtdb		Gain of TX Antenna in dB
		 * 		Grdb		Gain of RX Antenna in dB
		 * 		R			Distance to Target in km
		 * 		freq		Signal Frequency in GHz
		**/
		float rxPwrDBM(float PtdBm, float GtdB, float GrdB, float R, float freq);
		
		
		float getFresnelRadius(float freqGHz, float distKM);
		float getPLF(float phi);
		float getFBW(void);
		
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
		
		void printRxData( RECEIVER rx );
		void printRxData( struct Receiver rx );
		void printRxDBM( float PtxdBm, float GtxdB, float GrxdB, float dist, float freq);
};

#endif

