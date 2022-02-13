/* 
* 
* Reyhan Koyun
* 2/10/2022
*
*/

#include "creature.h"
#include <iostream>
#include <sstream>

// prints current location of creature
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) 
{
  Out << "C(" << Creature.Row << ", " << Creature.Col << ")" << endl;
  return Out;
}

// constructor
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}

// if the creature reached exit row and column, return true.
// otherwise return false
bool Creature::atExit(const Maze &Maze, int row, int col) const 
{
  return row == Maze.getExitRow() && col == Maze.getExitColumn();
}

// checks if there's a path by calling the helper solve method
// if there's a path, returns path
// otherwise prints a message
string Creature::solve(Maze &Maze) 
{
  bool result = solve(Maze, Row, Col);
  if(result)
  {
    cout << endl << "Found a path: " << endl;
  } 
  else 
  {
    cout << endl << "No valid path!" << endl;
  }
  Maze.markOrigin(Row, Col);
  string path = getPath(Maze);
  return path;
}

// helper solve method
bool Creature::solve(Maze& Maze, int row, int col)
{
  // checks if creature is at exit
  if(atExit(Maze, row, col))
  {
    Maze.markAsPath(row, col);
    return true;
  }

  // if the square is not clear, returns false
  if(!Maze.isClear(row, col))
  {
    return false;
  }
 
  // otherwise marks the square as visited
  Maze.markAsVisited(row, col);
  string step = "";
  if(goNorth(Maze, row, col))
  {
    step = "N";
  }
  else if(goWest(Maze, row, col))
  {
    step = "W";
  }
  else if(goEast(Maze, row, col))
  {
    step = "E";
  } 
  else if(goSouth(Maze, row, col))
  {
    step = "S";
  }
  if(step != "")
  {
    Maze.markAsPath(row, col);

    // adds string in form of NEEN to stack
    walkSteps.push(step);
    return true;
  }
  return false;
}

// pops the stack so that the string is printed in the right order
string Creature::getWalkSteps()
{
  std::ostringstream oss;
  while(!walkSteps.empty())
  {
    oss << walkSteps.top();
    walkSteps.pop();
  }
  return oss.str();
}

// prints maze with the path
string Creature::getPath(Maze &Maze) 
{
  std::ostringstream oss;
  oss << Maze;
  std::string Path = oss.str();
  return Path;
}

// try to go to north of row, col
bool Creature::goNorth(Maze &Maze, int row, int col) 
{
  if(row == 0)
  {
    return false;
  }
  if(Maze.isClear(row - 1, col))
  {
    return solve(Maze, row-1, col);
  }
  return false;
}

// try to go to west of row, col
bool Creature::goWest(Maze &Maze, int row, int col) 
{
  if(col == 0)
  {
    return false;
  }
  if(Maze.isClear(row, col-1))
  {
    return solve(Maze, row, col-1);
  }
  return false;
} 

// try to go to east of row, col
bool Creature::goEast(Maze &Maze, int row, int col) 
{
  if(col == Maze.getWidth()-1)
  {
    return false;
  }
  if(Maze.isClear(row, col+1))
  {
    return solve(Maze, row, col+1);
  }
  return false;  
}

// try to go to south of row, col
bool Creature::goSouth(Maze &Maze, int row, int col) 
{
  if(row == Maze.getHeight()-1)
  {
    return false;
  }
  if(Maze.isClear(row+1, col))
  {
    return solve(Maze, row+1, col);
  }
  return false; 
}
