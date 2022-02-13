/* 
* 
* Reyhan Koyun
* 2/10/2022
*
*/

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {

  // prints maze
  friend ostream &operator<<(ostream &Out, const Maze &Maze);

private:
  const static int MAX_SIZE = 100;
  char Field[MAX_SIZE][MAX_SIZE];
  int Width, Height;
  int ExitRow, ExitColumn;
  
public:

  // constructor 
  explicit Maze(const string &FileName);

  // checks if the square is clear
  bool isClear(int Row, int Col) const;

  // marks the square as path by placing a *
  void markAsPath(int Row, int Col);

  // marks the square as visited by placing a +
  void markAsVisited(int Row, int Col);

  // marks the starting point by placing o
  void markOrigin(int Row, int Col);

  // gets the exit row
  int getExitRow() const;

  // gets the exit column
  int getExitColumn() const;

  // gets the width of the maze
  int getWidth() const;

  // gets the height of the maze
  int getHeight() const;


};

#endif //ASS3_MAZE_H