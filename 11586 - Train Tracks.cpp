/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11586 - Train Tracks
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Read the number of test cases.
	int testCases;
	cin >> testCases;
	// Ignore \n
	cin.ignore(256, '\n');
	// Execute the algorithm while there is test cases.
	while(testCases--)
	{
		string pieces;
		int female = 0;
		int male = 0;
		// Read all pieces.
		getline(cin, pieces);
		// Get the length of pieces.
		int i = pieces.length();
		// Go through the whole string of pieces.
		while(i--)
		{
			// Evalaute the character in position i.
			switch(pieces[i])
			{
				// If the character is F then is a female so add to the quantity of female pieces.
				case 'F':
					++female;
					break;
				// If the character is M then is a male so add to the quantity of male pieces.
				case 'M':
					++male;
					break;
			}
					
		}
		// If there is just one then It's not a loop.
		if(male == 1)
			cout << "NO LOOP\n";
		// If there is more than one the evaluate the quantity of pieces.
		else
		{
			// Evaluate If there are the same number of pieces female and male.
			switch(male == female)
			{
				// If there are the same number of pieces then It's a loop. 
				case 1:
					cout << "LOOP\n";
					break;
				// If there are not the same number of pieces then It's not a loop.
				default:
					cout << "NO LOOP\n";
			}
		}		
	}
	return 0;
}
