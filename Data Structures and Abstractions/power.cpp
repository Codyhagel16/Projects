//This is a simple code that is designed to calculate the power of an inputted number x by the power of an inputted number n//
#include <iostream>
using namespace std;

int power1(int x, int n) //This is the function that will be used to calculate the power of an inputted number x by the power of an inputted number n
{
  int result = 1; //initalize result to 1
  
  for (int i = 0; i < n; i++) //for loop in which result is multipled by x n times
  {
      result *= x;
  }
  
  return result; //returns the result
}

int main() 
{
  int x, n; //declare two integer values x and n

  cout << "Please Enter Base Number: " << endl; //prompt to input base number
    cin >> x;

  cout << "Please Enter Power: " << endl; //prompt to enter power value
    cin >> n;

  cout << "Result: " << power1(x, n) << endl; //displays the result of x^n by calling the power1 function and sending the values of x and n to the function

  return 0;
}