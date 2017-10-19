/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11396 - Claw Decomposition
*/
#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int V;
	while(cin >> V and V)
	{
		int a;
		int b;
		vector<int> adj[++V];

		while(cin >> a >> b and a)
		{
			adj[a].push_back(b);		
			adj[b].push_back(a);		
		}

		queue<int> node;
		node.push(1);
		bool isBipartite = true;
		vector<int> colour(V, UNVISITED);
		
		colour[1] = 0;
		while(not node.empty())
		{
			int u = node.front();

			node.pop();
			int size = adj[u].size();

			for(int i = 0; i < size; ++i)
			{
				int v = adj[u][i];
				if(colour[v] == UNVISITED)
				{
					colour[v] = 1 - colour[u];
					node.push(v);
				}
				else if(colour[v] == colour[u])
				{
					isBipartite = false;
					break;
				}
			}
		}

		if(isBipartite)
			cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}