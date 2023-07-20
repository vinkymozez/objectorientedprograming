#include <iostream>
#include <cmath>
using namespace std;

class Shapes {
public:
    double rectangleArea() {
        double length, width;
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
        double area = length * width;
        cout << "Area of the rectangle is " << area << endl;
        return area;
    }

    double squareArea() {
        double side;
        cout << "Enter side length: ";
        cin >> side;
        double area = side * side;
        cout << "Area of the square is " << area << endl;
        return area;
    }

    double circleArea() {
        double radius;
        cout << "Enter the radius: ";
        cin >> radius;
        double area = M_PI * radius * radius;
        cout << "Area of the circle is " << area << endl;
        return area;
    }
};

int main() {
    Shapes shapeCalculator;

    int choice;
    cout << "Shapes Calculator\n";
    cout << "1. Rectangle\n";
    cout << "2. Square\n";
    cout << "3. Circle\n";
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            shapeCalculator.rectangleArea();
            break;
        case 2:
            shapeCalculator.squareArea();
            break;
        case 3:
            shapeCalculator.circleArea();
            break;
        default:
            cout << "Invalid choice. Please select 1, 2, or 3." << endl;
    }

    return 0;
}
