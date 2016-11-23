# Makefile for Vra-Xa-Psa game
# Developer Team [Vasilis Tzivaras] & [Vasilis Tasios]

CPP = g++

# Music library
#OPTS =  -I"include" -L"/usr/lib" bin/linux-gcc/libIrrKlang.so -pthread

# OpenGL libraries
OPENGL = -lglut -lGLU -lGL

# Implementation of the Makefile
all:
	$(CPP) src/main.cpp -o vraxapsa $(OPENGL)
clean:
	rm *.o
