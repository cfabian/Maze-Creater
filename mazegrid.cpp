//Caleb Fabian
//CS 302 - Lab 6 Mazegrid
//April 4, 2016

#include <iostream>
#include "mazegrid.h"
#include "dset.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//Sets the adjacent cells and marks the top, bottom, left, and right of the maze.
void maze::initialize_maze() {
    mazegrid.resize(rows * cols);
    for (int i = 0; i < (rows * cols); i++) {
        mazegrid[i] = cell(i);
        if (i >= cols) { //top
            mazegrid[i].top = (i - cols);
        }else {
            mazegrid[i].top = -1;
            mazegrid[i].topwall = 0;
        }
        if (i < (cols * rows) - cols) { //bottom
            mazegrid[i].bottom = (i + cols);
        }else {
            mazegrid[i].bottom = -1;
            mazegrid[i].bottomwall = 0;
        }
        if (i % cols != 0) { //left
            mazegrid[i].left = (i - 1);
        }else {
            mazegrid[i].left = -1;
            mazegrid[i].leftwall = 0;
        }
        if ((i + 1) % cols != 0) { //right
            mazegrid[i].right = (i + 1);
        }else {
            mazegrid[i].right = -1;
            mazegrid[i].rightwall = 0;
        }
    }
    return;
}

//Uses a disjoint set to randomly take away walls until there is a path from the top left to the bottom right
void maze::create_maze() {
    //Initializes the maze
    initialize_maze();
    dset adjacent(mazegrid.size());
    while (adjacent.size() != 1) {
        //Selects a random cell to start with
        int randcell = rand() % mazegrid.size();
        //Selects a random neighnoring cell of the random cell.
        int randneighbor = rand() % 4;
        if (randneighbor == 0) {
            randneighbor = mazegrid[randcell].top;
        }
        if (randneighbor == 1) {
            randneighbor = mazegrid[randcell].bottom;
        }
        if (randneighbor == 2) {
            randneighbor = mazegrid[randcell].left;
        }
        if (randneighbor == 3) {
            randneighbor = mazegrid[randcell].right;
        }
        if (randneighbor == -1) {
            continue;
        }
        if (adjacent.find(randcell) == adjacent.find(randneighbor)) {
            continue;
        }
        adjacent.merge(randcell, randneighbor);
        //cout << randcell << " " << randneighbor << endl;
        delete_wall(randcell, randneighbor);
    }
    return;
}

//Removes (marks as 0) selected walls and adjacent walls.
void maze::delete_wall(int i, int j) {
    if (mazegrid[i].top == j) {
        mazegrid[i].topwall = 0;
    }else if (mazegrid[i].bottom == j) {
        mazegrid[i].bottomwall = 0;
    }else if (mazegrid[i].left == j) {
        mazegrid[i].leftwall = 0;
    }else if (mazegrid[i].right == j) {
        mazegrid[i].rightwall = 0;
    }else {
        cout << "error 1" << endl;
    }
    if (mazegrid[j].top == i) {
        mazegrid[j].topwall = 0;
    }else if (mazegrid[j].bottom == i) {
        mazegrid[j].bottomwall = 0;
    }else if (mazegrid[j].left == i) {
        mazegrid[j].leftwall = 0;
    }else if (mazegrid[j].right == i) {
        mazegrid[j].rightwall = 0;
    }else {
        cout << "error 2 " << j << " " << i << endl;
    }
    return;
}

//Prints the maze file
void maze::print_maze() {
    cout << "MAZE " << rows << " " << cols << endl;
    for (int i = 0; i < (int)mazegrid.size(); i++) {
        if (mazegrid[i].topwall != 0 && i < mazegrid[i].top) {
            cout << i << " " << mazegrid[i].top << endl;
        }
        if (mazegrid[i].bottomwall != 0 && i < mazegrid[i].bottom) {
            cout << i << " " << mazegrid[i].bottom << endl;
        }
        if (mazegrid[i].leftwall != 0 && i < mazegrid[i].left) {
            cout << i << " " << mazegrid[i].left << endl;
        }
        if (mazegrid[i].rightwall != 0 && i < mazegrid[i].right) {
            cout << i << " " << mazegrid[i].right << endl;
        }
    }
    return;
}

