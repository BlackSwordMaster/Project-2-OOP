#include "Edge.h"

Edge::Edge() : length(0) {} // default constructor -- Jake

Edge::Edge(double length) : length(length) {} // Initializes the length to a certain value -- Jake

double Edge::getLength() const {  // Accessor for length and returns the current value of length -- Jake
      return length;
}
void Edge::setLength(double newlength) {
      this->length = newlength; //assigns the value of the parameter length to the memeber variable length -- Jake
}
      
