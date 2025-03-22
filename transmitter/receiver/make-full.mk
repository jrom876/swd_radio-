#************************************************************************
# 	Makefile for receiver.cpp - Receiver Class for Software Defined Radio
#************************************************************************

# Compiler flags
CC=g++
CFLAGS=-Wall -g

# Debug build settings
DEBUG=-g

# Libraries
LIBS=-lm -lcheck -lpthread -lrt -lsubunit -lcheck_pic 

# Dependencies
DEPS = receiver.cpp receiver.hpp
OBJ = receiver receiver.o receiver.i receiver.s receiver.pie receiver.hex

all: receiver

receiver: receiver.o
	$(CC) -o receiver receiver.o $(LIBS)

receiver.o: $(DEPS)
	$(CC) $(CFLAGS) -c receiver.cpp $(LIBS)
#~ 	$(CC) -E receiver.cpp -o receiver.i $(LIBS)
#~ 	$(CC) -S receiver.cpp -fverbose-asm -o receiver.s $(LIBS)
#~ 	$(CC) -pie receiver.cpp -o receiver.pie $(LIBS)
#~ 	objcopy -O ihex receiver receiver.hex

clean:
	rm -f $(OBJ) 
