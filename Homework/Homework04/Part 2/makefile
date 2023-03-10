#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle 3/9/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Matrix.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Die.o : Matrix.h Matrix.cpp
	$(CC) $(CPPFLAGS) -c Matrix.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
