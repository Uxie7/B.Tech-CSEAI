// 1. Using conditional operator shown as follows, determine:  
// a. If the ages of Ram and Shyam are input through the keyboard, write a program to determine the younger of the two.




#include <iostream>
using namespace std;

// condition ? expression_if_true : expresion_if_false;
// Expression 1 ? Expression 2 : Expression 3

int main(){
    int ram, shyam;
    cout << "Enter Age Of Ram: ";
    cin >> ram;
    cout << "Enter Age Of Shyam: ";
    cin >> shyam;

    int younger = (ram <shyam) ? ram : shyam;
    cout << "Younger Age is: " << younger << endl;

    // if (ram < shyam)
    //     younger = ram;
    // else
    //     younger = shyam;

        return 0;

}