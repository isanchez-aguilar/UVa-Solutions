/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11547 - Automatic Answer
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
	while(testCases--)
	{
		// Variable to save the number to operate.
		int number;
		// Read the number to operate.
		cin >> number;
		// Print the answer of operation.
		cout <<  fabs((number * 315 + 36962) / 10 % 10) << "\n";
	}
	return 0;
}