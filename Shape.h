#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;
//Abstract class Shape:Ian
class Shape{
  //changed private to protected : Ian
  protected:
//Member variable to store the name of the shape:Ian
  string name;
  public:
//constructor that initizalizes the name of the shape:Ian
  Shape(string SN);
//Pure virtual function Display():Ian
  virtual void Display() = 0;

// Pure virtual function Area() - Added calculation : Julio
  virtual double Area() const = 0;

// Pure virtual function Perimeter() - Added calculation : Julio
  virtual double Perimeter() const = 0;

//Virtual destructor to clean up properly:Ian
  virtual ~Shape();
};

#endif
