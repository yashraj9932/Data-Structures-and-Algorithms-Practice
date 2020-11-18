#include <bits/stdc++.h>
using namespace std;

bool checker(string s)
{
	stack<char> b;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='['||s[i]=='{'||s[i]=='(')
			b.push(s[i]);
		else if(s[i]==']'||s[i]=='}'||s[i]==')')
		{
			if(b.empty())
				return false;
			if(s[i]==']' && b.top()!='[')
				return false;
			if(s[i]=='}' && b.top()!='{')
				return false;
			if(s[i]==')' && b.top()!='(')
				return false;
			else
				b.pop();
		}	
	}
	return b.empty();
}

int main()
{
	cout<<"Enter a string: ";
	string s; cin>>s;
	if(checker(s))
		cout<<"True";
	else
		cout<<"False";
	cout<<endl;
	return 0;
}
