#include <iostream>
#include "mazegrid.h"
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    int cell_width, r, c;
    string maze_fname, solution_fname, header;
    ifstream maze_infile, solution_infile;
    if (argc == 3) {
        cell_width = atoi(argv[1]);
        maze_fname = argv[2];
        maze_infile.open(maze_fname);
        if (maze_infile.is_open()) {
            maze_infile >> header;
            //Checks that the inputted file is a maze file
            if (header == "MAZE") {
                maze_infile >> r >> c;
                //Reads in the maze file, solves the maze and prints out the solution indeces
                maze maze1(r, c);
                maze1.rev_init_maze();
                while (maze_infile >> r >> c) {
                    maze1.build_wall(r, c);
                }
                maze1.print_maze_image(cell_width);
            }
        }
        return 0;
    }else if (argc == 4) {
        string sheader;
        int sr, sc, index;
        cell_width = atoi(argv[1]);
        maze_fname = argv[2];
        solution_fname = argv[3];
        maze_infile.open(maze_fname);
        solution_infile.open(solution_fname);
        if (maze_infile.is_open() && solution_infile.is_open()) {
            maze_infile >> header;
            solution_infile >> sheader;
            //Checks that the inputted file is a maze file
            if (header == "MAZE" && sheader == "PATH") {
                maze_infile >> r >> c;
                solution_infile >> sr >> sc;
                if (r == sr && c == sc) {
                    //Reads in the maze file, solves the maze and prints out the solution indeces
                    maze maze1(r, c);
                    maze1.rev_init_maze();
                    while (maze_infile >> r >> c) {
                        maze1.build_wall(r, c);
                    }
                    while (solution_infile >> index) {
                        maze1.path.push_back(index);
                    }
                    maze1.print_solution_image(cell_width);
                }
            }
        }
        return 0;
    }else {
        cout << "Usage: mazeshow cell_width maze_file_name solve_maze_file_name(optional)" << endl;
        return -1;
    }
    return -1;
}