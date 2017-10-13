/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10305 - Ordering Tasks
*/
#include <bits/stdc++.h>

using namespace std;

int n;
bool visited[101];
bool adj[101][101];

void topologicalSort(int length)
{
	if(n == length)
	{
		cout << "\n";
		return;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(not visited[i])
		{
			bool mostImportant = true;

			for(int j = 1; j <= n; ++j)
			{
				if(not visited[j] and adj[j][i])
				{
					mostImportant = false;
					break;
				}
			}

			if(mostImportant)
			{
				visited[i] = true;
				cout << (length?" ":"") << i;
				topologicalSort(length + 1);
				visited[i] = false;

				return;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	while(cin >> n >> m and (n or m))
	{
		memset(adj, false, sizeof adj);
		fill(visited, visited + 101, false);

		for(int i = 0; i < m; ++i)
		{
			int a;
			int b;
			cin >> a >> b;
			adj[a][b] = true;
		}

		topologicalSort(0);
	}

	return 0;
}