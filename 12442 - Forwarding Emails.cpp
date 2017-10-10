/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12442 - Forwarding Emails
*/
#include <bits/stdc++.h>

using namespace std;

int adj[50001];
int memo[50001];
bool visited[50001];

inline int dfs(int u)
{
	int length = 0;
	visited[u] = true;
	
	if(adj[u] and not visited[adj[u]])
		length += dfs(adj[u]) + 1;

	visited[u] = false;

	return memo[u] = length;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		int martians;
		cin >> martians;

		fill(adj, adj + martians + 1, 0);
		fill(memo, memo + martians + 1, -1);
		
		for(int i = 0; i < martians; ++i)
		{
			int u;
			int v;
			cin >> u >> v;

			adj[u] = v;
		}

		int index = 0;
		int longest = 0;

		for(int u = 1; u <= martians; ++u)
		{
			if(memo[u] == -1)
				dfs(u);

			if(longest < memo[u])
			{
				index = u;
				longest = memo[u];
			}
		}

		cout << "Case " << t << ": " << index << "\n";
	}

	return 0;
}