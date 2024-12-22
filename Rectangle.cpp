#include "Rectangle.h"
using namespace std;//added cause i dont like to use std:: - Ian


/*
void Point::display() const {
    std::cout << "Point(x=" << x << ", y=" << y << ")";
}

// Shape class 
void Shape::display() const {
    std::cout << "This is a shape" << std::endl;
}

Edge::Edge() : l(1.0);{}
Edge::Edge(double l) : l(l){}
void Edge::display()const{
    std::cout <<  "Edge(Length = " << l <<")"<<;
}
*/

// Rectangle class 
//added Shape("Rectangle") to initialize shape name to "Rectangle" - Ian
Rectangle::Rectangle() : Shape("Rectangle"), corner(Point()), width(1.0), height(1.0) {}// Ian, Julio
//added Shape("Rectangle") same reason as previous constructor and added const to both Edge since we have it in .h we need to have it here -Ian
Rectangle::Rectangle(const Point& corner,const Edge& width,const Edge& height)// Julio, Ian
    : Shape("Rectangle"), corner(corner), width(width), height(height) {}


//fixed lowercase d to D - Ian
//made output into example output from requirements - Ian
void Rectangle::Display() {//Ian,Jake
    cout << "Rectangle Details:" << endl;
    cout << "Name: " << name << endl;
    cout << "Width: " << width.getLength() << endl;
    cout << "Height: " << height.getLength() << endl;
    cout << "Bottom-left Coordinates: (" << corner.getX() << ", " << corner.getY() << ")" << endl;
    cout << "Area: " << Area() << endl; //added cout for area - jake
    cout << "Perimeter: " << Perimeter() << endl; //added cout for perimeter - jake
}
    
    // Compute the area for the rectangle : Julio
    //formula w*h
double Rectangle::Area() const {// Julio
    return width.getLength() * height.getLength();
}

// Compute the perimeter for the rectangle : Julio
// formula 2*(w+h)
double Rectangle::Perimeter() const {// Julio
    return 2 * (width.getLength() + height.getLength());
}
    
    
    
    /*std::cout << "Rectangle(";
    corner.display();
    std::cout << ", width=" << width << ", height=" << height << ")" << std::endl;*/

Rectangle::~Rectangle(){}
