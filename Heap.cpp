//A complete binary tree is one having all nodes filled till h-1 height and if there are any more nodes they should be as left as possible in the level.
//Height is always log(n) of CBT.
//Heap is a complete binary tree.
//min heap-cbt having less value than all descendants
//max heap-cbt having greater value than all descendants
//While inserting(max) we insert it at the smallest empty index availble and the direction of swapping is upwards.
//So the creation of whole heap of n nodes is n times log(n)=nlog(n) of each insertion.
//only the topmost element(root) can be removed from the heap.
//after removing the element at maximum possible filled index is moved to root and then compared with
// children and accordingly swapped.(direction is downwards,opposite direction to that of insertion)
//heap sort is the process of continously removing element from root and placing it at the last free index ,
//this way after traversing(deleting) all nodes we get a sorted array.
//Given a set of elements,create a heap delete the heap,and thats heap sort.
//Heapify is first inserting elements into array normally then checking from backwards,(last element) .
//If its lonely(no child) then consider it as heap. then this way the last level is covered and then,
// when we reach parent wala level of this alone wala level then we check values with children and,
// values if required adjusted accordingly,this way the process is repeated till we get the max heap.
//if Smaller Number Higher Priority create min heap ,and vice versa(for priority queues).
//Why is heap best structure to implement pq? Because it does both inserting and deleting in log n and creating in n.
//Other processes always take o(1) & o(n) for insertion and deletion or vice versa.

/*
Note:
Root is at index 0 in array.
Left child of i-th node is at (2*i + 1)th index.
Right child of i-th node is at (2*i + 2)th index.
Parent of i-th node is at (i-1)/2 index.
*/
#include <iostream>
using namespace std;

int arr[] = { 12, 11, 13, 5, 6, 7 };
int n = sizeof(arr) / sizeof(arr[0]);

// Heapify a node:Means converting the node and its subtree to heap.Done from top down.
// To heapify a subtree rooted with node i which is an index in arr[]. N is size of heap 
void heapifytopdown(int n,int i)
{
 	int lar=i;
 	int l=2*i+1;   
 	int r=2*i+2;
 	if(l<n && arr[lar]<arr[l])   
 		lar=l;
 	if(r<n && arr[lar]<arr[r])   
 		lar=r;
 	if(lar!=i)
 	{
 		swap(arr[i],arr[lar]);	
 		//Recursive heapify the tree jis se value chori karke present location pe daalas
 		heapifytopdown(n,lar);
	}
}

// Function to heapify ith node in a Heap of size n following a Bottom-up approach 

void heapifybottomup(int i)
{
	int parent=(i-1)/2;
	if(arr[parent]>0)
	{
		// For Max-Heap If current node is greater than its parent 
        // Swap both of them and call heapify again for the parent 
        if (arr[i] > arr[parent]) 
        { 
            swap(arr[i], arr[parent]); 
  
            // Recursively heapify the parent node 
            heapifybottomup(parent); 
        }
	}
}

void buildheap()
{
	//Since the last level are lonely node(therefore heap) they are not checked .
	//The index of last non-leaf node
	int startIdx=(n/2)-1;

	//Perform reverse level order traversal from last non-leaf node and heapify each node 
    for (int i = startIdx; i >= 0; i--)
        heapifytopdown(n,i);
}

//Deletes root node
void deleteroot()
{
	int ele=arr[n-1];
	arr[0]=ele;
	n=n-1;
	heapifytopdown(n,0);
}

//Insert an element into the heap
void insert(int x)
{
	n=n+1;
	arr[n-1]=x;
	heapifybottomup(n-1);
}

// To print the heap in the level order traversal
void print()
{
	cout<<"The elements are: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

// main function to do heap sort
void heapSort()
{
    // Build heap (rearrange array)
    buildheap();
    print();
 	//Continuously elements being deleted from the heap in same deletion manner and the root element started being stored from last(in short being swapped)
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapifytopdown(i,0);
    }
}



int main()
{
	print();
	// buildheap();
	// print();
	// deleteroot();
	// print();
	// insert(55);
	// print();
	heapSort();
	print();
	return 0;
}
