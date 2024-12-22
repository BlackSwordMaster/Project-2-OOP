#include "Point.h"
  //default constructor - Ian
  Point::Point() : x(0),y(0){}
  //constructor with default values : Ian
  Point::Point(double x, double y):x(x), y(y){}
  //getter for x : Ian
  double Point::getX(){return x;}
  //getter for y : Ian
  double Point::getY(){return y;}
  //setter for x : Ian
  void Point::setX(double nx){x=nx;}
  //setter for y : Ian
  void Point::setY(double ny){y=ny;}



