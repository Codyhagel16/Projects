//This is a project designed to display all possible combinations of numbers that sum up to a user inputted n value, using exactly k number of values. Both u and k are user inputted and displaysrecurison and vectors for dynamic storage.//

#include <iostream>
#include <bits/stdc++.h> //for the vector decleration
using namespace std;

void identify(int n, int k, vector<vector<int>> &x, vector<int> &y) //this is the void function to determine all the possible solutions it uses two regular integer values n and k that will be user inputs and then two vector elements x and y used in place of an array as vectors can grow dynamically
{
  if(n == 0) //this is the base case, if the value of n is 0 
  { 
    if(k == 0) //if the value of k is 0 and the value of n is 0
    {
      x.push_back(y);//adds the y value to the end of vector x
    }
    return;
  }
    
  else if(k == 0) //if the k value is 0
  {
    return; //end the program
  }
  
  for(int i = 0; i <= n; i++)  //starts at value 0 and sees which combination of values can equal the given input, assuming 0 can be used
  {
    y.push_back(i);//adds the i value to the end of the y vector
    identify(n - i, k - 1, x, y);//calls identify function with decremented values
    y.pop_back(); //outputs/removes the last value from the y vector
  }
}

int main() 
{
  int n, k; //declares two integr values n and k for user prompt values

  do //do statement to prompt the user until the values are acceptable
  {
    cout << "Enter A Value For N(Must be a greater value than 2):";
      cin >> n;
    
    cout << "Enter A Value For K(Must be a greater value than N and greater than 2):";
      cin >> k;

    if(n > k) // n is greater than k
    {
      cout << "n can not be a greater value than k!" << endl;
      cout << endl;
    }

    if(n < 2 || k < 2) //if 2 is greater than n or k
    {
      cout << "K and N can not be less than 2!" << endl;
      cout << endl;
    }
  }while(n > k || n < 2 ||k < 2);

  cout << endl; //endl for spacing
  
  vector<vector<int>> x; //this vector stores all solutions possib;e
  
  vector<int> y;//this vector stores the current solution

  identify(k, n, x, y);//calls the identify function
  
  cout << "Identifying the possible solutions..." << endl;
  cout << "There Is " << x.size() << " solutions where n=" << n << " and k=" << k  << endl;
  
  for(int i = 0; i < x.size(); i++) //for the size of x aka the number of values in x
  {
    cout << "--------------------------" << endl;
    cout << "Combination " << i + 1 << ". ";
    for(int j = 0; j < x[i].size(); j++) //for the number of values in x
    {
      cout << x[i][j] << " ";//prints out the values combination
    }
    cout << endl;//for spacing
  }
  return 0;//returns program one finished 
}