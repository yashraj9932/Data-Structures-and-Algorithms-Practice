#include<bits/stdc++.h>
using namespace std;

int a[6],n=6,f=-1,r=-1;

void insertBeginning(int x);
void deleteEnd();
void deleteBeginning();
void insertEnd(int x);
void create();
void print();

int main()
{
	create();
	deleteBeginning();
	deleteEnd();
	deleteBeginning();
	deleteEnd();
	deleteBeginning();
	deleteEnd();

}

void deleteBeginning()
{
	if(f==-1)
		cout<<"The Queue is Empty"<<endl;
	else if(f==r)
		f=r=-1;
	else 
		f=(f+1)%n;
	print();
}

void deleteEnd()
{
	if(r==-1)
		cout<<"The Queue is Empty"<<endl;	
	else if(f==r)
		f=r=-1;
	else
		r=(r-1)%n;
	print();
}

void insertEnd()
{
	cout<<"Enter the value: ";
	int x; cin>>x;
	if(r==n-1 || r+1==f)
		cout<<"The Queue is full"<<endl;
	else if(r==-1)
	{
		f=r=0;
		a[r]=x;
	}
	else
	{
		r=(r+1)%n;
		a[r]=x;
	}
	print();
}

void insertBeginning()
{
	cout<<"Enter the value: ";
	int x; cin>>x;
	//f==0
	if(r==n-1 || r+1==f)
		cout<<"The Queue is full"<<endl;
	else if(f==-1)
	{
		f=r=0;
		a[f]=x;
	}
	else
	{
		f=(f-1)%n;
		a[f]=x;
	}
	print();
}
void create()
{
	f=0;r=0;
	int x;
	cout<<"Enter the numbers: ";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a[r++]=x;
	}
	print();
}

void print()
{
	cout<<"The elements are: ";
	if(f==-1)
		cout<<"Empty"<<endl;
	else if(f<r)
	{
		for(int i=f;i<r;i++)
		{
			cout<<a[i]<<" ";
		}
	}
	else
	{
		for(int i=f;i<6;i++)
		{
			cout<<a[i]<<" ";
		}

		for(int i=0;i<r;i++)
		{
			cout<<a[i]<<" ";
		}
	}
	cout<<endl;
}