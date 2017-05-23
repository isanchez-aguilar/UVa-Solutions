/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11498 - Division of Nlogonia
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of queries.
	int numberQueries;
	// Read the number the queries.
	cin >> numberQueries;
	// Read while there are queries.
	while(numberQueries)
	{
		// Variable to save coordinates of division.
		int xDivision, yDivision;
		// Read coordinates of division.
		cin >> xDivision >> yDivision;
		// Read queries.
		for(int i = 0; i < numberQueries; ++i)
		{
			// Variable to save coordinates of querie.
			int x;
			int y;
			// Read the coordinates of query.
			cin >> x >> y;
			// If the residence is on one border.
			if(xDivision == x || yDivision == y)
				cout << "divisa\n";
			// If the residence is on north.
			else if(y > yDivision)
			{
				// If the residence is on west.
				if(x < xDivision)
					cout << "NO\n";
				// If the residence is on east.
				else
					cout << "NE\n";
			}
			// If the residence is on south.
			else
			{
				// If the residence is on west.
				if(x < xDivision)
					cout << "SO\n";
				// If the residence is on east.
				else
					cout << "SE\n";		
			}
		}
		// Read the number the queries.
		cin >> numberQueries;
	}
	return 0;
}