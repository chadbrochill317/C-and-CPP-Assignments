#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

// Game of Life Assignment 4


  const int MAXGEN = 10;
  const int MAXROWS = 10 ;
  const int MAXCOLS = 10 ;

 //population user array
  void initialize (int grid[][MAXCOLS], int n, int m){
    cout << "Enter 1 or 0: \n";
    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++)
         cin >> grid[i][j];
      cout << endl;
  }

//pop given density
  void initialize2(int grid[][MAXCOLS], int n, int m){
    cout << "Density: ";
    int density;
    cin >> density;
    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++){
        int random = rand()%100;
        if (random < density)
          grid[i][j] = 1;
        else grid[i][j] = 0;
      }
  }

 //Number of Neighbours
  int countNeighbours (int grid[][MAXCOLS], int n, int m, int i, int j){
      int sum = 0;
      for (int x = -1; x <= 1; x++)
        for (int y = -1; y <= 1; y++)
           if (!(x==0 && y==0))
            sum =  sum + grid[(i+x+n)%n][(j+y+m)%m];
      return sum;
  }

//Live neighbours
  int countNeighbours2 (int grid[][MAXCOLS], int n, int m, int i, int j){
      int sum = 0;
      int up, down, right, left;

      // assign values to up, down, righ, left depending on where the cell i,j is
      if (i==0)
        up=n-1;
      else up = i-1;
      if (i==n-1)
        down = 0;
      else down = i+1;
      if (j==0)
        left = m-1;
      else left = j-1;
      if (j==m-1)
        right = 0;
      else right = j+1;

      if (grid[up][left]==1)
         sum++;
      if (grid[up][j]==1)
         sum++;
      if (grid[up][right]==1)
         sum++;
      if (grid[i][left]==1)
         sum++;
      if (grid[i][right]==1)
         sum++;
      if (grid[down][left]==1)
         sum++;
      if (grid[down][j]==1)
         sum++;
      if (grid[down][right]==1)
         sum++;

    return sum;
  }

//New generation
  void reproduce (int grid[][MAXCOLS], int n, int m){
    int up, down, right, left;
    int newGrid[n][m];
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        int count = countNeighbours (grid,n,m,i,j);
        switch (grid[i][j]){
           case 0:        // cell is dead
                   if (count == 3)
                      newGrid[i][j] = 1;
                   else newGrid[i][j] =0; break;
           case 1:        // cell is alive
                   if (count == 2 || count == 3)
                      newGrid[i][j] = 1;
                   else newGrid[i][j] =0; break;
        }
      }
    }
    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++)
         grid[i][j]= newGrid[i][j];
    }

//Dead popluation?
  bool allDead (int grid[][MAXCOLS], int n, int m){
    bool dead = true;
    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++)
        if (grid[i][j]==1)  dead = false;
    return dead;
  }

//prints
  void print (int grid[][MAXCOLS], int n, int m){
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++)
         cout << setw(2) << grid[i][j];
      cout << endl;
    }
  }

int main(){

    int grid[MAXROWS][MAXCOLS];
    int n, m;
    cout << "Enter n and m ";
    cin >> n >> m;
    cout <<"Start? Y/N ";
    char answer;
    cin >> answer;
    if (answer =='Y' || answer == 'y')
       initialize(grid, n, m);
    else initialize2(grid, n, m);
    cout << "Initial population = \n";
    print(grid, n, m);
    int gen = 1;

    while (gen<=MAXGEN && !allDead(grid, n, m)){
      cout << "\ngen = " << gen << endl;
      reproduce(grid, n, m);
      print(grid, n, m);
      gen++;
    }
  }

