/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10369 - Arctic Network
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

	while(testCases--)
	{
		int s;
		int p;
		cin >> s >> p;
		
		parent.resize(p);
		for(int i = 0; i < p; ++i)
			parent[i] = i;

		vector< pair<int, int> > coordinates(p);
	
		for(int i = 0; i < p; ++i)
			cin >> coordinates[i].first >> coordinates[i].second;
		
		vector< pair< int, pair<int, int> > > distance;
		for(int i = 0; i < p; ++i)
		{
			for(int j = i + 1; j < p; ++j)
			{
				int x = coordinates[i].first - coordinates[j].first;
				int y = coordinates[i].second - coordinates[j].second;

				distance.push_back(make_pair(x * x + y * y, make_pair(i, j)));
			}

		}

		double maxD = 0.0L;
		int components = p;

		sort(distance.begin(), distance.end());
		for(int i = 0; i < (int)distance.size(); ++i)
		{
			pair< int, pair<int, int> > front = distance[i];

			int u = getParent(front.second.first);
			int v = getParent(front.second.second);
			
			if(u != v)
			{
				parent[u] = v;
				maxD = max(maxD, sqrt(front.first));
				
				if(--components <= s)
					break;
			}
		}

		cout << fixed << setprecision(2) << maxD << "\n";
	}

	return 0;
}