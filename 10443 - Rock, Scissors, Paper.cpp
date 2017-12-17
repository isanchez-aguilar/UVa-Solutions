/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10443 - Rock, Scissors, Paper
*/
#include <bits/stdc++.h>

using namespace std;

inline bool win(char a, char b)
{
	if(a == 'R')
	{
		if(b == 'S')
			return true;

		return false;

	}
	if(a == 'P')
	{
		if(b == 'R')
			return true;

		return false;
	}

	if(b == 'P')
		return true;

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	const int moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	cin >> testCases;

	while(testCases--)
	{
		int r;
		int c;
		int n;

		cin >> r >> c >> n;

		vector< vector<char> > matrix(r, vector<char>(c));

		for(int i = 0; i < r; ++i)
		{
			for(int j = 0; j < c; ++j)
				cin >> matrix[i][j];
		}

		for(int d = 0; d < n; ++d)
		{
			vector< vector<char> > backup(matrix);

			for(int i = 0; i < r; ++i)
			{
				for(int j = 0; j < c; ++j)
				{
					for(int k = 0; k < 4; ++k)
					{
						int x = i + moves[k][0];
						int y = j + moves[k][1];

						if(x > -1 and x < r and y > -1 and y < c)
						{
							if(win(backup[i][j], backup[x][y]))
								matrix[x][y] = backup[i][j];
						}
					}
				}
			}
		}

		for(int i = 0; i < r; ++i)
		{
			for(int j = 0; j < c; ++j)
				cout << matrix[i][j];
			cout << "\n";
		}

		if(testCases)
			cout << "\n";
	}

	return 0;
}