//Caleb Fabian
//CS 302 - Lab 6 Mazemake
//April 4, 2016

#include <iostream>
#include "mazegrid.h"
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    //Input is two cmd line args, row and cols
    if (argc != 3) {
        cout << "Usage: ./mazmake rows columns" << endl;
        return -1;
    }
    //Creates and prints the wall locations for the maze
    maze maze1(atoi(argv[1]), atoi(argv[2]));
    maze1.create_maze();
    maze1.print_maze();
    return 0;
}