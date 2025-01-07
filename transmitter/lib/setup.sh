#!/bin/bash

make -f make-full.mk 
./attenuator
./clock
./dds
./outamp
./preamp

