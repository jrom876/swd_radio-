#************************************************************************
# 	Makefile for sw_def_radio.c - Software Defined Radio
#************************************************************************

# Compiler flags
CC=g++
CFLAGS=-Wall -g

# Debug build settings
DEBUG=-g

# Libraries
LIBS=-lm -lcheck -lpthread -lrt -lsubunit -lcheck_pic 

# Dependencies
DEPS = sw_def_radio.cpp sw_def_radio.hpp
OBJ = sw_def_radio.o sw_def_radio.i sw_def_radio.s sw_def_radio.pie sw_def_radio.hex

all: sw_def_radio

sw_def_radio: sw_def_radio.o
	$(CC) -o sw_def_radio sw_def_radio.o $(LIBS)

sw_def_radio.o: $(DEPS)
	$(CC) $(CFLAGS) -c sw_def_radio.cpp $(LIBS)
	$(CC) -E sw_def_radio.cpp -o sw_def_radio.i $(LIBS)
	$(CC) -S sw_def_radio.cpp -fverbose-asm -o sw_def_radio.s $(LIBS)
	$(CC) -pie sw_def_radio.cpp -o sw_def_radio.pie $(LIBS)
	objcopy -O ihex sw_def_radio sw_def_radio.hex

clean:
	rm -f $(OBJ) 
