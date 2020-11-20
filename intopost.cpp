//Infix to Postfix 
#include <bits/stdc++.h>
using namespace std;

int prec(char ch)
{
	switch (ch)
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
	cout << "Enter the infix string" << endl;
	string s;
	cin >> s;
	string res;
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')//Checks if its a digit
			res += s[i];
		else if (s[i] == '(')//Checks and pushes an opening bracket into stack
			st.push(s[i]);
		else if (s[i] == ')')//Checks for closing bracket
		{
			while (st.top() != '(')//Pops things till it gets an opening bracket
			{
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		/*If neither of above,then its probably an operand,so pops till the list is empty
 		or till its precedence is less than the current element  on top of stack,whichever
 		comes first,Pop all the operators from the stack which are greater than or equal to 
 		in precedence than that of the scanned operator.*/
		else
		{
			while (!st.empty() && prec(s[i]) <= prec(st.top()))
			{
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	//If any elements are still left in stack then its added to the result in the required order.
	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}
	cout << res << endl;
	return 0;
}