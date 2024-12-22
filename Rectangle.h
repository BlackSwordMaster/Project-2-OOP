//moved from my file but mine didnt upload properly so I pasted it here : Julio

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point.h"
#include "Edge.h"
/*
class Point {
public:
    double x, y;

    // Default constructor
    Point();

    // Constructor
    Point(double x, double y);

    // Display Point
    void display() const;
};

// Shape class def
class Shape {
public:
    // Base class for shapes
    virtual void display() const;
};
*/

// Rectangle class def
class Rectangle : public Shape {
private:
    Point corner; // Bottom-left corner of the rectangle
    // Width and height of the rectangle
    // changed double to Edge - Ian
    Edge width, height; 

public:
    // Default constructor
    Rectangle();

    // Constructor 
    Rectangle(const Point& corner, const Edge& width, const Edge& height);

    // Compute the area for the rectangle  : Julio
    double Area() const override;

    // Compute the perimeterfor the rectangle  : Julio
    double Perimeter() const override;

    // Display Rectangle
    //fixed display to match Shape display - Ian
    void Display() override;
    //Added a deconstructor or clean up - Ian
    ~Rectangle();
};

#endif 
