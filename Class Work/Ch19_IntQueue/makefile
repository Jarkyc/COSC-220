#Created by Don Spickler  1/28/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o IntQueue.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

IntQueue.o : IntQueue.cpp IntQueue.h
	$(CC) $(CPPFLAGS) -c IntQueue.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
