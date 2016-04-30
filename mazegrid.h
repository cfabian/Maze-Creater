//Caleb Fabian
//CS 302 - Lab 6 Mazegrid Header
//April 4, 2016

#ifndef MAZEGRID_H
#define MAZEGRID_H

#include <iostream>
#include "dset.h"
#include <vector>
#include <cstdlib>
using namespace std;

class maze {
  //Stores the adjacent cell indeces, the wall on each side and whether it has been visited for each cell
  struct cell {
    cell() { }
    cell(int index) {
      top = 0;
      bottom = 0;
      left = 0;
      right = 0;
      //Initializes there to be walls everywhere
      //1 means there is a wall, 0 means there is no wall
      topwall = 1;
      bottomwall = 1;
      leftwall = 1;
      rightwall = 1;
      visited = false;
    }
    ~cell() { }
    int top;
    int bottom;
    int left;
    int right;
    int topwall;
    int bottomwall;
    int leftwall;
    int rightwall;
    bool visited;
  };
  public:
    vector<int> path;
    maze(int r, int c) {
        rows = r;
        cols = c;
        found_solution = false;
    }
    ~maze() {
      mazegrid.clear();
      path.clear();
    }
    void initialize_maze();
    void create_maze();
    void delete_wall(int, int);
    void print_maze();
    void read();
    void rev_init_maze();
    void build_wall(int, int);
    void solve_maze(int);
    void print_solution();
    void print_maze_image(int);
    void print_solution_image(int);
  private:
    vector<cell> mazegrid;
    int rows;
    int cols;
    bool found_solution;
};

struct RGB {
  RGB () { }
  RGB (char red, char green, char blue) {
    r = red;
    g = green;
    b = blue;
  }
  ~RGB () { }
  char r;
  char g;
  char b;
};

#endif