/*
*	User: Isanchez_Aguilar
*	Problem: UVA 339 - SameGame Simulation
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int r;
int c;
vvi board;
int elements;
bool visited[10][40];
const int moves[][2] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

inline bool isInside(int x, int y)
{
	return x > -1 and x < r and y > -1 and y < c;
}

inline void floodFill(int x, int y)
{
	++elements;
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int x1 = x + moves[i][0];
		int y1 = y + moves[i][1];

		if (y1 < board.size() and x1 < board[y1].size() and not visited[y1][x1] and board[y1][x1] == board[y][x])
			floodFill(x1, y1);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	while (cin >> r >> c and (r or c))
	{
		board.clear();
		board = vvi(c, vi(r));

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cin >> board[j][i];
		}

		int x;
		int y;
		while (cin >> x >> y and (x or y))
		{
			if (not isInside(x - 1, y - 1))
				continue;	
			
			elements = 0;
			memset(visited, false, sizeof visited);
			
			floodFill(x - 1, y - 1);
			


			if (elements > 1)
			{
				for (int i = board.size() - 1; i >= 0; --i)
				{
					for (int j = board[i].size() - 1; j >= 0; --j)
					{
						if (visited[i][j])
							board[i].erase(board[i].begin() + j);
					}
					
					if (board[i].size() == 0)
						board.erase(board.begin() + i);
				}
			}
		}

		if (t++)
			cout << "\n"; 
		
		cout << "Grid " << t << ".\n";
		
		if (board.size() == 0)
			cout << "    Game Won\n";
		else
		{
			for (int i = r - 1; i >= 0; --i)
			{
				cout << "   ";
				for (int j = 0; j < c; ++j)
				{
					if (board.size() > j and board[j].size() > i)
						cout << " " << board[j][i];
					else
						cout << "  ";
				}
				cout << "\n";
			}
		}
	}

	return 0;
}