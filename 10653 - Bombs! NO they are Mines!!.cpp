/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10653 - Bombs! NO they are Mines!!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r;
	int c;
	const int moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	while(cin >> r >> c and (r or c))
	{
		int rBombs;
		vector< vector<char> > grid(r, vector<char>(c, '.'));

		cin >> rBombs;

		for(int i = 0; i < rBombs; ++i)
		{
			int row;
			int cBombs;
			cin >> row >> cBombs;

			for(int j = 0; j < cBombs; ++j)
			{
				int column;
				cin >> column;

				grid[row][column] = '*';
			}
		}

		int sX;
		int sY;
		int tX;
		int tY;

		cin >> sY >> sX >> tY >> tX;
		
		int totalMoves = -1;
		queue< pair<int, int> > cell;
		vector< vector<int> > d(r, vector<int>(c, INT_MAX));

		d[sY][sX] = 0;
		cell.push(make_pair(sY, sX));

		while(not cell.empty())
		{
			pair<int, int> u = cell.front();
			cell.pop();

			for(int i = 0; i < 4; ++i)
			{
				int y = moves[i][0] + u.first;
				int x = moves[i][1] + u.second;
				if(x < c and x > -1 and y < r and y > -1)
				{
					if(d[y][x] == INT_MAX and grid[y][x] != '*')
					{
						d[y][x] = d[u.first][u.second] + 1;
						
						if(x == tX and y == tY)
						{
							totalMoves = d[y][x];
							break;
						}

						cell.push(make_pair(y, x));
					}
				}
			}

			if(totalMoves != -1)
				break;
		}

		cout << totalMoves << "\n";
	}

	return 0;
}