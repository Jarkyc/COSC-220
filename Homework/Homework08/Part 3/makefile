#Created by Don Spickler  1/21/2022
<<<<<<< HEAD
#Edited by Charles Reigle 3/9/2023
=======
#Edited by Charles Reigle 3/1/2023
>>>>>>> master

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
