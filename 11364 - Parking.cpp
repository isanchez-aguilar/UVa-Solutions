/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11364 - Parking
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of test cases.
	int testCases;
	// Red the number of test cases.
	cin >> testCases;
	// Read while not EOF.
	while(testCases--)
	{
		// Variable to save the number of stores.
		int numberStores;
		// Read the number of stores.
		cin >> numberStores;
		// Variables to save minimum and maximum position of the stores.
		int minPosition = 99;
		int maxPosition = 0;
		// Read the position of stores.
		for(int i = 0; i < numberStores; ++i)
		{
			// Variable to save the position of current store.
			int positionStore;
			// Read the position of current store.
			cin >> positionStore;
			// Get minimum and maximum value between minPosition and positionStore.
			minPosition = min(minPosition, positionStore);
			maxPosition = max(maxPosition, positionStore);
		}
		// Compute distance between maxPosition and minPosition and get the round trip.
		cout << (maxPosition - minPosition) * 2;
	}
	return 0;
}