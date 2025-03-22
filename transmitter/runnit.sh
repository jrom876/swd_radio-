#!/bin/bash

#~ echo 

#~ g++ -g -std=c++20 -o main main.cpp -lm -lrt
#~ ./main

#~ echo

#~ g++ -g -std=c++20 -o signal signal.cpp -lm -lrt
#~ ./signal

#~ echo

#~ g++ -g -std=c++20 -o clock clock.cpp -lm -lrt
#~ ./clock

#~ g++ -g -std=c++20 -o dds dds.cpp -lm -lrt
#~ ./dds

#~ g++ -g -std=c++20 -o filter filter.cpp -lm -lrt
#~ ./filter

#~ g++ -g -std=c++20 -o attenuator attenuator.cpp -lm -lrt
#~ ./attenuator


#~ g++ -g -std=c++20 -o preamp preamp.cpp -lm -lrt
#~ ./preamp

g++ -g -std=c++20 -o rfswitch rfswitch.cpp -lm -lrt
./rfswitch

#~ g++ -g -std=c++20 -o outamp outamp.cpp -lm -lrt
#~ ./outamp

#~ g++ -g -std=c++20 -o tools tools.cpp -lm -lrt
#~ ./tools

#~ g++ -g -std=c++20 -o transmitter transmitter.cpp -lm -lrt
#~ ./transmitter

#cd ../transmitter/
#~ make -f make-full.mk 
#~ ./transmitter
#~ ./clock
#~ ./dds
#~ ./filter
#~ ./attenuator
#~ ./preamp
#~ echo
#~ ./rfswitch
#~ echo
#~ ./outamp

