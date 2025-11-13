// 7. Write a C++ program to demonstrate multiple inheritance by creating a class cuboid which extends class rectangle, class shape. It calculates area and volume. Use appropriate constructors and member variables.

#include <iostream>
using namespace std;

//base Class : Shape
class Shape {
protected:
    int length;
    int breadth;
public:
    Shape(int l = 0, int b = 0) : length(l), breadth(b) {}
};

//derived Class : Rectangle
class Rectangle : public Shape {
public:
    Rectangle(int l = 0, int b = 0) : Shape(l, b) {}

    int area() const {
        return length * breadth;
    }
};

//derived Class : Cuboid
class Cuboid : public Rectangle {
    int height;
public:
    //constructor: calls Rectangle constructor for length, breadth, sets height separately
    Cuboid(int l, int b, int h) : Rectangle(l, b), height(h) {}

    int volume() const {
        return length * breadth * height;
    }

    void display() const {
        cout << "Area of Rectangle: " << area() << '\n';
        cout << "Volume of Cuboid: " << volume() << '\n';
    }
};

int main() {
    int l, b, h;

    cout << "Enter length, breadth, and height of cuboid: ";
    cin >> l >> b >> h;

    Cuboid c(l, b, h);

    c.display();

    return 0;
}
