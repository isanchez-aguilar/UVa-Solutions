/*
*	User: Isanchez_Aguilar
*	Problem: UVA 216 - Getting in Line
*/
#include <bits/stdc++.h>

using namespace std;

int path[8];
int computers;
int bestPath[8];
double minLength;
double adj[8][8];

inline double sqr(int p){ return (double)(p * p); }

inline void getShortestLength(int coordinate, int connected, int visited, double length)
{
	if(connected == computers)
	{
		if(length < minLength)
		{
			minLength = length;
			for(int i = 0; i < computers; ++i)
				bestPath[i] = path[i];
		}
		return;
	}

	for (int i = 0; i < computers; ++i)
	{
		if(not (visited & (1 << i)))
		{
			path[connected] = i;
			getShortestLength(i, connected + 1, visited | (1 << i), length + adj[coordinate][i]);
		}
	}
	
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	pair<int, int> p[8];
	cout << fixed << setprecision(2);
	while(cin >> computers and computers)
	{
		for(int i = 0; i < computers; ++i)
			cin >> p[i].first >> p[i].second;

		for(int i = 0; i < computers; ++i)
		{
			for(int j = i + 1; j < computers; ++j)
			{
				adj[i][j] = sqrt(sqr(abs(p[i].first - p[j].first)) + sqr(abs(p[i].second - p[j].second))) + 16.0;
				adj[j][i] = adj[i][j];
			}
		}

		

		minLength = (double)INT_MAX;
		for(int i = 0; i < computers; ++i)
		{
			path[0] = i;
			getShortestLength(i, 1, 1 << i, 0.0);
		}

		cout << "**********************************************************\n";
		cout << "Network #" << ++t << "\n";
		for(int i = 0; i < computers - 1; ++i)
		{
			int x1 = p[bestPath[i]].first;
			int y1 = p[bestPath[i]].second;
			int x2 = p[bestPath[i + 1]].first;
			int y2 = p[bestPath[i + 1]].second;
			cout << "Cable requirement to connect (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ") is " << adj[bestPath[i]][bestPath[i + 1]] << " feet.\n";
		}
		cout << "Number of feet of cable required is " << minLength << ".\n";
	}

	return 0;
}