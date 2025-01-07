#************************************************************************
# 	Makefile for antenna.cpp - Antenna Class for Software Defined Radio
#************************************************************************

# Compiler flags
CC=g++
CFLAGS=-Wall -g

# Debug build settings
DEBUG=-g

# Libraries
LIBS=-lm -lcheck -lpthread -lrt -lsubunit -lcheck_pic 

# Dependencies
DEPS = antenna.cpp antenna.hpp
OBJ = antenna antenna.o antenna.i antenna.s antenna.pie antenna.hex

all: antenna

antenna: antenna.o
	$(CC) -o antenna antenna.o $(LIBS)

antenna.o: $(DEPS)
	$(CC) $(CFLAGS) -c antenna.cpp $(LIBS)
#~ 	$(CC) -E antenna.cpp -o antenna.i $(LIBS)
#~ 	$(CC) -S antenna.cpp -fverbose-asm -o antenna.s $(LIBS)
#~ 	$(CC) -pie antenna.cpp -o antenna.pie $(LIBS)
#~ 	objcopy -O ihex antenna antenna.hex

clean:
	rm -f $(OBJ) 
