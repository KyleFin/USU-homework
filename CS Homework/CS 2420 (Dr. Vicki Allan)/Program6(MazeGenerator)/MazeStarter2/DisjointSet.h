#ifndef DisjointSet_H
#define DisjointSet_H

#include <sstream>
using namespace std;

class DisjointSet
{
private:
	int* groupArray;
	int size;

public:
	DisjointSet(int s)
	{
		size = s;
		groupArray = new int[size];
		for(int i=0; i<size; i++)
			groupArray[i] = -1;
	}

	int find(int e)
	{
		if(e >= size) //Make sure e is within bounds
			return -999;

		if(groupArray[e] < 0)
			return e;

		int root = find(groupArray[e]);
		groupArray[e] = root; //Path compression
		return root;
	}

	int unionSets(int a, int b)//Merge groups of a and b, returning "root" of new group
	{
		if(a >= size || b >= size) //Make sure a and b are within bounds
			return -999;

		//We need to use the "roots" of the groups to union
		int aGroup = find(a);
		int bGroup = find(b);

		//We want to merge the shorter group into the taller to keep our "tree" short
		//(height is stored at the "root" as a negative value)
		if(groupArray[aGroup] < groupArray[bGroup]) //aGroup taller than bGroup.  Merge bGroup to aGroup
		{
			groupArray[bGroup] = aGroup;
			return aGroup;
		}

		if(groupArray[aGroup] == groupArray[bGroup])
			groupArray[bGroup]--; //Update bGroup height 
		groupArray[aGroup] = bGroup;
		return bGroup;
	}

	string toString()
	{
		stringstream ss;
		ss << endl;
		for(int i=0; i<size; i++)
		{
			ss << i << " " << groupArray[i] << endl;	
		}
		ss << endl;
		return ss.str();
	}
};

#endif