//Reads in the maze file
void maze::read() {
    int r, c;
    rev_init_maze();
    while (cin >> r >> c) {
        build_wall(r, c);
    }
    return;
}

//Initializes the maze with no walls (opposite of before)
void maze::rev_init_maze() {
    mazegrid.resize(rows * cols);
    for (int i = 0; i < (rows * cols); i++) {
        mazegrid[i] = cell(i);
        if (i >= cols) { //top
            mazegrid[i].top = (i - cols);
            mazegrid[i].topwall = 0;
        }else {
            mazegrid[i].top = -1;
            mazegrid[i].topwall = 0;
        }
        if (i < (cols * rows) - cols) { //bottom
            mazegrid[i].bottom = (i + cols);
            mazegrid[i].bottomwall = 0;
        }else {
            mazegrid[i].bottom = -1;
            mazegrid[i].bottomwall = 0;
        }
        if (i % cols != 0) { //left
            mazegrid[i].left = (i - 1);
            mazegrid[i].leftwall = 0;
        }else {
            mazegrid[i].left = -1;
            mazegrid[i].leftwall = 0;
        }
        if ((i + 1) % cols != 0) { //right
            mazegrid[i].right = (i + 1);
            mazegrid[i].rightwall = 0;
        }else {
            mazegrid[i].right = -1;
            mazegrid[i].rightwall = 0;
        }
    }
    return;
}

//Creates walls in the maze using the indeces in the inputted maze file
void maze::build_wall(int i, int j) {
    if (mazegrid[i].top == j) {
        mazegrid[i].topwall = 1;
    }else if (mazegrid[i].bottom == j) {
        mazegrid[i].bottomwall = 1;
    }else if (mazegrid[i].left == j) {
        mazegrid[i].leftwall = 1;
    }else if (mazegrid[i].right == j) {
        mazegrid[i].rightwall = 1;
    }else {
        cout << "error 1" << endl;
    }
    if (mazegrid[j].top == i) {
        mazegrid[j].topwall = 1;
    }else if (mazegrid[j].bottom == i) {
        mazegrid[j].bottomwall = 1;
    }else if (mazegrid[j].left == i) {
        mazegrid[j].leftwall = 1;
    }else if (mazegrid[j].right == i) {
        mazegrid[j].rightwall = 1;
    }else {
        cout << "error 2 " << j << " " << i << endl;
    }
    return;
}

//Solves the maze recursively
void maze::solve_maze(int i) {
    //Checks whether it reached the bottom right corner (end of maze)
    if (i == (int)mazegrid.size() - 1) {
        found_solution = true;
    }
    //Returns and stores the index if the end of the maze was reached
    if (found_solution == true) {
        //cout << "found solution" << endl;
        path.push_back(i);
        return;
    }
    //Goes through the maze using depth first search
    if (mazegrid[i].rightwall == 0 && mazegrid[mazegrid[i].right].visited != true && (i + 1) % cols != 0) {
        //cout << i << " right" << endl;
        mazegrid[i].visited = true;
        solve_maze(mazegrid[i].right);
        if (found_solution == true) {
            //cout << "found solution" << endl;
            path.push_back(i);
            return;
        }
    }
    if (mazegrid[i].bottomwall == 0 && mazegrid[mazegrid[i].bottom].visited != true && i < (cols * rows) - cols) {
        //cout << i << " down" << endl;
        mazegrid[i].visited = true;
        solve_maze(mazegrid[i].bottom);
        if (found_solution == true) {
            //cout << "found solution" << endl;
            path.push_back(i);
            return;
        }
    }
    if (mazegrid[i].leftwall == 0 && mazegrid[mazegrid[i].left].visited != true && i % cols != 0) {
        //cout << i << " left" << endl;
        mazegrid[i].visited = true;
        solve_maze(mazegrid[i].left);
        if (found_solution == true) {
            //cout << "found solution" << endl;
            path.push_back(i);
            return;
        }
    }
    if (mazegrid[i].topwall == 0 && mazegrid[mazegrid[i].top].visited != true && i >= cols) {
        //cout << i << " up" << endl;
        mazegrid[i].visited = true;
        solve_maze(mazegrid[i].top);
        if (found_solution == true) {
            //cout << "found solution" << endl;
            path.push_back(i);
            return;
        }
    }else {
        //cout << i << " lost" << endl;
        return;
    }
}

