// Game of Life -- Samuel Essery -- 002130654
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Global constants
const int MAXGEN = 3; // maximum no. of generations
const int MAXROWS = 10 ;    // no. of rows
const int MAXCOLS = 10 ;    // no. of colums

void initialize(int grid[][MAXCOLS], int n, int m){
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            cout << "Enter Cell Information Here, 1 for alive, 0 for dead: " << endl;       //  Initilaize grid with user input, 2 nested for loops that repeat themleves for each row and column
            cin >> grid[j][i];
        }
    }
}

void initialize2(int grid[][MAXCOLS], int n, int m) {
    int density;
    cout << "Enter Population Density: " << endl;
    cin >> density;
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            int temp = rand() % 100 + 1;;           // Initialize grid with random density using random number generator, 1 being alive, 0 being dead, Random number is less than or equal to density
            if(temp <= density){
                grid[j][i] = 1;
            }else {
                grid[j][i] = 0;
            }
        }
    }
}

int countNeighbours(int grid[][MAXCOLS], int row, int col){
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (!(i == 0 && j == 0) && grid[row+i][col+j] == '1'){      // Count neighbours by comparing the rows and columns around each other,
                    return 1;                                           //  each position is inserted and then compared to -1 and +1 above/across from it
                 }else{                                                 // if it meets the rules of life, it returns a 1, if not it returns a 0
                    return 0;
                 }
        }
    }
}

void reproduce(int grid[MAXROWS][MAXCOLS], int n, int m){
    int tempGrid[MAXROWS][MAXCOLS];
    for (int x = 0; x <= MAXROWS; x++){
           for(int y = 0; y <=MAXCOLS; y++){
                tempGrid[x][y] = countNeighbours(grid,x, y);        // This set of for loops sends each position, into the neighbour checker, and inputs the answer into the temp grid
           }
    }
    int pointGrid[MAXROWS][MAXCOLS] = *grid[MAXROWS][MAXCOLS];      // Sets up pointer in order to change the values of grid
    for (int i = 0; i<= MAXROWS; i++){
        for(int j = 0; j <= MAXCOLS; i++) {                         // Set of for loops input each new cell on the current grid
            pointGrid[i][j] = tempGrid[i][j];
        }
}
}

bool allDead(int grid[][MAXCOLS], int n, int m){
    for(int i = 0; i <= MAXROWS; i++){
        for(int j = 0; j <= MAXCOLS; j++){                      // Checks each cell to see if it is a 0 or a 1, if its 0 it continues, if its 1 it returns false
            if (grid[i][j] == 1){
                return false;
            }
        }
    }
}

void print(int grid[][MAXCOLS], int n, int m){
    for (int i=0; i <= MAXROWS; i++){
        int count = 0;
        for (int j=0; i <= MAXCOLS; j++){           // Set of for loops that prints out each cell, intitalize count
            cout << setw(2) << grid[i][j];
            count ++;
            if(count = 10){                     // if count reache 10 skip a line and reset count to 0
                   cout << endl;
                   count = 0;
            }
        }
    }
}

int main(){
    int grid[MAXROWS][MAXCOLS];
    int n, m, gen;
    initialize(grid,n,m);     // you should call either initialize, or initialize2
    cout << "Initial population = \n";
    print(grid,n,m);
    gen = 1;
    print (grid,n,m);
    while (gen <= MAXGEN && !allDead(grid,n,m)){
       cout << "gen = " << gen;
       reproduce(grid,n,m);    // will call the function countNeighbours for each cell
       print (grid,n,m);
       gen++;
    }
  }

