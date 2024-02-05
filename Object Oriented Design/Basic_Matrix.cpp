//This program is used to show the creation and basic manipulation of a matrix//

#include <iostream>
using namespace std;

class Matrix //declare class matrix
{
  public:
    int m[2][2]; //initalize two dimensional array m that will be a 2x2 matrix

    Matrix() //initalize all values in matrix to 0
    {
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 2; j++) 
            {
                m[i][j] = 0;
            }
        }
    }

    Matrix(int Array[2][2]) //initalize matrix m with the values from the assigined array
    {
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 2; j++) 
            {
                m[i][j] = Array[i][j];
            }
        }
    }

    void printMatrix(const string& arrayName) //print out the matrix
    {
        cout << "The array " << arrayName << " is:" << endl;
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 2; j++) 
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() 
{
    int array1[2][2] = {{1, 2}, {3, 4}}; // Initialized array1
    int array2[2][2] = {{5, 6}, {7, 8}}; // Initialized array2

    Matrix myArray1(array1); //call matrix function for array1
    Matrix myArray2(array2); //call matrix function for array 2

    myArray1.printMatrix("Result1"); //call to print array1 result
    myArray2.printMatrix("Result2"); //call to print array2 result

    return 0;
}