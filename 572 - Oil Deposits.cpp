/*
*	User: Isanchez_Aguilar
*	Problem: UVA 572 - Oil Deposits
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int m;
char grid[101][101];
const int moves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

inline bool isInside(int i, int j)
{
	return i < n and i > -1 and j < m and j > -1;
}

inline void floodFill(int i, int j)
{
	grid[i][j] = '*';

	for(int k = 0; k < 8; ++k)
	{
		int x = i + moves[k][0];
		int y = j + moves[k][1];

		if(isInside(x, y) and grid[x][y] == '@')
			floodFill(x, y);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n >> m and n)
	{

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
				cin >> grid[i][j];
		}

		int oil = 0;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(grid[i][j] == '@')
				{
					++oil;
					floodFill(i, j);
				}
			}
		}

		cout << oil << "\n";
	}

	return 0;
}