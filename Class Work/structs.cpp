#include <iostream>

using namespace std;

// Everything is public in structs
struct Rect
{
    double width = 0;
    double height = 0;
    //double area = width * height; // Due to the fact that area is something that changes if you change the other variables, you shouldn't store it because it won't change unless you write
                                    // struct.area = x*y after you change the other variables
    double area(){
        return width * height;  // This is a better way to store stuff that needs to be calculated, because this is dynamic
    }   // Functions are stored as pointers internally, meaning if we were to override this we would need to figure out a way to tell the object.area() to point to another functions memory loc.

    double area(param){         // Structs support function overloading
        cout << param << endl;
        return width * height;
    }
};

int main(){

    Rect r1;

    r1.width = 17;
    r1.height = 3;

    // OR

    Rect r2 = {5, 7};   // Structs have constructors that are accessed via array notation.

    cout << r1.width << " " << r1.height << " " << r1.area << endl; //Area will be 0, because we are accessing width and height not as it is constructing, but afterwards. Area establishes during
                                                                    // construction

    cout << r2.width << " " << r2.height << " " << r2.area << endl;


}
