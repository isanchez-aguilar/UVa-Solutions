/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11906 - Knight in a War Grid
*/
#include <bits/stdc++.h>

#define WATER -1

using namespace std;

int r;
int c;
int m;
int n;
int grid[102][102];
bool visited[102][102];
int neighbors[102][102];
int sign[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

inline bool isInside(int x, int y)
{
	return (x < r and x >= 0 and y < c and y >= 0);
}

inline void dfs(int x, int y)
{
	if(visited[y][x])
		return;

	visited[y][x] = true;
	for(int i = 0; i < 4; ++i)
	{
		int y1 = y + sign[i][0] * m;
		int x1 = x + sign[i][1] * n;

		if(isInside(x1, y1) and grid[y1][x1] != WATER)
		{
			++neighbors[y1][x1];
			dfs(x1, y1);
		}

		y1 = y + sign[i][0] * n;
		x1 = x + sign[i][1] * m;

		if(isInside(x1, y1) and grid[y1][x1] != WATER)
		{
			++neighbors[y1][x1];
			dfs(x1, y1);				
		}
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
		int w;
		cin >> r >> c >> m >> n >> w;

		memset(grid, 0, sizeof(grid));
		memset(visited, false, sizeof(visited));
		memset(neighbors, 0, sizeof(neighbors));

		while(w--)
		{
			int x;
			int y;
			cin >> x >> y;
			grid[y][x] = WATER;
		}

		dfs(0, 0);

		int odd = 0;
		int even = 0;
		for(int i = 0; i < c; ++i)
		{
			for(int j = 0; j < r; ++j)
			{
				if(m == 0 or n == 0 or n == m)
					neighbors[i][j] >>= 1;
			
				if(neighbors[i][j] or not(i or j))
				{
					if(neighbors[i][j] & 1)
						++odd;
					else
						++even;
				}
			}
		}

		cout << "Case " << t << ": " << even << " " << odd << "\n";
	}	

	return 0;
}