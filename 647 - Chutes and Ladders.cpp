/*
*	User: Isanchez_Aguilar
*	Problem: UVA 647 - Chutes and Ladders
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int value;
	string line;
	int board[100];
	bool lose[100];
	bool extra[100];
	vector<int> throws;
	getline(cin, line);
	istringstream in(line);

	while (in >> value)
		throws.push_back(value);

	int players;
	while (cin >> players and players)
	{	
		vector<bool> turn(players, true);
		vector<int> position(players, 0);
		for (int i = 0; i < 100; ++i)
			board[i] = i;
		
		int a;
		int b;
		
		while (cin >> a >> b and (a or b))
			board[a] = b;

		memset(lose, false, sizeof lose);
		memset(extra, false, sizeof extra);

		while (cin >> a and a)
		{
			if (a < 0)
				lose[-a] = true;
			else
				extra[a] = true;
		}

		int winner = -1;
		int currentPlayer = 0;

		for (int i = 0; i < throws.size(); ++i)
		{
			if (not turn[currentPlayer])
			{
				turn[currentPlayer] = true;
				currentPlayer = (currentPlayer + 1) % players;
				continue;
			}
			if (position[currentPlayer] + throws[i] > 100)
			{
				currentPlayer = (currentPlayer + 1) % players;
				continue;
			}
			
			if (position[currentPlayer] + throws[i] == 100)
			{
				winner = currentPlayer + 1;
				break;
			}

			bool extraTurn = false;
			int &p = position[currentPlayer];
			
			p += throws[i];
			
			if (lose[p])
				turn[currentPlayer] = false;
			else if (extra[p])
				extraTurn = true;

			p = board[p];

			if (not extraTurn)
				currentPlayer = (currentPlayer + 1) % players;
		}

		cout << winner << "\n";
	}

	return 0;
}