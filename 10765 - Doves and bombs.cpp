/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10765 - Doves and bombs
*/
#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

int root;
int counter;
int childNodes;
vector<int> parent;
vector<int> dfs_low;
vector<int> dfs_num;
vector< vector<int> > adj;
vector<int> articulationPoints;


inline void findArticulationPoint(int u)
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

			if(u == root)
				++childNodes;
		
			findArticulationPoint(v);

			if(dfs_low[v] >= dfs_num[u])
				++articulationPoints[u];

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
	int m;
	while(cin >> n >> m and (n or m))
	{
		int x;
		int y;

		parent.assign(n, UNVISITED);
		adj.assign(n, vector<int>());
		dfs_low.assign(n, UNVISITED);
		dfs_num.assign(n, UNVISITED);
		articulationPoints.assign(n, 0);
		
		while(cin >> x >> y and x != -1)
		{
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		counter = 0;
		for(int i = 0; i < n; ++i)
		{
			if(dfs_num[i] == UNVISITED)
			{
				root = i;
				childNodes = 0;
				findArticulationPoint(i);
				articulationPoints[i] = (childNodes > 1);
			}
		}

		multimap<int, int> bombs;

		for(int i = 0; i < n; ++i)
		{
			++articulationPoints[i];
			bombs.insert(make_pair(-articulationPoints[i], i));
		} 

		int j = 0;
		for(multimap<int, int>::iterator i = bombs.begin(); i != bombs.end() and j < m; ++i, ++j)
			cout << i->second << " " << -i->first << "\n";

		cout << "\n";
	}

	return 0;
}