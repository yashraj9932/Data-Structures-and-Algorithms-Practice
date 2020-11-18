#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data;
	Node *next;
};

Node *front=NULL,*rear=NULL;


void print()
{
	Node *temp=front;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;

}

void push(int x)
{
	Node* t=new Node();
	t->data=x;
	t->next=NULL;
	if(front==NULL && rear==NULL)
		front=t;
	else
		rear->next=t;
	rear=t;
}

void pop()
{
	if(front==NULL)
		return;
	if(front==rear)
	{
		front=rear=NULL;
		return;
	}
	Node *t=front;
	front=front->next;
	free(t);
}
int main()
{
	int n;
	cout<<"Enter the number of elements:"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{	
		push(i);
	}
	print();
	pop();
	pop();
	print();
	return 0;
}

