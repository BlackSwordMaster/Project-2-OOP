#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Shape.h"
#include "Edge.h"

//spelled class correct : Ian
class Triangle: public Shape{
private:
  //added edge member variable a,b : Ian 
  Edge a, b;
  //added vertex point between a,b : Ian
  Point vertex;
  //added angle between a,b : Ian
  double degree;
public:
  //added default constructor : Ian
  Triangle();
  //added constructor with four arguments : Ian
  //added const, Use const to allow binding temporary objects like Edge(l),Point(3,3) - Ian
  Triangle(const Edge& edge1,const Edge& edge2,const Point& v, double d);

//Functions for area and perimeter: Julio
  double Area() const override;
  double Perimeter() const override;


  //added a Override display function : Ian
  void Display() override;
  //added a deconstructor : Ian
  ~Triangle();
};
#endif
