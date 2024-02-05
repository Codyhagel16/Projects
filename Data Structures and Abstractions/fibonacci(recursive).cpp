//This code is designed to run the fibonacci sequence recursively. The code prompts a user to input the value for n and then prints out what each value of the fibonacci sequence would be up until the user input for n is hit. The code also uses the chrono clock library to track how long the function takes.//

#include <iostream>
#include<chrono>
using namespace std;

auto start = std::chrono::high_resolution_clock::now();
int fib_recr(int n) //declares intreger function to return the fibonacci number
{
  if(n == 0) //declares an if statment so if the n value equals 0 the program ends
  {
    return 0;
  }

  if(n == 1 || n == 2) //declares an if statment so if the n value equals 1 or 2 the program returns true
  {
    return 1;
  }

  return fib_recr(n-1) + fib_recr(n-2); //the formula for recursive functions is (an = an-2 + an-1) so this returns the answer to the inputted value
};

int main() 
{
  int n;
  cout << "Please Enter A Value For N: " << endl;
    cin >> n;
  
  for(int i = 0; i < n; i++) //starts a for loop that will run as many times as inputted into value n
    {
    cout << "Term " << i + 1 << ": " << fib_recr(i) << endl; //prints out the fibonacci value using the value from the return of fib_recr(n-1) + fib_recr(n-2)
    }

  //I put my for loop into int main because the for loop is printing based on a return value from the int function above
  auto stop = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
  return 0;
}