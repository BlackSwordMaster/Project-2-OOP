# Create the executable file and specify its dependencies
prog: Main.o Shape.o Point.o Triangle.o Rectangle.o Circle.o Edge.o DynamicArray.o
	g++ -std=c++11 -o prog Main.o Shape.o Point.o Triangle.o Rectangle.o Circle.o Edge.o DynamicArray.o

# Rules for creating object files
Main.o: Main.cpp Shape.h Point.h Triangle.h Rectangle.h Circle.h Edge.h DynamicArray.h
	g++ -std=c++11 -c Main.cpp

Shape.o: Shape.cpp Shape.h
	g++ -std=c++11 -c Shape.cpp

Point.o: Point.cpp Point.h
	g++ -std=c++11 -c Point.cpp

Triangle.o: Triangle.cpp Triangle.h Shape.h Point.h Edge.h
	g++ -std=c++11 -c Triangle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h Point.h Edge.h
	g++ -std=c++11 -c Rectangle.cpp

Circle.o: Circle.cpp Circle.h Shape.h Point.h
	g++ -std=c++11 -c Circle.cpp

Edge.o: Edge.cpp Edge.h
	g++ -std=c++11 -c Edge.cpp

DynamicArray.o: DynamicArray.cpp DynamicArray.h 
	g++ -std=c++11 -c DynamicArray.cpp

# Rule to delete/clean object files and executable
clean:
	rm -f Main.o Shape.o Point.o Triangle.o Rectangle.o Circle.o Edge.o DynamicArray.o
	rm -f prog
#Instructions
#right click the folder project is in -copy path
#go to terminal cd (copyed path)
#make
#./prog
#make clean(to refresh and update changed stuff)

