/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11679 - Sub-prime
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Vairables to save the data of test case.
	int numberBanks;
	int numberDebentures;
	// Array to save the state of banks.
	vector<int> banks(21);
	// Read while there are test cases.
	while(cin >> numberBanks >> numberDebentures)
	{
		if(!numberBanks && !numberDebentures)
			return 0;
		bool possiblePay = true;
		// Read data of every single bank.
		for(int i = 0; i < numberBanks; ++i)
			cin >> banks[i];
		// Read data of every single debenture.
		for(int i = 0; i < numberDebentures; ++i)
		{
			// Variables to save the data of debenture.
			int debtor;
			int creditor;
			int loan;
			cin >> debtor >> creditor >> loan;
			// Update the state of banks.
			banks[debtor - 1] -= loan;
			banks[creditor - 1] += loan;
		}
		// Check the state of every single bank.
		for(int i = 0; i < numberBanks; ++i)
		{
			// If the i-th bank has negative credit then It is not possible pay all loans.
			if(banks[i] < 0)
			{
				possiblePay = false;
				cout << "N\n";
				break;
			}
		}
		// If every bank could pay then is possible pay all loans.
		if(possiblePay)
			cout << "S\n";
	}
	return 0;
}