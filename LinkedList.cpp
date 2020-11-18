#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void createList(int n);
void insertAtEnd(int x);
void deleteNode();
void insertAtBeginning(int x);
void print();
void reverseList();
void printRecur(Node *t);
void printReverse(Node *t);
void reverseListRecur(Node *t);

Node *start;

int main()
{
    start = NULL;
    cout<<"Enter the value of n:"<<endl;
    int n;
    cin>>n;
    createList(n);
    // deleteNode();
    // reverseList();
    reverseListRecur(start);
    print();
    return 0;
}
void createList(int n)
{
    cout<<"Enter the numbers:"<<endl;
    for(int i=0;i<n;i++)
    {
        Node *temp=new Node();
        Node *last;
        cin>>temp->data;
        temp->next=NULL;
        if(start==NULL)
            start=temp;
        else
            last->next=temp;
        last=temp;
    }
    print();
    // printRecur(start);
    // printReverse(start);

}
void insertAtBeginning(int x)
{
	Node *t1=new Node();
	t1->data=x;
	t1->next=start;
	start=t1;
}
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
void insertAtEnd(int x)
{
    if(start==NULL)
        insertAtBeginning(x);
    else
    {
        Node *t=new Node();
        t->data=x;
        t->next=NULL;
        Node *t1=start;
        while(t1->next!=NULL)
            t1=t1->next;
        t1->next=t;

    }  
}
void deleteNode()
{
    cout<<"Enter the position of node to delete"<<endl;
    int pos; cin>>pos;
    if(pos<=0)
        cout<<"Invalid position.Are you an Idiot?Will have to terminate! :("<<endl;
    else if(pos==1)
        start=start->next;
    else
    {
        int i=1;
        Node *temp=start;
        while(true)
        {
            i++;
            if(i==pos)
                break;
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
    print();
}
void reverseList()
{
    Node *prev=NULL;
    Node *curr=start;
    Node *t;
    while(curr!=NULL)
    {
        t=curr->next;
        curr->next=prev;
        prev=curr;
        curr=t;
    }
    start=prev;
    print();
}
void printRecur(Node *t)
{
    if(t==NULL)
    {
        cout<<endl;
        return;
    }
    else
    {
        cout<<t->data<<" ";
        printRecur(t->next);
    }
}
void printReverse(Node *t)
{
   if(t==NULL)
        return;
    else
    {
        printReverse(t->next);
        cout<<t->data<<" ";
    } 
}
void reverseListRecur(Node *t)
{
    if(t->next==NULL)
    {
        start=t;
        return;
    }
    reverseListRecur(t->next);
    t->next->next=t;
    t->next=NULL;
}
