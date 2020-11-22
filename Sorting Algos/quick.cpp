/*
Like Merge Sort, QuickSort is a Divide and Conquer algorithm.
It picks an element as pivot and partitions the given array around the picked pivot .
*/
#include<iostream>
using namespace std;

void swap(int *xp,int *yp)
{
	int t=*xp;
	*xp=*yp;
	*yp=t;
}

int partition(int arr[],int low,int high)
{
	int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
  	//We arrange all the small elements than the pivot(last element in the start),
  	//so that when we swap pivot with the beech wala value it is in a perfect position.
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  //jahan tak chota elements daala uske thik baad pivot daaldia
    return (i + 1);  
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		/* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
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
	int arr[]={6,7,8,1,4,0,3,22,19,41};
	int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    print(arr, n);  
	return 0;
}