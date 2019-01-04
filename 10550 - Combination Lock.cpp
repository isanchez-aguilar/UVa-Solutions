/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10550 - Combination Lock
*/
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variables to save the combination.
	int digit1;
	int digit2;
	int digit3;
	// Variable to save the initial position.
	int initialPosition;
	// Read If any number is different from zero or while not EOF.
	while(cin >> initialPosition >> digit1 >> digit2 >> digit3 and (initialPosition != 0 or digit1 != 0 or digit2 != 0 or digit3 != 0))
	{
		// Variable to save the rotations.
		int degrees = 120;
		// Turn clockwise.
		degrees += (initialPosition - digit1 + (initialPosition - digit1 < 0 ? 40: 0));
		// Turn counter-clockwise.
		degrees += (digit2 - digit1 + (digit2 - digit1 < 0 ? 40: 0));
		// Turn clockwise.
		degrees += (digit2 - digit3 + (digit2 - digit3 < 0 ? 40: 0));
		// Print the number of rotated degrees.
		cout << degrees * 9 << "\n";
	}
	
	return 0;
}
