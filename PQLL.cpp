//PriorityQueue Using Linked List
//Pop function not written,its easy,the smallest element needs to be popped which is removing first element.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int p;
	int data;
	Node *next;
};

Node *start = NULL;

//Printing the Linked List
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

//Inserting a node according to priority
void insert(int pri, int x)
{
	Node *t = new Node();
	t->data = x;
	t->p = pri;
	t->next = NULL;
	//If the list is empty ,then the node is inserted at beginning.
	if (start == NULL)
	{
		start = t;
	}
	else
	{
		int f = 0;
		Node *t1 = start;
		//Traverse till the required priority or till the end if it has the least priority
		while (t1->next != NULL && t1->next->p <= pri)
		{
			f = 1;
			t1 = t1->next;
		}
		//It means that it didnt go in the while loop at all,indicating its priority to be the least,also indicating that the list aint empty
		if (f == 0)
		{
			t->next = start;
			start = t;
		}
		//Adjustment of links for inserting the node at required priority
		else
		{
			t->next = t1->next;
			t1->next = t;
		}
	}
	print();
}

int main()
{
	cout << "Enter the value of n: " << endl;
	int n;
	cin >> n;
	cout << "Enter the priority" << endl;
	for (int i = 1; i <= n; i++)
	{
		int pri;
		cin >> pri;
		insert(pri, i);
	}

	return 0;
}