/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12005 - Find Solutions
*/
#include <bits/stdc++.h>

#define MAX 40000000

using namespace std;

vector<int> prime;

inline int getNumberOfDivisors(long long n)
{
	int index = 0;
	int divisors = 1;
	long long primeFactor = prime[0];

	while (primeFactor * primeFactor <= n)
	{
		int power = 0;
		while (n % primeFactor == 0)
		{
			++power;
			n /= primeFactor; 
		}

		divisors *= (power + 1);
		primeFactor = prime[++index];
	}

	if (n != 1)
		divisors <<= 1;

	return divisors;
}

void sieve()
{
	vector<bool> isNotPrime(MAX);

	for (int i = 2; i < MAX; ++i)
	{
		if (not isNotPrime[i])
		{
			prime.push_back(i);

			for (int j = (i << 1); j < MAX; j += i)
				isNotPrime[j] = true;
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long c;

	sieve();

	while (cin >> c and c)
		cout << c << " " << getNumberOfDivisors((c << 2LL) - 3) << "\n";

	return 0;
}