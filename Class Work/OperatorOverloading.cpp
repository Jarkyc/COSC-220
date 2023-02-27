#include <iostream>

using namespace std;

class FeetInches{
private:
    int feet;
    int inches;
    void simplify();
public:
    FeetInches(int f = 0, int i = 0);
    void setFeet(int);
    void setInches(int);
    int getFeet();
    int getInches();
    FeetInches operator +(const FeetInches&);
    FeetInches operator -(const FeetInches&);
    FeetInches operator ++(); // Prefix ++
    FeetInches operator ++(int); // Postfix ++
    bool operator >(const FeetInches&);
    bool operator <(const FeetInches&);
    bool operator ==(const FeetInches&);
    bool operator >=(const FeetInches&);
    bool operator <=(const FeetInches&);
    bool operator !=(const FeetInches&);

};

FeetInches::FeetInches(int f, int i){
    feet = f;
    inches = i;
    simplify();
}

void FeetInches::simplify(){
    if (inches >= 12) {
        feet += (inches / 12);
        inches = inches % 12;
    } else if (inches < 0) {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

void FeetInches::setFeet(int f){
    feet = f;
}

void FeetInches::setInches(int i){
    inches = i;
}

int FeetInches::getFeet(){
    return feet;
}

int FeetInches::getInches(){
    return inches;
}
FeetInches FeetInches::operator +(const FeetInches &right){
    FeetInches temp;

    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}

FeetInches FeetInches::operator -(const FeetInches &right){
    FeetInches temp;

    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

FeetInches FeetInches::operator ++(){
    ++inches;
    simplify();
    return *this;
}

FeetInches FeetInches::operator ++(int){
    FeetInches temp(feet, inches);

    inches++;
    simplify();
    return temp;
}

bool FeetInches::operator >(const FeetInches &right){
    int total = (feet * 12) + inches;
    int totalRight =(right.feet * 12) + right.inches;
    return total > totalRight;
}

bool FeetInches::operator <(const FeetInches &right){
    int total = (feet * 12) + inches;
    int totalRight =(right.feet * 12) + right.inches;
    return total < totalRight;
}

bool FeetInches::operator ==(const FeetInches &right){
    int total = (feet * 12) + inches;
    int totalRight =(right.feet * 12) + right.inches;
    return total == totalRight;
}

bool FeetInches::operator >=(const FeetInches &right){
    return !(*this < right);
}

bool FeetInches::operator <=(const FeetInches &right){
    return !(*this > right);
}

bool FeetInches::operator !=(const FeetInches &right){
    return !(*this == right);
}



int main(){
    FeetInches first(0, 120);
    FeetInches second(10, 0);

    FeetInches third;

    third = first + second;

    cout << third.getFeet() << endl;
    cout << third.getInches() << endl;

    cout << (second <= first) << endl;
    cout << (second >= first) << endl;

}
