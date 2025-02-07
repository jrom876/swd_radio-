
// clock.hpp
#ifndef CLOCK_HPP
#define CLOCK_HPP

class CLOCK {			
    public:	
    	
		float 	fout; 		// GHz
		float 	control_volt; 	// Volts DC	
		
		struct Clock {
			float 	fout; 	
			float 	control_volt; 	
		} clock;
		
		/// CONSTRUCTORS
		CLOCK();
		CLOCK(struct Clock clk);
		
		/// DESTRUCTOR
		virtual ~CLOCK();
		
		/// SETTERS        
        //~ virtual float setFout	(float);       
        //~ virtual float setCVolt	(float);  
              
        void setFout(float f)	{ fout = f; };       
	void setCVolt(float cv)	{ control_volt = cv; }; 
        
        /// GETTERS           
        float getFout() 	{ printf("\nClock fout:\t%.2f\n",fout); return fout; } 
        float getCVolt() 	{ printf("Clock control_volt:\t%.2f\n",control_volt); return control_volt; }   
       
};

#endif

