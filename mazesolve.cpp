//Caleb Fabian
//CS 302 - Lab 6 Mazesolve
//April 4, 2016

#include <iostream>
#include "mazegrid.h"
#include <vector>
#include <string>
using namespace std;

int main() {
    string header;
    int r, c;
    cin >> header;
    //Checks that the inputted file is a maze file
    if (header == "MAZE") {
        cin >> r >> c;
        //Reads in the maze file, solves the maze and prints out the solution indeces
        maze maze1(r, c);
        maze1.read();
        maze1.solve_maze(0);
        maze1.print_solution();
    }
    return 0;
}