#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "Shape.h"

class Circle: public Shape{ // class created by Rafi circle inherits from Shape.h
private:
    Point center; //This is for the center of the circle -> Rafi
    double radius; //This is for the radius of the circle -> Rafi
public:
    Circle(); // This is the default constructor. Initializes circle with Point(0,0) -> Rafi 
    Circle(const Point& c, double r); // Constructor includes the center with point object and double for radius -> Rafi
    void Display()override; //This is the override display function. -> Rafi
          // ^ The Display function will print the circle details -> Rafi

    double Area() const override; // Calculates/returns the area for the circle : Julio
    double Perimeter() const override; // Calculates/returns the perimeter for the circle : Julio


    ~Circle(); //This is the deconstructor which makes sure to clean up  -> Rafi
};

#endif

