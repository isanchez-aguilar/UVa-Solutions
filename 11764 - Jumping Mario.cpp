/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11764 - Jumping Mario
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of test cases.
	int testCases;
	// Read the number of test cases.
	cin >> testCases;
	// Read while there are test cases.
	for(int i = 1; i <= testCases; ++i)
	{
		// Variable to save the number of walls.
		int walls;
		cin >> walls;
		// Variable to save the initial position.
		int initialPosition;
		cin >> initialPosition;
		// Variable to save the height to next position.
		int nextPosition;
		// Variables to save the high and low jumps.
		int highJumps = 0;
		int lowJumps = 0;
		// Read the jumps.
		for(int j = 1; j < walls; ++j)
		{
			cin >> nextPosition;
			if(initialPosition < nextPosition)
				++highJumps;
			else if(initialPosition > nextPosition)
				++lowJumps;
			initialPosition = nextPosition;
		}
		// Print information about jumps.
		cout << "Case " << i << ": " << highJumps << " " << lowJumps << "\n";
	}
	return 0;
}