/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12157 - Tariff Plan
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
	// Read while there are test cases.
	for(int i = 1; i <= testCases; ++i)
	{
		// Print information of case.
		cout << "Case " << i << ": ";
		// Variable to save the number of call durations.
		int calls;
		cin >> calls;
		// Variable to save the cost of every call duration.
		int mile = 0;
		int juice = 0;
		// Read all call durations.
		for(int j = 0; j < calls; ++j)
		{
			// Variable to save the current call duration.
			float callDuration;
			cin >> callDuration;
			// Compute to every plan.
			mile += static_cast<int>(ceil((callDuration + 1) / 30)) * 10;
			juice += static_cast<int>(ceil((callDuration + 1) / 60)) * 15;
		}
		// If the best plan is juice.
		if(mile > juice)
			cout << "Juice " << juice << "\n";
		// If the best plan is juice.
		else if(mile < juice)
			cout << "Mile " << mile << "\n";
		// If the plans are equal.
		else
			cout << "Mile Juice " << mile << "\n";
	}
	return 0;
}