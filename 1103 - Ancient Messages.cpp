/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1103 - Ancient Messages
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int grid[410][410];

const int moves[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

inline void floodFill(int y, int x, int newValue, int value)
{
	if(x < 0 or x > m or y < 0 or y > n)
		return;

	if(grid[y][x] != value)
		return;

	grid[y][x] = newValue;
	for(int i = 0; i < 4; ++i)
	{
		int y1 = y + moves[i][0];
		int x1 = x + moves[i][1];
		floodFill(y1, x1, newValue, value);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int holes[210];
	char symbols[2000];
	char matrix[401][51];
	
	while(cin >> n >> m and (n or m))
	{
		memset(grid, 0, sizeof(grid));
		memset(holes, 0, sizeof(holes));
		memset(symbols, 0, sizeof(symbols));
		
		// Read grid.
		for(int i = 0; i < n; ++i)
			cin >> matrix[i];

		// Create binary grid.
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				int position = 3;
				int n = (matrix[i][j] >= '0' and matrix[i][j] <= '9')?matrix[i][j] - '0':matrix[i][j] - 'a' + 10;
				
				// Assigning bits.
				while(n)
				{
					grid[i][(j << 2) + position] = (n & 1);

					n >>= 1;
					--position;
				}
			}
		}

		// Four times original size because every single digit is a set of four bits.
		m <<= 2;
		// Removing the background.
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{ 
				if(i == 0 or j == 0 or i == n - 1 or j == m - 1)
					floodFill(i, j, -1, 0); 
			}
		}

		// ID of symbol.
		int id = 2;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				// If It is a 0 then increase the number of holes on the current id symbol and sparse the number.
				if(grid[i][j] == 0)
				{ 
					++holes[grid[i][j - 1]];
					floodFill(i, j, grid[i][j - 1], 0);
				}
				// If It is a 1 then It is a new symbol.
				else if(grid[i][j] == 1)
					floodFill(i, j, id++, 1);
			}
		}

		int size = 0;
		// Check the frequency of symbols.
		for(int i = 2; i < id; ++i)
		{
			if(holes[i] == 0)
				symbols[size++] = 'W';
			else if(holes[i] == 1)
				symbols[size++] = 'A';
			else if(holes[i] == 2)
				symbols[size++] = 'K';
			else if(holes[i] == 3)
				symbols[size++] = 'J';
			else if(holes[i] == 4)
				symbols[size++] = 'S';
			else if(holes[i] == 5)
				symbols[size++] = 'D';
		}
		// Sort the symbols lexicographically..
		sort(symbols, symbols + size);
		cout << "Case " << ++t << ": " << symbols << "\n";
	}
	return 0;
}