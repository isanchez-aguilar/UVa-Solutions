/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11459 - Snakes and Ladders
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	vi positions(1000000, 1);
	cin >> testCases;

	while(testCases--)
	{
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		vi board(101, 0);
		// Read the snakes an d ladders.
		for(int i = 0; i < b; ++i)
		{
			int p1;
			int p2;
			cin >> p1 >> p2;
			board[p1] = p2;	
		}
		int winner = -1;
		// Execution of the shots of the dice.
		for(int i = 0; i < c; ++i)
		{
			int number;
			cin >> number;
			if(winner == -1)
			{
				int j = i % a;
				positions[j] += number;
				if(board[positions[j]])
					positions[j] = board[positions[j]];

				if(positions[j] >= 100)
				{
					winner = j;
					positions[j] = 100;
				}
			}
		}
		// Printing information of each player.
		for(int i = 0; i < a; ++i)
		{
			cout << "Position of player " <<  i + 1 << " is " << positions[i] << ".\n";
			positions[i] = 1;
		}
	}
	return 0;
}