/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10505 - Montesco vs Capuleto
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int n;
		cin >> n;
		vector<vi> adj(n);
		for (int u = 0; u < n; ++u)
		{
			int m;
			cin >> m;
			
			for (int j = 0; j < m; ++j)
			{
				int v;
				cin >> v;
			
				if (--v < n)
				{
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
			}
		}

		vi colour(n, -1);
		bool isBipartite;
		int maxPeople = 0;

		for (int s = 0; s < n; ++s)
		{
			if (colour[s] == -1)
			{
				queue<int> node;
				isBipartite = true;
				vi colourFrequency(2, 0);
				
				node.push(s);
				colour[s] = 0;		
				++colourFrequency[0];
			
				while (not node.empty())
				{
					int u = node.front();
					node.pop();

					for (int j = 0; j < adj[u].size(); ++j)
					{
						int v = adj[u][j];

						if (colour[v] == -1)
						{
							node.push(v);
							colour[v] = 1 - colour[u];
							++colourFrequency[colour[v]];
						}
						else if (colour[u] == colour[v])
						{
							isBipartite = false;
							
						}
					}
				}

				if (isBipartite)
					maxPeople += max(colourFrequency[0], colourFrequency[1]);
			}
		}
		cout << maxPeople << "\n";
	}

	return 0;
}