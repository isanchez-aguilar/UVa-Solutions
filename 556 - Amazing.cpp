/*
*	User: Isanchez_Aguilar
*	Problem: UVA 556 - Amazing
*/
#include <bits/stdc++.h>

using namespace std;

int width;
int height;

inline bool isValid(int x, int y)
{
	return x > -1 and x < width and y > -1 and y < height;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	const int move[4][2] = {
		{ 0,  1},
		{ 1,  0},
		{ 0, -1},
		{-1,  0}
	};

	while (cin >> height >> width and (width or height))
	{
		char grid[height][width];
		
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
				cin >> grid[i][j];
		}

		int currentX = 0;
		int currentDirection = 0;
		int currentY = height - 1;
		int gridFrequency[height][width];
		memset(gridFrequency, 0, sizeof gridFrequency);

		do
		{
			// Right side.
			int y = currentY + move[(currentDirection + 1) % 4][0];
			int x = currentX + move[(currentDirection + 1) % 4][1];

			if (isValid(x, y) and grid[y][x] == '0')
				currentDirection = (currentDirection + 1) % 4;

			y = currentY + move[currentDirection][0];
			x = currentX + move[currentDirection][1];

			// While It cannot move turn left.
			while (not isValid(x, y) or grid[y][x] == '1')
			{
				currentDirection = (currentDirection + 3) % 4;	
				y = currentY + move[currentDirection][0];
				x = currentX + move[currentDirection][1];
			}

			currentY = y;
			currentX = x;
			++gridFrequency[y][x];

		}while (currentX != 0 or currentY != height - 1);

		int f[5];
		memset(f, 0, sizeof f);

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (gridFrequency[i][j] < 5 and grid[i][j] == '0')
					++f[gridFrequency[i][j]];
			}
		}

		for (int i = 0; i < 5; ++i)
			cout << setw(3) << f[i];

		cout << "\n";
	}

	return 0;
}