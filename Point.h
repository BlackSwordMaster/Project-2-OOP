#ifndef POINT_H
#define POINT_H

class Point{
private:
  double x;
  double y;
public:
  //added a default constructor - Ian
  Point();
  //added constructor with default values, if no value is created sets x and y to 0 : Ian
  Point(double x, double y);
  //added getter for x : Ian
  double getX();
  //added getter for y : Ian
  double getY();
  //added setter for x : Ian
  void setX(double nx);
  //added setter for y : Ian
  void setY(double ny);
  

 
};
#endif
  
