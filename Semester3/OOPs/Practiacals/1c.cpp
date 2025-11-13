// c. Write a program to check largest of three numbers.

#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cout << "Enter num1: ";
    cin >> a;
    cout << "Enter num2: ";
    cin >> b;
    cout << "Enter num3: ";
    cin >> c;

    int largest = (a>b) ? ((a>c) ? a:c) : ((b>c) ? b:c);
    cout << "Largest number is:" << largest << endl;

    return 0;

}