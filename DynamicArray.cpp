#include "DynamicArray.h"
#include "Shape.h"
#include <fstream>
#include <sstream>    // Included f/sstream for simplicity and easier functionallity : Julio
#include <vector>
#include <cassert>

template<class T>// Default constructor initializes an empty array -> Rafi
DynamicArray<T>::DynamicArray():p(nullptr),capacity(0),numElements(0){}
template<class T>// Constructor initialized with a specific capacity -> Rafi
DynamicArray<T>::DynamicArray(int s):capacity(s),numElements(0) {
    p = new T[capacity];// This is to allocate memory for the array -> Rafi
}
template<class T>// This is the copy constructor which duplicates an array -> Rafi
DynamicArray<T>::DynamicArray(const DynamicArray<T>& d)
    :capacity(d.capacity),numElements(d.numElements) {
    //added cout to match example output: Ian
    cout << "DynamicArray => Copy constructor was called" << endl;
    p = new T[capacity];// This allocates memory for the new array -> Rafi
    for (int i = 0; i < numElements; i++){
        p[i] = d.p[i]; // Copies elements from the source array -> Rafi
    }
}
template <class T>// This is the destructor, cleans up allocated memory -> Rafi
DynamicArray<T>::~DynamicArray() {
    //added cout to match example output-Ian
    cout << "DynamicArray => Destructor was called" << endl;
    delete[] p; // This here frees the allocated memory -> Rafi
}
template <class T>// The assignment operator handles object assignment -> Rafi
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& d) {
    if (this == &d) return *this;// This checks for self-assignment -> Rafi
    //added cout to match exmaple output-Ian
    cout << "DynamicArray => Assignment op was called" << endl;
    delete[] p;// This cleans up existing memory -> Rafi
    capacity = d.capacity;// This copies capacity -> Rafi
    numElements = d.numElements; // This copies number of elements -> Rafi
    p = new T[capacity];// This allocates new memory -> Rafi
    for (int i = 0; i < numElements; i++) {
        p[i] = d.p[i];// This copies elements -> Rafi
    }
    return *this;// This returns the updated object -> Rafi
}
template <class T>// This gets the current capacity of the array -> Rafi
int DynamicArray<T>::getCapacity() const {
    return capacity;
}
template <class T>// This gets the current number of elements in the array -> Rafi
int DynamicArray<T>::getNumElements() const {
    return numElements;
}
template <class T>// This is the overloaded [] operator to access elements by index -> Rafi
T& DynamicArray<T>::operator[](int index){
    assert(index >= 0 && index < numElements); // This checks index bounds -> Rafi
    return p[index];// This returns the element at the specified index -> Rafi
}
template<class T>//This is the function to add an element -> Rafi
void DynamicArray<T>::add(T &e){
    if (numElements >= capacity){
        int newCapacity = (capacity == 0) ? 1: capacity * 2; // Logic to resize -> Rafi
        T* temp = new T[newCapacity];// This allocates new memory -> Rafi
        for (int i = 0; i < numElements; i++){
            temp[i] = p[i];// This copies old elements -> Rafi
        }
        delete[] p;// This deletes old memory -> Rafi
        p = temp;// This updates the pointer -> Rafi
        capacity = newCapacity;// This update capacity -> Rafi
    }
    p[numElements++] = e;// This adds the new element -> Rafi
}
/*template class DynamicArray<Shape*>; 
tells the compiler to generate code for 
DynamicArray with Shape* since the template implementation is in a .cpp file
*/
template class DynamicArray<Shape*>;


// Code Pasted from my Repository after rewriting : Julio
/*
// moved to main.cpp since i misread the instructions
td::vector<Shape*> CreateDynamicArray::CreateDynamicShapeArray(const std::string& filename) {
    std::vector<Shape*> shapes;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl; // to avoid errors and verify : Julio
        return shapes;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string shapeType;
        stream >> shapeType;

        Shape* shape = nullptr;
        if (shapeType == "Circle") {
            double radius;
            stream >> radius;
            shape = new Circle(radius); // Assuming Circle is derived from Shape/Shape class : Julio
        } else if (shapeType == "Rectangle") {
            double width, height;
            stream >> width >> height;
            shape = new Rectangle(width, height); // Assuming Rectangle is derived from Shape/Shape class : Julio
        } else if (shapeType == "Triangle") {
            double base, height;
            stream >> base >> height;
            shape = new Triangle(base, height); // Assuming Triangle is derived from Shape/Shape class : Julio
        }
       

        if (shape) {
            shapes.push_back(shape);
        }
    }

    file.close();
    return shapes;
*/
