/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11661 - Burger Time?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int length;
	// Read while the length of highway is nonzero.
	while(cin >> length && length)
	{
		// Initialize the variables.
		char character;
		bool z = false;
		bool r = false;
		bool d = false;
		int dD = 0;
		int dR = 0;
		int minimum = INT_MAX;
		// Read character by character while the length is nonzero.
		while(length--)
		{
			cin >> character;
			// If It has not benn read a Z.
			if(!z)
			{
				// Evaluate the read character.
				switch(character)
				{
					// If It is a z(restaurant and drugstore) then the minimum distance is zero and z is equal to true.
					case 'Z':
						z = true;
						minimum = 0;
						break;
					// If It is a r(restaurant) the r is equal to true.
					case 'R':
						// If had alredy been read a d then get the minimum beetwen minimum and dR.
						if(d)
							minimum = min(minimum, dR);
						dD = 0;
						r = true;
						break;
					// If It is a d(restaurant) the d is equal to true.
					case 'D':
						// If had alredy been read a r then get the minimum beetwen minimum and dR.
						if(r)
							minimum = min(minimum, dD);
						dR = 0;
						d = true;
						break;
				}
			}
			// Increase the distance.
			++dR;
			++dD;
		}
		// Print the minimum distance beetwen a restaurant and drugstore.
		cout << minimum << "\n";
	}
	return 0;
}
