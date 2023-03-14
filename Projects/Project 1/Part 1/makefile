#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle 3/13/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Date.o StockDay.o StockList.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Date.o : Date.h Date.cpp
	$(CC) $(CPPFLAGS) -c Date.cpp

StockDay.o : StockDay.h StockDay.cpp
	$(CC) $(CPPFLAGS) -c StockDay.cpp

StockList.o : StockList.h StockList.cpp
	$(CC) $(CPPFLAGS) -c StockList.cpp
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
