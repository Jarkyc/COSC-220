/**
Author: Charles Reigle
Creation Date: 2/16/2023
Last Update: 2.16.2023
Description: Structure and prototypes of the IntArrayList class
Notes:
**/

#ifndef INTARRAYLIST_H
#define INTARRAYLIST_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>


class IntArrayList{
private:
    int *list;
    int size;
    int filled;

public:
    IntArrayList();
    ~IntArrayList();

    void duplicate(IntArrayList&);
    void display(bool vert = false);
    void displayAddress();
    void sort();
    void add(int);
    void concat(const IntArrayList&);
    void remove(int, int);
    void shuffle();
    void sub(int, int);
    void insert(const IntArrayList&, int);
    void insert(int, int);
    int get(int);
    void set(int, int);
    void resize(int);
    int length();

};

#endif
