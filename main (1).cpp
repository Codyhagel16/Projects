//This is a project based on the tormino tiling problem. This code takes a user input and creates a 2^N x 2^N checkboard of trominoes (L-Shaped tiles). The user than chooses the location for the "hole", which is a tile that is uncovered. This is done by recursively dividing the board into sections and filling them with triminoes while avoiding the designated "hole"//

#include <iostream>
#include <cmath> //for pow function
using namespace std;

int n, b, a; //declare integer values to take in the grid size, and hole coordinates
int arr[128][128]; // max size the array can be printed out

// Function to assure tiles are placed in right triominoes
void triominoe(int x1, int y1, int x2, int y2, int x3, int y3, int cnt) 
{
  arr[x1][y1] = cnt; //first tromino square
  arr[x2][y2] = cnt; //second tromino square
  arr[x3][y3] = cnt; //third trimino square
}

// Function to Find the holes location and build around it
void insert(int size, int x, int y, int holeX, int holeY, int cnt) 
{
  if (size == 2) //base case representing a 2x2 grid
  {
    cnt++;
    for (int i = 0; i < size; i++) 
    {
      for (int j = 0; j < size; j++) 
      {
        if (arr[x + i][y + j] == 0) 
        {
          arr[x + i][y + j] = cnt;
        }
      }
    }
    return;
  }

  int mid = size / 2; //calculate midpoint of grid
  int newHoleX[4] = {x + mid - 1, x + mid, x + mid - 1, x + mid}; //setting hole positions in x coordinate
  int newHoleY[4] = {y + mid - 1, y + mid - 1, y + mid, y + mid}; //setting hle positions in y coordinate
  
  if (holeX < x + mid) //adjust hole location based on the actual hole
  {
    if (holeY < y + mid) newHoleX[0] = holeX, newHoleY[0] = holeY;
    else newHoleX[2] = holeX, newHoleY[2] = holeY;
  } 
    
  else 
  {
    if (holeY < y + mid) newHoleX[1] = holeX, newHoleY[1] = holeY;
    else newHoleX[3] = holeX, newHoleY[3] = holeY;
  }

  //place the triminos
  triominoe(newHoleX[0], newHoleY[0] + 1, newHoleX[1], newHoleY[1] + 1, newHoleX[1] - 1, newHoleY[1], cnt + 1); 
  insert(mid, x, y, newHoleX[0], newHoleY[0], cnt + 1);
  insert(mid, x, y + mid, newHoleX[1], newHoleY[1], cnt + 1);
  insert(mid, x + mid, y, newHoleX[2], newHoleY[2], cnt + 1);
  insert(mid, x + mid, y + mid, newHoleX[3], newHoleY[3], cnt + 1);
}

int main() 
{
  cout << "Enter the size of the grid (2^n), at least 1 (for 2x2 grid): ";
    cin >> n;
  n = pow(2, n);

  cout << "Enter the vertical coordinate for the hole (0 to " << n - 1 << "): ";
    cin >> a;

  cout << "Enter the horizontal coordinate for the hole (0 to " << n - 1 << "): ";
    cin >> b;

  arr[a][b] = -1; //insert hole location
  insert(n, 0, 0, a, b, 0);

  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < n; j++)
      cout << arr[i][j] << "\t";
    cout << endl;
  }
}
