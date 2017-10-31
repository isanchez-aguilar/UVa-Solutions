/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11101 - Mall Mania
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector< vector<int> > grid(2001, vector<int>(2001));
	vector< vector<int> > moves(2001, vector<int>(2001));
	const int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	while(cin >> n and n)
	{

		queue< pair<int, int> > node;
		for(int i = 0; i < 2001; ++i)
		{
			fill(grid[i].begin(), grid[i].end(), 0);
			fill(moves[i].begin(), moves[i].end(), -1);
		}

		for(int i = 0; i < n; ++i)
		{
			int x;
			int y;
			cin >> x >> y;

			grid[x][y] = 1;
			moves[x][y] = 0;
			node.push(make_pair(x, y));
		}
		int m;
		cin >> m;
		for(int i = 0; i < m; ++i)
		{
			int x;
			int y;
			cin >> x >> y;
			
			grid[x][y] = 2;
		}

		int distance = -1;
		while(not node.empty())
		{
			pair<int, int> u = node.front();
			node.pop();

			if(grid[u.first][u.second] == 2)
			{
				distance = moves[u.first][u.second];
				break;
			}

			for(int i = 0; i < 4; ++i)
			{
				int x = u.first + move[i][0];
				int y = u.second + move[i][1];

				if(x < 2000 and x > -1 and y < 2000 and y > -1 and moves[x][y] == -1)
				{
					node.push(make_pair(x, y));
					moves[x][y] = moves[u.first][u.second] + 1;
				}
			}
		}

		cout << distance << "\n";
	}

	return 0;
}