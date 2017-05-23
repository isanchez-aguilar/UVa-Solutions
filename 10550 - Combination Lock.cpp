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
	// Variable to save the initial position.
	int initialPosition;
	// Variables to save the combination.
	int digit1;
	int digit2;
	int digit3;
	// Read while not EOF.
	while(scanf("%d %d %d %d", &initialPosition, &digit1, &digit2, &digit3) != EOF)
	{
		// If any number is different from zero.
		if(initialPosition | digit1 | digit2 | digit3)
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
			printf("%d\n", degrees * 9);
		}
		// If all numbers are zero then finish execution.
		else
			return 0;
	}
	return 0;
}