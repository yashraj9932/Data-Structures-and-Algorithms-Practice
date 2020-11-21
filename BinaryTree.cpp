//Program for implementation of binary tree
//Read comments of BST for more understanding
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};
Node *root=NULL;


Node* Binarytreecreation()
{
	int data; cin>>data;
	if(data!=-1)
	{
		Node *t=new Node();
		t->data=data;
		cout<<"Enter left child of "<<data<<": ";
		t->left=Binarytreecreation();
		cout<<"Enter right child of "<<data<<": ";
		t->right=Binarytreecreation();
		return t;
	}
	else
		return NULL;
}

//Prints preorder without recursion using explicit stack
void preorder(Node *t)
{
	if(t==NULL)
		return;
	stack<Node*> ss;
	while(t!=NULL)//Evaluating till there are elements in the stack
	{
		cout<<t->data<<" ";
		if(t->right!=NULL)//If node has right subtree ,it is checked first,its stored to be printed after left is printed.
			ss.push(t->right);
		if(t->left!=NULL)//If the same node has left subtree.it is iterated towards that node .
			t=t->left;
		else if(!ss.empty())//This means that the current node has no children,It this is the case
		{
			t=ss.top();//Then the most recent element is put in the curr pointer,and the aboove process is repeated.
			ss.pop();//Also the element is popped out.
		}
		else//If all elements are done with,we come out.
			break;
	}
	cout<<endl;
}

void preorderecur(Node *t) 
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		preorder(t->left);
		preorder(t->right);
	}
}

int main()
{
	cout<<"Enter data for entering data or -1 if you dont want any value: ";
	root=Binarytreecreation();
	preorderecur(root);
	preorder(root);
}
