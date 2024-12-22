#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <cassert>
#include <vector>
#include <string>    // Implemented vector. string, and "Shape.h" : Julio
#include "Shape.h"

using namespace std;

template<class T>// Template-based DynamicArray created by Rafi
class DynamicArray {
public:
    DynamicArray();//This is default constructor, it initializes an empty array -> Rafi
    DynamicArray(int s); // The constructor initializes with a specific capacity -> Rafi
    DynamicArray(const DynamicArray<T>& d); // The copy constructor duplicates an array -> Rafi
    ~DynamicArray(); // The destructor cleans up the allocated memory -> Rafi
    DynamicArray<T>& operator=(const DynamicArray<T>& d); // Assignment operator handles the object assignment -> Rafi
    int getCapacity() const; // This is the getter for the current capacity of the array -> Rafi
    int getNumElements() const; // This is the getter for the current number of elements -> Rafi
    T& operator[](int index); // Overloaded [] This operator is used to access elements by index -> Rafi
    void add(T& e); // Function to add an element -> Rafi

private:
    T* p; // This puts pointer to array -> Rafi
    int capacity; // This is the max capacity for the array -> Rafi
    int numElements; // This is for the number of elements in the array -> Rafi
};


/*
Moved to main.cpp since pt is to be done therer : Julio

// New Class for creating a new dynamic array : Julio
class CreateDynamicArray {
public:
    static std::vector<Shape*> CreateDynamicShapeArray(const std::string& filename);
};

*/
#endif


