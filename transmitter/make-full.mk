#************************************************************************
# 	Makefile for Transmitter - Software Defined Radio
#************************************************************************

# Compiler flags
CC=g++
CFLAGS=-Wall -g

# Debug build settings
DEBUG=-g

# Libraries
LIBS=-lm -lcheck -lpthread -lrt -lsubunit -lcheck_pic 

# Dependencies
DEPS = transmitter.cpp transmitter.hpp \
		attenuator.cpp attenuator.hpp \
		clock.cpp clock.hpp \
		dds.cpp attenuator.hpp \
		outamp.cpp outamp.hpp \
		preamp.cpp preamp.hpp 
		
OBJ = transmitter transmitter.o transmitter.i transmitter.s transmitter.pie transmitter.hex \
		attenuator attenuator.o  \
		clock clock.o \
		dds dds.o \
		outamp outamp.o \
		preamp preamp.o

all: transmitter attenuator clock dds outamp preamp

transmitter: transmitter.o
	$(CC) -o transmitter transmitter.o $(LIBS)

transmitter.o: $(DEPS)
	$(CC) $(CFLAGS) -c transmitter.cpp $(LIBS)
#~ 	$(CC) -E transmitter.cpp -o transmitter.i $(LIBS)
#~ 	$(CC) -S transmitter.cpp -fverbose-asm -o transmitter.s $(LIBS)
#~ 	$(CC) -pie transmitter.cpp -o transmitter.pie $(LIBS)
#~ 	objcopy -O ihex transmitter transmitter.hex

attenuator: attenuator.o
	$(CC) -o attenuator attenuator.o $(LIBS)
attenuator.o: $(DEPS)
	$(CC) $(CFLAGS) -c attenuator.cpp $(LIBS)

clock: clock.o
	$(CC) -o clock clock.o $(LIBS)
clock.o: $(DEPS)
	$(CC) $(CFLAGS) -c clock.cpp $(LIBS)

dds: dds.o
	$(CC) -o dds dds.o $(LIBS)
dds.o: $(DEPS)
	$(CC) $(CFLAGS) -c dds.cpp $(LIBS)

outamp: outamp.o
	$(CC) -o outamp outamp.o $(LIBS)
outamp.o: $(DEPS)
	$(CC) $(CFLAGS) -c outamp.cpp $(LIBS)

preamp: preamp.o
	$(CC) -o preamp preamp.o $(LIBS)
preamp.o: $(DEPS)
	$(CC) $(CFLAGS) -c preamp.cpp $(LIBS)

clean:
	rm -f $(OBJ) 
