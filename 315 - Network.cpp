/*
*	User: Isanchez_Aguilar
*	Problem: UVA 315 - Network
*/
#include <bits/stdc++.h>

#define MAX 101
#define UNVISITED -1

using namespace std;

int n;
int root;
int counter;
int childNodes;
int parent[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
vector<int> adj[MAX];
bitset<MAX> articulationPoint;

inline void findArticulationPoints(int u)
{
	dfs_num[u] = counter++;
	dfs_low[u] = dfs_num[u];
	int size = adj[u].size();

	for(int i = 0; i < size; ++i)
	{
		int v = adj[u][i];

		if(dfs_num[v] == UNVISITED)
		{
			parent[v] = u;
			
			if(root == u)
				++childNodes;

			findArticulationPoints(v);

			if(dfs_low[v] >= dfs_num[u])
				articulationPoint[u] = true;

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

	while(cin >> n and n)
	{
		cin.ignore();
		articulationPoint.reset();
		fill(adj, adj + MAX, vector<int>(0));
		fill(dfs_num, dfs_num + MAX, UNVISITED);
		
		string s;
		while(getline(cin, s) and s != "0")
		{
			int u;
			int v;
			stringstream in(s);
			
			in >> u;
			while(in >> v)
			{
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		counter = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(dfs_num[i] == UNVISITED)
			{
				root = i;
				childNodes = 0;
				findArticulationPoints(i);
				articulationPoint[i] = (childNodes > 1);
			}
		}

		cout << articulationPoint.count() << "\n";
	}

	return 0;
}