#include <iostream>
using namespace std;

// Abstract Base Class
class Shape 
{
public:
    virtual double calculateArea() const = 0; // Pure virtual function for calculating the area
};

class Circle : public Shape // Concrete Derived Class: Circle
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {} // Constructor
    // Implementation of the pure virtual function
    double calculateArea() const override { return 3.14159 * radius * radius; } // Area of a circle: π * r^2
};

class Rectangle : public Shape // Concrete Derived Class: Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {} // Constructor
    // Implementation of the pure virtual function
    double calculateArea() const override { return length * width; }// Area of a rectangle: length * width
};

int main() {
    // Creating objects of derived classes
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Using the abstract base class pointer to access the derived classes
    Shape* shape1 = &circle;
    Shape* shape2 = &rectangle;

    // Calculating and displaying the areas
    cout << "Area of the circle: " << shape1->calculateArea() << endl;
    cout << "Area of the rectangle: " << shape2->calculateArea() << endl;

    return 0;
}
