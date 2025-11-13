// 6. Create a base class student. Create a function get() to get the student details including roll number and marks of 3 subjects.
// Create a derived class sports. Declare and define the function getsm() to input the sports marks of the student.
// Create a class reportcard derived from student and sports. Create the function display() to find out the total and average of all marks of the student including sports marks. Display the report card results.

#include <iostream>
using namespace std;

//base class : Student
class Student {
protected:
    int rollno;
    int marks[3];   //marks of 3 subjects out of 100

public:
    void get() {
        cout << "Enter Roll Number: ";
        cin >> rollno;
        cout << "Enter marks of 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }
};

//derived class: Sports
class Sports {
protected:
    int sportsMarks;

public:
    void getsm() {
        cout << "Enter sports marks: ";
        cin >> sportsMarks;  //marks out of 100
    }
};

//multiple Inheritance
class ReportCard : public Student, public Sports {
public:
    void display() {
        int total = sportsMarks;  // start with sports marks
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        float average = total / 4.0;

        cout << "\n------- Report Card -------\n";
        cout << "Roll Number: " << rollno << endl;
        cout << "Subject Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nSports Marks: " << sportsMarks << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
        cout << "---------------------------------\n";
    }
};

int main() {
    ReportCard r;
    r.get();      //student details
    r.getsm();    //sports marks
    r.display();  //report card
    return 0;
}
