#include <iostream>
#include "IntArrayList.h"

using namespace std;

int main(){
    IntArrayList l1;
    for(int i = 0; i < 20; i++){
        l1.add(i + 1);
    }

    IntArrayList l2;
    l1.duplicate(l2);

    l1.display();

    return 0;
}

/**
TODO
- Make resize always set filled to the proper size, but set size to always be a multiple of 10.

**/
