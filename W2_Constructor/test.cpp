#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// Circle class definition
class Circle {
    double x, y;         // Coordinates of the center of the circle
    double radius;       // Radius of the circle
    char* name;          // Name of the circle
    char* color;         // Color of the circle

public:
    // Default constructor
    Circle() {
        this->name = new char[10];
        strcpy(this->name, "circle");
        this->color = new char[8];
        strcpy(this->color, "Unknown");
        this->x = 0;
        this->y = 0;
        this->radius = 0;
    }

    // Parameterized constructor
    Circle(char* name, double x, double y, double r) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->color = new char[8];
        strcpy(this->color, "Unknown");
        this->x = x;
        this->y = y;
        this->radius = r;
    }

    // Copy constructor
    Circle(const Circle &c) {
        this->name = new char[strlen(c.name) + 1];
        strcpy(this->name, c.name);
        this->color = new char[strlen(c.color) + 1];
        strcpy(this->color, c.color);
        this->x = c.x;
        this->y = c.y;
        this->radius = c.radius;
    }

    // Destructor
    ~Circle() {
        delete[] name;
        delete[] color;
        cout << "Destructing..." << endl;
    }

    double area() {
        return 3.1416 * radius * radius;
    }

    double circumference() {
        return 2 * 3.1416 * radius;
    }

    void contains(double x, double y) {
        double dist = sqrt((this->x - x)*(this->x - x) + (this->y - y)*(this->y - y));
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

    void contains(Circle c) {
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

    void translate(double dx, double dy) {
        this->x += dx;
        this->y += dy;
    }

    void translate(string dir, double dist) {
        if(dir=="up"){
            this->y += dist;
        }
        else if(dir == "down"){
            this->y -= dist;
        }
        else if(dir == "left"){
            this->x -= dist;
        }
        else if(dir== "right"){
            this->x += dist;
        }
    }

    void scale(double factor) {
        this->radius *= factor;
    }

    void display() {
        cout << "Circle Name: " << this->name << endl;
        cout << "Center: (" << this->x << ", " << this->y << ")" << endl;
        cout << "Radius: " << this->radius << endl;
        cout << "Area: "<< this->area() << endl;
        cout << "Circumference: " << this->circumference() << endl;
        cout << "Color: " << this->color << endl;
    }

    void setName(char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setColor(char* color) {
        delete[] this->color;
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
    }

    char* getName() {
        return this->name;
    }

    char* getColor() {
        return this->color;
    }
};

// Main function to test the Circle class
int main() {
    Circle c1("C1", 0, 0, 5);
    Circle c2("C2", 6, 4, 1);
    Circle c3("C3", 2, 2, 3);
    Circle c4("C4", 1, 2, 2);
    c1.setColor("Red");
    c2.setColor("Blue");

    c1.display();
    cout << endl;
    c2.display();
    cout << endl;

    c1.contains(3, 5);
    c1.contains(2, 2);
    c1.contains(c2);
    c1.contains(c3);
    c1.contains(c4);

    c1.translate(2, 3);
    c1.display();
    cout << endl;

    c1.translate("up", 2);
    c1.display();
    cout << endl;

    c1.scale(2);
    c1.display();

    return 0;
}
