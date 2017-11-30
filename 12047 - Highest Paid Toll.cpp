/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12047 - Highest Paid Toll
*/
#include <bits/stdc++.h>

#define MAX 1e6

using namespace std;

typedef pair<int, int> ii;

int n;
int p;

inline int dijkstra(vector<ii> adj[], vector<int>& dist, int s, int t)
{
	priority_queue< ii, vector<ii>, greater<ii> > node;

	dist[s] = 0;
	node.push(ii(0, s));

	while(not node.empty())
	{
		int u = node.top().second;
		int d = node.top().first;

		node.pop();
		if(dist[u] < d)
			continue;
		for(int i = 0; i < adj[u].size(); ++i)
		{
			ii v = adj[u][i];
			if(dist[u] + v.second < p and dist[u] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u] + v.second;
				node.push(ii(dist[v.first], v.first));
			}
		}
	}

	return dist[t];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int m;
		int s;
		int t;
		cin >> n >> m >> s >> t >> p;

		++n;
		vector<ii> adj1[n];
		vector<ii> adj2[n];

		for(int i = 0; i < m; ++i)
		{
			int u;
			int v;
			int c;
			cin >> u >> v >> c;

			adj1[u].push_back(make_pair(v, c));
			adj2[v].push_back(make_pair(u, c));
		}

		int maxP = -1;
		vector<int> d1(n, MAX);
		vector<int> d2(n, MAX);

		dijkstra(adj1, d1, s, t);
		dijkstra(adj2, d2, t, s);
		
		for(int u = 1; u < n; ++u)
		{
			for(int i = 0; i < adj1[u].size(); ++i)
			{
				ii v = adj1[u][i];

				if(d1[u] + v.second + d2[v.first] <= p)
					maxP = max(maxP, v.second);	
			}
		}

		cout << maxP << "\n";
	}

	return 0;
}