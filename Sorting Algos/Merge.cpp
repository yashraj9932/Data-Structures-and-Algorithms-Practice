//Merge sort is like binary tree post order, first left right then merge in root
/*
It divides the input array into two halves, calls itself for the two halves,and then merges the 
two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r)
is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. 
*/

#include<iostream>
using namespace std;

// Merges two subarrays of arr[]. First subarray is arr[l..m] Second subarray is arr[m+1..r]
void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

     int i = 0,j = 0,k = l;

     while(i< n1 && j<n2)
     {
        if(L[i]<R[i])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
     }
      // Copy the remaining elements of L[], if there are any
    while (i < n1) 
        arr[k++] = L[i++];
 
    // Copy the remaining elements of R[], if there are any
    while (j < n2) 
        arr[k++] = R[j++];
}

void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(r+l-1)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout<<endl;
}

int main()
{

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is \n";
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}