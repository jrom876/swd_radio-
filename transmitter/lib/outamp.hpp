
// outamp.hpp
#ifndef OUTAMP_HPP
#define OUTAMP_HPP

class OUTAMP {
	private:
		float 		freq; 		// Current freq setting of TX Output Amp
		float 		pwr_limit; 	// Power limit in Watts
		float 		gain; 		// Output Amp gain in dB
		float		noise; 		// Output Amp noise in dB
		float		zout;		// Output Impedance, assume 50 Ohms	
    public:	    	
		struct Outamp {
			float 		freq; 		// Current freq setting of TX Output Amp
			float 		pwr_limit; 	// Power limit in Watts
			float 		gain; 		// Output Amp gain in dB
			float 		noise; 		// Output Amp noise in dB
			float 		zout;		// Output Impedance, assume 50 Ohms
		};
	
		struct Outamp	outamp;	// 
		
		/// CONSTRUCTORS
		OUTAMP();
		OUTAMP(struct Outamp oamp);
	
		/// SETTERS        
        float setFreq		(float freq);        
        float setPwrLimit	(float pwr_limit);       
        float setGain		(float gain);        
        float setNoise		(float noise);  
        
        /// GETTERS           
        float getFreq() 	{ printf("\nOutput amp Frequency:\t%.2f\n",freq); 		return freq; }         
        float getPwrLimit() { printf("Output amp Power Limit:\t%.2f\n",pwr_limit); 	return pwr_limit; }         
        float getGain() 	{ printf("Output amp Gain Limit:\t%.2f\n",gain);		return gain; } 
        float getNoise() 	{ printf("Output amp Noise:\t%f\n",noise); 				return noise; }   
       
};

#endif

