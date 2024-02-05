//This code is an example of how to use structures. The code defines a structure Cody and includes a method within the structure to print the details of various instances of Cody//

#include <iostream>
using namespace std;

struct Cody //for structure Cody
{
  string firstName; //declare string variable firstname
  int houseNumber; //declare int variable houseNumber

  Cody()
  {
    firstName = ""; //initalize firstname
    houseNumber = 0; //initalize hosue number
  }

  Cody(string fn, int hn)
  {
    fn = firstName;
    hn = houseNumber;
  }

  void printArray() /./printarray function
  {
  Cody cody1; //Declare cody1
  
  cody1.firstName = "Kabeer"; // Input values for cody1
  cody1.houseNumber = 200;

  Cody cody2; //declare cody2

  cody2.firstName = "John"; //imput values for cody2 
  cody2.houseNumber = 40;

  Cody cody3;

  cody3.firstName = "Paul";
  cody3.houseNumber = 64;

  Cody cody4;

  cody4.firstName = "Kaur";
  cody4.houseNumber = 38;

  Cody cody5;

  cody5.firstName = "Patel";
  cody5.houseNumber = 200406438;

  cout << "Name: " << cody1.firstName << " House Number: " << cody1.houseNumber << endl; //print out values in cody1

  cout << "Name: " << cody2.firstName << " House Number: " << cody2.houseNumber << endl; //print out values in cody2

  cout << "Name: " << cody3.firstName << " House Number: " << cody3.houseNumber << endl;

  cout << "Name: " << cody4.firstName << " House Number: " << cody4.houseNumber << endl;

  cout << "Name: " << cody5.firstName << " House Number: " << cody5.houseNumber << endl;
  }
};

int main() 
{
  Cody cody; //declare structure cody
  cody.printArray(); //print array
  
};