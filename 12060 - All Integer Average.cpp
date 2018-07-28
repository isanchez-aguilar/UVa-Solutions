/*
*	User: Isanchez_Aguilar
*	Problem: UVA 
*/
#include <bits/stdc++.h>

using namespace std;

inline int getNumberOfDigits(int n)
{
	int digits = 0;

	while (n != 0)
	{
		n /= 10;
		++digits;
	}

	return digits;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;

	while (cin >> n and n)
	{
		int sum = 0;

		for (int i = 0; i < n; ++i)
		{
			int number;
			cin >> number;

			sum += number;
		}

		cout << "Case " << ++t << ":\n";
		
		if (sum % n == 0)
			cout << (sum < 0?"- ":"") << abs(sum / n) << "\n";
		else
		{
			bool isNegative = sum < 0;
			
			if (isNegative)
				sum = abs(sum);

			int numerator = sum % n;
			int integerPart = sum / n;
			int divisor = __gcd(numerator, n);
			
			n /= divisor;
			numerator /= divisor;

			int integerPartLength = getNumberOfDigits(integerPart);
			int longestLength = max(getNumberOfDigits(numerator), getNumberOfDigits(n));

			// Numerator.
			if (isNegative)
				cout << "  ";

			for (int i = 0; i < integerPartLength; ++i)
				cout << " ";

			cout << setw(longestLength) << numerator << "\n";

			// Integer part.
			if (isNegative)
				cout << "- ";

			if (integerPart != 0)
				cout << integerPart;

			for (int i = 0; i < longestLength; ++i)
				cout << "-";
			
			cout << "\n";

			// Denominator
			if (isNegative)
				cout << "  ";

			for (int i = 0; i < integerPartLength; ++i)
				cout << " ";

			cout << setw(longestLength) << n << "\n";
		}

	}

	return 0;
}