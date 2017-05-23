/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11799 - Horror Dash
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of test cases.
	int testCases;
	cin >> testCases;
	// Read while there are test cases.
	for(int i = 1; i <= testCases; ++i)
	{
		// Variable to save the number of creatures.
		int creatures;
		cin >> creatures;
		// Variable to save the minimum speed that the clown must to have.
		int minimumSpeed = 0;
		// Read all speed of creatures.
		for(int  j = 0; j < creatures; ++j)
		{
			int speed;
			// Read the speed of i-th creature.
			cin >> speed;
			// Get the maximum speed of creature.
			minimumSpeed = max(speed, minimumSpeed);
		}
		// Print the speed that the clown must to have.
		cout << "Case " << i << ": " << minimumSpeed << "\n";
	}
	return 0;
}