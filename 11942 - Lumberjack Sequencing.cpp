/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11942 - Lumberjack Sequencing
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
	cout << "Lumberjacks:\n";
	// Read while there are test cases.
	while(testCases--)
	{
		// Variable to compare the order.
		int lastMeasure;
		int currentMeasure;
		// Variable to indicate the state of arrangement.
		bool toSmall = true;
		bool toBigger = true;
		// Read the first measure.
		cin >> lastMeasure;
		for(int i = 9; i > 0; --i)
		{
			// Read the current measure.
			cin >> currentMeasure;
			// If It is ordered from small to big.
			if(toBigger && lastMeasure <= currentMeasure)
				toSmall = false;
			// If It is ordered from big to small.
			else if(toSmall && lastMeasure >= currentMeasure)
				toBigger = false;
			// If It is undordered.
			else
			{
				toBigger = false;
				toSmall = false;
			}
			// Change the last data to current measure to next comparation.
			lastMeasure = currentMeasure;
		}
		// If the arrangement is ordered from one way or another.
		if(toSmall || toBigger)
			cout << "Ordered\n";
		// If the arrangement is unordered.
		else
			cout << "Unordered\n";
	}
	return 0;
}