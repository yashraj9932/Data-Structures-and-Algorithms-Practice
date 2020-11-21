//Binary tree implementation Using Array 
//2*i+1 is the formula for finding the location of the left child of the current i
//2*i+2 is the formula for finding the location of the right child of the current i

#include <iostream>
using namespace std;

int arr[15];

void btcreation(int i)
{
	int right,left;
	cout<<"Enter left child: ";
	cin>>left;
	if(left!=-1)
	{
		arr[2*i+1]=left;
		btcreation(2*i+1);
	}
	cout<<"Enter right child: ";
	cin>>right;
	if(right!=-1)
	{
		arr[2*i+2]=right;
		btcreation(2*i+2);
	}
	else
		return;

}

void preorder(int i)
{
	cout<<100;
	if(i>15)
		return;
	if(arr[i]==0)
		return;
	cout<<arr[0]<<" ";
	preorder(2*i+1);
	preorder(2*i+2);
}

int main()
{
	cout<<"Enter root: ";
	cin>>arr[0];
	btcreation(0);
	for(int i=0;i<15;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	preorder(0);
	return 0;
}