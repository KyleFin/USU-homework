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

		listNode* nextNode = head;
		while(nextNode->next != NULL)
			nextNode = nextNode->next;
		nextNode->next = new listNode(p);
		return nextNode->next;
	}

	Pos remove(int n) //return the nth element and remove it from the list
	{
		listNode* iter = head;
		for(int i=0; i<n; i++)
		{
			if(iter->next == NULL)
				return NULL;
			iter = iter->next;
		}
		listNode* victim = iter;
		*iter = *iter->next;
		return victim->p;
	}
	
	bool isEmpty() { if(head == NULL) return true; return false;}
	
	string toString()
	{
		stringstream out;
		listNode* n = head;
		while(n != NULL)
		{
			out << n->p.toString() << " -> ";
			n = n->next;
		}
		out << endl;
		return out.str();
	}
};