
// clock.hpp
#ifndef CLOCK_HPP
#define CLOCK_HPP

class CLOCK {
	private:
		float 		fout; 	// MHz
		float 		cvolt; 	// Volts DC		
    public:	
    	
		struct Clock {
			float 		fout; 	
			float 		cvolt; 	
		};
	
		struct Clock	clock;	// 

		
		/// CONSTRUCTORS
		CLOCK();
		CLOCK(struct Clock clk);
	
		/// SETTERS        
        float setCVolt	(float v); 
        
        /// GETTERS           
        float getFout() 	{ printf("\nClock fout:\t%.2f\n",fout); return fout; } 
        float getCVolt() 	{ printf("Clock cvolt:\t%.2f\n",cvolt); return cvolt; }   
       
};

#endif

