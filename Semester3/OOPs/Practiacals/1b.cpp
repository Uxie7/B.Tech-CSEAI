// b. Write a program to check whether a number is even or odd.


#include <iostream>
using namespace std;

int main(){
    int num;
    cout <<"Enter Number:";
    cin >> num;

    cout << num << " is " << ((num%2 ==0) ? "Even" : "Odd") << endl;

    return 0;
}