/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10849 - Move the bishop
*/
#include <bits/stdc++.h>

using namespace std;

inline bool biconditional(bool p, bool q) { return (!p || q) && (p || !q); }

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p[4];
	int testCases;
	// Read number of test cases.
	cin >> testCases;
	// While there is test cases.
	while(testCases--)
	{
		int size;
		int moves;
		// Read number of moves and size of chessboard.
		cin >> moves >> size;

		for(int i = 0; i < moves; ++i)
		{
			// Read positions.
			for(int j = 0; j < 4; ++j)
				cin >> p[j];
			// If the initial position and final position is equal then is 0 moves.
			if(p[0] == p[2] && p[1] == p[3])
				cout << "0\n";
			else
			{
				// Compute the distance between positions x and y.
				int x = abs(p[0] - p[2]);
				int y = abs(p[1] - p[3]);
				// Check if It is possible with biconditional of distance % 2.
				if(biconditional(x & 1, y & 1))
				{
					if(x == y)
						cout << "1\n";
					else
						cout << "2\n";
				}
				else
					cout << "no move\n";
			}
		}
	}
	return 0;
}