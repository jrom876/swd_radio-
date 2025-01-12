
// attenuator.hpp
#ifndef RFSWITCH_HPP
#define RFSWITCH_HPP

#include <bitset>
#include <iostream>
#include <cstdint>

class RFSWITCH {
	private:
		float 				freq_in; 	// input - Current freq reading of RF Switch
		float 				ampl_in; 	// input - Current amplitude reading of RF Switch
		bool 				swt; 		// output - High Speed Switch --> 0 == Off, 1 == On
		float 				setpt; 		// input - Amplitude peak setpoint
		uint8_t				atten; 		// output - Attenuator setting, 2^8 range 	
		std::bitset<8> 			mask{0};	// input - Cutoff Set Point, 2^8 range 	
		
	public:		
		struct RFSwitch {
			float 			freq_in; 	// Current freq setting of RF Switch
			float 			ampl_in; 	// Current amplitude reading of RF Switch
			bool 			swt; 		// High Speed Switch --> 0 == Off, 1 == On
			float			setpt; 		// Amplitude peak setpoint
			uint8_t			atten; 		// TX attenuator setting, 2^8 range
			std::bitset<8> 		mask;		// Cutoff Set Point, 2^8 range
		};
	
		/// CONSTRUCTORS
		RFSWITCH();
		RFSWITCH(struct RFSwitch rfswitch);
				
		/// DESTRUCTOR
		~RFSWITCH();
		
		/// SETTERS            
        virtual void setFin	(float);   
        virtual void setAmpIn	(float);  
        virtual void setSwitch	(bool);  
        virtual void setPt	(float);          
        virtual void setAtten	(uint8_t);          
        virtual void setMask	(std::bitset<8>); 
        
        bool setFreqRange(float low, float hi, float freq);
        
        /// GETTERS           
        float getFin();  
        float getAmpIn();          
        bool getSwitch();         
        float getPt();
        uint8_t getAtten();
        std::bitset<8> getMask();
        
	/// dB converters
        //~ float dBm_to_float (float dbm);
        //~ float float_to_dBm (float flt);
        //~ float dB_to_float (float db);
        //~ float float_to_dB (float flt);
        
        bool flip_switch();
        
        bool checkFreqRange(float bw, float freq);
	float getFreqRange(float low, float hi);
		
        virtual bool compare_ain_to_setpt(void);
        virtual bool compare_ain_to_setpt(float, float, float);
       
};

#endif


        //~ bool setFin		(float f); 
        //~ virtual void setFin	(float);   
        //~ bool setAmpIn	(float ain);  
        //~ bool setSwitch	(bool state);  
        //~ bool setRefV	(float rv);          
        //~ bool setAtten	(uint8_t a);          
        //~ bool setSetPt	(std::bitset<8> setp); 
