/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11085 - Back to the 8-Queens
*/
#include <bits/stdc++.h>

using namespace std;

int rows[8];
int position[8];

bool areAttacked(int i, int currentQueen)
{
	for(int j = 0; j < currentQueen; ++j)
	{
		if(i == rows[j])
			return true;
		if(abs(currentQueen - j) == abs(rows[j] - i))
			return true;
	}
	return false;
}

int searchPosition(int currentQueen)
{
	if(currentQueen == 8)
		return 0;

	int moves = 8;
	for(int i = 0; i < 8; ++i)
	{
		if(!areAttacked(i, currentQueen))
		{
			rows[currentQueen] = i;
			moves = min(moves, position[currentQueen] == i?searchPosition(currentQueen + 1):(searchPosition(currentQueen + 1)) + 1);
		}
	}

	return moves;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	while(cin >> position[0])
	{
		rows[0] = --position[0];
		for(int i = 1; i < 8; ++i)
		{
			cin >> position[i];
			
			rows[i] = --position[i];
		}
		
		cout << "Case " << ++t << ": " << searchPosition(0) << "\n";
	}
	return 0;
}