//Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

//Structure of Tree 
struct Node 
{
	Node *left;
	Node *right;
	int data;
};

bool search(Node *root, int x);
Node *insertElement(Node *root, int x);
int max(Node *curr);
Node *newNode(int x);
int min(Node *curr);
int height(Node *root);
void preorder(Node *curr);
void postorder(Node *curr);
void inorder(Node *curr);
void levelorder(Node *curr);
Node* deleteNode(Node *root,int x);

//Checking if the binary tree is a binary search tree.
/*Using the condition that every value of node has to be within a certain range in a bst ,so
if that is true then it is a bst*/
bool isbst(Node *root,int min,int max)
{
	if(root==NULL)
		return true;
	if(root->data>min && root->data<max && 
		isbst(root->left,min,root->data) && isbst(root->right,root->data,max))
		return true;
	else
		return false;
}

//The Address of the Minimum Node is returned
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

//Method to delete a particular given value
Node* deleteNode(Node *root,int x)
{
	if(root==NULL)
		return NULL;
	//If value is less,node to be deleted is searched in left subtree.
	else if(x<root->data)
		root->left=deleteNode(root->left,x);
	//If value is more,node to be deleted is searched in right subtree.
	else if(x>root->data)
		root->right=deleteNode(root->right,x);
	//The value is finally found. Hihi:-)
	else
	{
		//Case 1:When it is a leaf node and has no child
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		//When it just has a right child.
		else if(root->left==NULL)
		{
			Node *t=root;
			root=root->right;
			delete t;
		}
		//When it just has a left child.
		else if(root->right==NULL)
		{
			Node *t=root;
			root=root->left;
			delete t;
		}
		//When it has both the children.
		else
		{
			Node *t=FindMin(root->right);//The adress of the minimal value in the right subtree of the node to be deleted is found
			root->data=t->data;//The value of present is replaced with that min value
			root->right=deleteNode(root->right,t->data);//the right of root is now modified after deleting that minimal wala node in right.
		}
	}
	return root;
}

//Method to return the adresss of a given value in tree
Node* Find(Node*root, int data) {
	if(root == NULL) 
		return NULL;
	else if(root->data == data) 
		return root;
	else if(root->data < data) 
		return Find(root->right,data);
	else 
		return Find(root->left,data);
}

//Function to find Inorder Successor in a BST
Node* Getsuccessor(struct Node* root,int data) {
	// Search the Node - O(h)
	 Node* current = Find(root,data);
	if(current == NULL) return NULL;
	if(current->right != NULL) 
	{
		  //Case 1: Node has right subtree
		return FindMin(current->right); // O(h)
	}
	else {  
		 //Case 2: No right subtree  - O(h)
		Node* successor = NULL;
		Node* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data)
			 {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}
int main()
{
	Node *root = NULL;

	root = insertElement(root, 7);
	root = insertElement(root, 1);
	root = insertElement(root, 5);
	root = insertElement(root, 9);
	root = insertElement(root, 3);
	root = insertElement(root, 8);
	root = insertElement(root, 6);
	// if (search(root, 9))
	// 	cout << "True\n";
	// else
	// 	cout << "False\n";
	// int mins = min(root);
	// cout << mins << endl;
	// int miax = max(root);
	// cout << miax << endl;
	// cout << height(root) << endl;
	// preorder(root);
	// cout<<endl;
	inorder(root);
	cout<<endl;
	// postorder(root);
	// cout<<endl;
	// levelorder(root);
	// cout<<endl;
	// bool t=isbst(root,INT_MIN,INT_MAX);
	// if(t)
	// cout<<"True"<<endl;
	// deleteNode(root);
	inorder(root);
	Node *t=Getsuccessor(root,3);
	cout<<t->data;
	cout<<endl;
	return 0;
}

//Traversing the tree in level order way
//A queue is used to store the adresses visited since a first visited node will be popped and printed first.
//As the tree is traversed ,the visited node children are added to queue ,then this process is done till the level is printed ,
//than same process is done for each level at every node ,when the queue becomes empty(indicating traversal over),the process is stopped.
void levelorder(Node *root)
{
	if(root==NULL) return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node *curr=q.front();
		cout<<curr->data<<" ";
		if(curr->left!=NULL)q.push(curr->left);
		if(curr->right!=NULL)q.push(curr->right);
		q.pop();
	}

}

//Finding the minimum value by continuously traversing to the left from the tree.
int min(Node *curr)
{
	if (curr == NULL)
		cout << "The tree is empty" << endl;
	else if (curr->left == NULL)
		return curr->data;
	return min(curr->left);
}

//Finding the maximum value by continuously traversing to the right from the tree.
int max(Node *curr)
{
	while (curr->right != NULL)
		curr = curr->right;
	return curr->data;
}

//Traversing the tree in preorder way
void preorder(Node *curr)
{	
	if(curr==NULL)
		return;
	cout<<curr->data<<" ";
	preorder(curr->left);
	preorder(curr->right);
}

//Traversing the tree in inorder way
void inorder(Node *curr)
{
	if(curr==NULL)
		return;
	inorder(curr->left);
	cout<<curr->data<<" ";
	inorder(curr->right);
}

//Traversing the tree in post order way
void postorder(Node *curr)
{
	if(curr==NULL)
		return;
	postorder(curr->left);
	postorder(curr->right);		
	cout<<curr->data<<" ";
}

//Finding the height of the tree
//The leaf nodes are at height 0 so their children(unexisting) return -1,+1 is added to the max of them so the height becomes 0 of the leaf node.
//The height of left and right subtrees are compared at every level and the max is returned and 1 is added for going up one more level in the next recursion.
//The height of node is defined as the longest path from an attached leaf node to itself.
//This way the height of the tree is calculated as the longest distance from any leaf node to the root node.
int height(Node *root)
{
	if (root == NULL)
		return -1;
	return max(height(root->left), height(root->right)) + 1;
}

//Returns a New Node
Node *newNode(int x)
{
	Node *t = new Node();
	t->data = x;
	t->left = NULL;
	t->right = NULL;
	return t;
}

//Search complexity Reduces since it travels only one subtree to find value.
bool search(Node *root, int x)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == x)
	{
		return true;
	}
	else if (x <= root->data)
	{
		return search(root->left, x);
	}
	else
	{
		return search(root->right, x);
	}
}

//For inserting any element ,the modified current is returned to be stored in the original current pointer after inserting element in its left or right accordingly
Node *insertElement(Node *root, int x)
{
	if (root == NULL)
		root = newNode(x);
	else if (x <= root->data)
		root->left = insertElement(root->left, x);
	else
		root->right = insertElement(root->right, x);
	return root;
}