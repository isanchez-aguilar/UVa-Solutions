/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10449 - Traffic
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
#define source first.first;
#define destination first.second;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;
	while(cin >> n)
	{
		long long dist[n + 1];
		int busyness[n + 1];

		for(int i = 1; i <= n; ++i)
		{
			dist[i] = INT_MAX;
			cin >> busyness[i];
		}

		int junctions;

		cin >> junctions;
		vector<iii> adj(junctions);

		for(int i = 0; i < junctions; ++i)
		{
			int u;
			int v;
			cin >> u >> v;
			adj[i] = iii(ii(u,v), pow(busyness[v] - busyness[u], 3));
		}

		dist[1] = 0;
		for(int i = 0; i < n - 1; ++i)
		{
			for(int j = 0; j < junctions; ++j)
			{
				int u = adj[j].source;
				int v = adj[j].destination;
				int d = adj[j].second;
				
				if(dist[u] != INT_MAX and dist[u] + d < dist[v])
					dist[v] = dist[u] + d;
			}
		}

		for(int i = 0; i < junctions; ++i)
		{
			int u = adj[i].source;
			int v = adj[i].destination;
			int d = adj[i].second;
			
			if(dist[u] != INT_MAX and dist[u] + d < dist[v])
				dist[v] = -INT_MIN;
		}

		int queries;
		cin >> queries;

		cout << "Set #" << ++t << "\n"; 
		while(queries--)
		{
			int goal;
			cin >> goal;
			if(dist[goal] < 3 or dist[goal] == INT_MAX)
				cout << "?\n";
			else
				cout << dist[goal] << "\n";
		}
	}

	return 0;
}