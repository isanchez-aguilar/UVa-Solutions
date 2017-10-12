/*
*	User: Isanchez_Aguilar
*	Problem: UVA 872 - Ordering
*/
#include <bits/stdc++.h>

using namespace std;

bool impossible;
bool adj[27][27];
bool available[27];

inline void printSolution(string s, int length)
{
	if(not length)
	{
		cout << s << "\n";
		impossible = false;

		return;
	}

	for(int i = 0; i < 27; ++i)
	{
		if(available[i])
		{
			bool smallest = true;

			for(int j = 0; j < 27; ++j)
			{
				if(available[j] and adj[j][i])
				{
					smallest = false;
					break;
				}
			}

			if(smallest)
			{
				available[i] = false;

				printSolution(s + (s.empty()?"":" ") + (char)('A' + i), length - 1);

				available[i] = true;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	

	cin.ignore();
	while(testCases--)
	{
		cin.ignore();
		int length = 0;
		string variables;
		memset(adj, false, sizeof(adj));
		fill(available, available + 27, false);
		
		getline(cin, variables);
		stringstream in(variables);
		
		char a;
		while(in >> a)
		{
			++length;
			available[a - 'A'] = true;
		}
		
		string constraints;
		getline(cin, constraints);
		
		in.clear();
		in.str(constraints);

		while(in >> a)
		{
			char b;
			in >> b >> b;
			adj[a - 'A'][b - 'A'] = true;
		}

		impossible = true;

		printSolution("", length);

		if(impossible)
			cout << "NO\n";

		if(testCases)
			cout << "\n";
	}

	return 0;
}