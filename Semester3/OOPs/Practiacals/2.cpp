// 2. Write a program to input angles of a triangle and check whether triangle is valid or not.

#include <iostream>
using namespace std;

int main(){
    int angle1, angle2, angle3;
    cout << "Angle1:" ;
    cin >> angle1;
    cout << "Angle2:" ;
    cin >> angle2;
    cout << "Angle3:" ;
    cin >> angle3;

    string result = (angle1 + angle2 +angle3 == 180) ? " Valid Triangle" : "Invalid Triangle";
    cout << result << endl;

    return 0;

}
