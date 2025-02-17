EXPERIMENTAL SOFTWARE DEFINED RADIO FRAMEWORK

This ongoing project is the framework for a C++ Object Oriented Software Defined Radio. It will mathematically model a radar transceiver and antenna, but the algorithms can be applied to many other types of radios.

There are also makefiles and shell scripts to compile and run it all with just a few keystrokes.

Unit tests will be added in the near future.

Bandpass Gaussian Filter Simulator, filter.cpp, will be augmented with code options to generate various types of bandpass filters. 

Options will include 3-element and 2-element, Impedance-matched Chebychev, Butterworth and Bessel bandpass filters. 

See bpf3Calc.c at link below:

https://github.com/jrom876/sciCalc/blob/master/sciCalc-master/sciCalc/bpf3Calc.c


DISCLAIMER:

Only the Transmitter section has anything resembling developed code. 

It is EXPERIMENTAL (i.e. just for fun and education), and as such many parts are unfinished and untested, there are tons of mistakes that need correction, and the code is subject to sudden and nebulous change. Feel free to branch off and add, remove, or fix anything.


BACKGROUND:

I originally wrote much of this RF modeling software several years ago to help me with the development of a ground penetrating radar system. 

