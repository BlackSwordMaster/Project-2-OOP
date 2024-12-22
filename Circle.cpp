#include "Circle.h"
#include <iostream> 
#include <cmath> //added for easier calculation : Julio
using namespace std;
// Default constructor -> Rafi 
Circle::Circle() : Shape("Circle"), center(Point()), radius(0) {}//contributed -Rafi 
                    // ^Initializes parent class shape with name "Circle" sets center to (0,0) and rad = 0
 // This is the constructor with arguments to initialize -> Rafi
//added const, Use const to allow binding temporary objects like Point(3,3) - Ian
Circle::Circle(const Point& c, double r) : Shape("Circle"), center(c), radius(r) {} //contributed Rafi

//added function to calculate Area : Julio
double Circle::Area() const {//contributed Julio
    return M_PI * radius * radius; // Area = πr²
}

// Computes the perimeter (circumference) of the circle : Julio
double Circle::Perimeter() const {//contributed Julio
    return 2 * M_PI * radius; // Perimeter = 2πr
}


void Circle::Display() {//contributed Rafi,Julio,Jake
    cout<<"Circle Details:"<<endl; 
    cout<<"Center: ("<<center.getX()<<", "<< center.getY()<<")"<<endl; // Calls getX+Y functions of Point class to get x and y -> Rafi
    cout<<"Radius: "<<radius<<endl; // This prints the radius -> Rafi
    cout << "Area: " << Area() << endl; // added cout for area - jake 
    cout << "Perimeter: " << Perimeter() << endl; // added cout for perimeter - jake
}
// This is the destructor.This handles resources -> Rafi  
Circle::~Circle() {} //contributed Rafi
