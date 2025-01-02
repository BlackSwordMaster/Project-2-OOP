#include <iostream>
#include <fstream>//include this for file input/output - Ian
#include <sstream>
#include <vector>
#include <limits>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Point.h"
#include "Edge.h"
#include "DynamicArray.h"
using namespace std;
//Phase 3 main 

// function to help below Array function for pt 1 : Jlio
Point parsePoint(const std::string& pointStr) {// Julio
    double x, y;
    char discard; 
    std::istringstream iss(pointStr);

    iss >> discard >> x >> discard >> y >> discard;

    if (iss.fail()) {
        throw std::runtime_error("Invalid point format: " + pointStr);  //reduce error : Julio
    }

    return Point(x, y);
}

//Pt 1 file array : JUlio
std::vector <Shape*> CreateDynamicShapeArray(const std::string& filename) {
    std::ifstream file(filename);
    std::vector <Shape*> shapes; // replaced to regualr pointer : Julio

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl; // Error message to alert user : Julio
        return shapes;
    }

    int totalShapes;
    file >> totalShapes;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip the rest of the line : Julio

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string shapeType;
        ss >> shapeType;

// the shapes/shape type configuration below : Julio

        if (shapeType == "Triangle") {
            double sideA, sideB, angle;
            std::string vertexStr;
            ss >> sideA >> sideB >> vertexStr >> angle;
            Point vertex = parsePoint(vertexStr);
            shapes.push_back(new Triangle(sideA, sideB, vertex, angle));
        } else if (shapeType == "Rectangle") {
            std::string vertexStr;
            double length, width;
            ss >> vertexStr >> length >> width;
            Point vertex = parsePoint(vertexStr);
            shapes.push_back(new Rectangle(vertex, length, width));
        } else if (shapeType == "Circle") {
            std::string centerStr;
            double radius;
            ss >> centerStr >> radius;
            Point center = parsePoint(centerStr);
            shapes.push_back(new Circle(center, radius));
        } else {
            std::cerr << "Unknown shape type: " << shapeType << std::endl;
        }
    }



    file.close();
    return shapes; // return and end function
}

//added MaxArea function - Ian
double MaxArea(DynamicArray<Shape*> shapes){// Ian
    //MA = max area
    //to initialize MA -Ian
    double MA = 0.0;
    //loops through each shape in the DynamicArray - Ian
    for(int i = 0; i < shapes.getNumElements(); i++){
        //cA = current area
        //Calculate the current shape's area by calling the Area() - Ian
        double cA = shapes[i]->Area();
        //checks if cA is bigger then MA then updates -Ian
        if(cA > MA){
            MA = cA;
        }
    }
    //returns Max Area - Ian
    return MA;
}
//Phase 1 Main
/*int main(){
Shape **a = new Shape*[3];
a[0] = new Triangle(Edge(4),Edge(3),Point(2,3),90);
a[1] = new Rectangle(Point(2,2),Edge(5),Edge(6));
a[2] = new Circle(Point(3,3),10);
for(int i=0;i<3;i++) {
a[i]->Display();
cout<<endl;
}
return 0;
}
*/
//What output should look like:
/*
Name: Triangle
Length of Edge A: 4
Length of Edge B: 3
Coordinates of Vertex: (2, 3)
Angle (in degrees): 90
Rectangle Details:
Name: Rectangle
Width: 5
Height: 6
Bottom-left Coordinates: (2, 2)
Circle Details:
Center: (3, 3)
Radius: 10
*/
//Phase 2 Main
/*int main(){
Shape **a = new Shape*[3];
a[0] = new Triangle(Edge(4),Edge(3),Point(2,3),90);
a[1] = new Rectangle(Point(2,2),Edge(5),Edge(6));
a[2] = new Circle(Point(3,3),10);
DynamicArray<Shape*> shape1;
shape1.add(a[0]);
DynamicArray<Shape*> shape2(shape1);
shape2.add(a[1]);
DynamicArray<Shape*> shape3;
shape3 = shape2;
shape3.add(a[2]);
cout<<"--------Shape 1--------"<<endl;
for(int i=0;i<shape1.getNumElements();i++){
shape1[i]->Display();
}
cout<<"--------Shape 2--------"<<endl;
for(int i=0;i<shape2.getNumElements();i++){
shape2[i]->Display();
}
cout<<"--------Shape 3--------"<<endl;
for(int i=0;i<shape3.getNumElements();i++){
shape3[i]->Display();
}
cout<<"-----------------------"<<endl;
return 0;
}*/
//What Phase 2 should look like
/*
DynamicArray => Copy constructor was called
DynamicArray => Assignment op was called
--------Shape 1--------
Triangle Details:
Name: Triangle
Length of Edge A: 4
Length of Edge B: 3
Coordinates of Vertex: (2, 3)
Angle (in degrees): 90
Area: 6
Parameter: 12
--------Shape 2--------
Triangle Details:
Name: Triangle
Length of Edge A: 4
Length of Edge B: 3
Coordinates of Vertex: (2, 3)
Angle (in degrees): 90
Area: 6
Parameter: 12
Rectangle Details:
Name: Rectangle
Width: 5
Height: 6
Bottom-left Coordinates: (2, 2)
Area: 30
Due date: Nov 26, 11:59 PM
Parameter: 22
--------Shape 3--------
Triangle Details:
Name: Triangle
Length of Edge A: 4
Length of Edge B: 3
Coordinates of Vertex: (2, 3)
Angle (in degrees): 90
Area: 6
Parameter: 12
Rectangle Details:
Name: Rectangle
Width: 5
Height: 6
Bottom-left Coordinates: (2, 2)
Area: 30
Parameter: 22
Circle Details:
Center: (3, 3)
Radius: 10
Area: 314.159
Parameter: 62.8319
-----------------------
DynamicArray => Destructor was called
DynamicArray => Destructor was called
DynamicArray => Destructor was called
*/
//phase 3 main
int main(){// Jake
    while (true){  // this loops the prompt - Jake
        std::string filename; // created a vcariable to store the filename entered by the user - Jake
        std::cout << "Enter the name of the file or type 'stop' to exit: "; //this is the prompt for the file - Jake
        std::getline(std::cin, filename);
        
        if ( filename == "stop") {  // this checks if the user entered stop and will end the loop - Jake
            break;
        }
    std::vector<Shape*> shapes = CreateDynamicShapeArray(filename); //calls CreateDynamicShapeArray to process the file and create shapes - Jake
    std::cout << "Shape Details:\n";
    for (int i = 0; i < static_cast<int>(shapes.size()); ++i){ 
       cout << "--------------------------------------\n";
       shapes[i]->Display(); //calls display() to print the shapes details -Jake
       cout << endl;
       cout << "--------------------------------------\n";
    }

    DynamicArray<Shape*> dynamicShapes; // this creates a dynamicarray of raw pointers
    for (int i = 0; i < static_cast<int>(shapes.size()); ++i) {
            dynamicShapes.add(shapes[i]); 
    }
    double maxArea = MaxArea(dynamicShapes);  //calls max area to get the max area and then prints it out - Jake
    cout << "\n=========== Maximum Area ===========\n";
    cout << maxArea << "\n";
    cout << "====================================\n\n";
    cout << "--------------------------------------\n";
}
return 0;
}




