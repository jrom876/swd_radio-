
// dds.hpp
#ifndef DDS_HPP
#define DDS_HPP

#include <bitset>
#include <iostream>
#include <cstdint>
#include "clock.hpp"

class DDS {
		
    public:  	
    
		float		clk_in; 	// Freq input from clock
		float		ampl_out;	// Amplitude in mVpp (?)
		uint8_t		selector;	// 8-bit frequency selector	
		float		fout = clk_in/selector; // Freq outputs of DDS
									
		struct DDSynth {			// Direct Digital Synthesizer
			float 		clk_in; 	// Freq input from clock
			float 		ampl_out; 	// Signal amplitude in mVpp 
			uint8_t 	selector;	// 3-bit frequency selector
			float 		fout; 		// Freq output of DDS
		}dds;		
		
		/// CONSTRUCTORS
		DDS();
		DDS(struct DDSynth dds);
				
		/// DESTRUCTOR
		virtual ~DDS();
		
		/// SETTERS        
        //~ virtual float setClkIn	(float);        
        //~ virtual float setFout	(float);               
        //~ virtual uint8_t setSelector	(float); 
        
              
	float setClkIn(float c)		{ clk_in = c; return clk_in; };       
	float setAmpl(float a)		{ ampl_out = a; return ampl_out; };          
	uint8_t setSelector(float s)	{ selector = s; return selector; }; 	       
	float setFout(float f)		{ fout = f; return fout; };  
        
        /// GETTERS           
        float getClkIn() 	{ printf("DDS clk_in:\t%.4f\n",clk_in); return clk_in; }         
        float getAmpl() 	{ printf("DDS amp:\t%.4f\n",ampl_out); return ampl_out; }
        uint8_t getSelector() 	{ printf("DDS selector:\t%d\n",selector); return selector; }        
        float getFout() 	{ printf("DDS fout:\t%.4f\n",fout); return fout; }    
       
};

#endif

