
// dds.hpp
#ifndef DDS_HPP
#define DDS_HPP

class DDS {
	private:
		float		clk_in; 	// Freq input from clock
		float		fout; 		// Freq outputs of DDS
		int			selector;	// 3-bit frequency selector	
	public:  								
		struct DDSynth {			// Direct Digital Synthesizer
			float 		clk_in; 	// Freq input from clock
			float 		fout; 		// Freq output of DDS
			int 		selector;	// 3-bit frequency selector
		}dds;		
		
		/// CONSTRUCTORS
		DDS();
		DDS(struct DDSynth dds);
				
		/// DESTRUCTOR
		~DDS();
		
	/// SETTERS        
        float setClkIn		(float clk_in);        
        float setFout		(float freq_out);       
        float setSelector	(float selector); 
        
        /// GETTERS           
        float getClkIn() 	{ printf("DDS clk_in:\t%.2f\n",fout); return clk_in; }         
        float getFout() 	{ printf("DDS fout:\t%.2f\n",fout); return fout; } 
        float getSelector() { printf("DDS selector:\t%d\n",selector); return selector; }   
       
};

#endif

