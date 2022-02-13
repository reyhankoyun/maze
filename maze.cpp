/* 
* 
* Reyhan Koyun
* 2/10/2022
*
*/

#include <fstream>
#include <iostream>
#include "maze.h"
#include <string>

using namespace std;

// prints maze
ostream &operator<<(ostream &Out, const Maze &Maze) {
  for (int Row = 0; Row < Maze.Height; ++Row) {
    for (int Col = 0; Col < Maze.Width; ++Col) {
      Out << Maze.Field[Row][Col];
    }
    Out << endl;
  }
  Out << endl;
  return Out;
}

// For Clion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
Maze::Maze(const string &FileName) {
  ifstream InFile;
  InFile.open(FileName);
  if (!InFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  InFile >> Width >> Height;
  InFile >> ExitRow >> ExitColumn;
  string Str;
  getline(InFile, Str);
  for (int Row = 0; Row < Height; ++Row) {
    for (int Col = 0; Col < Width; ++Col) {
      InFile.get(Field[Row][Col]);
      // cout << Row << ", " << col << ": " << field[Row][col] << endl;
    }
    getline(InFile, Str);
  }

}

// gets the exit row
int Maze::getExitRow() const {
  return ExitRow;
}

// gets the exit column
int Maze::getExitColumn() const {
  return ExitColumn;
}

// checks if the square is clear
bool Maze::isClear(int Row, int Col) const {
  return Field[Row][Col] == ' ';
}

// marks the square as path by placing a *
void Maze::markAsPath(int Row, int Col) {
  Field[Row][Col] = '*';
}

// marks the square as visited by placing a +
void Maze::markAsVisited(int Row, int Col) {
  Field[Row][Col] = '+';
}

// marks the starting point by placing o
void Maze::markOrigin(int Row, int Col){
    Field[Row][Col] = 'o';
}

// gets the width of the maze
int Maze::getWidth() const {
  return Width;
}

// gets the height of the maze
int Maze::getHeight() const {
  return Height;
}