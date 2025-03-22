
// filter.hpp
#ifndef FILTER_HPP
#define FILTER_HPP

class FILTER {
	
    public:	
    
		float 		freq_in; 	// Input signal
		float 		pwr_limit; 	// Power limit in Watts or dBm 
		float 		gain; 		// gain or loss in dB
		float 		noise; 		// noise in dB
		float 		freq_out;	// Attenuated output signal
		float		bandwidth;	// bandwidth, fh - fl, +/- 3dB point
    
 		struct Filter {
			float 		freq_in; 	// Input signal
			float 		pwr_limit; 	// Power limit in Watts or dBm 
			float 		gain; 		// gain or loss in dB
			float 		noise; 		// noise in dB
			float 		freq_out;	// Attenuated output signal	
			float		bandwidth;	// bandwidth, fh - fl, +/- 3dB point
		}filter;
		
		/// CONSTRUCTORS
		FILTER();
		FILTER(struct Filter filter);
				
		/// DESTRUCTOR
		~FILTER();
		
		/// SETTERS        
        //~ virtual float setFreq		(float freq_in);        
        //~ virtual float setPwrLimit	(float pwr_limit);       
        //~ virtual float setGain		(float gain);        
        //~ virtual float setNoise		(float noise);      
        //~ virtual float setFout		(float freq_out);      
        //~ virtual float setBW			(float bandwidth);  
        
        float setFreq		(float f)	{ freq_in = f; 		return freq_in; };        
		float setPwrLimit	(float p)	{ pwr_limit = p; 	return pwr_limit; };       
		float setGain		(float g)	{ gain = g; 		return gain; };        
		float setNoise		(float n)	{ noise = n; 		return noise; };  
		float setFout		(float f)	{ freq_out = f; 	return freq_out; }; 
		float setBW			(float f)	{ bandwidth = f; 	return bandwidth; }; 
        
        /// GETTERS           
        float getFreq() 	{ printf("\nFilter Frequency:\t%.2f\n",freq_in); 	return freq_in; }         
        float getPwrLimit() { printf("Filter Power Limit:\t%.2f\n",pwr_limit);	return pwr_limit; }         
        float getGain() 	{ printf("Filter Gain Limit:\t%.2f\n",gain);		return gain; } 
        float getNoise() 	{ printf("Filter Noise:\t\t%f\n",noise); 			return noise; }  
        float getFout() 	{ printf("Output Frequency:\t\t%f\n",freq_out); 	return freq_out; }  
        float getBW() 		{ printf("Filter Bandwidth:\t%f\n",bandwidth); 	return bandwidth; }  
        
        void showFilterElements (FILTER t1);
        
};

#endif

