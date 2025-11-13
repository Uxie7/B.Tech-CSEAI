// 5. Create a base class that asks the user to enter a complex number having two components – real and img. Also create a method in the base class to display the user input.
// Create a derived class that accepts another complex number from user and adds the complex number of its own with the base. Display the added result. Finally make a third class that is friend of derived and calculates the difference of base complex number and its own complex number. Display the result.

#include <iostream>
using namespace std;

class ComplexBase {
protected:
    int real, img;

public:
    
    ComplexBase() {
        cout << "Enter real part of base complex number: ";
        cin >> real;
        cout << "Enter imaginary part of base complex number: ";
        cin >> img;
    }
    
    void displayBase() {
        cout << "Base Complex Number = " << real << " + " << img << "i" << endl;
    }

    //give access to derived
    int getReal() { return real; }
    int getImg() { return img; }
};

class ComplexDerived;


class ComplexFriend {
public:
    void difference(ComplexDerived d);
};


class ComplexDerived : public ComplexBase {
    int real2, img2; //its own complex number

public:
    ComplexDerived() {
        cout << "\nEnter real part of derived complex number: ";
        cin >> real2;
        cout << "Enter imaginary part of derived complex number: ";
        cin >> img2;
    }

    void displayDerived() {
        cout << "Derived Complex Number = " << real2 << " + " << img2 << "i" << endl;
    }

    //function to add base + derived
    void add() {
        int sumReal = real + real2;
        int sumImg = img + img2;
        cout << "Sum (Base + Derived)= " << sumReal << " + " << sumImg << "i" << endl;
    }

    friend class ComplexFriend;

    //give accessors for friend usage
    int getReal2() { return real2; }
    int getImg2() { return img2; }
};


void ComplexFriend::difference(ComplexDerived d) {
    int diffReal = d.real - d.real2;
    int diffImg = d.img - d.img2;
    cout << "Difference (Base - Derived) = " << diffReal << " + " << diffImg << "i" << endl;
}

int main() {
    ComplexDerived obj;  //object of derived
    cout << endl;
    
    obj.displayBase();   //show base number
    obj.displayDerived();  //show derived number
    obj.add();           //show sum

    ComplexFriend f;
    f.difference(obj);   //show difference

    return 0;
}