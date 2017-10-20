/*
*	User: Isanchez_Aguilar
*	Problem: UVA 796 - Critical Links
*/
#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

int counter;
vector<int> *adj;
vector<int> parent;
vector<int> dfs_low;
vector<int> dfs_num;
priority_queue< pair<int, int> > criticalLinks;

inline void findBridges(int u)
{
	dfs_low[u] = counter;
	dfs_num[u] = counter++;
	int size = adj[u].size();

	for(int i = 0; i < size; ++i)
	{
		int v = adj[u][i];

		if(dfs_num[v] == UNVISITED)
		{
			parent[v] = u;
			findBridges(v);

			if(dfs_low[v] > dfs_num[u])
			{
				int a = min(u, v);
				int b = max(u, v);
				criticalLinks.push(make_pair(-a, -b));
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n)
	{
		parent.assign(n, 0);
		dfs_low.assign(n, UNVISITED);
		dfs_num.assign(n, UNVISITED);
		adj = new vector<int>[n];

		for(int i = 0; i < n; ++i)
		{
			int a;
			int m;
			char brace;
			cin >> a >> brace >> m >> brace;

			for(int j = 0; j < m; ++j)
			{
				int b;
				cin >> b;
				adj[a].push_back(b);
			}
		}

		counter = 0;
		for(int i = 0; i < n; ++i)
		{
			if(dfs_num[i] == UNVISITED)
				findBridges(i);
		}

		cout << criticalLinks.size() << " critical links\n";
		while(not criticalLinks.empty())
		{
			pair<int, int> e = criticalLinks.top();
			criticalLinks.pop();

			cout << -e.first << " - " << -e.second << "\n"; 
		}
		cout << "\n";
	}

	return 0;
}