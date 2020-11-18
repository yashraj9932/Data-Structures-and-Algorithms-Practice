#include<bits/stdc++.h>
using namespace std;

int prec(char ch)
{
	switch(ch)
	{
		case '-':
		case '+':
		return 1;
		case '*':
		case '/':
		return 2;
		case '^':
		return 3;
	}
	return -1;
}
int main()
{
	cout<<"Enter the infix string"<<endl;
	string s; cin>>s;
	string res;
	stack<char> st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
			res+=s[i];
		else if(s[i]=='(')
			st.push(s[i]);
		else if(s[i]==')')
		{
			while(st.top()!='(')
			{
				res+=st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while(!st.empty() && prec(s[i])<=prec(st.top()))
			{
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty())
	{
		res+=st.top();
		st.pop();
	}
	cout<<res<<endl;
	return 0;
}