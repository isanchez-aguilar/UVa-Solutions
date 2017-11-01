/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10986 - Sending email
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int T = 1; T <= testCases; ++T)
	{
		int m;
		int n;
		int s;
		int t;
		cin >> n >> m >> s >> t;

		vector< pair<int, int> > adj[n];

		for(int i = 0; i < m; ++i)
		{
			int a;
			int b;
			int c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}

		int d[n];
		for(int i = 0; i < n; ++i)
			d[i] = INT_MAX;
		
		priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > node;

		d[s] = 0;
		node.push(make_pair(0, s));

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

				if(dist + v.second < d[v.first])
				{
					d[v.first] = dist + v.second;
					node.push(make_pair(d[v.first], v.first));
				}
			}
		}

		cout << "Case #" << T << ": ";

		if(d[t] != INT_MAX)
			cout << d[t] << "\n";
		else
			cout << "unreachable\n";
	}

	return 0;
}