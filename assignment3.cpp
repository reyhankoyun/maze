/* 
* 
* Reyhan Koyun
* 2/10/2022
*
*/

#include <iostream>

#include "creature.h"
#include "maze.h"

// tests the maze provided in the starter
void test() {
    Maze M("maze.txt");
    cout << M << endl;
    Creature C(4, 4);
    cout <<  C.solve(M) << endl;
    cout << "Path: " << C.getWalkSteps() << endl;
}

// test maze1
void test1() {
    Maze M1("maze1.txt");
    cout << M1 << endl;
    Creature C1(3, 1);
    cout <<  C1.solve(M1) << endl;
    cout << "Path: " << C1.getWalkSteps() << endl;
}

// tests maze 2
void test2() {
    Maze M2("maze2.txt");
    cout << M2 << endl;
    Creature C2(5, 33);
    cout <<  C2.solve(M2) << endl;
    cout << "Path: " << C2.getWalkSteps() << endl;
}

// tests maze3
void test3() {
    Maze M3("maze3.txt");
    cout << M3 << endl;
    Creature C3(4, 4);
    cout <<  C3.solve(M3) << endl;
    cout << "Path: " << C3.getWalkSteps() << endl;
}

// executes the tests
int main() {
    cout << "Test: " << endl;
    test();
    cout << "Done!" << endl << endl;

    cout << "Test 1: " << endl << endl;
    test1();
    cout << "Done!" << endl;

    cout << "Test 2: " << endl << endl;
    test2();
    cout << "Done!" << endl;
    
    cout << "Test 3: " << endl << endl;
    test3();
    cout << "Done!" << endl;
    return 0;


}