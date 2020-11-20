//Parenthesis Checker that checks if the brackets match correctly.
#include <bits/stdc++.h>
using namespace std;

bool checker(string s)
{
	stack<char> b;
	for (int i = 0; i < s.length(); i++)
	{
		//If its an opening bracket,pushed to stack.
		if (s[i] == '[' || s[i] == '{' || s[i] == '(')
			b.push(s[i]);
		else if (s[i] == ']' || s[i] == '}' || s[i] == ')')
		{
			//If no closing bracket,false returned.
			if (b.empty())
				return false;
			//If brackets falsely matched,false returned.
			if (s[i] == ']' && b.top() != '[')
				return false;
			if (s[i] == '}' && b.top() != '{')
				return false;
			if (s[i] == ')' && b.top() != '(')
				return false;
			//If all ok,exexution continued.
			else
				b.pop();
		}
	}
	//If the stack is empty,returns true indicating all brackets matched correctly.
	return b.empty();
}

int main()
{
	cout << "Enter a string: ";
	string s;
	cin >> s;
	if (checker(s))
		cout << "True";
	else
		cout << "False";
	cout << endl;
	return 0;
}
