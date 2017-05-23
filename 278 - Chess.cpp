/*
*	User: Isanchez_Aguilar
*	Problem: UVA 278 - Chess
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCases;
	// Read the number of test cases.
	cin >> testCases;
	// Execute while testCases is not equal to zero.
	while(testCases--)
	{
		int m;
		int n;
		char piece;
		// Read the data of test case.
		cin >> piece >> m >> n;
		// Evaluate the piece.
		switch(piece)
		{
			// If the piece is a rook.
			case 'r':
				cout << min(m, n) << '\n';
			break;
			// If the piece is a knight.
			case 'k':
				cout << (m * n + 1) / 2 << '\n';
			break;
			// If the piece is a queen.
			case 'Q':
				cout << min(m, n) << '\n';
			break;
			// If the piece is a king.
			default:
				cout << ((m + 1) / 2) * ((n + 1) / 2) << '\n';
		}
	}
	return 0;
}