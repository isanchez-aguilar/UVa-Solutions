/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11228 - Transportation system.
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

inline int getParent(int u)
{
	return (parent[u] == u?u:parent[u] = getParent(parent[u]));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		int n;
		double r;
		cin >> n >> r;

		parent.resize(n);
		vector< pair<int, int> > coordinates(n);

		for(int i = 0; i < n; ++i)
		{
			parent[i] = i;
			cin >> coordinates[i].first >> coordinates[i].second;
		}

		vector< pair< int, pair<int, double> > > distances;

		for(int i = 0; i < n; ++i)
		{
			for(int j = i + 1; j < n; ++j)
			{
				int x = coordinates[i].first - coordinates[j].first;
				int y = coordinates[i].second - coordinates[j].second;
				x *= x;
				y *= y;
				distances.push_back(make_pair(x + y, make_pair(i, j)));
			}
		}

		sort(distances.begin(), distances.end());
	
		int states = 1;
		double minRail = 0;
		double minRoad = 0;
		int components = 0;

		for(int i = 0; i < (int)distances.size(); ++i)
		{
			pair< int, pair<int, double> > front = distances[i];
			
			int u = getParent(front.second.first);
			int v = getParent(front.second.second);

			if(u != v)
			{
				parent[u] = v;

				if(front.first <= r * r)
					minRoad += sqrt(front.first);
				else
				{
					++states;
					minRail += sqrt(front.first);
				}

				if(++components == n - 1)
					break;
			}
		}

		cout << "Case #" << t << ": " << states << " " << (int)round(minRoad) << " " << (int)round(minRail) << "\n";
	}

	return 0;
}