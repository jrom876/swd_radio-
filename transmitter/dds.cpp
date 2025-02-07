
//	Package:	sw_def_radio
//	File:		dds.cpp
// 	Purpose:	Define the Transmitter's Direct Digital Synthesizer Class
// 	Author:		jrom876

/// C++ Libraries

#include <bitset>
#include <cstdint>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "clock.hpp"
#include "dds.hpp"
#include "tools.hpp"
using namespace std;


/////////////
// Globals //
/////////////
float tempf;	// Needed for writing data to file

//~ CLOCK::Clock DUMMY_CLOCK = {2.4, 0.5};
//~ DDS::DDSynth DUMMY_DDS = {2.4, 0.3, 0x02};

// Default Constructor
//~ DDS::DDSynth ddsynth = {2.4,0.3,0x02};

// Default Constructor
//~ DDS::DDS(ddsynth);
//~ CLOCK t2 = CLOCK(testStruct);

// Default Constructor
DDS::DDS() {
	DDS::clk_in	= 2.4; 		// GHz
	DDS::ampl_out	= 0.3; 		// mVpp
	DDS::selector 	= 0x02; 	// 0 to 255
	DDS::fout 	= clk_in / selector; 	// GHz
};

// DESTRUCTOR
DDS::~DDS() {std::cout << "Direct Digital Synthesizer Destructor is executed\n";};

// Parameterized Constructor
//~ DDS::DDS(struct DDSynth dds) {
	//~ DDS::clk_in 	= dds.clk_in;	 
	//~ DDS::ampl_out 	= dds.ampl_out;	 	 
	//~ DDS::fout 		= dds.fout;	 
	//~ DDS::selector 	= dds.selector;	
//~ };
       
//~ float DDS::setClkIn(float c)	{ clk_in = c; return clk_in; };       
//~ float DDS::setFout(float f)		{ fout = f; return fout; };        
//~ uint8_t DDS::setSelector(float s)	{ selector = s; return selector; }; 
	
/// Main ///
int main(int argc, char const *argv[]) {
	
	//~ DDS::DDSynth testStruct = {0.3,12.5,4};
	DDS t1 = DDS();
	DDS t3 = DDS();
	
	printf("\nStarting t1 DDS test:\n");
	t1.getClkIn();
	t1.getAmpl();
	t1.getFout();
	t1.getSelector();
		
	printf("\nModifying t1 Values\n");
	t1.setClkIn(4.8);
	t1.getClkIn();
	t1.setSelector(8);
	t1.getSelector();	
	t1.setAmpl(0.3);
	t1.getAmpl();
	//~ t1.setFout(1.4);
	t1.getFout();
	//~ printf("\nAfter that\n");
	
	
	//~ printf("\nStarting t3 DDS test:\n");
	//~ t3.getClkIn();
	//~ t3.getFout();
	//~ t3.getSelector();
		
	//~ printf("\nModifying t3 Values\n");
	//~ t3.setClkIn(0.5);
	//~ t3.getClkIn();
	//~ t3.setFout(1.4);
	//~ t3.getFout();
	//~ t3.setSelector(2);
	//~ t3.getSelector();	
	//~ printf("\nAfter that\n");
	
	
	//~ DDS t2 = DDS(testStruct);	
	//~ printf("\nNew test using teststruct\n");
	//~ t2.setClkIn(0.5);
	//~ t2.getClkIn();
	//~ t2.setFout(1.4);
	//~ t2.getFout();
	//~ t2.setSelector(2);
	//~ t2.getSelector();
	
	//~ printf("\nAfter modifying it\n");
	
	
	return 0;
}
