#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle 3/9/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o PersonData.o CustomerData.o PreferredCustomer.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

PersonData.o : PersonData.h PersonData.cpp
	$(CC) $(CPPFLAGS) -c PersonData.cpp
	
CustomerData.o: CustomerData.h CustomerData.cpp
	$(CC) $(CPPFLAGS) -c CustomerData.cpp

PreferredCustomer.o: PreferredCustomer.h PreferredCustomer.cpp
	$(CC) $(CPPFLAGS) -c PreferredCustomer.cpp
	
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
