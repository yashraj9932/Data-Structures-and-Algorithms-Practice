//Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *prev;
	Node *next;
};

Node *start = NULL;

//Creates and Returns a Node
Node *createNode(int x)
{
	Node *t = new Node();
	t->data = x;
	t->next = NULL;
	t->prev = NULL;
	return t;
}

//Inserting at Beginning
void insertBeginning(int x)
{
	Node *newNode = createNode(x);
	if (start == NULL)
	{
		start = newNode;
		return;
	}
	start->prev = newNode;
	newNode->next = start;
	start = newNode;//New start since the element is inserted at beginning.
}

//Inserting at end
void insertEnd(int x)
{
	Node *newNode = createNode(x);
	Node *temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	newNode->prev = temp;
	temp->next = newNode;
}

//Printing the elements
void print()
{
	Node *t = start;
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}

//Main Method
int main()
{
	cout << "Enter the value of n" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		insertBeginning(i);
	}
	for (int i = 0; i < n; i++)
	{
		insertEnd(i);
	}
	print();
	return 0;
}