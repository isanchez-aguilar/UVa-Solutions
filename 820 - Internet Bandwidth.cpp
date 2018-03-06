/*
*	User: Isanchez_Aguilar
*	Problem: UVA 820 - Internet Bandwidth
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int f;
int s;
int t;
vi parent;
int adj[101][101];

void augment(int v, int minEdge)
{
	if (s == v)
	{
		f = minEdge;
		return;
	}
	else if (parent[v])
	{
		augment(parent[v], min(minEdge, adj[parent[v]][v]));
		adj[parent[v]][v] -= f;
		adj[v][parent[v]] += f;
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int testCase = 0;

	while (cin >> n and n)
	{
		int m;

		cin >> s >> t >> m;
		memset(adj, 0, sizeof adj);

		for (int i = 0; i < m; ++i)
		{
			int u;
			int v;
			int c;
			cin >> u >> v >> c;

			adj[u][v] += c;
			adj[v][u] += c;
		}

		int mf = 0;
		while (true)
		{
			f = 0;
			queue<int> node;
			vi dist(n + 1, INF);
			
			dist[s] = 0;
			node.push(s);
			parent.assign(n + 1, 0);

			while (not node.empty())
			{
				int u = node.front();
				node.pop();

				if (u == t)
					break;

				for (int v = 1; v <= n; ++v)
				{
					if (adj[u][v] > 0 and dist[v] == INF)
					{
						node.push(v);
						parent[v] = u;
						dist[v] = dist[u] + 1;
					}
				}
			}

			augment(t, INF);

			if (not f)
				break;

			mf += f;
		}

		cout << "Network " << ++testCase << "\n"; 
		cout << "The bandwidth is " << mf << ".\n\n";
	}
}