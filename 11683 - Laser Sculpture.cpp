/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11683 - Laser Sculpture
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int height;
	int length;
	// Read while height is nonzero.
	while(cin >> height && height)
	{
		cin >> length;
		// Initialize the variables.
		int lastHeight = height;
		int currentHeight;
		int cuts = 0;
		// Read the height of every single level.
		while(length--)
		{
			cin >> currentHeight;
			// If the last read height is lower than the current then add to cuts the difference.
			switch(lastHeight > currentHeight)
			{
				case 1:
					cuts += lastHeight - currentHeight;
			}
			// Update the last height.
			lastHeight = currentHeight;
		}
		// Print the information of height.
		cout << cuts << '\n';
	}
	return 0;
}
