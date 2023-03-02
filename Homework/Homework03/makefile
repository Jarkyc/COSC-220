#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle 3/1/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Array2D.o Die.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Array2D.o : Array2D.h Array2D.cpp
	$(CC) $(CPPFLAGS) -c Array2D.cpp

Die.o : Die.h Die.cpp
	$(CC) $(CPPFLAGS) -c Die.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
