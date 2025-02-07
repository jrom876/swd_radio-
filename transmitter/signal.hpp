
// signal.hpp
#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <bitset>
#include <iostream>
#include <cstdint>


/// https://en.cppreference.com/w/cpp/language/static

class SIGNAL {
		
    public:	
		    
		float 		freq; 		// freq in Hertz
		float		amp; 		// amplitude in millivolts
		float		bw;			// bandwidth 	
		int 		modul; 		// modulation type
		uint8_t		id;			// uniqe id
    	
		struct Signal {
			float 		freq; 	// freq in Hertz
			float		amp; 	// amplitude in millivolts	
			float		bw;		// bandwidth 	
			int			modul; 	// modulation type
			uint8_t		id;		// uniqe id
		}signal;

		//~ enum Modulation {
			//~ FM = 1,
			//~ AM = 2,
			//~ PM = 3,
			//~ PSK = 4,
			//~ QPSK = 5		
		//~ };
		
		/// CONSTRUCTORS
		SIGNAL();
		SIGNAL(struct Signal signal);
				
		/// DESTRUCTOR
		virtual ~SIGNAL();
		
		/// SETTERS   
        void setFreq	(float f);           
        void setAmp		(float a);  
        void setBW		(float b);           
        void setMod		(int m);           
        void setID		(uint8_t i); 
        
        /// GETTERS           
        float getFreq() { printf("\nSignal frequency:\t%.4f GHz\n",freq); return freq; } 
        float getAmp() 	{ printf("Signal amplitute:\t%.4f Vpp\n",amp); return amp; }  
        float getBW() 	{ printf("Signal bandwidth:\t%.4f GHz\n",bw); return bw; }         
        int getMod() 	{ printf("Signal modulation:\t%i\n",modul); return modul; }         
        int getID() 	{ printf("Signal identifier:\t%d\n",id); return id; } 
       
};

#endif

