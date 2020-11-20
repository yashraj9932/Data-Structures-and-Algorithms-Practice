//Circular Linked List
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *start = NULL;
Node *last;
void createList(int n);
void print();
void deleteNode();
void insert(int x);

int main()
{
	cout << "Enter the value of n:" << endl;
	int n;
	cin >> n;
	createList(n);
	print();
	deleteNode();
	print();
	insert(33);
	print();
	insert(55);
	print();
	insert(44);
	print();
	return 0;
}

//Method to create List
void createList(int n)
{
	cout << "Enter the numbers: " << endl;
	for (int i = 0; i < n; i++)
	{
		Node *t = new Node();
		cin >> t->data;
		//Entry of first Node while creation
		if (start == NULL)
			start = t;
		else
			last->next = t;
		t->next = start;
		last = t;
	}
}

//For deleting a Node
void deleteNode()
{
	cout << "Enter the position to delete: ";
	int pos;
	cin >> pos;
	if (pos < 1)
		pos = 1;
	if (pos == 1)
	{
		Node *t1 = start;
		start = start->next;
		last->next = start;//The last node pointer gets updated with new start.
		free(t1);
	}
	else
	{
		Node *t = start;
		Node *t2 = start;
		int i = 1;
		while (t->next != start)
		{
			i++;
			t = t->next;
			if (i == pos)//Iterated till the required position of deletion is to be found.
			{
				t2->next = t->next;
				break;
			}
			t2 = t;
		}
		if (t2->next == start)//Special of adjusting last pointer if the last node was to be deleted.
			last = t2;
		free(t);
	}
}

//Inserting Elements
void insert(int x)
{
	cout << "Enter the position to insert Node" << endl;
	int pos;
	cin >> pos;
	Node *t = new Node();
	t->data = x;
	if (pos == 1)
	{
		t->next = start;
		start = t;
		last->next = t;
	}
	else
	{
		Node *t1 = start;
		int i = 1;
		while (t1->next != start)
		{
			i++;
			if (i == pos)//Iterated till the required position of insertion.
			{
				t->next = t1->next;
				t1->next = t;
				break;
			}
			t1 = t1->next;
		}
		if (t1->next == start)
		{
			t1->next = t;
			t->next = start;
			last = t;
		}
	}
}

//Printing the Elemnets
void print()
{
	Node *temp = start;
	while (temp->next != start)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data;
	cout << endl;
}