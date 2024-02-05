//This program was made to demonstarte the iterative approach to caluclating a fibonaucci sequence and measure the time efficency of the algorithm itself. The user will input a value N that will then calulate the terms for that fibonacci sequence (the two previous terms are added together for the value of the next term). Using the chrono clock the program can measure the time efficency of the algorithm.//

#include <iostream>
#include <chrono>
using namespace std;

//void fucntion to calculate the first n terms in a fibbonacci sequence
void fib_iter(int n) 
{
    if (n <= 0) //if value of n is negative
    {
        cout << "Please enter a positive integer." << endl; //prompt user to enter a positive integer
        return;
    }

    int f1 = 0; //initalize first term
    int f2 = 1; //initalize second term
    int fn; //declare integer value fn

    cout << "Term 1: " << f1 << endl; //print out first term
  
    if (n > 1) 
    {
        cout << "Term 2: " << f2 << endl; //print out second term
    }

    for (int i = 2; i < n; i++) //for loop to calculate the next n terms
    {
        fn = f1 + f2;
        cout << "Term " << i + 1 << ": " << fn << endl;
        f1 = f2;
        f2 = fn;
    }
}

int main() 
{
    int n; //declare integer value n
    cout << "Please Enter A Value For N: ";
      cin >> n;

    auto start = chrono::high_resolution_clock::now(); //start clock
    fib_iter(n);
    auto stop = chrono::high_resolution_clock::now(); //stop clock

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); //calculate duration clock was being used
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
