
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
		}outamp;
		
		/// CONSTRUCTORS
		OUTAMP();
		OUTAMP(struct Outamp oamp);
				
		/// DESTRUCTOR
		virtual ~OUTAMP();
		
		/// SETTERS        
        float setFreq		(float freq);        
        float setPwrLimit	(float pwr_limit);       
        float setGain		(float gain);        
        float setNoise		(float noise);  
        
        /// GETTERS           
        float getFreq();        
        float getPwrLimit();        
        float getGain();
        float getNoise();
       
};

#endif

