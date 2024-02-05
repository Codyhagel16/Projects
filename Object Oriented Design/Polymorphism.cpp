//This project defines a class hierarchy in which there are three dictated classes. The classes are intended to represent geometrical shapes and calculate properties like area, radius, and width. This project was made to illustarte the concepts of inheritance, polymorphism, constructors, and encapsulation.//

#include <iostream>
using namespace std;

class CodyHagel //declare class CodyHagel
{
  protected:
    double perimeter; //store the perimeter value

  public:
    CodyHagel() 
    {
        perimeter = 0; //initalize perimeter to 0
    }

    CodyHagel(double p) 
    {
        perimeter = p; //set perimeter to p so it can be used as a double value
    }

    double getPerimeter() //return value of the perimeter
    {
        return perimeter;
    }

    virtual void printCodyHagel() //prints value of perimeter
    {
        cout << "Original: " << endl;
        cout << "Perimeter: " << perimeter << endl;
        cout << endl;
    }
};

class Cody: public CodyHagel //inherits from CodyHagel
{
  private: //declares two private variables, area and radius
    double area;
    double radius;

  public:
    Cody() : CodyHagel(20) //calls CodyHagel and fixes perimeter value to 20
    {
        // Perimeter is initialized through the base class constructor
    }

    double findArea() //finds area of the circle based on the perimeter
    {
        area = (perimeter * perimeter) / 12.56;
        return area;
    }

    double findRadius() //finds value of the radius based on the perimeter
    {
        radius = perimeter / 6.28;
        return radius;
    }

    void printCodyHagel() override //ovverides the abse class functions to print specific to a circle
    {
        cout << "Of Circle: " << endl;
        cout << "Perimeter: " << perimeter << endl;
        cout << "Area: " << findArea() << endl;
        cout << "Radius: " << findRadius() << endl;
        cout << endl;
    }
};

class Hagel: public CodyHagel  //inherits publicly from CodyHagel
{
  private: //declares three private variables, area, radius, and width
    double length;
    double width;
    double area;

  public:
    Hagel() : CodyHagel(64) //calls CodyHagel and fixes perimeter to 64
    {
        // Assuming a default value for length
        length = 10;  // Example value
    }

    double findArea() //finds area of rectangle based on the perimeter
    {
        area = (perimeter / 2 - length) * length;
        return area;
    }

    double findWidth() //finds width of a rectangle based on the perimeter
    {
        width = perimeter / 2 - length;
        return width;
    }

    void printCodyHagel() override //overrides the abse class function to print details specific to a rectangle
    {
        cout << "Of Rectangle: " << endl;
        cout << "Perimeter: " << perimeter << endl;
        cout << "Area: " << findArea() << endl;
        cout << "Width: " << findWidth() << endl;
        cout << endl;
    }
};

int main() {
    //declare instances for CodyHagel, cody and hagel, calls printCodyHagel method to demonstrate polymorphic behaviour
    CodyHagel codyhagel;
    codyhagel.printCodyHagel();

    Cody cody;
    cody.printCodyHagel();

    Hagel hagel;
    hagel.printCodyHagel();

    return 0;
}