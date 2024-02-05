//This C++ program calculates and displays the sum of values at even indices in two different arrays: one of integers and one of doubles. The program uses function overloading to handle both types of arrays.""

#include <iostream>
using namespace std;

int sumOfEven(const int* array, int size) //declares an int function to find the sum of even numbers within an integer array
{
  int sum = 0; //sets sums beginning value to 0
  for(int i = 0; i < size; i++)  //starts a for loop that will stop once the user input lines up with the requested number of inputs
  {
    if(i % 2 == 0) //if statement that allows for addiction only in even portions of teh array
    {
      sum += array[i]; //adds the sum of the array
    }
  }

  return sum; //returns sum
}
double sumOfEven(const double *array, int size)//declares an double function to find the sum of even numbers within an double array
{
  double sum = 0; //sets sums beginning value to 0
  for(int i = 0; i < size; i++)  //starts a for loop that will stop once the user input lines up with the requested number of inputs
  {
    if(i % 2 == 0) //if statement that allows for addiction only in even portions of teh array
    {
      sum += array[i]; //adds the sum of the array
    }
  }

  return sum; //returns sum
}

int main() 
{
  int integers[5]; //sets the array to be able to hold five input values
  double numbers[5];

  cout << "Please Enter 5 Integer Values: " << endl; //prompts user for input
  for (int i = 0; i < 5; i++)  //starts a for loop that will end after five inputs from teh user
  {
    cin >> integers[i]; //stores the inputs in the array
  }
    
  cout << "Sum Of Inputted Values At Even Points Of The Array: " << sumOfEven(integers, 5) << endl; //prints out the inputted values sum at even array points

  cout << "Please Enter 5 Double Values: " << endl; //prompts user for input 
  for (int i = 0; i < 5; i++) //starts a for loop that ends after five inputs from the user
  {
    cin >> numbers[i]; //stores the inputs in the array
  }

  cout << "Sum Of Inputted Values At Even Points Of The Array: " << sumOfEven(numbers, 5) << endl; //prints out the inputted values sum at even array points
  
  return 0;
}