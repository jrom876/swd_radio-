
// attenuator.hpp
#ifndef ATTENUATOR_HPP
#define ATTENUATOR_HPP

class ATTENUATOR {
	private:
		float 		freq_in; 	// Current freq setting of Attenuator
		float 		atten; 		// Attenuator setting, 2^7 range (?)	
		
	public:		
		struct Attenuator {
			float 		freq_in; 	// Current freq setting of Attenuator
			float 		atten; 		// TX attenuator setting, 2^7 range
		}attenuator;
	
		/// CONSTRUCTORS
		ATTENUATOR();
		ATTENUATOR(struct Attenuator attenuator);
				
		/// DESTRUCTOR
		~ATTENUATOR();
		
		/// SETTERS   
        float setFin	(float f);           
        float setAtten	(float a); 
        
        /// GETTERS           
        float getFin() 		{ printf("\nAttenuator freq_in:\t%.2f\n",freq_in); return freq_in; } 
        float getAtten() 	{ printf("Attenuator atten:\t%.2f\n",atten); return atten; } 
       
};

#endif

