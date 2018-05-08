/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10363 - Tic Tac Toe
*/
#include <bits/stdc++.h>

using namespace std;

char board[3][4];

inline int countWins(char c)
{
	int cnt = 0;
	
	if (board[0][0] == c)
	{
		if (board[0][1] == c and board[0][2] == c)
			++cnt;
		if (board[1][0] == c and board[2][0] == c)
			++cnt;
		if (board[1][1] == c and board[2][2] == c)
			++cnt;
	}

	if (board[1][1] == c)
	{
		if (board[0][1] == c and board[2][1] == c)
			++cnt;
		if (board[1][0] == c and board[1][2] == c)
			++cnt;
		if (board[2][0] == c and board[0][2] == c)
			++cnt;
	}

	if (board[2][2] == c)
	{
		if (board[2][1] == c and board[2][0] == c)
			++cnt;
		if (board[1][2] == c and board[0][2] == c)
			++cnt;
	}	
	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCases;
	cin >> testCases;
	
	while (testCases--)
	{
		int o = 0;
		int x = 0;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> board[i][j];
				
				if (board[i][j] == 'O')
					++o;
				else if (board[i][j] == 'X')
					++x;
			}
		}
		
		bool possible = true;

		if (o == x)
			possible = countWins('X') <= 0;
		else if (o + 1 == x)
			possible = countWins('O') <= 0;
		else
			possible = false;

		if (possible)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	
	return 0;
}
