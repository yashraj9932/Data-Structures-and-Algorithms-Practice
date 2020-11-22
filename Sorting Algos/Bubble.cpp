/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the 
adjacent elements if they are in wrong order.
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *xp,int *yp)
{
	int t=*xp;
	*xp=*yp;
	*yp=t;
}

void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);
		}
	}
}

void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[]={9,8,7,6,32,10,5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);  
    cout << "Sorted array: \n";  
    print(arr, n);
	return 0;
}