//Prints the indeces of the mazes solution
void maze::print_solution() {
    cout << "PATH " << rows << " " << cols << endl;
    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << path[i] << endl;
    }
    return;
}

//Prints the image of the maze
void maze::print_maze_image(int cell_width) {
    int i, j, rindex, cindex, index;
    bool nowall;
    vector<RGB>pixels;
    RGB RGB1(255, 255, 255); //white
    RGB RGB2(0, 0, 0); //black
    //ofstream outfile;
    //outfile.open("maze.ppm", ofstream::binary);
    cout << "P6" << endl
         << (cols * cell_width) << " " << (rows * cell_width) << endl
         << "255" << endl;
    for (i = 0; i < (rows * cell_width); i++) {
        rindex = (i / cell_width);
        for (j = 0; j < (cols * cell_width); j++) {
            nowall = true;
            cindex = (j / cell_width);
            index = (rindex * cols) + cindex;
            if (j == 0 || i == 0 || j == (cols * cell_width) - 1 || i == (rows * cell_width) - 1) {
                pixels.push_back(RGB2);
            }else {
                /*
                if (mazegrid[index].topwall == 1 && (i % cell_width == 0)) {
                    pixels.push_back(RGB2);
                    nowall = false;
                }
                */
                if (mazegrid[index].bottomwall == 1 && ((i + 1) % cell_width == 0)) {
                    pixels.push_back(RGB2);
                    nowall = false;
                }
                /*
                if (mazegrid[index].leftwall == 1 && (j % cell_width == 0)) {
                    pixels.push_back(RGB2);
                    nowall = false;
                }
                */
                if (mazegrid[index].rightwall == 1 && ((j + 1) % cell_width == 0)) {
                    if (nowall == true) {
                        pixels.push_back(RGB2);
                        nowall = false;
                    }
                }
                if (nowall == true) {
                    pixels.push_back(RGB1);
                }
            }
        }
    }
    cout.write((char*)&pixels[0], (3 * (rows * cell_width) * (cols * cell_width)));
    //outfile.close();
    return;
}

//Prints the image of the mazes solution
void maze::print_solution_image(int cell_width) {
    int i, j, rindex, cindex, index;
    bool nowall, notfound;
    vector<RGB>pixels;
    RGB RGB1(255, 255, 255); //white
    RGB RGB2(0, 0, 0); //black
    RGB RGB3(255, 255, 0); //yellow
    //ofstream outfile;
    //outfile.open("maze.ppm", ofstream::binary);
    cout << "P6" << endl
         << (cols * cell_width) << " " << (rows * cell_width) << endl
         << "255" << endl;
    for (i = 0; i < (rows * cell_width); i++) {
        rindex = (i / cell_width);
        for (j = 0; j < (cols * cell_width); j++) {
            nowall = true;
            cindex = (j / cell_width);
            index = (rindex * cols) + cindex;
            if (j == 0 || i == 0 || j == (cols * cell_width) - 1 || i == (rows * cell_width) - 1) {
                pixels.push_back(RGB2);
            }else {
                if (mazegrid[index].bottomwall == 1 && ((i + 1) % cell_width == 0)) {
                    pixels.push_back(RGB2);
                    nowall = false;
                }
                if (mazegrid[index].rightwall == 1 && ((j + 1) % cell_width == 0)) {
                    if (nowall == true) {
                        pixels.push_back(RGB2);
                        nowall = false;
                    }
                }
                if (nowall == true) {
                    notfound = true;
                    for (int k = 0; k < (int)path.size(); k++) {
                        if (index == path[k]) {
                            pixels.push_back(RGB3);
                            notfound = false;
                        }
                    }
                    if (notfound == true) {
                        pixels.push_back(RGB1);
                    }
                }
            }
        }
    }
    cout.write((char*)&pixels[0], (3 * (rows * cell_width) * (cols * cell_width)));
    //outfile.close();
    return;
}