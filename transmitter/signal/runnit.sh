#!/bin/bash

#~ echo 

g++ -g -std=c++20 -o signal signal.cpp -lm -lrt
./signal

#~ echo

##cd ../signal/
#~ make -f make-full.mk 
#~ ./signal
