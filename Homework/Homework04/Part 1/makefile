#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle 3/1/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Point.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Die.o : Point.h Point.cpp
	$(CC) $(CPPFLAGS) -c Point.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
