/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10801 - Lift Hopping
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int k;
	int time[5];
	int floor[101];
	vector<ii> adj[100];

	while(cin >> n >> k)
	{
		for(int i = 0; i < n; ++i)
			cin >> time[i];

		string line;
		cin.ignore();

		for(int i = 0; i < n; ++i)
		{
			getline(cin, line);
			
			int size = 0;
			stringstream in(line);

			while(in >> floor[size++]);
			--size;

			for(int k = 0; k < size; ++k)
			{	
				for(int l = k + 1; l < size; ++l)
				{
					adj[floor[k]].push_back(make_pair(floor[l], (floor[l] - floor[k]) * time[i]));
					adj[floor[l]].push_back(make_pair(floor[k], (floor[l] - floor[k]) * time[i]));
				}
			}
		}

		vector<int> dist(100, INT_MAX);
		priority_queue< ii, vector<ii>, greater<ii> > pq;

		dist[0] = 0;
		pq.push(make_pair(0, 0));
		
		while(not pq.empty())
		{
			int d = pq.top().first;
			int u = pq.top().second;
			
			pq.pop();
			
			if(u == k)
				break;

			if(d > dist[u])
				continue;

			for(int i = 0; i < adj[u].size(); ++i)
			{
				int v = adj[u][i].first;
				int time = adj[u][i].second;

				if(dist[u] + time + 60 < dist[v])
				{
					dist[v] = dist[u] + time + 60;
					pq.push(make_pair(dist[v], v));
				}
			}
		}
		
		if(dist[k] == INT_MAX)
			cout << "IMPOSSIBLE\n";
		else
			cout << (k?dist[k] - 60:dist[k]) << "\n";

		for(int i = 0; i < 100; ++i)
			adj[i].clear();
	}

	return 0;
}