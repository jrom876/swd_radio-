#************************************************************************
# 	Makefile for Transmitter - Software Defined Radio
#************************************************************************

# Compiler flags
CC=g++
CFLAGS=-Wall -g -std=c++20

# Debug build settings
DEBUG=-g

# Libraries
LIBS=-lm -lcheck -lpthread -lrt -lsubunit -lcheck_pic 

# Dependencies
DEPS = transmitter.cpp transmitter.hpp \
		attenuator.cpp attenuator.hpp \
		clock.cpp clock.hpp \
		dds.cpp dds.hpp \
		filter.cpp filter.hpp \
		outamp.cpp outamp.hpp \
		preamp.cpp preamp.hpp  \
		rfswitch.cpp rfswitch.hpp \
		signal.cpp signal.hpp \
		tools.cpp tools.hpp \
		main.cpp
		
OBJ = transmitter transmitter.o transmitter.i transmitter.s transmitter.pie transmitter.hex \
		attenuator attenuator.o  \
		clock clock.o \
		dds dds.o \
		filter filter.o \
		outamp outamp.o \
		preamp preamp.o \
		rfswitch rfswitch.o \
		signal signal.o \
		tools tools.o \
		main main.o

all: main transmitter attenuator clock dds filter outamp preamp rfswitch signal tools

main: main.o
	$(CC) -o main main.o $(LIBS)
main.o: $(DEPS)
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

signal: signal.o
	$(CC) -o signal signal.o $(LIBS)
signal.o: $(DEPS)
	$(CC) $(CFLAGS) -c signal.cpp $(LIBS)
	
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

filter: filter.o
	$(CC) -o filter filter.o $(LIBS)
filter.o: $(DEPS)
	$(CC) $(CFLAGS) -c filter.cpp $(LIBS)

outamp: outamp.o
	$(CC) -o outamp outamp.o $(LIBS)
outamp.o: $(DEPS)
	$(CC) $(CFLAGS) -c outamp.cpp $(LIBS)

preamp: preamp.o
	$(CC) -o preamp preamp.o $(LIBS)
preamp.o: $(DEPS)
	$(CC) $(CFLAGS) -c preamp.cpp $(LIBS)

rfswitch: rfswitch.o
	$(CC) -o rfswitch rfswitch.o $(LIBS)
rfswitch.o: $(DEPS)
	$(CC) $(CFLAGS) -c rfswitch.cpp $(LIBS)

tools: tools.o
	$(CC) -o tools tools.o $(LIBS)
tools.o: $(DEPS)
	$(CC) $(CFLAGS) -c tools.cpp $(LIBS)
	
clean:
	rm -f $(OBJ) 
