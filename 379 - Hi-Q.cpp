/*
*	User: Isanchez_Aguilar
*	Problem: UVA 379 - Hi-Q
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

bool pegs[7][7];
int  value[7][7];
ii coordinates[33];
bool available[7][7];
const int moves[][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

inline bool isValidMove(int x, int y, int dx, int dy)
{
	if (x + (dx << 1) < 7 and x + (dx << 1) >= 0 and y + (dy << 1) < 7 and y + (dy << 1) >= 0)
		return pegs[x + dx][y + dy] and pegs[x + (dx << 1)][y + (dy << 1)];
	
	return false;
}

inline bool play()
{
	ii to(-1, -1);
	ii middle(-1, -1);
	ii source(-1, -1);
	
	for (int i = 6; i > -1 and to.first == -1; --i)
	{
		for (int j = 6; j > -1 and to.first == -1; --j)
		{
			if (available[i][j] and not pegs[i][j])
			{
				for (int k = 0; k < 4; ++k)
				{
					int dx = moves[k][0];
					int dy = moves[k][1];
					
					if (isValidMove(i, j, dx, dy))
					{
						to = ii(i, j);
						middle = ii(i + dx, j + dy);
						source = ii(i + (dx << 1), j + (dy << 1));
						break;
					}
				}
			}
		}
	}

	if (to.first != -1)
	{
		pegs[to.first][to.second] = true;
		pegs[source.first][source.second] = false;
		pegs[middle.first][middle.second] = false;

		return true;
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0, v = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if ((i < 2 or i > 4) and (j < 2 or j > 4))
				continue;

			value[i][j] = v + 1;
			available[i][j] = true;
			coordinates[v++] = ii(i, j);
		}
	}

	int n;
	cin >> n;
	cout << "HI Q OUTPUT\n";
	while (n--)
	{
		int cell;
		memset(pegs, false, sizeof pegs);

		while (cin >> cell and cell)
		{
			int i = coordinates[cell - 1].first;
			int j = coordinates[cell - 1].second;

			pegs[i][j] = true;
		}

		while (play());

		int score = 0;

		for (int i = 0; i < 7; ++i)
		{
			for (int j = 0; j < 7; ++j)
			{
				if (pegs[i][j])
					score += value[i][j];
			}
		}

		cout << score << "\n";
	}
	cout << "END OF OUTPUT\n";

	return 0;
}