#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle 2/16/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Sphere.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Sphere.o : Sphere.h Sphere.cpp
	$(CC) $(CPPFLAGS) -c Sphere.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
