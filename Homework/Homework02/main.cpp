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

