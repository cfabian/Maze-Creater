# Maze-Creater

Creates and solves mazes.

##Usage

There are three different executables in this package. <br/>
Run the makefile to compile.

###mazemake

Outputs the size of the maze and the two blocks that do not have a wall between them in the maze. It is best to redirect this to a text file so it can be used with the other parts.
```
./mazemake rows columns > maze.txt
```

###mazesolve

Outputs the size of the maze and the block number that is necessary to go through in order to solve the maze. It takes the file from mazemake through stdin as a parameter. Once agian it is best to redirect this to a text file so it can be used with the other parts.
```
./mazesolve < maze.txt > solved_maze.txt
```

###mazeshow

Outputs a PPM image of the maze. It takes the choosen width of the blocks in the maze, the file created by mazemake and the file created by mazesolve (optional) as parameters. The PPM file contents will be sent to stdout so it is best to redirect to a PPM file. <br/>
``` 
./mazeshow block_width maze.txt solved_maze.txt(optional) > maze.ppm
```
This can be combined with the linux utility convert to make a .png image instead.
```
./mazeshow block_width maze.txt | convert - maze.png
