/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element 
(considering ascending order) from unsorted part and putting it at the beginning.
*/
#include <bits/stdc++.h>
using namespace std;

void swap(int *xp,int *yp)
{
	int t=*xp;
	*xp=*yp;
	*yp=t;
}

void selectionSort(int arr[],int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
				min=j;

		}
		swap(&arr[i],&arr[min]);
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
	int arr[]={10,9,8,7,6,5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);  
    cout << "Sorted array: \n";  
    print(arr, n);
	return 0;
}