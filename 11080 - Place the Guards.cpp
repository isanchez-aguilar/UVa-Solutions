/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11080 - Place the Guards
*/
#include <bits/stdc++.h>

#define UNVISITED -1

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int V;
		int e;

		cin >> V >> e;
		vector<int> adj[V];

		for(int i = 0; i < e; ++i)
		{
			int a;
			int b;
			cin >> a >> b;
		
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int guards = 0;
		queue<int> currentNode;
		vector<int> colour(V, UNVISITED);
		
		for(int k = 0; k < V; ++k)
		{
			if(colour[k] == UNVISITED)
			{
				vector<int> frequenceColour(2, 0);
				
				colour[k] = 0;
				currentNode.push(k);
				++frequenceColour[0];
				bool isBipartite = true;

				while(not currentNode.empty())
				{
					int u = currentNode.front();
					int size = adj[u].size();
					currentNode.pop();

					for(int i = 0; i < size; ++i)
					{
						int v = adj[u][i];

						if(colour[v] == UNVISITED)
						{
							currentNode.push(v);
							colour[v] = 1 - colour[u];
							++frequenceColour[colour[v]];
						}
						else if(colour[v] == colour[u])
						{
							isBipartite = false;
							break;
						}
					}
				}

				if(isBipartite)
				{
					if(frequenceColour[0] and frequenceColour[1])
						guards += min(frequenceColour[0], frequenceColour[1]);
					else
						guards += max(frequenceColour[0], frequenceColour[1]);
				}
				else
				{
					guards = -1;
					break;
				}
			}
		}	

		cout << guards << "\n";
	}

	return 0;
}