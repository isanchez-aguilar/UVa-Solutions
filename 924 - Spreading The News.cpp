/*
*	User: Isanchez_Aguilar
*	Problem: UVA 924 - Spreading The News
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int e;
	while(cin >> e)
	{
		vector<int> adj[e];

		for(int i = 0; i < e; ++i)
		{
			int n;
			cin >> n;

			adj[i].resize(n);
			
			for(int j = 0; j < n; ++j)
				cin >> adj[i][j];
		}

		int testCases;
		cin >> testCases;

		for(int i = 0; i < testCases; ++i)
		{
			int s;
			cin >> s;

			if(adj[s].size())
			{	
				queue<int> node;
				
				node.push(s);
				int maxLevel = 0;
				map<int, int> boom;
				vector<int> level(e, INT_MAX);
				
				boom[0] = 1;
				level[s] = 0;

				while(not node.empty())
				{
					int u = node.front();
					
					node.pop();
					int size = adj[u].size();

					for(int i = 0; i < size; ++i)
					{
						int v = adj[u][i];
						
						if(level[v] == INT_MAX)
						{
							level[v] = level[u] + 1;
							
							node.push(v);
							++boom[level[v]];
						}
					}
				}

				int day;
				int maxBoom = -1;
				for(map<int, int>::iterator i = ++boom.begin(); i != boom.end(); ++i)
				{
					if(maxBoom < i->second)
					{
						day = i->first;
						maxBoom = i->second;
					}
				}

				cout << maxBoom << " " << day << "\n";
			}
			else
				cout << "0\n";
		}
	}

	return 0;
} 