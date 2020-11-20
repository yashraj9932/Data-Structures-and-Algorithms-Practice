//Linked List Reversal Using Stack.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *prev;
	Node *next;
};

Node *start = NULL;

void print()
{
	Node *temp = start;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void createList(int n)
{
	cout << "Enter the numbers:" << endl;
	for (int i = 0; i < n; i++)
	{
		Node *temp = new Node();
		Node *last;
		cin >> temp->data;
		temp->next = NULL;
		if (start == NULL)
			start = temp;
		else
			last->next = temp;
		last = temp;
	}
	print();
}

//Using an explicit stack to reverse then using the functional call stack to reverse linked list.
void revStack()
{
	Node *temp = start;
	stack<Node *> s;
	while (temp != NULL)
	{
		s.push(temp);
		temp = temp->next;
	}
	Node *t = s.top();
	start = t;
	while (!s.empty())
	{
		t->next = s.top();
		s.pop();
		t = t->next;
	}
	t->next = NULL;
}
int main()
{
	cout << "Enter the value of n:" << endl;
	int n;
	cin >> n;
	createList(n);
	print();
	revStack();
	print();
	return 0;
}