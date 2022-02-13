/* 
* 
* Reyhan Koyun
* 2/10/2022
*
*/

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>
#include <stack>

class Creature {
public:

  // prints current location of creature
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row;
  int Col;

  // helper solve method
  bool solve(Maze& maze, int row, int col);

  // holds the string of path
  stack<string> walkSteps;

public:
  
  // constructor
  Creature(int Row, int Col);

  // returns a string in the form of NNEEN
  string solve(Maze &Maze);

  // if the creature reached exit row and column, returns true.
  // otherwise returns false
  bool atExit(const Maze &Maze, int row, int col) const;
  
  // try to go to north of row, col
  bool goNorth(Maze &Maze, int row, int col);

  // try to go to south of row, col
  bool goSouth(Maze &Maze, int row, int col);

  // try to go to east of row, col
  bool goEast(Maze &Maze, int row, int col);
  
  // try to go to west of row, col
  bool goWest(Maze &Maze, int row, int col);

  // prints maze with the path
  string getPath(Maze &Maze);

  // pops the stack so that the string is printed in the right order
  string getWalkSteps();

};

#endif //ASS3_CREATURE_H
