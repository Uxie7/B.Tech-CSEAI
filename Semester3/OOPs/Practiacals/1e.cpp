// e. Write a program to enter two numbers. Make a comparison between them with the conditional operator. If the first number is greater than the second, perform division operation otherwise multiplication operation.

#include <iostream>
using namespace std;

int main(){
    int x,y;
    cout << "Enter 1st Number :";
    cin >> x;
    cout << "Enter 2nd Number :";
    cin >> y;

    int result = (x>y) ? (x/y) : (x*y);
    cout << "Result : " << result <<endl;

    return 0;
}