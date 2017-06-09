/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10409 - Die Game
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCases;
	char input[7];
	// Read the number of test cases while os not zero.
	while (cin >> testCases && testCases)
	{
		// Initialize the value of every single face.
		int top = 1;
		int north = 2;
		int west = 3;
		int east = 4;
		int south = 5;
		int bottom = 6;
		// Read the test cases.
		while (testCases--)
		{
			// Backuo of top's value.
			int auxiliary = top;
			// Read the move.
			cin >> input;
			// Change the faces with their respective movement.
			if(input[0] == 'n')
			{
				top = south;
				south = bottom;
				bottom = north;
				north = auxiliary;
			}
			else if(input[0] == 'e')
			{
				top = west;
				west = bottom;
				bottom = east;
				east = auxiliary;
			}
			else if(input[0] == 's')
			{
				top = north;
				north = bottom;
				bottom = south;
				south = auxiliary;
			}
			else
			{
				top = east;
				east = bottom;
				bottom = west;
				west = auxiliary;
			}
		}
		// Print the final state of top after moves.
		cout << top << '\n';
	}
	return 0;
}