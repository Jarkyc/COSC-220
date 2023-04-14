#Created by Don Spickler  1/21/2022
#Edited by Charles Reigle 4/7/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Shape.o Rectangle.o Square.o Triangle.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

shape.o : Shape.cpp
	$(CC) $(CPPFLAGS) -c Shape.cpp

rectangle.o : Rectangle.cpp
	$(CC) $(CPPFLAGS) -c Rectangle.cpp

square.o : Square.cpp
	$(CC) $(CPPFLAGS) -c Square.cpp

triangle.o : Triangle.cpp
	$(CC) $(CPPFLAGS) -c Triangle.cpp
clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
