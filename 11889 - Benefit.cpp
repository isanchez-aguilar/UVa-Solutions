/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11889 - Benefit
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 32769;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	// gcd(a, b) = lcm(a, b) / (a * b).
	while (testCases--)
	{
		int a;
		int c;
		cin >> a >> c;

		if (c % a != 0)
			cout << "NO SOLUTION\n";
		else
		{
			int b = c / a;
			int gcd = __gcd(a, b);

			// While a and b have common factors we need to get them to add to b.
			while (gcd != 1)
			{
				b *= gcd;
				a /= gcd;
				cout << "\t" << gcd << endl;
				gcd = __gcd(a, b);
			}

			cout << b << "\n";
		}
	}

	return 0;
}