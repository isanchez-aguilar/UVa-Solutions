/*
*	User: Isanchez_Aguilar
*	Problem: UVA 929 - Number Maze
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	const int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	cin >> testCases;

	while(testCases--)
	{
		int r;
		int c;
		cin >> r >> c;

		int grid[r][c];
		for(int i = 0; i < r; ++i)
		{
			for(int j = 0; j < c; ++j)
				cin >> grid[i][j];
		}

		int d[r][c];
		for(int i = 0; i < r; ++i)
		{
			for(int j = 0; j < c; ++j)
				d[i][j] = INT_MAX;
		}
		priority_queue< pair< int, pair<int, int> >, vector< pair< int, pair<int, int> > >, greater< pair< int, pair<int, int> > > > node;

		d[0][0] = grid[0][0];
		node.push(make_pair(d[0][0], make_pair(0, 0)));

		while(not node.empty())
		{
			int dist = node.top().first;
			pair<int, int> p = node.top().second;
			node.pop();

			if(dist > d[p.first][p.second])
				continue;

			for(int i = 0; i < 4; ++i)
			{
				int y = p.first + moves[i][0];
				int x = p.second + moves[i][1];
				if(x < c and x > -1 and y < r and y > -1)
				{	
					if(dist + grid[y][x] < d[y][x])
					{
						d[y][x] = dist + grid[y][x];
						node.push(make_pair(d[y][x], make_pair(y, x)));
					}
				}
			}
		}

		cout << d[r - 1][c - 1] << "\n";
	}

	return 0;
}