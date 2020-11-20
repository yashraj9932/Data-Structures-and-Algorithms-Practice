//Double Ended Queue using Doubly Linked List
//Single Linked List is not used generally since DLL provides ease of deletion at end and also other things.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *prev;
};

Node *front = NULL, *rear = NULL;

void print()
{
	Node *t;
	for (t = front; t != rear->next; t = t->next)
	{
		cout << t->data << " ";
	}
	cout << endl;
}

//Also checks that all prev links are set correctly
void printRev()
{
	Node *t;
	for (t = rear; t != front->prev; t = t->prev)
	{
		cout << t->data << " ";
	}
	cout << endl;
}

Node *createNode(int x)
{
	Node *t = new Node();
	t->data = x;
	t->next = NULL;
	t->prev = NULL;
	return t;
}

void insertBeginning()
{
	cout << "Enter the value" << endl;
	int x;
	cin >> x;
	Node *temp = createNode(x);
	temp->next = front;
	front->prev = temp;
	front = temp;
}

void deleteBeginning()
{
	Node *t = front;
	front = front->next;
	front->prev = NULL;
	free(t);
}

void insertEnd()
{
	cout << "Enter the value" << endl;
	int x;
	cin >> x;
	Node *temp = createNode(x);
	rear->next = temp;
	temp->prev = rear;
	rear = temp;
}

void deleteEnd()
{
	Node *t = rear;
	t->prev->next = NULL;
	rear = t->prev;
	free(t);
}

void createList(int n)
{
	cout << "Enter the numbers: " << endl;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		Node *temp = createNode(x);
		if (front == NULL)
			front = temp;
		else
		{
			temp->prev = rear;
			rear->next = temp;
		}
		rear = temp;
	}
}

int main()
{
	cout << "Enter the values of n: ";
	int n;
	cin >> n;
	createList(n);
	print();
	cout << "Now" << endl;
	deleteEnd();
	print();
	cout << "Now" << endl;
	deleteBeginning();
	print();
	cout << "Now" << endl;
	insertBeginning();
	print();
	insertEnd();
	print();
	printRev();
	return 0;
}