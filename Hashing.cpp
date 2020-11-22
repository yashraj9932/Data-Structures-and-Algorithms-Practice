/*
Types of hashing:
1.Division method:
h(k)=k%n
A disadvantage of the division method id that consecutive keys map to consecutive hash values in the hash table. This leads to a poor performance.
2.Folding method
by taking sum of digits and storing that in that paericular index(sum).
3.Mid-square Method:
The mid square method is a very good hash function.
It involves squaring the value of the key and then extracting the middle r digits as the hash value.
The value of r can be decided according to the size of the hash table.
Suppose the hash table has 100 memory locations.
So r=2 because two digits are required to map the key to memory location.
k = 50  k*k = 2500  h(50) = 50

The hash value obtained is 50

4.Multiplication Method:
h(k) = floor( n( kA mod 1 ) )
Here, k is the key and A can be any constant value between 0 and 1. 
Both k and A are multiplied and their fractional part is separated. 
This is then multiplied with n to get the hash value.

k=123 n=100 A=0.618033
h(123) = 100 (123 * 0.618033 mod 1)
= 100 (76.018059 mod 1) = 100 (0.018059) = 1
The hash value obtained is 1

An advantage of the multiplication method is that it can work with any value of A,
although some values are believed to be better than others.
*/
/*
Collision Problems may occur:
Techniques to help:
1.Linear Probing:
Linear probing

It is a strategy for resolving collisions.
In this the new key is placed in the closest following empty cell.
Advantage - It is faster due to locality of reference.
Disadvantage - It needs a five-way independence in the hash function.

2.Open Chaining:
Advantages:
1) Simple to implement.
2) Hash table never fills up, we can always add more elements to the chain.
3) Less sensitive to the hash function or load factors.
4) It is mostly used when it is unknown how many and how frequently keys may be inserted or deleted.

Disadvantages:
1) Cache performance of chaining is not good as keys are stored using a linked list. Open addressing provides better cache performance as everything is stored in the same table.
2) Wastage of Space (Some Parts of hash table are never used)
3) If the chain becomes long, then search time can become O(n) in the worst case.
4) Uses extra space for links.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{

	return 0;
}