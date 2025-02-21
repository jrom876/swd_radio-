// main.cpp

/// C++ Libraries
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "transmitter.hpp"
#include "attenuator.hpp"
#include "dds.hpp"
#include "clock.hpp"
#include "filter.hpp"
#include "outamp.hpp"
#include "preamp.hpp"
#include "rfswitch.hpp"
#include "signal.hpp"
#include "tools.hpp"
using namespace std;

/**
 * round_to_N(float val, int n) 
 * This function truncates unruly doubles
**/
float round_to_N(float val, int n) {	
	switch (n) {
		case 1:
			val = std::ceil(val * 10.0) / 10.0;
			//~ printf("value = %f\n",val);
			break;		
		case 2:
			val = (std::ceil(val * 100.0)) / 100.0;
			//~ printf("value = %f\n",val);
			break;
		case 3:
			val = (std::ceil(val * 1000.0)) / 1000.0;
			//~ printf("value = %f\n",val);
			break;
			
		case 4:
			val = std::ceil(val * 10000.0) / 10000.0;
			//~ printf("value = %f\n",val);
			break;
			
		case 5:
			val = std::ceil(val * 100000.0) / 100000.0;
			//~ printf("value = %f\n",val);
			break;
		default:
			break;
	}	
    //~ double value = 0.123;
    //~ value = std::ceil(value * 100.0) / 100.0;
    //~ std::cout << value << std::endl; // prints 0.13
    return val;
}

/**
 * ADJUSTERS -- using a Simplified IIR Filter to adjust values
 * 
 * This algorithm is VERY useful for embedded control systems!!
 * 
 * It provides Critically Damped control system changes, 
 * which are very smooth and fast.
 * 
 * Doctor Jeff's simplified IIR Filter with filtering factor alpha:
 * 
 * 		speed += alpha*(speed_target - speed);
 * 
 * if alpha == 0.5, we take 2 filter samples,
 * if alpha == 0.2, we take 5 samples,
 * if alpha == 0.1, we take 10 samples...
 * You get the idea... 
 * 
 * alpha == filtering factor
 * speed_target == setpoint
 * speed == currently measured value
 * 
 * */

float adjust_signal (float signal, float alpha, float lim) {		
	int count = 0;
	printf("start signal = %.4f\n", signal);
	while (signal != lim) {
		signal += alpha*(lim - signal);
		count +=1;
		printf("%d\tsignal = %.8f\tsetpoint = %.8f\n", count, signal, lim);
	} 
	printf("signal = %.8f\tsetpoint = %.8f\n", signal, lim);
	return signal;
} 

float adjust_setpoint (float signal, float alpha, float lim) {		
	printf("start signal = %.4f\n", signal);	
	float hysteresis = 0.000;	
	//signal = signal*(1.0 - hysteresis);
	////~ float roundo = round(signal,4);
	int count = 0;
	lim =  lim * (1.0 - hysteresis);
	printf("end signal = %.4f\n", signal);
	while ((lim != ((1.0 + hysteresis) * signal)) && (count < 21)) {
		lim += alpha*(signal - lim);
		////~ printf("%d signal = %.8f\tsetpoint = %.8f\n", count, signal, lim);
		printf("%d signal = %.8f\tsetpoint = %.8f\n", count, round_to_N(signal,3), round_to_N(lim, 4));
		count += 1;
	}
	printf("%d signal = %.8f\tsetpoint = %.8f\n", count, signal, lim);
	return lim;
}

/// dB converters ///
float float_to_dB (float flt) {
	float db = (10*(log10(flt)));
	printf("%.2f Watts = %.2f dB\n",flt, db); 	// DBPRINT
	return db;
	////~ return (10*(log10(flt)));
}

float dB_to_float (float db) {
	float result = pow(10,((db)/10));
	printf("%.2f dB = %.2f Watts\n",db, result); 	// DBPRINT
	return result;
	//~ return pow(10,((db)/10));
}

//////////////////////////////////////////////
//////////////////////////////////////////////

	/// Create static Signal definition
