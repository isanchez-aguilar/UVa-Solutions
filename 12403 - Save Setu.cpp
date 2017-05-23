/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12403 - Save Setu
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to account.
	int account = 0;
	// Variable to save the number of operations.
	int numberOperations;
	// Read the number of operations.
	cin >> numberOperations;
	// Read while there are operations.
	while(numberOperations--)
	{
		// Variable to save the operation.
		string operation;
		// Read the instruction.
		cin >> operation;
		// If It is a donation then add money.
		if(operation[0] == 'd')
		{
			// Variable to save the donation.
			int donation;
			// Read the donation.
			cin >> donation;
			// Add the donation.
			account += donation;
		}
		// If is a report then show the account.
		else
			cout << account << "\n";
	}
	return 0;
}