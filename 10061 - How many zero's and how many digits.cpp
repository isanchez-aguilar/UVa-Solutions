/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10061 - How many zero's and how many digits ?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int b;

	while (cin >> n >> b)
	{	
		double digits = 0;

		for (int i = 1; i <= n; ++i)
			digits += log(i);

		digits /= log(b);
		digits = floor(digits + 1);

		int auxB = b;
		int trailingZeros = n;
		
		for (int i = 2; i <= b; ++i)
		{
			if (auxB % i == 0)
			{
				int power = 0;
				while (auxB % i == 0)
				{
					++power;
					auxB /= i;
				}

				int auxN = n;
				int powerFactor = 0;

				while (auxN > 0)
				{
					powerFactor += auxN / i;
					auxN /= i;
				}

				trailingZeros = min(trailingZeros, powerFactor / power);
			}
		}

		cout << (int)trailingZeros << " " << (int)digits << "\n";
	}

	return 0;
}