/*
*	User: Isanchez_Aguilar
*	Problem: UVA 414 - Machined Surfaces
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of rows.
	int rows;
	// Read while there are rows.
	while(cin >> rows && rows)
	{
		// Variable to save the character 'X' or 'B'.
		char character;
		// Variable to save the number of X.
		int numberX;
		// Variable to save the maximum length of rows
		int maximumLength = 0;
		// Array to save the lengths of rows.
		vector<int> lengthRow(rows);
		// Read the data of every single row.
		for(int i = 0; i < rows; ++i)
		{
			cin >> character;
			// Initializing the number of x on the row.
			numberX = 0;
			for(int j = 0; j < 25; ++j)
			{
				// Read the character.
				cin.read(&character, 1);
				// if the character is a X then add to count.
				if(character == 'X')
					++numberX;
			}
			// Get the maximum length.
			maximumLength = max(numberX, maximumLength);
			// Add the length of i-th row.
			lengthRow[i] = numberX;
		}
		// Variable to save the number of void spaces.
		int voidSpaces = 0;
		// Get the number of void spaces of the rows.
		for(int i = 0; i < rows; ++i)
			voidSpaces += maximumLength - lengthRow[i];
		// Print the number of void spaces.
		cout << voidSpaces << "\n";
	}
	return 0;
}