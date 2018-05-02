/*
*	User: Isanchez_Aguilar
*	Problem: UVA 232 - Crossword Answers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r;
	int c;
	int t = 0;
	char board[10][10];
	int numbered[10][10];

	while (cin >> r >> c and r)
	{
		int n = 0;
		memset(numbered, -1, sizeof numbered);

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cin >> board[i][j];
			
		}
		for (int i = 0; i < c; ++i)
		{
			if (board[0][i] != '*')
				numbered[0][i] = ++n;
		}

		for (int i = 1; i < r; ++i)
		{
			if (board[i][0] != '*' or (board[i][0] != '*' and board[i - 1][0] == '*'))
				numbered[i][0] = ++n;

			for (int j = 1; j < c; ++j)
			{
				if (board[i][j] == '*' or (numbered[i][j - 1] != -1 and board[i - 1][j] != '*'))
					continue;

				if (board[i][j - 1] == '*' or board[i - 1][j] == '*')
					numbered[i][j] = ++n;
			}
		}

		vector< pair<string, int> > down;
		vector< pair<string, int> > across;
		vector< vector<bool> > downVisited(r, vector<bool>(c));
		vector< vector<bool> > acrossVisited(r, vector<bool>(c));

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (numbered[i][j] != -1)
				{
					string s = "";

					if (i == 0 or (i > 0 and not downVisited[i - 1][j]))
					{	
						for (int k = i; k < r and board[k][j] != '*'; ++k)
						{
							s += board[k][j];
							downVisited[k][j] = true;
						}

						down.push_back(make_pair(s, numbered[i][j]));

					}

					if (j == 0 or (j > 0 and not acrossVisited[i][j - 1]))
					{	
						s = "";
						for (int k = j; k < c and board[i][k] != '*'; ++k)
						{
							s += board[i][k];
							acrossVisited[i][k] = true;
						}
						
						across.push_back(make_pair(s, numbered[i][j]));
					}
				}
			}
		}
		
		if (t++)
			cout << "\n";

		cout << "puzzle #" << t << ":\n";
		cout << "Across\n";

		for (int i = 0; i < across.size(); ++i)
			cout << setw(3) << across[i].second << "." << across[i].first << "\n";
		cout << "Down\n";
		for (int i = 0; i < down.size(); ++i)
			cout << setw(3) << down[i].second << "." << down[i].first << "\n";
	}

	return 0;
}