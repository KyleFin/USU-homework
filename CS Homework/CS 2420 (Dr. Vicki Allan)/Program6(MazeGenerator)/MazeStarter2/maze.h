
#include "Pos.h"
#include <string>
#include <assert.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

enum{WALLUP='|', WALLACROSS= '-', WALLJOINT = '+', EMPTY=' ',VISITED = '@'};
enum Dir {NORTH, EAST,SOUTH, WEST};

class Maze 
{
private:
   Pos start;   // Location where path search begins
   Pos final;   // Location where path search ends
   int maze_rows, maze_cols;  //Size of cell
   char **cell;               // Grid of characters (including walls) of maze
   bool solveMaze(Pos curr,ofstream & fout);
   bool isEven(int val){ return ((val%2)==0);}
   void initializeMaze(int rows, int cols);
   char getSymbol(Dir d);
   Pos getPos(Pos curr, Dir dir,int inc);
   void mark(Pos p,char c) {cell[p.row][p.col] = c;};

public:
	Maze(){ 
		cell = NULL;	
    };
 	void readMaze(char *);
    string toString(string msg="", bool cleanIt=false);
	void createRandomMaze(int rows, int cols);
	bool solveMaze(ofstream & fout){return solveMaze(start,fout);}
};