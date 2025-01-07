#************************************************************************
# 	Makefile for transmitter/lib - Software Defined Radio
#************************************************************************

# Compiler flags
CC=g++
CFLAGS=-Wall -g

# Debug build settings
DEBUG=-g

# Libraries
LIBS=-lm -lcheck -lpthread -lrt -lsubunit -lcheck_pic 

# Dependencies
DEPS = attenuator.cpp attenuator.hpp \
		clock.cpp clock.hpp \
		dds.cpp dds.hpp \
		outamp.cpp outamp.hpp \
		preamp.cpp preamp.hpp
		
OBJ = attenuator attenuator.o  \
		clock clock.o \
		dds dds.o \
		outamp outamp.o \
		preamp preamp.o

all: attenuator clock dds outamp preamp

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
