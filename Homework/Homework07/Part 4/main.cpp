#include <iostream>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "LinkedList.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(0));

    LinkedList<Shape*> list;
    int num;

    cout << "How many shapes do you wish to create: ";
    cin >> num;

    for(int i = 0; i < num; i++){
        int r = rand() % 3;
        string color = "red";
        int s1 = rand() % ((15 - 5) + 1) + 5;
        int s2 = rand() % ((15 - 5) + 1) + 5;
        int s3 = rand() % ((15 - 5) + 1) + 5;
        if(r == 0){
            Triangle *t = new Triangle(s1, s2, s3, color);
            list.push_back(t);
        } else if(r == 1){
            Rectangle *r = new Rectangle(s1, s2, color);
            list.push_back(r);
        } else if(r == 2){
            Square *s = new Square(s1, color);
            list.push_back(s);
        }
    }

    for(int i = 0; i < num; i++){
        list[i]->draw();
    }

    // Clear the memory
    for(int i = 0; i < list.length(); i++){
        Shape *curr = list.pop_front();
        delete curr;
    }
}
