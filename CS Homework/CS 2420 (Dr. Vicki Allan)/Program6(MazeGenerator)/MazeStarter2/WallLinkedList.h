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

	listNode* add(Pos p) //add p to the end of the linked list
	{
		size++;
		if(head == NULL)
		{
			head = new listNode(p);
			return head;
		}

		listNode* nextNode = head->next;
		while(nextNode != NULL)
			nextNode = nextNode->next;
		nextNode = new listNode(p);
		return nextNode;
	}

	Pos* remove(int n); //return a pointer to the nth element and remove it from the list
	bool isEmpty() { if(head == NULL) return true; return false;}
};