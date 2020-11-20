//Circular queue using linked list which is same as queue using circular linked list.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *front = NULL, *rear = NULL;

void print()
{
	Node *temp = front;
	while (temp->next != front)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data;//Explicitly printing the last element.
	cout << endl;
}

//Inserting Elements
void insert(int x)
{
	Node *t = new Node();
	t->data = x;
	if (rear == NULL)
	{
		front = t;
	}
	else
		rear->next = t;
	t->next = front;
	rear = t;
}

//Deleting Element
void deletee()
{
	Node *t = front;
	front = front->next;
	rear->next = front;
	free(t);
}
int main()
{
	cout << "Enter the value of n:" << endl;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		insert(i);
		print();
	}
	cout << "Next" << endl;
	for (int i = 1; i < 3; i++)
	{
		deletee();
		print();
	}
	cout << "Next" << endl;
	for (int i = 1; i <= n; i++)
	{
		insert(i);
		print();
	}
	return 0;
}