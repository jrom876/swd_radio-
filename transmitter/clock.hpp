
// clock.hpp
#ifndef CLOCK_HPP
#define CLOCK_HPP

class CLOCK {
	private:
		float 		fout; 	// GHz
		float 		control_volt; 	// Volts DC	
			
    public:	
    	
		struct Clock {
			float 		fout; 	
			float 		control_volt; 	
		} clock;
		
		/// CONSTRUCTORS
		CLOCK();
		CLOCK(struct Clock clk);
		
		/// DESTRUCTOR
		~CLOCK();
		
		/// SETTERS        
        float setCVolt	(float v); 
        
        /// GETTERS           
        float getFout() 	{ printf("\nClock fout:\t%.2f\n",fout); return fout; } 
        float getCVolt() 	{ printf("Clock control_volt:\t%.2f\n",control_volt); return control_volt; }   
       
};

#endif

