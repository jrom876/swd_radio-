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
DEPS = signal.cpp signal.hpp 
		
OBJ = signal signal.o  

all: signal 

signal: signal.o
	$(CC) -o signal signal.o $(LIBS)
signal.o: $(DEPS)
	$(CC) $(CFLAGS) -c signal.cpp $(LIBS)

clean:
	rm -f $(OBJ) 
