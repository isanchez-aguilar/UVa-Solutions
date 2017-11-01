/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1112 - Mice and Maze
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	while(testCases--)
	{
		int n;
		int e;
		int t;
		int m;
		cin >> n >> e >> t >> m;

		vector< pair<int, int> > adj[n + 1];
		for(int i = 0; i < m; ++i)
		{
			int a;
			int b;
			int time;
			cin >> a >> b >> time;

			adj[a].push_back(make_pair(b, time));
		}

		int total = 0;

		for(int i = 1; i <= n; ++i)
		{
			vector<int> d(n + 1, INT_MAX);
			priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > node;
			
			d[i] = 0;
			node.push(make_pair(0, i));
			while(not node.empty())
			{
				int u = node.top().second;
				int dist = node.top().first;
				
				node.pop();

				if(dist > d[u])
					continue;

				int size = adj[u].size();
				for(int i = 0; i < size; ++i)
				{
					pair<int, int> v = adj[u][i];

					if(d[u] + v.second < d[v.first])
					{
						d[v.first] = d[u] + v.second;
						node.push(make_pair(d[v.first], v.first));
					}
				}
			}

			if(d[e] <= t)
				++total;
		}
		cout << total << "\n";
		if(testCases)
			cout << "\n";
	}

	return 0;
}