#!/bin/bash

cd antenna/
./setup.sh

cd ../receiver/
./setup.sh

cd ../transmitter/
./setup.sh

#~ cd ..signal/
#~ ./setup.sh
#~ make -f make-full.mk 
#~ ./signal

#~ cd ../sw_def_radio/
#~ make -f make-full.mk 
#~ ./sw_def_radio

cd ..
