#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int p;
	int data;
	Node *next;
};

Node *start=NULL;

void print()
{
	Node *temp=start;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;

}
void insert(int pri,int x)
{
	Node *t=new Node();
	t->data=x;
	t->p=pri;
	t->next=NULL;
	if(start==NULL)
	{
		start=t;
	}
	else
	{
		int f=0;
		Node *t1=start;
		while(t1->next!=NULL && t1->next->p<=pri)
		{
			f=1;
			t1=t1->next;
		}
		if(f==0)
		{
			t->next=start;
			start=t;
		}
		else
		{
			t->next=t1->next;
			t1->next=t;
		}
	}
	print();
}

int main()
{
	cout<<"Enter the value of n: "<<endl;
	int n; cin>>n;
	cout<<"Enter the priority"<<endl;
	for(int i=1;i<=n;i++)
	{
		int pri;
		cin>>pri;
		insert(pri,i);
	}

	return 0;
}