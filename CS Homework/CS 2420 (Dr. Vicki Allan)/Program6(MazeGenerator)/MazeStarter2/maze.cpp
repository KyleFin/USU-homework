#include "maze.h"
//From current position, return the position inc away in given dir
Pos Maze::getPos(Pos curr, Dir dir,int inc=1)
{ 
	switch (dir)
		{
		   case NORTH: 
			   return Pos(curr.row-inc, curr.col);
		   case EAST:
			   return Pos(curr.row, curr.col+inc);
		   case SOUTH:
			   return Pos(curr.row+inc, curr.col);
		   case WEST:
			   return Pos(curr.row, curr.col-inc);
		}
	assert(false);
	return Pos();
}

// return direction symbol associated with Direction d
char Maze::getSymbol(Dir d)
{  switch(d){
	case NORTH: return '^';
	case SOUTH: return 'v';
	case EAST:  return '>';
	case WEST:  return '<';
   }
   assert(false);
   return static_cast<Dir>('<');
}

// Return true if maze can be solved from position curr.
// fout stores debug information
// solveMaze marks solution in maze
bool Maze::solveMaze(Pos curr,ofstream & fout)
{
	if(curr == final)
	{
		mark(curr, '!');
		return true;
	}
//(From Hint) The following method iterates through choices in an enumerated type:
//I changed the order of the enums so we try east and south before north and east (we're starting in the northwest corner)
    for (Dir d = EAST; d <= NORTH; d = static_cast<Dir>(d+1))
    {   
		mark(curr, getSymbol(d));
		Pos neighbor = getPos(curr, d , 1);
		if(cell[neighbor.row][neighbor.col] != EMPTY)
			continue;
		if(solveMaze(neighbor,fout))
			return true;
    }
	mark(curr, VISITED); // if it doesn't find the path, set curr to '@' and return false
	return false; 
}

//Create an initial maze as defined by rows and cols
void Maze::initializeMaze(int rows, int cols)
{	
    maze_rows = rows;
	maze_cols = cols;
	// dynamically create correct size grid
	cell = new char * [maze_rows];
	for (int r = 0; r < maze_rows; r++)
		cell[r] = new char [maze_cols];

	final = Pos(maze_rows-2,maze_cols-2);
	start = Pos(1,1);

	for(int i =0;i<maze_rows;i++)
		for(int j=0;j<maze_cols;j++)
			if(isEven(i) && isEven(j))
				cell[i][j] = WALLJOINT; // if row is odd, put wall on the position
			else if (!isEven(i) && isEven(j))    // if column is odd , put wall on the position
				cell[i][j] = WALLUP;
			else if (isEven(i) && !isEven(j))    // if column is odd , put wall on the position
				cell[i][j] = WALLACROSS;
			else
				cell[i][j] = EMPTY; // if odd and column are even, put space on the position 	}
}

// Create a maze by randomly removing walls between segments that are NOT already connected
void Maze::createRandomMaze(int rows, int cols)
{//*****************Need to create linked list wallList and unionSet of rooms	
	//create maze with all walls
	
	//put interior walls into wallList and rooms into unionSet

	//remove walls randomly from wallList
/*	while(!wallList.isEmpty())
	{
		wall = wallList(rand % size);
		if(find(roomSide1) != find(roomSide2)) //*****make function to test adjacent rooms (for horizontal or vertical walls)
		{
			mark(wall, EMPTY);
			unionSet(roomSide1, roomSide2);
		}
		wallList.remove(wall); //size-- as part of remove
	}*/
}

// Create a string version of maze, preceeded by msg.
// if cleanIt: Don't print visited markings
string Maze::toString(string msg, bool cleanIt)
{  stringstream cout;
   cout <<msg << endl<< "   ";
   for (int j=0; j < maze_cols;j++)
		cout << j%10;
   cout<< endl;
	for (int i = 0; i < maze_rows;i++){
		cout << setw(2)<<i <<" ";
		for (int j=0; j < maze_cols;j++)
			if (cleanIt && cell[i][j]== VISITED)
				cout << " ";
			else
				cout << cell[i][j];
	    cout << " " << setw(2) << i <<endl;
    }
   cout<<  "   ";   
   for (int j=0; j < maze_cols;j++)
		cout << j%10;
   cout<< endl; 
   return cout.str();
}


// Read the maze from the given filename.  
void Maze::readMaze(char * filename)
{  
	ifstream fin;
	fin.open(filename);
	assert(fin!=NULL);
	string str;
	fin >> maze_rows >> maze_cols;
	fin.ignore();  // Ignore end of line character
	initializeMaze(maze_rows, maze_cols);
	for(int i=0;i<maze_rows;i++)
	{
		getline(fin,str);
		cout << "STRING$" << str << "$"<< str.length() << endl;
		assert((int) str.length() >=maze_cols);
		for(int j=0;j<maze_cols;j++)
			 cell[i][j] = str[j];
	}
	fin.close();
}

