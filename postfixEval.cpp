//Evaluation of Postfix
#include <bits/stdc++.h>
using namespace std;

int op2, op1;
int main()
{
	string s;
	stack<char> pf;
	cout << "Enter a string to be evaluated:" << endl;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != '/' && s[i] != '*' && s[i] != '+' && s[i] != '-')
			pf.push(s[i] - '0');
		else
		{
			op2 = pf.top();
			pf.pop();
			op1 = pf.top();
			pf.pop();
			switch (s[i])
			{

			case '+':
				pf.push(op1 + op2);
				break;
			case '-':
				pf.push(op1 - op2);
				break;
			case '*':
				pf.push(op1 * op2);
				break;
			case '/':
				pf.push(op1 / op2);
				break;
			}
		}
	}
	int res = pf.top();
	cout << res << endl;
	return 0;
}