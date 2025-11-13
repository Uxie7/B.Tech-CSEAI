// 3. Write a program to input marks of five subjects Physics, Chemistry, Biology, Mathematics and Computer. Calculate percentage and grade according to following:

// Percentage >= 90% : Grade A
// Percentage >= 80% : Grade B
// Percentage >= 70% : Grade C
// Percentage >= 60% : Grade D
// Percentage >= 40% : Grade E
// Percentage < 40% : Grade F


#include <iostream>
using namespace std;

int main(){
    int phy, chem, bio, math, comp;

    cout<< "Physics: ";
    cin >> phy;
    cout<< "Chemistry: ";
    cin >> chem;
    cout<< "Biology: ";
    cin >> bio;
    cout<< "Mathematics: ";
    cin >> math;
    cout<< "Computer: ";
    cin >> comp;

    float percentage = (phy + chem + bio + math + comp)/5.0;

    char grade = (percentage >=90) ? 'A': (percentage >=80) ? 'B':  (percentage >=70) ? 'C': (percentage >=60) ? 'D': (percentage >=40) ? 'E': 'F';
    
    cout << "Percentage: " << percentage << "%" << endl;
    cout << "Grade:" << grade << endl;
                  
    return 0 ;
}