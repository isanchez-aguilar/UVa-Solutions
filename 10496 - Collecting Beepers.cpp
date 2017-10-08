/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10496 - Collecting Beepers
*/
#include <bits/stdc++.h>

using namespace std;

int beepers;
int adj[11][11];
int memo[11][4096];

inline int getShortestPerimeter(int coordinate, int visited)
{
	if(visited == (1 << (beepers + 1)) - 1)
		return adj[coordinate][0];

	int &c = memo[coordinate][visited];

	if(c != -1)
		return c;

	int shortest = 2000000000;

	for (int i = 0; i <= beepers; i++)
	{
		if (i != coordinate and not (visited & (1 << i)))
			shortest = min(shortest, adj[coordinate][i] + getShortestPerimeter(i, visited | (1 << i)));
	}
	
	return c = shortest;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	pair<int, int> coordinates[11];
	
	cin >> testCases;
	while(testCases--)
	{
		int width;
		int height;
		
		cin >> width >> height;
		cin >> coordinates[0].first >> coordinates[0].second;

		cin >> beepers;

		for(int i = 1; i <= beepers; ++i)
			cin >> coordinates[i].first >> coordinates[i].second;

		for(int i = 0; i <= beepers; ++i)
		{
			for(int j = i + 1; j <= beepers; ++j)
			{
				adj[i][j] = abs(coordinates[i].first - coordinates[j].first) + abs(coordinates[i].second - coordinates[j].second);
				adj[j][i] = adj[i][j];
			}
		}

		memset(memo, -1, sizeof(memo));

		cout << "The shortest path has length " << getShortestPerimeter(0, 1) << "\n";
	}

	return 0;
}