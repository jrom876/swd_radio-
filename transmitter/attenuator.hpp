
// attenuator.hpp
#ifndef ATTENUATOR_HPP
#define ATTENUATOR_HPP

#include <bitset>
#include <iostream>
#include <cstdint>


class ATTENUATOR {
    public:		
    
	float 		sig_in; 	// Current freq setting of Attenuator
	uint8_t		atten; 		// output - Attenuator setting, 2^8 range 	
	uint8_t		mask;		// input - Cutoff Set Point, 2^8 range 	
	float 		sig_out; 	// output signal (this may become a class)
				
	struct Attenuator {
		float 		sig_in; 	// Current freq setting of Attenuator
		uint8_t		atten; 		// output - Attenuator setting, 2^8 range 	
		uint8_t		mask;		// input - Cutoff Set Point, 2^8 range 	
		float 		sig_out; 	// output signal (this may become a class)
	}attenuator;
	
	/// CONSTRUCTORS
	ATTENUATOR();
	ATTENUATOR(struct Attenuator attenuator);
				
	/// DESTRUCTOR
	virtual ~ATTENUATOR();
		
	/// SETTERS   
        void setSig	(float s);           
        void setAtten	(float a);  
        void setMask	(float m);           
        void setSout	(float o); 
        
        /// GETTERS           
        float getSig() 		{ printf("\nAttenuator sig_in:\t%.8f\n",sig_in); return sig_in; } 
        uint8_t getAtten() 	{ printf("Attenuator atten:\t%d\n",atten); return atten; }  
        uint8_t getMask() 	{ printf("Attenuator mask:\t%d\n",mask); return mask; }         
        float getSout() 	{ printf("\nAttenuator sig_out:\t%.8f\n",sig_out); return sig_out; } 
       
};

#endif

