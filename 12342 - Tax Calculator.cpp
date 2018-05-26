/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12342 - Tax Calculator
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for (int t = 1; t <= testCases; ++t)
	{
		long long amount;
		long long tax = 0;

		cin >> amount;

		// Amount without tax.
		amount -= 180000;
		
		if (amount > 0)
		{
			tax = amount * 10;
			amount -= 300000;
			
			if (amount > 0)
			{
				tax += amount * 5;
				amount -= 400000;
				
				if (amount > 0)
				{
					tax += amount * 5;
					amount -= 300000;
					
					if (amount > 0)
						tax += amount * 5;
				}
			}
			if (tax % 100)
				tax += (100 - (tax % 100));
			
			tax /= 100;
			
			if (tax < 2000)
				tax = 2000;
		}

		cout << "Case " << t << ": " << tax << "\n";
	}

	return 0;
}