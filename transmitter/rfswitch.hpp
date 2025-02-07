
// rfswitch.hpp
#ifndef RFSWITCH_HPP
#define RFSWITCH_HPP

#include <bitset>
#include <iostream>
#include <cstdint>

class RFSWITCH {
	private:
		float 			freq_in; 	// input - Current freq reading of RF Switch
		float 			ampl_in; 	// input - Current amplitude reading of RF Switch
		bool 			swt; 		// output - High Speed Switch --> 0 == Off, 1 == On
		float 			setpt; 		// input - Amplitude peak setpoint
		uint8_t			atten; 		// output - Attenuator setting, 2^8 range 	
		uint8_t		 	mask;		// input - Cutoff Set Point, 2^8 range 	
		
    public:		
		
		float 			ref_v;		// reference voltage for adc conversion
		float			hyster;		// hysteresis of setpoint, indeterminate units
		float			bandwidth;	// bandwidth, fh - fl, +/- 3dB point
		
		struct RFSwitch {
			float 		freq_in; 	// Current freq setting of RF Switch
			float 		ampl_in; 	// Current amplitude reading of RF Switch
			bool 		swt; 		// High Speed Switch --> 0 == Off, 1 == On
			float		setpt; 		// Amplitude peak setpoint
			uint8_t		atten; 		// TX attenuator setting, 2^8 range
			uint8_t		mask;		// Cutoff Set Point, 2^8 range
		};
	
		/// CONSTRUCTORS
		RFSWITCH();
		RFSWITCH(struct RFSwitch rfswitch);
				
		/// DESTRUCTOR
		virtual ~RFSWITCH();
		
		/// SETTERS            
        virtual void setFin	(float);   
        virtual void setAmpIn	(float);  
        virtual void setSwitch	(bool);  
        virtual void setPt	(float);          
        virtual void setAtten	(uint8_t);          
        virtual void setMask	(uint8_t); 
        
        void setRefV(float);
        void setBW(float bw);
        
        bool checkFreqRange(float bw, float freq);
	float getFreqRange(float low, float hi);
		
        
        /// GETTERS           
        float getFin();  
        float getAmpIn();          
        bool getSwitch();         
        float getPt();
        uint8_t getAtten();
        uint8_t getMask();
        
        float getRefV();
        float getBW();
        
        virtual bool compare_ain_to_setpt(void);
        virtual bool compare_ain_to_setpt(float, float, float);
       
	/// dB converters
        //~ float dBm_to_float (float dbm);
        //~ float float_to_dBm (float flt);
        //~ float dB_to_float (float db);
        //~ float float_to_dB (float flt);
        
        bool flip_switch();
        
	float adjust_signal (float signal, float alpha);
	float adjust_setpoint (float signal, float alpha);
		
	//~ float adc_calc (int adc_value, int adc_min, int adc_max,
			//~ float out_min, float out_max);
							
        //~ float scaleAndShift (float adc_value, 
					//~ float adc_min, 
					//~ float out_max, 
					//~ float out_min, 
					//~ float adc_max);
					
	//~ float round_to_N(float val, int n);
};

#endif


        //~ bool setFin		(float f); 
        //~ virtual void setFin	(float);   
        //~ bool setAmpIn	(float ain);  
        //~ bool setSwitch	(bool state);  
        //~ bool setRefV	(float rv);          
        //~ bool setAtten	(uint8_t a);          
        //~ bool setSetPt	(uint8_t setp); 
