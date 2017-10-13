/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11060 - Beverages
*/
#include <bits/stdc++.h>

using namespace std;

typedef map<string, int> msi;
typedef map<int, string> mis;

int n;
msi names;
mis idx;
bool visited[101];
bool adj[101][101];

inline void topologicalSort(int length)
{
	if(n == length)
	{
		cout << ".\n\n";
		return;
	}

	for(int i = 0; i < n; ++i)
	{
		if(not visited[i])
		{
			bool lowest = true;

			for(int j = 0; j < n; ++j)
			{
				if(not visited[j] and adj[j][i])
				{
					lowest = false;
					break;
				}
			}

			if(lowest)
			{
				visited[i] = true;

				cout << (length?" ":"") << idx[i];
				topologicalSort(length + 1);

				visited[i] = false;
				return;
			}
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	while(cin >> n)
	{
		names.clear();
		memset(adj, false, sizeof adj);
		fill(visited, visited + 101, false);

		for(int i = 0; i < n; ++i)
		{
			string name;
			cin >> name;
			idx[i] = name;
			names.insert(make_pair(name, i));
		}

		int m;
		cin >> m;

		for(int i = 0; i < m; ++i)
		{
			string a;
			string b;

			cin >> a >> b;
			adj[names[a]][names[b]] = true;
		}

		cout << "Case #" << ++t << ": Dilbert should drink beverages in this order: ";

		topologicalSort(0);
	}

	return 0;
}