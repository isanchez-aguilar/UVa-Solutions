/*
*	User: Isanchez_Aguilar
*	Problem: UVA 247 - Calling Circles
*/
#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

int counter;
vector<int> dfs_low;
vector<int> dfs_num;
vector<bool> visited;
vector<int> component;
vector< vector<int> > adj;
map<string, int> indexName;
map<int, string> nameIndex;

inline void findStronglyConnectedComponents(int u)
{
	visited[u] = true;
	dfs_low[u] = counter;
	dfs_num[u] = counter++;
	component.push_back(u);
	int size = adj[u].size();

	for(int i = 0; i < size; ++i)
	{
		int v = adj[u][i];

		if(dfs_num[v] == UNVISITED)
			findStronglyConnectedComponents(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	
	if(dfs_num[u] == dfs_low[u])
	{
		while(component.size() > 0)
		{
			int v = component.back();

			visited[v] = false;
			component.pop_back();
			
			cout << nameIndex[v] << (v == u?"\n":", ");
			if(u == v)
				break;
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;
	int t = 0;

	while(cin >> n >> m and (n or m))
	{
		int index = 0;
		indexName.clear();
		nameIndex.clear();
		adj.assign(n, vector<int>());

		for(int i = 0; i < m; ++i)
		{
			string a;
			string b;
			cin >> a >> b;
			
			int u;
			int v;

			if(indexName.count(a) > 0)
				u = indexName[a];
			else
			{
				u = index;
				nameIndex[index] = a;
				indexName[a] = index++;
			}

			if(indexName.count(b) > 0)
				v = indexName[b];
			else
			{
				v = index;
				nameIndex[index] = b;
				indexName[b] = index++;				
			}

			adj[u].push_back(v);
		}

		counter = 0;
		visited.assign(n, false);
		dfs_low.assign(n, UNVISITED);
		dfs_num.assign(n, UNVISITED);
		
		if(t++)
			cout << "\n";
		cout << "Calling circles for data set " << t << ":\n";
		
		for(int i = 0; i < n; ++i)
		{
			if(dfs_num[i] == UNVISITED)
				findStronglyConnectedComponents(i);
		}
	}

	return 0;
}