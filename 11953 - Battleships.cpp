/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11953 - Battleships
*/
#include <bits/stdc++.h>

using namespace std;

int l;
char grid[101][101];
const int moves[8][2] = {{-1, 0}, {-1, -1},  {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

inline bool isInside(int x, int y)
{
	return (x < l and x >= 0 and y < l and y >= 0);
}

inline void floodFill(int x, int y)
{
	grid[y][x] = '.';

	for(int i = 0; i < 8; ++i)
	{
		int y1 = y + moves[i][0];
		int x1 = x + moves[i][1];
		
		if(isInside(x1, y1) and grid[y1][x1] != '.')
			floodFill(x1, y1);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		cin >> l;

		for(int i = 0; i < l; ++i)
			cin >> grid[i];

		int ships = 0;

		for(int i = 0; i < l; ++i)
		{
			for(int j = 0; j < l; ++j)
			{
				if(tolower(grid[i][j]) == 'x')
				{
					++ships;
					floodFill(j, i);
				}
			}
		}

		cout << "Case " << t << ": " << ships << "\n";
	}

	return 0;
}