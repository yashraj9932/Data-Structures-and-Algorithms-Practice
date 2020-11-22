//If any node gets disbalanced due to the node added in left child of its left child it is called LL Imbalance and LL rotation(rotation clockwise) is done on the disbalanced node.
//If any node gets disbalanced due to the node added in right child of its left child it is called LR Imbalance and LR rotation is done.(which is right rotation (anticlockeise of the left child) and then Left is performed on the disbalanced node. )
//The above RL is a two step rotation of first rotating the child node  andd then the main .This can be done directly.
//send the left ka right to the root(disabled node ) and the original root to this naya wala root ka right. This is shortcut.
//The first ancestor that became imbalanced after insertion,rotation is to be done on that(if multiple nodes are imbalanced).
//Suppose the imbalance took because of right child ka left ka left ke kaaran,still you need to take RL rotation and not RLL.(only the first two letters)
//Insert,balnce,repeat ,dont wait for insertion of all elements
//If you want,read about red-black tree 
#include <iostream>
using namespace std;

int main()
{

	return 0;
}