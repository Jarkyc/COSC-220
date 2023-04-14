#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle 4/12/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Date.o FeetInches.o Person.o NBAPlayer.o NFLPlayer.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Date.o : Date.h Date.cpp
	$(CC) $(CPPFLAGS) -c Date.cpp

FeetInches.o : FeetInches.h FeetInches.cpp
	$(CC) $(CPPFLAGS) -c FeetInches.cpp

Person.o : Person.h Person.cpp
	$(CC) $(CPPFLAGS) -c Person.cpp

NBAPlayer.o : NBAPlayer.h NBAPlayer.cpp
	$(CC) $(CPPFLAGS) -c NBAPlayer.cpp

NFLPlayer.o : NFLPlayer.h NFLPlayer.cpp
	$(CC) $(CPPFLAGS) -c NFLPlayer.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
