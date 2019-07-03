/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11287 - Pseudoprime Numbers
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

int n;
int p;
int currentN;
int powerSize;
int prime[25];
int primeSize = 0;
bitset<MAX> isNotPrime;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	prime[primeSize++] = 2;

	for (size_t i = 4; i < MAX; i += 2)
		isNotPrime[i] = true;
	
	for (size_t i = 3; i < MAX; i += 2)
	{
		if (not isNotPrime[i])
		{
			for (size_t j = i * i; j < MAX; j += i)
				isNotPrime[j] = true;

			prime[primeSize++] = i;
		}
	}

	n;

	while (cin >> n and n)
	{
		powerSize = 0;

		cout << setw(3) << n << "! =";

		for (size_t i = 0; i < primeSize and prime[i] <= n; ++i)
		{
			p = 0;
			currentN = n;
			
			while (currentN > 0)
			{
				currentN /= prime[i];
				p += currentN;
			}

			if (i > 0 and i % 15 == 0)
				cout << "\n      ";

			cout << setw(3) << p;
		}

		cout << "\n";
	}

	return 0;
}