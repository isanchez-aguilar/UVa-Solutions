/*
*	User: Isanchez_Aguilar
*	Problem: UVA 599 - The Forrest for the Trees
*/
#include <bits/stdc++.h>

using namespace std;

bool isTree;
int neighbors;
bitset<26> visited;
vector< bitset<26> > adj(26);

inline void searchPath(int j, int previousJ)
{
	visited[j] = 1;

	if(!isTree)
		return;

	++neighbors;
	
	for(int i = 0; i < 26; ++i)
	{
		if(adj[j][i] && i != previousJ)
		{
			// Check If It is a cycle.
			if(visited[i])
				isTree = 0;
			else
				searchPath(i, j);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	while(testCases--)
	{
		string s;

		visited.reset();
		for(int i = 0; i < 26; ++i)
			adj[i].reset();

		while(cin >> s && s[0] != '*')
		{
			adj[s[1] - 'A'][s[3] - 'A'] = 1;
			adj[s[3] - 'A'][s[1] - 'A'] = 1;
		}

		cin >> s;

		int trees = 0;
		int acorns = 0;
		int length = s.length();
		
		for(int i = 0; i < length; i += 2)
		{
			int j = s[i] - 'A';

			if(visited[j])
				continue;

			isTree = 1;
			neighbors = 0;
			searchPath(j, -1);

			if(neighbors == 1)
				++acorns;
			else if(isTree)
				++trees;
		}

		cout << "There are " << trees << " tree(s) and " << acorns <<" acorn(s).\n";
	}

	return 0;
}