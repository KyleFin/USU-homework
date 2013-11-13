#ifndef WallLinkedList_H
#define WallLinkedList_H

#include "Pos.h"

class listNode
{
public:
	Pos p;
	listNode* next;
	listNode(Pos& pos) { p.row = pos.row; p.col = pos.col; next = NULL;}
};

class WallLinkedList
{
private:
	listNode* head;
	int size;
public:
	WallLinkedList(){ head = NULL; size = 0; }

	int getSize(){ return size; }

	listNode* add(Pos p) //add p to the end of the linked list
	{
		int s = 1;
		if(head == NULL)
		{
			head = new listNode(p);
			size++;
			return head;
		}

		listNode* nextNode = head;
		while(s < size)
		{
			nextNode = nextNode->next;
			s++;
		}
		nextNode->next = new listNode(p);
		size++;
		return nextNode->next;
	}

	Pos remove(int n) //return the nth element and remove it from the list
	{
		if(isEmpty())
			return Pos(-999, -999);
		n = n%size;
		listNode* iter = head;
		for(int i=0; i<n; i++)
			iter = iter->next;
		Pos victim(iter->p);
		size--;
		if(n < size)
			*iter = *iter->next;
		return victim;
	}
	
	bool isEmpty() { if(size <= 0) return true; return false;}
	
	string toString()
	{
		stringstream out;
		if(isEmpty())
			out << "The list is empty";
		listNode* n = head;
		int s = 0;
		while(s < size)
		{
			out << n->p.toString() << " -> ";
			n = n->next;
			s++;
		}
		out << endl;
		return out.str();
	}
};

#endif