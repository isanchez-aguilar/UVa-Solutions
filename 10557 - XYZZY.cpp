/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10557 - XYZZY
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int dist[101];
int energy[101];
bool visited[101];
vector<int> adj[101];

inline bool isPath(int u)
{
	visited[u] = true;

	for(int i = 0; i < adj[u].size(); ++i)
	{
		int v = adj[u][i];

		if(v == n - 1)
			return true;
		if(not visited[v] and isPath(v))
			return true;
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n and n != -1)
	{
		++n;
		for(int u = 1; u < n; ++u)
		{
			int e;
			int rooms;
			adj[u].clear();
			
			cin >> e >> rooms;

			energy[u] = e;
			for(int i = 0; i < rooms; ++i)
			{
				int v;
				cin >> v;
				adj[u].push_back(v);
			}
		}
		
		dist[1] = 100;

		for(int i = 2; i < n; ++i)
			dist[i] = -1e6;


		for(int i = 0; i < n - 2; ++i)
		{
			for(int u = 1; u < n; ++u)
			{
				int size = adj[u].size();
				for(int j = 0; j < adj[u].size(); ++j)
				{
					int v = adj[u][j];
					int d = energy[u];

					if(dist[u] + d > 0)
						dist[v] = max(dist[v], dist[u] + d);
				}
			}
		}

		if(dist[n - 1] > 0)
			cout << "winnable\n";
		else
		{	
			bool possible = false;

			for(int u = 1; u < n and not possible; ++u)
			{
				for(int i = 0; i < adj[u].size(); ++i)
				{
					int v = adj[u][i];
					int d = energy[u];

					if(dist[v] < dist[u] + d and dist[u] + d > 0)
					{
						for(int j = 1; j < n; ++j)
							visited[j] = false;

						if(isPath(u))
						{
							possible = true;
							break;	
						}
					}
				}
			}

			if(possible)
			 	cout << "winnable\n";
			else
			cout << "hopeless\n";
		}
	}

	return 0;
}