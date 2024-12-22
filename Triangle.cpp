#include "Triangle.h"
#include <cmath>

// added cmath for help with trig functions

  //default constructor : Ian
  Triangle::Triangle():Shape("Triangle"), a(0), b(0), vertex(Point()), degree(0){}// Ian
  //constructor with four arguments : Ian
  Triangle::Triangle(const Edge& edge1,const Edge& edge2,const Point& v, double d):Shape("Triangle"), a(edge1), b(edge2), vertex(v), degree(d){}// Ian

  double Triangle::Area() const { // added area : Julio
    //formula 1/2 * b*h
    return 0.5 * a.getLength() * b.getLength() * sin(degree * M_PI / 180); // Convert to radians for easier undertanding
}

  double Triangle::Perimeter() const { // added Perimeter and clength function : Julio
   double cLength = sqrt(
        pow(a.getLength(), 2) + 
        pow(b.getLength(), 2) - 
        2 * a.getLength() * b.getLength() * cos(degree * M_PI / 180.0)
  );

return a.getLength() + b.getLength() + cLength;
}
//added Display : Ian
  void Triangle::Display(){// Ian, Jake
    cout << "Triangle Details:" << endl;
    cout << "Name: " << name << endl;
    cout << "Length of Edge A: " << a.getLength() << endl;
    cout << "Length of Edge B: " << b.getLength() << endl;
    cout << "Coordinates of Vertex: (" << vertex.getX() << ", " << vertex.getY() << ")" << endl;
    cout << "Angle (in degrees): " << degree << endl;
    cout << "Area: " << Area() << endl; // added cout for area - jake
    cout << "Perimeter: " << Perimeter() << endl; // added cout for perimeter - jake
 
  }
  //added a deconstructor : Ian
  Triangle::~Triangle(){}
