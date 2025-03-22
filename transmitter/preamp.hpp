
// preamp.hpp
#ifndef PREAMP_HPP
#define PREAMP_HPP

class PREAMP {

    public:	
    
		float 		freq; 		// freq setting of TX Pre Amp
		float 		pwr_limit; 	// Power limit in Watts
		float 		gain; 		// Pre Amp gain in dB
		float 		noise; 		// Pre Amp noise in dB
		float 		fout;		// 	
		
 		struct Preamp {
			float 		freq; 		// freq setting of TX Pre Amp
			float 		pwr_limit; 	// Power limit in Watts
			float 		gain; 		// Pre Amp gain in dB
			float 		noise; 		// Pre Amp noise in dB
			float 		fout;		// 
		}preamp;
		
		/// CONSTRUCTORS
		PREAMP();
		PREAMP(struct Preamp preamp);
				
		/// DESTRUCTOR
		virtual ~PREAMP();
		
		/// SETTERS        
        float setFreq		(float freq);        
        float setPwrLimit	(float pwr_limit);       
        float setGain		(float gain);        
        float setNoise		(float noise);  
        
        /// GETTERS           
        float getFreq() 	{ printf("\nPre amp Frequency:\t%.2f\n",freq); 		return freq; }         
        float getPwrLimit() { printf("Pre amp Power Limit:\t%.2f\n",pwr_limit); return pwr_limit; }         
        float getGain() 	{ printf("Pre amp Gain Limit:\t%.2f\n",gain);		return gain; } 
        float getNoise() 	{ printf("Pre amp Noise:\t\t%f\n",noise); 			return noise; }  
       
};

#endif

