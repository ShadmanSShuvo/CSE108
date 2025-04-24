/**
 * Jan25 CSE108 
 * Practice Session on Constructor, Destructor, and Function Overloading
 *  
 * 
 * Instructions:
 * * Implement the Circle class with the following functionalities:
 * *    - Default constructor
 * *    - Constructor with parameters for name, coordinates, and radius
 * *    - Copy constructor
 * *    - Method to calculate area and circumference
 * *    - Method to check if a point is inside the circle
 * *    - Method to check if another circle is inside, intersects, or outside this circle
 * *    - Method to translate the circle's position
 * *    - Method to scale the circle
 * *    - Method to display circle properties
 * *    - Setter and getter methods for name and color
 * * 
 * * After implementing the class, test it using the provided main function.
 * * Expected output is provided in the comments at the end of the code. 
 * * Be ready to explain the generated output to the evaluator.
 * 
 * 
 * 
 *  **---**
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// Circle class definition
class Circle{
    double x, y;         // Coordinates of the center of the circle
    double radius;       // Radius of the circle
    char* name;          // Name of the circle
    char* color;         // Color of the circle

public:
    // Default constructor to initialize a circle with default values
    Circle(){
        this->name = new char[10];
        strcpy(this->name, "circle");
        this->color = new char[10];
        strcpy(this->color, "unknown");
        this->x=0;
        this->y=0;
        this->radius=0;
    }

    // Constructor with parameters for a circle's name, coordinates, and radius
    Circle(const char* name, double x, double y, double r){
        //this->name = name;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->x=x;
        this->y=y;
        this->radius=r;
    }

    // Create a new circle from an existing one
    Circle(const Circle &c){
        this->name = new char[10];
        strcpy(this->name, c.name);
        this->x = c.x;
        this->y = c.y;
        this->radius = c.radius;
    }

    // Method to calculate and return the area of the circle
    double area(){
        double area;
        area = 3.1416 * radius * radius;
        return area;
    }
    // Method to calculate and return the circumference of the circle
    double circumference(){
        double circumference;
        circumference = 2* 3.1416 * radius;
        return circumference;
    }

    // Method to check if a point (x, y) is inside the circle
    void contains(double x, double y){
        double dist;
        dist = sqrt((this->x - x)*(this->x - x) + (this->y - y)*(this->y - y));
        if(dist < this->radius){
            cout << "Point (" << x << ", " << y << ") is inside the circle " << this->name << "." <<endl;
        }
        else if(dist > this->radius){
            cout << "Point (" << x << ", " << y << ") is outside the circle " << this->name << "." <<endl;
        }
        else{
            cout << "Point (" << x << ", " << y << ") is on the circle " << this->name << "." <<endl;
        }
    }

    // Method to check if another circle is inside, intersects, or outside this circle
    void contains(Circle c){
        double dist = sqrt(pow(this->x - c.x, 2) + pow(this->y - c.y, 2));
        if(dist + c.radius < this->radius){
            cout << "Circle " << c.name << " is inside the circle " << this->name << "." << endl;
        }
        else if(dist < this->radius + c.radius){
            cout << "Circle " << c.name << " intersects with the circle " << this->name << "." << endl;
        }
        else{
            cout << "Circle " << c.name << " is outside the circle " << this->name << "." << endl;
        }
    }

    // Method to translate the circle's position by a distance (dx, dy)
    void translate(double dx, double dy){
        this->x += dx;
        this->y += dy;
    }

    // Method to translate the circle in a given direction (up, down, left, right)
    void translate(string dir, double dist){
        if(dir=="up"){
            this->y += dist;
        }
        if(dir == "down"){
            this->y -= dist;
        }
        if(dir == "left"){
            this->x -= dist;
        }
        if(dir== "right"){
            this->x += dist;
        }
    }

    // Method to scale the circle by a given factor
    void scale(double factor){
        this->radius *= factor;
    }

    // Method to display circle properties (name, center, radius, area, cirumference, color.)
    void display(){
        cout << "Circle Name: " << this->name << endl;
        cout << "Center: (" << this->x << ", " << this->y << ")" << endl;
        cout << "Radius: " << this->radius << endl;
        cout << "Area: "<< this->area() << endl;
        cout << "Circumference: " << this->circumference() << endl;
        cout << "Color: " << this->color << endl;
    }

    // Setter method for the name of the circle
    void setName(const char* name){
        strcpy(this->name, name);
    }

    // Setter method for the color of the circle
    void setColor(const char* color){
        this->color = new char[10];
        strcpy(this->color, color);
    }

    // Getter method for the circle's name
    char* getName(){
        return this->name;
    }

    // Getter method for the circle's color
    char* getColor(){
        return this->color;
    }

    // Destructor to clean up dynamically allocated memory
    ~Circle(){
        delete[] name;
        delete[] color;
        cout << "Destructing..." << endl;
    }
};

// Main function to test the Circle class
int main() {
    Circle c1("C1", 0, 0, 5);  // Create a circle with name C1 at (0,0) with radius 5
    Circle c2("C2", 6, 4, 1);  
    Circle c3("C3", 2, 2, 3);  
    Circle c4("C4", 1, 2, 2);  
    c1.setColor("Red");  // Set color of circle C1 to Red
    c2.setColor("Blue"); 

    c1.display();  // Display properties of circle C1
    cout << endl;
    c2.display();  
    cout << endl;

    // Test 
    c1.contains(3, 5);  // Point (3, 5) should be outside circle C1
    c1.contains(2, 2);  // Point (2, 2) should be inside circle C1
    c1.contains(c2);    // Check if circle C2 is inside, intersects, or outside circle C1
    c1.contains(c3);    
    c1.contains(c4);    

    // Translate circle C1 by (2, 3)
    c1.translate(2, 3);
    c1.display();
    cout << endl;

    // Translate circle C1 upwards by 2 units
    c1.translate("up", 2);
    c1.display();
    cout << endl;

    // Scale circle C1 by a factor of 2
    c1.scale(2);
    c1.display();
    return 0;
}

// Expected Output:
/*
Circle Name: C1
Center: (0, 0)
Radius: 5
Area: 78.5397
Circumference: 31.4159
Color: Red

Circle Name: C2
Center: (6, 4)
Radius: 1
Area: 3.14159
Circumference: 6.28318
Color: Blue

Point (3, 5) is outside the circle C1.
Point (2, 2) is inside the circle C1.
Circle C2 is outside the circle C1.
Circle C3 intersects with the circle C1.
Circle C4 is inside the circle C1.
Circle Name: C1
Center: (2, 3)
Radius: 5
Area: 78.5397
Circumference: 31.4159
Color: Red

Circle Name: C1
Center: (2, 5)
Radius: 5
Area: 78.5397
Circumference: 31.4159
Color: Red

Circle Name: C1
Center: (2, 5)
Radius: 10
Area: 314.159
Circumference: 62.8318
Color: Red
*/