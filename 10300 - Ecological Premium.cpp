/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10300 - Ecological Premium
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// Variable to save the numbr of test cases.
	int testCases;
	// Read the number of test cases.
	cin >> testCases;

	// While there are test cases.
	while(testCases--)
	{
		// Variable to save the number of farmers.
		int farmers;
		// Read the numbr of farmers.
		cin >> farmers;
		
		// Read data of every single farmer.
		long long size;
		long long animals;
		long long pay = 0;
		long long factorEnviroment;
		
		while(farmers--)
		{
			// Read data of farmer.
			cin >> size >> animals >> factorEnviroment;
			// Add the pay of every farmer.
			pay += size * factorEnviroment;
		}
		
		// Print the pay of farmers.
		cout << pay << "\n";
	}
	return 0;
}
