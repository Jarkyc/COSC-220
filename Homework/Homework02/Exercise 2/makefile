#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle on 2/24/2023

#Makefiles are scripts that tell the compiler how to link all the files properly so all the custom external #includes work.

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o StateData.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

StateData.o : StateData.h StateData.cpp
	$(CC) $(CPPFLAGS) -c StateData.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
