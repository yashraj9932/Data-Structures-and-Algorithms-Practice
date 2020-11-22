//In BFS,we explore a node then visit all the vertex and then explore om on,in DFS we explore one neighbour then explore its neighboour one by one.
//For BFS we take a queue
//For DFS,we take a stack
//A spanning tree is a tree having all vertices of a graph but only n-1 edges ,the number of possibilities in nCr form is eCv-1
//Now if the graph is weighted then the graph with minimum total weight from spanning tree is minimum spanning tree.
//Now taking all trees and then checking each ka total weight and then comparing is a lenghty process.
//SO we have greedy methods like prims and kruskals
/*
Prims Algo
Always selected the minimum cost edge connected to the initial edge
For non connected graphs we dont find spanning treees since its not possible.
*/
/*
Kruskal Algo
Always take the minimum cost edge (no restrictions of connection to initial edge.)
Rule though:If any edge forming cycle then do not include that edge in the minimum spanning tree.
Complexity:O(vertices*Edges)(it can be improved though ,since e time is taken to find min edge,
if we store edges in min heap we will get min edge in logn time.so new complexity will become O(nlogn))
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{

	return 0;
}