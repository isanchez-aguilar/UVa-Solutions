/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11838 - Come and Go
*/
#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

int scc;
int counter;
vector<int> dfs_low;
vector<int> dfs_num;
vector< vector<int> > adj;

inline void findStronglyConnectedComponents(int u)
{
	dfs_low[u] = counter;
	dfs_num[u] = counter++;
	int size = adj[u].size();

	for(int i = 0; i < size; ++i)
	{
		int v = adj[u][i];
		
		if(dfs_num[v] == UNVISITED)
			findStronglyConnectedComponents(v);
		
		if(dfs_num[v] != UNVISITED)
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_num[u] == dfs_low[u])
		++scc;

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;
	while(cin >> n >> m and (n or m))
	{
		adj.assign(n + 1, vector<int>());

		for(int i = 0; i < m; ++i)
		{
			int a;
			int b;
			int ways;
			cin >> a >> b >> ways;

			adj[a].push_back(b);
			if(ways == 2)
				adj[b].push_back(a);
		}

		scc = 0;
		counter = 1;
		dfs_low.assign(n + 1, UNVISITED);
		dfs_num.assign(n + 1, UNVISITED);

		findStronglyConnectedComponents(1);

		for(int i = 2; i <= n; ++i)
		{
			if(dfs_num[i] == UNVISITED)
			{
				scc = 0;
				break;
			}
		}
	
		if(scc == 1)
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}
