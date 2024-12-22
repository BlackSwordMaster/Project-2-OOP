#ifndef EDGE_H
#define EDGE_H

class Edge {

private :
    double length; //the variable used to represent the length of the edge -- Jake

public:
    Edge(); // the default constructor -- Jake
    Edge(double length); 
    double getLength() const; // the accessor for the length -- Jake
    void setLength(double length); // the mutator for the length -- Jake

};

#endif //
