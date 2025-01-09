
// preamp.hpp
#ifndef PREAMP_HPP
#define PREAMP_HPP

class PREAMP {
	private:
		float 		freq; 		// Current freq setting of TX Output Amp
		float 		pwr_limit; 	// Power limit in Watts
		float 		gain; 		// Pre Amp gain in dB
		float 		noise; 		// Pre Amp noise in dB
		float 		zout;		// Pre Impedance, assume 50 Ohms	
		
	public:	
 		struct Preamp {
			float 		freq; 		// Current freq setting of TX Output Amp
			float 		pwr_limit; 	// Power limit in Watts
			float 		gain; 		// Pre Amp gain in dB
			float 		noise; 		// Pre Amp noise in dB
			float 		zout;		// Pre Impedance, assume 50 Ohms
		}preamp;
		
		/// CONSTRUCTORS
		PREAMP();
		PREAMP(struct Preamp preamp);
				
		/// DESTRUCTOR
		~PREAMP();
		
		/// SETTERS        
        float setFreq		(float freq);        
        float setPwrLimit	(float pwr_limit);       
        float setGain		(float gain);        
        float setNoise		(float noise);  
        
        /// GETTERS           
        float getFreq() 	{ printf("\nPre amp Frequency:\t%.2f\n",freq); 		return freq; }         
        float getPwrLimit() 	{ printf("Pre amp Power Limit:\t%.2f\n",pwr_limit); return pwr_limit; }         
        float getGain() 	{ printf("Pre amp Gain Limit:\t%.2f\n",gain);		return gain; } 
        float getNoise() 	{ printf("Pre amp Noise:\t\t%f\n",noise); 		return noise; }  
       
};

#endif

