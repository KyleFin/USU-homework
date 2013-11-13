#include "maze.h"
#include <windows.h>
#include "DisjointSet.h"
#include "WallLinkedList.h"

void pause()
{	cout<<endl<<"press any key to see the result of the created Maze problem";
	getchar();
}

int main()
{   ofstream fout;
   	fout.open("mazeOut.txt");
	/////////////////////////////////////////////////////////////
	// Demonstration of WallLinkedList                         //
	/////////////////////////////////////////////////////////////
/*	Pos ab(1,3);
	Pos bc(3,4);
	Pos dc(2,4);
	Pos c(7,4);
	Pos b(99,4);

	WallLinkedList a;
	a.add(ab);
	cout << a.toString();
	a.add(bc);
	cout << a.toString();
	a.add(dc);
	a.add(c);
	a.add(b);
	cout << a.toString();
	cout << "Removed " << a.remove(3).toString() << endl;
	cout << "Removed " << a.remove(3).toString() << endl;
	cout << "Removed " << a.remove(3).toString() << endl;
	cout << a.toString();
	cout << "Removed " << a.remove(3).toString() << endl;
	cout << "Removed " << a.remove(3).toString() << endl;
	cout << "Removed " << a.remove(3).toString() << endl;
	cout << a.toString();
*/	
	/////////////////////////////////////////////////////////////
	// Demonstration of disjoint set                           //
	/////////////////////////////////////////////////////////////

	fout<<"****  Disjoint problem  **** "<<endl;
	
	DisjointSet mySet(10); //create disjoint set

	mySet.unionSets(1,6);
	mySet.unionSets(6,7);
	mySet.unionSets(2,3);

	fout<< "3 is a member of =" << mySet.find(3) << endl;
	fout<< "2 is a member of =" << mySet.find(2) << endl;
	mySet.unionSets(4,5);
	mySet.unionSets(6,4);
	if(mySet.find(6)==mySet.find(4)) fout<<"6 and 4 are in same class"<<endl;
	if(mySet.find(7)==mySet.find(4)) fout<<"7 and 4 are in same class"<<endl;
	cout << mySet.toString();
	
	////////////////////////////////////////////////////////////
	// Demonstration of maze solve problem                    //
	////////////////////////////////////////////////////////////
    pause();

	system("cls");  // Clears the screen
		
	Maze maze1,maze2;

	maze1.readMaze("maze1.txt");
	cout << maze1.toString("\n**Original Maze from maze1.txt**");
    //fout << maze1.toString("\n**Original Maze from maze1.txt**");
	maze1.solveMaze(fout);
	cout << maze1.toString("\n**Solved Maze**",true);
	fout << maze1.toString("\n**Solved Maze**",true);

	/////////////////////////////////////////////////////////////
	// Demonstration of creation maze                          //
	/////////////////////////////////////////////////////////////

	maze2.createRandomMaze(21,23);
	fout << maze2.toString("\n**MY Created Maze**");
	cout << maze2.toString("\n**MY Created Maze**");
	maze2.solveMaze(fout);
    fout << maze2.toString("\n**Solved Maze**",false);
	fout << maze2.toString("\n**Solved Maze**",true);
	cout << maze2.toString("\n**Solved Maze**", false);
    fout.close();
	pause();
return 0;
}