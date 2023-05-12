#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle 4/27/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Process.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Process.o : Process.cpp
	$(CC) $(CPPFLAGS) -c Process.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
