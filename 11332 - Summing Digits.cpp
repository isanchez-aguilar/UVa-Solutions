/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11332 - Summing Digits
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number.
	int number;
	// Read while the number is bigger than zero.
	while(cin >> number && number)
	{
		// While the number has more of 1 digit.
		while(number > 9)
		{
			// Variable to save the sum of It digits.
			int sumDigits = 0;
			// While there are digits.
			while(number)
			{
				// Get the digit and add.
				sumDigits += number % 10;
				// Remove the added digit.
				number /= 10;
			}
			// The sum of It digits is the new number.
			number = sumDigits;
		}
		// Print the digit.
		cout << number << "\n";
	}
	return 0;
}