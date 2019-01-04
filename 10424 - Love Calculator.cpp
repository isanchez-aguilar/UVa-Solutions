/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10424 - Love Calculator
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Varibale to save the names of people.
	string name;
	// Read while not EOF.
	while (getline(cin, name))
	{
		// Varibale to save the percentage compute.
		int sum1 = 0;
		// Add value of every single letter.
		for (int i = 0; i < name.length(); ++i)
		{
			if (isalpha(name[i]))
				sum1 += tolower(name[i]) - 'a' + 1;
		}
		
		// The sum of digits' number n is n % 9. 
		sum1 %= 9;
		// If the module is 0 then is nine the sum.
		if (sum1 == 0)
			sum1 = 9;
		
		// Read the second name.
		getline(cin, name);
		
		int sum2 = 0;
		// Add value of every single letter.
		for (int i = 0; i < name.length(); ++i)
		{
			if (isalpha(name[i]))
				sum2 += tolower(name[i]) - 'a' + 1;
		}

		// The sum of digits' number n is n % 9.
		sum2 %= 9;
		// If the module is 0 then is nine the sum.
		if (sum2 == 0)
				sum2 = 9;
		
		if (sum1 < sum2)
			swap(sum1, sum2);

		cout << fixed << setprecision(2) << sum2 * 100.0 / sum1 << " %\n";
	}
	
	return 0;
}
