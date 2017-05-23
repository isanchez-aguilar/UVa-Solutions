/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11044 - Searching for Nessy
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save number of test cases.
	int testCases;
	// Read the number of test cases.
	cin >> testCases;
	// Read while number of test cases is bigger than zero.
	while(testCases--)
	{
		// Variables to save the size of grid.
		int rows;
		int columns;
		// Read the size of grid.
		cin >> rows >> columns;
		// Calculate the maximum sonar in rows and columns and then multiply to know the maximum sonar with its area.
		cout << (rows / 3) * (columns / 3) << "\n";
	}
	return 0;
}