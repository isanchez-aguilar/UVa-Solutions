/*
*	User: Isanchez_Aguilar
*	Problem: UVA 124 - Following Orders
*/
#include <bits/stdc++.h>

using namespace std;

bool adj[27][27];
bool available[27];

inline void printSolution(string s, int length)
{
	if (not length)
	{
		cout << s << "\n";
		return;
	}

	for (int i = 0; i < 27; ++i)
	{
		if (available[i])
		{
			bool smallest = true;

			for (int j = 0; j < 27; ++j)
			{
				if (available[j] and adj[j][i])
				{
					smallest = false;
					break;
				}
			}

			if (smallest)
			{
				available[i] = false;

				printSolution(s + (char)('a' + i), length - 1);

				available[i] = true;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string variables;
	int testCases = 0;
	
	while (getline(cin, variables))
	{
		char a;
		int length = 0;
		stringstream in(variables);

		memset(adj, false, sizeof(adj));
		fill(available, available + 27, false);
		
		while (in >> a)
		{
			++length;
			available[a - 'a'] = true;
		}
		
		char b;
		string constraints;
		getline(cin, constraints);
		
		in.clear();
		in.str(constraints);

		while (in >> a >> b)
			adj[a - 'a'][b - 'a'] = true;

		if (testCases++)
			cout << "\n";

		printSolution("", length);
	}

	return 0;
}