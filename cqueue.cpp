//Circular Queue using Array
#include <bits/stdc++.h>
using namespace std;

int main()
{

	return 0;
}

void insert(int x)
{
	if ((f == 0 && r == size - 1) || r + 1 == f)
		cout << "Overflow" << endl;
	else if (r == -1)
	{
		f = r = 0;
		a[r] = x;
	}
	else
	{
		r = (r + 1) % size;
		a[r] = x;
	}
}
int delete ()
{
	int ele;
	if (f == -1)
	{
		cout << "Underflow" << endl;
		return;
	}
	else if (f == r)
	{
		ele = a[f];
		f = r = 0;
	}
	else
	{
		ele = a[f];
		f = (f + 1) % size;
	}
	return ele;
}