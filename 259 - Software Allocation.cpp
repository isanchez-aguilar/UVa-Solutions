/*
*	User: Isanchez_Aguilar
*	Problem: UVA 259 - Software Allocation
*/
#include <bits/stdc++.h>

#define MAX 1e9

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int f;
vi parent;
int adj[38][38];

void augment(int v, int minEdge)
{
	if (v == 0)
	{
		f = minEdge;
		return;
	}
	else if (parent[v] != -1)
	{
		augment(parent[v], min(minEdge, adj[parent[v]][v]));
		adj[parent[v]][v] -= f;
		adj[v][parent[v]] += f;
	}

	return;
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string appInfo;

	while (getline(cin, appInfo))
	{
		int totalApps = 0;
		memset(adj, 0, sizeof adj);
		do
		{
			int nApp = appInfo[1] - '0';
			int u = appInfo[0] - 'A' + 1;

			
			adj[0][u] = nApp;
			totalApps += nApp;
			
			for (int i = 3; i < appInfo.length() - 1; ++i)
			{
				int v = appInfo[i] - '0' + 27;

				adj[u][v] = MAX;
				adj[v][37] = 1;
			}

		} while (getline(cin, appInfo) and appInfo.length());



		int mf = 0;
		while (true)
		{
			f = 0;
			queue<int> node;
			vi visited(38, false);
			
			node.push(0);
			visited[0] = true;
			parent.assign(38, -1);

			while (not node.empty())
			{
				int u = node.front();
				node.pop();

				if (u == 37)
					break;

				for (int v = 0; v < 38; ++v)
				{
					if (adj[u][v] > 0 and not visited[v])
					{
						node.push(v);
						parent[v] = u;
						visited[v] = true;
					}
				}
			}

			augment(37, MAX);

			if (not f)
				break;

			mf += f;
		}

		if (totalApps == mf)
		{
			for (int i = 27; i < 37; ++i)
			{
				bool used = false;	
				for (int j = 1; j < 27; ++j)
				{
					if (adj[i][j] == 1)
					{
						used = true;
						cout << (char)(j + 'A' - 1);
						break;
					}
				}

				if (used)
					continue;

				cout << "_";
			}
			cout << "\n";
		}
		else
			cout << "!\n"; 
	}

	return 0;
}