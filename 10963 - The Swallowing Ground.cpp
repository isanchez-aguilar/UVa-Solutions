/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10963 - The Swallowing Ground
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
	// While there are test cases.
	while(testCases--)
	{
		// Variable to save the number the columns.
		int columns;
		// Variables to save the boundaries.
		int y1;
		int y2;
		// Read the number of colums;
		cin >> columns;
		// Read y1 and y2 of first column.
		cin >> y1 >> y2;
		// Variable to save the distance between boundaries.
		int distance = y1 - y2;
		// Variable to know if It is possible close the gaps.
		bool possible = true;
		// Read the remaining gaps.
		while(columns--)
		{
			cin >> y1 >> y2;
			// If the distance is different then It cannot be closed.
			if(distance != y1 - y2)
				possible = false;
		}
		// If all the gaps have the same distance then It is possible close them.
		if(possible)
			cout << "yes\n";
		// If any gap has different distance then It is not possible.
		else
			cout << "no\n";
		if(testCases)
			cout << "\n";
	}
	return 0;
}