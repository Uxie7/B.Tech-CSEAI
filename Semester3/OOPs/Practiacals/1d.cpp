// d. Write a program to check whether a number is positive or negative.

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter Number :";
    cin >> n;

    cout << n << " is " << ((n>=0) ? "Positive":"Negative") <<endl;

    return 0;
}