SIGNAL::Signal sig1 = {2.4, 0.5, sig1.freq/10, 3, 0x04};
SIGNAL s1(struct sig1);
	//~ SIGNAL::freq 	= 4.8; 	// GHz
	//~ SIGNAL::amp 	= 0.25; 	// mVpp
	//~ SIGNAL::bw 		= freq/10; 	// GHz
	//~ SIGNAL::modul 	= 1; 		// Mod Type
	//~ SIGNAL::id 		= 0x01;		// unique identifier

//////////////////////////////////////////////
//////////////////////////////////////////////

int main(void) {
	
	int count = 0;
	printf("\nSTART MAIN\n");	
	
	/// SIGNAL -- sig1 ==> instantiated statically outside the main
	
	/// print signal definition									
	printf("\n~~~~~~~ SIGNAL UPDATE %i ~~~~~~~\n", count);
	printf("signal\t\tFreq\tAmpl\tBandW\tModul\tSig ID");						
	printf("\nsig1\t\t%.4f\t%.4lf\t%.4f\t%i\t%d\n",
			sig1.freq, sig1.amp,
			sig1.bw, sig1.modul,
			sig1.id);
	//~ printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	/// Create object definitions
	
	/// CLOCK 
	CLOCK::Clock clk1Struct = {sig1.freq,0.5};
	printf("\nClock\t\tfout\tcntl V\n");
	printf("clk1Struct\t%.2f\t%.2f\n\n",clk1Struct.fout, clk1Struct.control_volt);
	
	/// DDS
	DDS::DDSynth dds1Struct = {clk1Struct.fout, 0.25, (clk1Struct.fout/dds1Struct.selector), 4};
	printf("DDS\t\tclk_in\tfout\tselector\n");
	printf("dds1Struct\t %.2f\t%.2f\t%u\n\n",
			dds1Struct.clk_in,dds1Struct.fout, dds1Struct.selector);
	
	/// Update signal at output of DDS
	count += 1;								
	printf("\n~~~~~~~ SIGNAL UPDATE %i ~~~~~~~\n", count);			
	sig1 = {dds1Struct.fout, 0.5, sig1.freq/10, 3, 0x04};							
	printf("signal\t\tfreq\tamp\tbw\tmodul\tid");						
	printf("\nsig1\t\t%.4f\t%.4lf\t%.4f\t%i\t%d\n",
			sig1.freq, sig1.amp,
			sig1.bw, sig1.modul,
			sig1.id);
	//~ printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	/// FILTER
	FILTER::Filter fil1Struct = {sig1.freq,250,3.03,-65,sig1.freq, 0.12};	
	printf("\nFilter\t\tfreq_in\tpwr_lim\tgain\tnoise\tfreq_out\tbw\n");
	printf("fil1Struct\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\t%.2f\n",
			fil1Struct.freq_in, fil1Struct.pwr_limit,
			fil1Struct.gain, fil1Struct.noise,
			fil1Struct.freq_out, fil1Struct.bandwidth);
		
	/// Update signal at output of Every stage from now on...	
	count += 1;								
	printf("\n~~~~~~~ SIGNAL UPDATE %i ~~~~~~~\n", count);	
	//~ float result = pow(10,((fil1Struct.gain)/10));
	sig1.amp = sig1.amp * pow(10,((fil1Struct.gain)/10));
	sig1 = {fil1Struct.freq_out, sig1.amp, fil1Struct.bandwidth, 3, 0x04};							
	printf("signal\t\tfreq\tamp\tbw\tmodul\tid");								
	printf("\nsig1\t\t%.4f\t%.4lf\t%.4f\t%.2i\t%.2d\n",
			sig1.freq, sig1.amp,
			sig1.bw, sig1.modul,
			sig1.id);
	//~ printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	/// ATTENUATOR
	ATTENUATOR::Attenuator att1struct 
		= {sig1.amp, 0xFF, 0x04, (att1struct.sig_in/(att1struct.mask & att1struct.atten))};
	//~ float 		freq_in; 	// Current freq setting of Attenuator
	//~ uint8_t		atten; 		// output - Attenuator setting, 2^8 range 	
	//~ uint8_t		mask;		// input - Cutoff Set Point, 2^8 range 	
	//~ float 		freq_out; 	
	printf("\nAttenuator\tsig_in\tatten\tmask\tsig_out\n");
	printf("att1struct\t%.4f\t%d\t%d\t%.4f\n",
			att1struct.sig_in, att1struct.atten,
			att1struct.mask, att1struct.sig_out);
	
	
	/// Update signal at output of Every stage from now on...
	count += 1;								
	printf("\n~~~~~~~ SIGNAL UPDATE %i ~~~~~~~\n", count);	
	sig1 = {sig1.freq, att1struct.sig_out, sig1.bw, 3, 0x04};							
	printf("signal\t\tfreq\tamp\tbw\tmodul\tid");								
	printf("\nsig1\t\t%.4f\t%.4lf\t%.4f\t%.2i\t%.2d\n",
			sig1.freq, sig1.amp,
			sig1.bw, sig1.modul,
			sig1.id);
	//~ printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	/// PREAMP
	PREAMP::Preamp pa1Struct = {sig1.freq,250,13.03,-85,50};
	printf("\npre amp\t\tfreq\tpwr_lim\tgain\tnoise\tfout\n");
	printf("pa1Struct\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
				pa1Struct.freq, pa1Struct.pwr_limit,
				pa1Struct.gain, pa1Struct.noise,
				pa1Struct.fout);
	//~ PREAMP::freq		= pamp.freq; 		// Current freq setting in GHz
	//~ PREAMP::pwr_limit	= pamp.pwr_limit; 	// Power limit in Watts
	//~ PREAMP::gain		= pamp.gain; 		// gain in dB
	//~ PREAMP::noise		= pamp.noise; 		// noise in dB
	//~ PREAMP::zout		= pamp.zout;
	
	
	/// Update signal at output of Every stage from now on...
	count += 1;								
	printf("\n~~~~~~~ SIGNAL UPDATE %i ~~~~~~~\n", count);	
	float db = dB_to_float(pa1Struct.gain);
	//~ (10*(log10(pa1Struct.gain)));
	printf("dB\t%.4f\n", db);
	sig1 = {sig1.freq, (sig1.amp * db), sig1.bw, 3, 0x04};							
	printf("signal\t\tfreq\tamp\tbw\tmodul\tid");								
	printf("\nsig1\t\t%.4f\t%.4lf\t%.4f\t%.2i\t%.2d\n",
			sig1.freq, sig1.amp,
			sig1.bw, sig1.modul,
			sig1.id);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	
	/// RFSWITCH
	RFSWITCH::RFSwitch sw1Struct = {sig1.freq,sig1.amp,true, 5.7, 0xFF,0x4};
	sig1.amp = adjust_signal(sig1.amp, 0.5, sw1Struct.setpt);	// adjust_setpoint
	//~ sig1.amp = adjust_setpoint(sig1.amp, 0.5, 0.09);	// adjust_signal
	printf("\nRF Switch\tfreq_in\tampl_in\tswt\tsetpt\tatten\tmask\n");
	printf("sw1Struct\t %.2f\t %.2f\t %i\t %.2f\t %i\t %i\n",
				sw1Struct.freq_in, sw1Struct.ampl_in,
				sw1Struct.swt, sw1Struct.setpt,
				sw1Struct.atten, sw1Struct.mask);	
//~ float 		freq_in; 	// Current freq setting of RF Switch
//~ float 		ampl_in; 	// Current amplitude reading of RF Switch
//~ bool 		swt; 		// High Speed Switch --> 0 == Off, 1 == On
//~ float		setpt; 		// Amplitude peak setpoint
//~ uint8_t		atten; 		// TX attenuator setting, 2^8 range
//~ uint8_t		mask;		// Cutoff Set Point, 2^8 range
	
	
	/// Update signal at output of Every stage from now on...
	count += 1;								
	printf("\n~~~~~~~ SIGNAL UPDATE %i ~~~~~~~\n", count);	
	sig1.amp = (!sw1Struct.swt) ? 0.0 : sig1.amp;
	//~ db = (10*(log10(pa1Struct.gain)));
	
	sig1 = {sig1.freq, sig1.amp, sig1.bw, 3, 0x04};							
	printf("signal\t\tfreq\tamp\tbw\tmodul\tid");								
	printf("\nsig1\t\t%.4f\t%.4lf\t%.4f\t%.2i\t%.2d\n",
			sw1Struct.freq_in, sig1.amp,
			sig1.bw, sig1.modul,
			sig1.id);
	//~ printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	
	//~ t1.adjust_signal (t1.getAmpIn(), 0.5);
	
	/// Test Batteries	
		
	//~ printf("\n\nTesting Second Signal\n");	
	//~ float testFreq = 4.8;
	//~ float testAmp = 0.75;
	//~ float testBW = testFreq/10;
	//~ int testMod = 1;
	//~ uint8_t testID = 0x02;
	//~ SIGNAL::Signal testStruct = {testFreq, testAmp, testBW, testMod, testID};
	//~ SIGNAL s2 = SIGNAL(testStruct);	
	/// End of Signal Tests
	
	//~ ATTENUATOR::Attenuator att1Struct = {1,0};
	//~ printf("clk1Struct\t%.2f\t%.2f\n",clk1Struct.fout, clk1Struct.control_volt);
	
	
	//~ float 		freq_in; 	// Current freq setting of Attenuator
	//~ uint8_t		atten; 		// output - Attenuator setting, 2^8 range 	
	//~ uint8_t		mask;		// input - Cutoff Set Point, 2^8 range 	
	//~ float 		freq_out; 	
	
	//~ PREAMP::Preamp pa1Struct = {1.2,250,20,-85,50};
	//~ printf("clk1Struct\t%.2f\t%.2f\n",clk1Struct.fout, clk1Struct.control_volt);
	
	//~ RFSWITCH::RFSwitch sw1Struct = {1,1.6,true, 1.0, 0x77,0x5};
	//~ printf("clk1Struct\t%.2f\t%.2f\n",clk1Struct.fout, clk1Struct.control_volt);
	
	//~ OUTAMP::Outamp oa1Struct = {1.2,250,20,-85,50};
	//~ printf("clk1Struct\t%.2f\t%.2f\n",clk1Struct.fout, clk1Struct.control_volt);
	
	//~ CLOCK c1 = CLOCK();
	//~ CLOCK c2 = CLOCK(testStruct);
	
	//~ DDS::DDSynth testStruct = {0.3,12.5,4};
	
	//~ CLOCK* 			clk1(clk1Struct);
	//~ CLOCK c2 = CLOCK();
	//~ CLOCK*			clk1 = NULL;
	
	
	//~ CLOCK* clk1 = (CLOCK)malloc(sizeof(CLOCK));
	//~ clk1 = {4.8,0.5};
	//~ free (clk1);
	
	
	//~ CLOCK c1;
	//~ clk1 = &c1;
	//~ printf("clk1\t%.2f\t%.2f\n",clk1->fout, clk1->control_volt);
	//~ printf("fout = %.4f\n",float(clk1->fout));
	//~ DDS* 			dds1;
	//~ FILTER* 		fil1;
	//~ ATTENUATOR* 	att1;
	//~ PREAMP* 		pa1;
	//~ RFSWITCH* 		sw1;
	//~ OUTAMP* 		oa1;
	
	//~ clk1->fout = 4.8; // = {4.8,0.5};
	//~ clk1->setFout(2.4);
	//~ clk1->setFout(2.4);
	//~ clk1->getFout();
	
	//~ clk1->setFout(1.2);
	//~ clk1->getFout();
	
	//~ clk1->setFout(gck - 1.0);
	//~ gck = clk1->getFout();
	
	//~ dds1->setClkIn(1.2);
	//~ dds1->getClkIn();
	
	//~ dds1->setClkIn(gck);
	//~ printf(("%.4f"),dds1->getClkIn());
	
	//~ fil1->setFreq(gck);
	//~ float ff1 = fil1->getFreq();
	//~ printf(("%.4f"),fil1->getFreq());
	
	//~ dds1->setClkIn(2.4);
	//~ printf(("%.4f"),dds1->getClkIn());
	
	//~ dds1->getClkIn();
	//~ float gdds = clk1->getFout();
	//~ clk1->getFout();
	


    return 0;
}
