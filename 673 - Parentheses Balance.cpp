/*
*	User: Isanchez_Aguilar
*	Problem: UVA 673 - Parentheses Balance
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	cin.ignore();
	while(testCases--)
	{
		string s;
		getline(cin, s);

		stack<char> order;
		bool possible = true;
		int length = s.length();

		for(int i = 0; i < length; ++i)
		{
			if(s[i] == ')')
			{
				if(not order.empty() and order.top() == '(')
				{
					order.pop();
					continue;
				}
				possible = false;
				break;
			}
			else if(s[i] == ']')
			{
				if(not order.empty() and order.top() == '[')
				{
					order.pop();
					continue;
				}
				possible = false;
				break;	
			}
			else
				order.push(s[i]);
		}

		if(possible and order.empty())
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}