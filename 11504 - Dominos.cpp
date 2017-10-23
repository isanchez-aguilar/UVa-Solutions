/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11504 - Dominos
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> order;
vector<bool> visited;
vector< vector<int> > adj;

inline void topologicalSort(int u)
{
	visited[u] = true;
	int size = adj[u].size();
	
	for(int i = 0; i < size; ++i)
	{
		int v = adj[u][i];
		if(not visited[v])
			topologicalSort(v);
		
	}
		
	order.push_back(u);
	
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCases;
	cin >> testCases;
	
	while(testCases--)
	{
		int n;
		int m;
		cin >> n >> m;
		
		adj = vector< vector<int> >(n + 1);
		
		for(int i = 0; i < m; ++i)
		{
			int x;
			int y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		
		order.clear();
		visited.assign(n + 1, false);
		
		for(int i = 1; i <= n; ++i)
		{
			if(not visited[i])
				topologicalSort(i);
		}

		visited.assign(n + 1, false);
		int stronglyConnectedComponents = 0;
		
		int i = n;
		while(i--)
		{
			int u = order[i];
			if(not visited[u])
			{	
				topologicalSort(u);
				++stronglyConnectedComponents;
			}
		}
		
		cout << stronglyConnectedComponents << "\n";
	}
	
	return 0;
}
