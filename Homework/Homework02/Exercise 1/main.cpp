/**
Author: Charles Reigle
Creation Date: 2/23/2023
Last Update: 2/23/2023
Description: IntArrayList usage
User Interface:
Notes:
**/


#include <iostream>
#include "IntArrayList.h"

using namespace std;

int main(){
    IntArrayList li;
    li.resize(10);

    for(int i = 0; i < 10; i++){
        li.set(i, i+1);
    }

    li.sub(3, 7);
    li.display();
}

